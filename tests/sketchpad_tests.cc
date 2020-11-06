#include <iostream>
#include <catch2/catch.hpp>

#include "gui/simulation_ui.h"

using namespace ideal_gas;
using namespace visualizer;

//TODO refactor simulation_ui tests to explicitly test simulation
TEST_CASE("HandleParticleBrush Works Correctly") {
  SECTION("HandleParticleBrush does not draw particles "
          "if brush is outside of window") {
    ci::Rectf gas_window(0, 0, 200.0f, 300.0f);
    glm::vec2 mouse_coords(300, 400);

    SimulationUI simulation_ui = SimulationUI();
    Simulation simulation = Simulation();
    simulation_ui.HandleParticleBrush(mouse_coords, gas_window,
                                      ParticleType::kRed, simulation);

    REQUIRE(simulation.GetParticles().at(ParticleType::kRed).empty());
  }

  SECTION("HandleParticleBrush draws particles if brush is inside of window") {
    ci::Rectf gas_window(0, 0, 200.0f, 300.0f);
    glm::vec2 mouse_coords(100, 200);

    SimulationUI simulation_ui = SimulationUI();
    Simulation simulation = Simulation();
    simulation_ui.HandleParticleBrush(mouse_coords, gas_window,
                                      ParticleType::kRed, simulation);

    std::vector<Particle> particles = simulation.GetParticles().at(ParticleType::kRed);
    REQUIRE(particles.size() == 1);
    REQUIRE(particles[0].GetPosition() == mouse_coords);
    REQUIRE(particles[0].GetMass() == 1);
    REQUIRE(particles[0].GetRadius() == 2);
    REQUIRE(particles[0].GetColor() == ci::Color(1, 0, 0));
  }

}
