#include <iostream>
#include <catch2/catch.hpp>

#include "engine/simulation.h"
#include "engine/particle.h"

using namespace ideal_gas;

TEST_CASE("Histogram") {
  Simulation simulation = Simulation();

  for(size_t index = 0; index < 10; index++){
    Particle particle1 = Particle(glm::vec2(index, index),
                                  glm::vec2(index, index),
                                  ParticleType::kRed);
    simulation.AddParticle(particle1, ParticleType::kRed);
  }

  for(size_t index = 0; index < 10; index++){
    Particle particle1 = Particle(glm::vec2(index, index),
                                  glm::vec2(index, index),
                                  ParticleType::kRed);
    simulation.AddParticle(particle1, ParticleType::kBlue);
  }

  for(size_t index = 0; index < 10; index++){
    Particle particle1 = Particle(glm::vec2(index, index),
                                  glm::vec2(index, index),
                                  ParticleType::kRed);
    simulation.AddParticle(particle1, ParticleType::kGreen);
  }

  simulation.UpdateSpeedHistograms();
}