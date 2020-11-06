#include <iostream>
#include <catch2/catch.hpp>

#include "gui/simulation_ui.h"
using namespace ideal_gas;
using namespace visualizer;

TEST_CASE("IsBrushInsideWindow Stops HandleParticleBrush "
          "From Creating New Particle") {

  ci::Rectf gas_window(0, 0, 200.0f, 300.0f);
  glm::vec2 mouse_coords(300, 400);

  Sketchpad sketchpad = Sketchpad();
  sketchpad.HandleParticleBrush(mouse_coords, gas_window, ParticleType::kRed);

  REQUIRE(sketchpad.GetParticles().empty());
}

TEST_CASE("IsBrushInsideWindow Allows HandleParticleBrush "
          "to Create New Particle") {

  ci::Rectf gas_window(0, 0, 200.0f, 300.0f);
  glm::vec2 mouse_coords(100, 200);

  Sketchpad sketchpad = Sketchpad();
  sketchpad.HandleParticleBrush(mouse_coords, gas_window, ParticleType::kRed);

  REQUIRE(sketchpad.GetParticles().size() == 1);
}


