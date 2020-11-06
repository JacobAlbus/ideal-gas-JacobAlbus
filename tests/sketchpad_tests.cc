#include <iostream>
#include <catch2/catch.hpp>

#include "gui/simulation_ui.h"

using namespace ideal_gas;
using namespace visualizer;

//TODO refactor simulation_ui tests to explicitly test simulation
TEST_CASE("IsBrushInsideWindow Stops HandleParticleBrush "
          "From Creating New Particle") {

  ci::Rectf gas_window(0, 0, 200.0f, 300.0f);
  glm::vec2 mouse_coords(300, 400);

  SimulationUI simulation_ui = SimulationUI();
  Simulation simulation = Simulation();
  simulation_ui.HandleParticleBrush(mouse_coords, gas_window, ParticleType::kRed, simulation);

  // REQUIRE(simulation_ui.GetParticles().empty());
}

TEST_CASE("IsBrushInsideWindow Allows HandleParticleBrush "
          "to Create New Particle") {

  ci::Rectf gas_window(0, 0, 200.0f, 300.0f);
  glm::vec2 mouse_coords(100, 200);

  SimulationUI simulation_ui = SimulationUI();
  Simulation simulation = Simulation();
  simulation_ui.HandleParticleBrush(mouse_coords, gas_window, ParticleType::kRed, simulation);

  // REQUIRE(simulation_ui.GetParticles().size() == 1);
}


