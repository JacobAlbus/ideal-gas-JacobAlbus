#include <iostream>
#include <catch2/catch.hpp>

#include "engine/simulation.h"

using namespace ideal_gas;

TEST_CASE("Histogram Constructor") {
  const size_t kNumHistogramBins = 8;
  Simulation simulation = Simulation(kNumHistogramBins);
  speed_histograms_t histograms = simulation.GetSpeedHistograms();

  SECTION("Correct Number of Histogram Bins For Each Particle type") {
    std::vector<size_t> red_particle_hist_bins =
        histograms.at(ParticleType::kRed);
    REQUIRE(red_particle_hist_bins.size() == kNumHistogramBins);

    std::vector<size_t> blue_particle_hist_bins =
        histograms.at(ParticleType::kBlue);
    REQUIRE(blue_particle_hist_bins.size() == kNumHistogramBins);

    std::vector<size_t> green_particle_hist_bins =
        histograms.at(ParticleType::kGreen);
    REQUIRE(green_particle_hist_bins.size() == kNumHistogramBins);
  }
}

TEST_CASE("Add Particles") {
  const size_t kNumHistogramBins = 8;
  Simulation simulation = Simulation(kNumHistogramBins);

  SECTION("Red Particles Are Added Correctly") {
    for(size_t index = 0; index < 3; index++) {
      glm::vec2 velocity(index * 3, index * 5);
      glm::vec2 position(index * 1, index * 4);

      Particle particle = Particle(velocity, position, ParticleType::kRed);
      simulation.AddParticle(particle);
    }

    std::vector<Particle> particles = simulation.GetParticles();

    REQUIRE(particles[0] == Particle(glm::vec2(0, 0),
                                     glm::vec2(0, 0),
                                     ParticleType::kRed));
    REQUIRE(particles[1] == Particle(glm::vec2(3, 5),
                                     glm::vec2(1, 4),
                                     ParticleType::kRed));
    REQUIRE(particles[2] == Particle(glm::vec2(6, 10),
                                     glm::vec2(2, 8),
                                     ParticleType::kRed));
  }

  SECTION("Blue Particles Are Added Correctly") {
    for(size_t index = 0; index < 3; index++) {
      glm::vec2 velocity(index * 6, index * 7);
      glm::vec2 position(index * 3, index * 7);

      Particle particle = Particle(velocity, position, ParticleType::kGreen);
      simulation.AddParticle(particle);
    }

    std::vector<Particle> particles = simulation.GetParticles();

    REQUIRE(particles[0] == Particle(glm::vec2(0, 0),
                                     glm::vec2(0, 0),
                                     ParticleType::kGreen));
    REQUIRE(particles[1] == Particle(glm::vec2(6, 7),
                                     glm::vec2(3, 7),
                                     ParticleType::kGreen));
    REQUIRE(particles[2] == Particle(glm::vec2(12, 14),
                                     glm::vec2(6, 14),
                                     ParticleType::kGreen));
  }

  SECTION("Green Particles Are Added Correctly") {
    for(size_t index = 0; index < 3; index++) {
      glm::vec2 velocity(index * 2, index * 4);
      glm::vec2 position(index * 6, index * 1);

      Particle particle = Particle(velocity, position, ParticleType::kGreen);
      simulation.AddParticle(particle);
    }

    std::vector<Particle> particles = simulation.GetParticles();

    REQUIRE(particles[0] == Particle(glm::vec2(0, 0),
                                     glm::vec2(0, 0),
                                     ParticleType::kGreen));
    REQUIRE(particles[1] == Particle(glm::vec2(2, 4),
                                     glm::vec2(6, 1),
                                     ParticleType::kGreen));
    REQUIRE(particles[2] == Particle(glm::vec2(4, 8),
                                     glm::vec2(12, 2),
                                     ParticleType::kGreen));
  }
}

TEST_CASE("Clear Gets Rid of All Particles") {
  const size_t kNumHistogramBins = 8;
  Simulation simulation = Simulation(kNumHistogramBins);

  for(size_t index = 0; index < 3; index++) {
    glm::vec2 velocity(index * 3, index * 5);
    glm::vec2 position(index * 1, index * 4);

    Particle particle = Particle(velocity, position, ParticleType::kRed);
    simulation.AddParticle(particle);
  }

  REQUIRE(simulation.GetParticles().size() == 3);
  simulation.Clear();
  REQUIRE(simulation.GetParticles().empty());
}