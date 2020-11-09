#include "engine/particle.h"

namespace ideal_gas {

Particle::Particle(const glm::vec2& velocity,
                   const glm::vec2& position,
                   ParticleType type) :
                   velocity_(velocity),
                   position_(position),
                   kParticleType(type) {

  velocity_ = velocity;
  position_ = position;
  
  switch(type) {
    case ParticleType::kRed:
      mass_ = 1.0f;
      radius_ = 2.0f;
      particle_color_ = ci::Color(1, 0, 0);
      break;
    case ParticleType::kBlue:
      mass_ = 10.0f;
      radius_ = 4.0f;
      particle_color_ = ci::Color(0, 0, 1);
      break;
    case ParticleType::kGreen:
      mass_ = 40.0f;
      radius_ = 6.0f;
      particle_color_ = ci::Color(0, 1, 0);
      break;
    default:
      mass_ = 1.0f;
      radius_ = 2.0f;
      particle_color_ = ci::Color(1, 0, 0);
  }
}

void Particle::UpdateVelocity(Particle& particle_in_contact) {
  if(IsParticlesInContact(particle_in_contact) &&
     IsParticlesMovingCloser(particle_in_contact)) {

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
  if(position_.x <= (gas_box.getX1() + radius_) && velocity_.x < 0) {
    velocity_.x *= -1;
  } else if(position_.x >= (gas_box.getX2() - radius_) && velocity_.x > 0) {
    velocity_.x *= -1;
  }

  if(position_.y <= (gas_box.getY1() + radius_) && velocity_.y < 0) {
    velocity_.y *= -1;
  } else if(position_.y >= (gas_box.getY2() - radius_) && velocity_.y > 0) {
    velocity_.y *= -1;
  }

  position_ += velocity_;
}

bool Particle::operator==(const Particle &other_particle) const {
  return mass_ == other_particle.mass_ &&
         radius_ == other_particle.radius_ &&
         velocity_ == other_particle.velocity_ &&
         position_ == other_particle.position_ &&
         kParticleType == other_particle.kParticleType;
}

glm::vec2 Particle::CalculateUpdatedVelocity(
    const Particle& particle_in_contact) {

  float mass_coefficient =
      2.0f * (particle_in_contact.mass_ / (particle_in_contact.mass_ + mass_));
  glm::vec2 velocity_diff = velocity_ - particle_in_contact.velocity_;
  glm::vec2 position_diff = position_ - particle_in_contact.position_;

  float velocity_position_product = glm::dot(velocity_diff, position_diff);
  auto particle_distance = static_cast<float>(glm::pow(CalculateDistance(particle_in_contact), 2));

  glm::vec2 velocity_change =
      position_diff *
      (mass_coefficient * velocity_position_product) / particle_distance;

  return velocity_ - velocity_change;
}

bool Particle::IsParticlesInContact(const Particle& particle_in_contact) const {
  double touching_radius = radius_ + particle_in_contact.GetRadius();

  double distance = CalculateDistance(particle_in_contact);

  return position_ != particle_in_contact.GetPosition() &&
         distance <= touching_radius;
}

bool Particle::IsParticlesMovingCloser(
    const Particle& particle_in_contact) const {
  glm::vec2 position_diff = position_ - particle_in_contact.position_;
  glm::vec2 velocity_diff = velocity_ - particle_in_contact.velocity_;
  return glm::dot(velocity_diff, position_diff) < 0;
}

const glm::vec2 & Particle::GetVelocity() const {
  return velocity_;
}

const glm::vec2& Particle::GetPosition() const {
  return position_;
}

float Particle::GetRadius() const {
  return radius_;
}

const ci::Color& Particle::GetColor() const {
  return particle_color_;
}

float Particle::GetMass() const {
  return mass_;
}

ParticleType Particle::GetType() const {
  return kParticleType;
}

} //namespace ideal_gas