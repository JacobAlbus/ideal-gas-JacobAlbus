#ifndef IDEAL_GAS_JACOBALBUS_INCLUDE_PARTICLE_H_
#define IDEAL_GAS_JACOBALBUS_INCLUDE_PARTICLE_H_
#include <vector>
#include "../../../include/cinder/gl/gl.h"

namespace ideal_gas {

class Particle {
 public:
  /**
   * Instantiates Particle with velocity, position, and mass
   * @param initial velocity of particle
   * @param initial position of particle
   * @param mass of particle
   */
  Particle(glm::vec2 velocity, glm::vec2 position, size_t mass);

  /**
   * Updates current particle's velocity based on
   * attributes of particles it's colliding with
   * @param particles current one is colliding with
   */
  void UpdateParticle(std::vector<Particle> particles_in_contact);

  /**
   * Updates particle's velocity based on attributes of other particle
   * @param particle current one is colliding with
   */
  void UpdateParticle(Particle particle_in_contact);
 private:
  glm::vec2 velocity_;
  glm::vec2 position_;
  size_t kMass_;
};

} //namespace ideal_gas

#endif //IDEAL_GAS_JACOBALBUS_INCLUDE_PARTICLE_H_
