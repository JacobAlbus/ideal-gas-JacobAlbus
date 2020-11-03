#include "engine/particle.h"

namespace ideal_gas {

Particle::Particle(const glm::vec2& velocity,
                   const glm::vec2& position,
                   ParticleType type) {

  velocity_ = velocity;
  position_ = position;
  
  switch(type) {
    case ParticleType::kRed:
      mass_ = 1;
      radius_ = 3;
      particle_color_ = ci::Color(1, 0, 0);
      break;
    case ParticleType::kBlue:
      mass_ = 4;
      radius_ = 6;
      particle_color_ = ci::Color(0, 0, 1);
      break;
    default:
      mass_ = 1;
      radius_ = 3;
      particle_color_ = ci::Color(1, 0, 0);
  }
}

void Particle::UpdateVelocity(Particle& particle_in_contact) {
  if(IsParticlesInContact(particle_in_contact) &&
     IsParticlesInOppositeDirections(particle_in_contact)){

    glm::vec2 updated_velocity1 =
        CalculateUpdatedVelocity(particle_in_contact);
    glm::vec2 updated_velocity2 =
        particle_in_contact.CalculateUpdatedVelocity(*this);

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
  if(position_[0] <= (gas_box.getX1() + radius_) && velocity_[0] < 0) {
    velocity_[0] *= -1;
  } else if(position_[0] >= (gas_box.getX2() - radius_) && velocity_[0] > 0) {
    velocity_[0] *= -1;
  }

  if(position_[1] <= (gas_box.getY1() + radius_) && velocity_[1] < 0) {
    velocity_[1] *= -1;
  } else if(position_[1] >= (gas_box.getY2() - radius_) && velocity_[1] > 0) {
    velocity_[1] *= -1;
  }

  position_ += velocity_;
}

//TODO make not ugly
glm::vec2 Particle::CalculateUpdatedVelocity(const Particle& particle2) {
  double mass_coefficient =
      2 * (particle2.mass_ / (particle2.mass_ + mass_));
  glm::vec2 velocity_diff = velocity_ - particle2.velocity_;
  glm::vec2 position_diff = position_ - particle2.position_;

  double velocity_position_product = glm::dot(velocity_diff, position_diff);
  double particle_distance = glm::pow(CalculateDistance(particle2), 2);

  double temp =
      (mass_coefficient * velocity_position_product) / particle_distance;

  return velocity_ - (position_diff * static_cast<float>(temp));
}

bool Particle::IsParticlesInContact(const Particle &particle2) const {
  if(GetPosition() != particle2.GetPosition()) {
    double touching_radius = GetRadius() + particle2.GetRadius();
    if(CalculateDistance(particle2) <= touching_radius){
      return true;
    }
  }

  return false;
}

bool Particle::IsParticlesInOppositeDirections(const Particle& particle2) const {
  glm::vec2 position_diff = position_ - particle2.position_;
  glm::vec2 velocity_diff = velocity_ - particle2.velocity_;
  return glm::dot(velocity_diff, position_diff) < 0;
}

const glm::vec2 & Particle::GetVelocity() const {
  return velocity_;
}

const glm::vec2& Particle::GetPosition() const {
  return position_;
}

size_t Particle::GetRadius() const {
  return radius_;
}

const ci::Color& Particle::GetColor() const {
  return particle_color_;
}

double Particle::GetMass() const {
  return mass_;
}

} //namespace ideal_gas