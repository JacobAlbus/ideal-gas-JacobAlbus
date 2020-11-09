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

TEST_CASE("Manage Particles Updates Positions and Velocities") {
  const size_t kNumHistogramBins = 8;
  Simulation simulation = Simulation(kNumHistogramBins);

  for(size_t index = 1; index < 6; index++) {
    glm::vec2 velocity(index * 3, index * 5);
    glm::vec2 position(index * 1, index * 4);

    ParticleType particle_type = ParticleType::kRed;
    if(index % 2 == 0) {
      particle_type = ParticleType::kBlue;
    } else if(index % 3 == 0) {
      particle_type = ParticleType::kGreen;
    }

    Particle particle = Particle(velocity, position, particle_type);
    simulation.AddParticle(particle);
  }

  const std::vector<Particle>& particles = simulation.GetParticles();
  simulation.AddParticle(Particle(glm::vec2(2, 2),
                                  glm::vec2(3, 14),
                                  ParticleType::kBlue));

  simulation.UpdateParticles(ci::Rectf(0.0f, 0.0f, 200.0f, 200.0f));

  REQUIRE(particles[0] == Particle(glm::vec2(12.818182f, -0.0909099578f),
                                   glm::vec2(4.0f, 9.0f),
                                   ParticleType::kRed));
  REQUIRE(particles[1] == Particle(glm::vec2(7.92341757f, 7.82665348f),
                                   glm::vec2(7.1999998f, 17.6000004f),
                                   ParticleType::kBlue));
  REQUIRE(particles[2] == Particle(glm::vec2(9.00738144f, 15.948554f),
                                   glm::vec2(10.4160004f, 24.8880005f),
                                   ParticleType::kGreen));
  REQUIRE(particles[3] == Particle(glm::vec2(10.8480005f, 19.4239998f),
                                   glm::vec2(14.8480005f, 35.4239998f),
                                   ParticleType::kBlue));
  REQUIRE(particles[4] == Particle(glm::vec2(-1.00943184f, 10.5513096f),
                                   glm::vec2(3.99056816f, 30.5513096f),
                                   ParticleType::kRed));
  REQUIRE(particles[5] == Particle(glm::vec2(1.81818175f, 2.909091f),
                                   glm::vec2(4.81818199f, 16.9090919f),
                                   ParticleType::kBlue));
}