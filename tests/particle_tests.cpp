#include <iostream>
#include <catch2/catch.hpp>

#include "engine/particle.h"
using namespace ideal_gas;

TEST_CASE("Constructor Properly Instantiates Particle") {
  glm::vec2 position(5.0, 6.0);
  glm::vec2 velocity(0.5, -1.0);

  SECTION("Red Particle") {
    Particle red_particle = Particle(velocity, position, ParticleType::kRed);
    REQUIRE(red_particle.GetPosition() == glm::vec2(5.0, 6.0));
    REQUIRE(red_particle.GetVelocity() == glm::vec2(0.5, -1.0));
    REQUIRE(red_particle.GetRadius() == 3);
    REQUIRE(red_particle.GetMass() == 1);
    REQUIRE(red_particle.GetColor() == ci::Color(1, 0, 0));
  }

  SECTION("Blue Particle") {
    Particle red_particle = Particle(velocity, position, ParticleType::kBlue);
    REQUIRE(red_particle.GetPosition() == glm::vec2(5.0, 6.0));
    REQUIRE(red_particle.GetVelocity() == glm::vec2(0.5, -1.0));
    REQUIRE(red_particle.GetRadius() == 6);
    REQUIRE(red_particle.GetMass() == 4);
    REQUIRE(red_particle.GetColor() == ci::Color(0, 0, 1));
  }

  SECTION("Default Particle") {
    Particle red_particle = Particle(velocity, position, ParticleType::kDefault);
    REQUIRE(red_particle.GetPosition() == glm::vec2(5.0, 6.0));
    REQUIRE(red_particle.GetVelocity() == glm::vec2(0.5, -1.0));
    REQUIRE(red_particle.GetRadius() == 3);
    REQUIRE(red_particle.GetMass() == 1);
    REQUIRE(red_particle.GetColor() == ci::Color(1, 0, 0));
  }
}

TEST_CASE("Update Particle Properly Updates Velocity") {
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

TEST_CASE("Calculate Distance Returns Correct Distance"){
  glm::vec2 position1(5.0, 6.0);
  glm::vec2 velocity1(0.5, -1.0);
  Particle particle1 = Particle(velocity1, position1, ParticleType::kRed);

  glm::vec2 position2(6.0, 7.0);
  glm::vec2 velocity2(1.0, -2.0);
  Particle particle2 = Particle(velocity2, position2, ParticleType::kRed);

  REQUIRE(particle1.CalculateDistance(particle2) == Approx(1.414213562));
}

TEST_CASE("Update Position Works Correctly"){
  glm::vec2 position(5.0, 6.0);
  glm::vec2 velocity(0.5, -1.0);
  Particle particle = Particle(velocity, position, ParticleType::kRed);

  ci::Rectf gas_box(200.0f, 300.0f, 200.0f, 300.0f);

  particle.UpdatePosition(gas_box);
  REQUIRE(particle.GetPosition()[0] == Approx(5.5));
  REQUIRE(particle.GetPosition()[1] == Approx(7.0));
}

TEST_CASE("IsParticlesInContact Will Allow Velocities To Be Updated") {
  glm::vec2 position1(5.0, 6.0);
  glm::vec2 velocity1(0.5, -1.0);
  Particle particle1 = Particle(velocity1, position1, ParticleType::kRed);

  glm::vec2 position2(6.0, 7.0);
  glm::vec2 velocity2(1.0, -2.0);
  Particle particle2 = Particle(velocity2, position2, ParticleType::kRed);

  particle1.UpdateVelocity(particle2);
  REQUIRE_FALSE(particle1.GetVelocity() == velocity1);
}

TEST_CASE("IsParticlesInContact Will Stop Velocities From Being Updated") {
  glm::vec2 position1(511.0, 6.0);
  glm::vec2 velocity1(0.5, -1.0);
  Particle particle1 = Particle(velocity1, position1, ParticleType::kRed);

  glm::vec2 position2(6.0, 7.0);
  glm::vec2 velocity2(1.0, -2.0);
  Particle particle2 = Particle(velocity2, position2, ParticleType::kRed);

  particle1.UpdateVelocity(particle2);
  REQUIRE(particle1.GetVelocity() == velocity1);
}

TEST_CASE("IsParticlesMovingCloser Will Allow Velocities To Be Updated") {
  glm::vec2 position1(5.0, 6.0);
  glm::vec2 velocity1(0.5, -1.0);
  Particle particle1 = Particle(velocity1, position1, ParticleType::kRed);

  glm::vec2 position2(6.0, 7.0);
  glm::vec2 velocity2(1.0, -2.0);
  Particle particle2 = Particle(velocity2, position2, ParticleType::kRed);

  particle1.UpdateVelocity(particle2);
  REQUIRE(particle1.GetVelocity() == velocity1);
}

TEST_CASE("IsParticlesMovingCloser Will Stop Velocities From Being Updated") {
  glm::vec2 position1(5.0, 6.0);
  glm::vec2 velocity1(-0.5, -1.0);
  Particle particle1 = Particle(velocity1, position1, ParticleType::kRed);

  glm::vec2 position2(6.0, 7.0);
  glm::vec2 velocity2(1.0, 2.0);
  Particle particle2 = Particle(velocity2, position2, ParticleType::kRed);

  particle1.UpdateVelocity(particle2);
  REQUIRE_FALSE(particle1.GetVelocity() == velocity1);
}
