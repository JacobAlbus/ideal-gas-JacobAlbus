#include <iostream>
#include <catch2/catch.hpp>

#include "particle.h"

using namespace ideal_gas;

TEST_CASE("Update Particle Properly Updates Velocity"){
  glm::vec2 position1(5.0, 6.0);
  glm::vec2 velocity1(0.5, -1.0);
  size_t mass1 = 1;
  size_t radius1 = 1;
  Particle particle1 = Particle(velocity1, position1, mass1, radius1);

  glm::vec2 position2(6.0, 7.0);
  glm::vec2 velocity2(1.0, -2.0);
  size_t mass2 = 1;
  size_t radius2 = 1;
  Particle particle2 = Particle(velocity2, position2, mass2, radius2);

  particle1.UpdateParticles(particle2);

  REQUIRE(particle1.GetVelocity()[0] == Approx(0.25));
  REQUIRE(particle1.GetVelocity()[1] == Approx(-1.25));

  REQUIRE(particle2.GetVelocity()[0] == Approx(1.25));
  REQUIRE(particle2.GetVelocity()[1] == Approx(-1.75));
}

TEST_CASE("Update Position Works Correctly"){
  glm::vec2 position(5.0, 6.0);
  glm::vec2 velocity(0.5, -1.0);
  size_t mass = 1;
  size_t radius = 1;
  Particle particle = Particle(velocity, position, mass, radius);

  particle.UpdatePosition();
  REQUIRE(particle.GetPosition()[0] == Approx(5.5));
  REQUIRE(particle.GetPosition()[1] == Approx(5.0));
}

TEST_CASE("Calculate Distance Returns Correct Distance"){
  glm::vec2 position1(5.0, 6.0);
  glm::vec2 velocity1(0.5, -1.0);
  size_t mass1 = 1;
  size_t radius1 = 1;
  Particle particle1 = Particle(velocity1, position1, mass1, radius1);

  glm::vec2 position2(6.0, 7.0);
  glm::vec2 velocity2(1.0, -2.0);
  size_t mass2 = 1;
  size_t radius2 = 1;
  Particle particle2 = Particle(velocity2, position2, mass2, radius2);

  double distance = particle1.CalculateDistance(particle2);

  REQUIRE(distance == Approx(1.414213562));
}

