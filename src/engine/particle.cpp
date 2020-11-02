#include "engine/particle.h"

namespace ideal_gas {

Particle::Particle(const glm::vec2& velocity,
                   const glm::vec2& position,
                   ParticleType type) {

  velocity_ = velocity;
  position_ = position;

  //TODO is this magical
  switch(type) {
    case ParticleType::kRed:
      kMass_ = 1;
      kRadius_ = 3;
      kParticleColor_ = ci::Color(1, 0, 0);
      break;
    case ParticleType::kBlue:
      kMass_ = 4;
      kRadius_ = 6;
      kParticleColor_ = ci::Color(0, 0, 1);
      break;
    default:
      kMass_ = 1;
      kRadius_ = 3;
      kParticleColor_ = ci::Color(1, 0, 0);
  }
}

void Particle::UpdateVelocity(Particle& particle_in_contact) {
  if(IsParticlesInContact(*this, particle_in_contact) &&
     IsParticlesInOppositeDirections(*this, particle_in_contact)){

    glm::vec2 updated_velocity1 =
        CalculateUpdatedVelocity(*this, particle_in_contact);
    glm::vec2 updated_velocity2 =
        CalculateUpdatedVelocity(particle_in_contact, *this);

    velocity_ = updated_velocity1;
    particle_in_contact.velocity_ = updated_velocity2;
  }
}

double Particle::CalculateDistance(const Particle& other_particle) const {
  glm::vec2 position_diff = position_ - other_particle.position_;
  return sqrt(pow(position_diff[0], 2) + pow(position_diff[1], 2));
}

void Particle::UpdatePosition(ci::Rectf gas_box) {
  // checks to see if particle is touching walls
  // and changes velocity in opposite direction
  if(position_[0] <= (gas_box.getX1() + kRadius_) ||
     position_[0] >= (gas_box.getX2() - kRadius_)) {
    velocity_[0] *= -1;
  }

  if(position_[0] <= (gas_box.getX1() + kRadius_) && velocity_[0] < 0) {
    velocity_[0] *= -1;
  } else if(position_[0] >= (gas_box.getX2() - kRadius_) && velocity_[0] > 0) {
    velocity_[0] *= -1;
  }

  if(position_[1] <= (gas_box.getY1() + kRadius_) && velocity_[1] < 0) {
    velocity_[1] *= -1;
  } else if(position_[1] >= (gas_box.getY2() - kRadius_) && velocity_[1] > 0) {
    velocity_[1] *= -1;
  }

  position_ += velocity_;
}

//TODO make not ugly
glm::vec2 Particle::CalculateUpdatedVelocity(const Particle& particle1,
                                             const Particle& particle2) {

  double mass_coefficient =
      2 * (particle1.kMass_ / (particle1.kMass_ + particle2.kMass_));
  glm::vec2 velocity_diff = particle1.velocity_ - particle2.velocity_;
  glm::vec2 position_diff = particle1.position_ - particle2.position_;

  double velocity_position_product = glm::dot(velocity_diff, position_diff);
  double particle_distance = glm::pow(particle1.CalculateDistance(particle2), 2);

  double temp =
      (mass_coefficient * velocity_position_product) / particle_distance;

  return particle1.velocity_ - (position_diff * static_cast<float>(temp));
}

bool Particle::IsParticlesInContact(const Particle &particle1,
                                    const Particle &particle2) const {
  if(particle1.GetPosition() != particle2.GetPosition()) {
    double touching_radius = this->GetRadius() + particle2.GetRadius();
    if(particle1.CalculateDistance(particle2) <= touching_radius){
      return true;
    }
  }

  return false;
}

bool Particle::IsParticlesInOppositeDirections(const Particle& particle1,
                                               const Particle& particle2)
                                               const {
  glm::vec2 position_diff = particle1.GetPosition() - particle2.GetPosition();
  glm::vec2 velocity_diff = particle1.GetVelocity() - particle2.GetVelocity();
  return glm::dot(velocity_diff, position_diff) < 0;
}

const glm::vec2& Particle::GetPosition() const {
  return position_;
}

const glm::vec2& Particle::GetVelocity() const {
  return velocity_;
}

size_t Particle::GetRadius() const {
  return kRadius_;
}

const ci::Color& Particle::GetColor() const {
  return kParticleColor_;
}

} //namespace ideal_gas