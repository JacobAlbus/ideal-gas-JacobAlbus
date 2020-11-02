#include <iostream>
#include <catch2/catch.hpp>

#include "engine/particle.h"
#include "engine/particles.h"
using namespace ideal_gas;

TEST_CASE("AS"){
  Particles part = Particles(10);
}

TEST_CASE("Update Particle Properly Updates Velocity"){
  glm::vec2 position1(5.0, 6.0);
  glm::vec2 velocity1(0.5, -1.0);
  Particle particle1 = Particle(velocity1, position1, ParticleType::kRed);

  glm::vec2 position2(6.0, 7.0);
  glm::vec2 velocity2(1.0, -2.0);
  Particle particle2 = Particle(velocity2, position2, ParticleType::kRed);

  particle1.UpdateVelocity(particle2);

  REQUIRE(particle1.GetVelocity()[0] == Approx(0.25));
  REQUIRE(particle1.GetVelocity()[1] == Approx(-1.25));

  REQUIRE(particle2.GetVelocity()[0] == Approx(1.25));
  REQUIRE(particle2.GetVelocity()[1] == Approx(-1.75));
}

TEST_CASE("Update Position Works Correctly"){
  glm::vec2 position(5.0, 6.0);
  glm::vec2 velocity(0.5, -1.0);
  Particle particle = Particle(velocity, position, ParticleType::kRed);

  ci::Rectf gas_box(200.0f, 300.0f, 200.0f, 300.0f);

  particle.UpdatePosition(gas_box);
  REQUIRE(particle.GetPosition()[0] == Approx(4.5));
  REQUIRE(particle.GetPosition()[1] == Approx(7.0));
}

TEST_CASE("Calculate Distance Returns Correct Distance"){
  glm::vec2 position1(5.0, 6.0);
  glm::vec2 velocity1(0.5, -1.0);
  Particle particle1 = Particle(velocity1, position1, ParticleType::kRed);

  glm::vec2 position2(6.0, 7.0);
  glm::vec2 velocity2(1.0, -2.0);
  Particle particle2 = Particle(velocity2, position2, ParticleType::kRed);

  double distance = particle1.CalculateDistance(particle2);

  REQUIRE(distance == Approx(1.414213562));
}

