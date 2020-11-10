#include <iostream>
#include <catch2/catch.hpp>

#include "gui/simulation_ui.h"

using namespace ideal_gas;
using namespace visualizer;

TEST_CASE("HandleParticleBrush Works Correctly") {
  SECTION("HandleParticleBrush does not draw particles "
          "if brush is outside of window") {
    ci::Rectf gas_window(0, 0, 200.0f, 300.0f);
    glm::vec2 mouse_coords(300, 400);

    SimulationUI simulation_ui = SimulationUI();
    simulation_ui.HandleParticleBrush(mouse_coords, gas_window,
                                      ParticleType::kRed);

    REQUIRE(simulation_ui.GetSimulationParticles().empty());
  }

  SECTION("HandleParticleBrush draws particles if brush is inside of window") {
    ci::Rectf gas_window(0, 0, 200.0f, 300.0f);
    glm::vec2 mouse_coords(100, 200);

    SimulationUI simulation_ui = SimulationUI();
    simulation_ui.HandleParticleBrush(mouse_coords, gas_window,
                                      ParticleType::kRed);

    std::vector<Particle> particles = simulation_ui.GetSimulationParticles();
    REQUIRE(particles.size() == 1);
    REQUIRE(particles[0].GetPosition() == mouse_coords);
    REQUIRE(particles[0].GetVelocity().x == Approx(1.27408f));
    REQUIRE(particles[0].GetVelocity().y == Approx(0.51631f));
    REQUIRE(particles[0].GetMass() == Approx(1.0f));
    REQUIRE(particles[0].GetRadius() == Approx(2.0f));
    REQUIRE(particles[0].GetColor() == ci::Color(1, 0, 0));
  }
}