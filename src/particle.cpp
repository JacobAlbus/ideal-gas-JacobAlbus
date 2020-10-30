#include "../include/particle.h"
#include <math.h>
namespace ideal_gas {

Particle::Particle(const glm::vec2& velocity, const glm::vec2& position,
                   double mass, size_t radius) {
  velocity_ = velocity;
  position_ = position;
  kMass_ = mass;
  kRadius_ = radius;
}

void Particle::UpdateParticles(Particle& particle_in_contact) {
  glm::vec2 updated_velocity1 = CalculateUpdatedVelocity(*this, particle_in_contact);
  glm::vec2 updated_velocity2 = CalculateUpdatedVelocity(particle_in_contact, *this);

  velocity_ = updated_velocity1;
  particle_in_contact.velocity_ = updated_velocity2;
}

double Particle::CalculateDistance(const Particle &other_particle) {
  glm::vec2 position_diff = position_ - other_particle.position_;
  return sqrt(pow(position_diff[0], 2) + pow(position_diff[1], 2));
}

void Particle::UpdatePosition() {
  position_ += velocity_;
}

glm::vec2 Particle::CalculateUpdatedVelocity(const Particle& particle1, const Particle& particle2) const {
  double mass_coefficient = 2 * (particle1.kMass_ / (particle1.kMass_ + particle2.kMass_));
  glm::vec2 velocity_diff = particle1.velocity_ - particle2.velocity_;
  glm::vec2 position_diff = particle1.position_ - particle2.position_;

  double numerator = (velocity_diff[0] * position_diff[0]) + (velocity_diff[1] * position_diff[1]);
  double denominator = pow(position_diff[0], 2) + pow(position_diff[1], 2);

  double temp = (mass_coefficient * numerator) / denominator;

  return particle1.velocity_ - (position_diff * static_cast<float>(temp));
}

const glm::vec2& Particle::GetPosition() {
  return position_;
}

const glm::vec2& Particle::GetVelocity() {
  return velocity_;
}

} //namespace ideal_gas