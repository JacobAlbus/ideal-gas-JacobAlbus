#include "../include/particle.h"

namespace ideal_gas {

Particle::Particle(glm::vec2 velocity, glm::vec2 position, size_t mass) {
  velocity_ = velocity;
  position_ = position;
  kMass_ = mass;
}

} //namespace ideal_gas