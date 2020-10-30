#ifndef IDEAL_GAS_JACOBALBUS_INCLUDE_PARTICLE_H_
#define IDEAL_GAS_JACOBALBUS_INCLUDE_PARTICLE_H_
#include <vector>
#include "cinder/gl/gl.h"

namespace ideal_gas {

class Particle {
 public:
  /**
   * Instantiates Particle with velocity, position, and mass
   * @param initial velocity of particle
   * @param initial position of particle
   * @param mass of particle
   */
  Particle(const glm::vec2& velocity, const glm::vec2& position,
           double mass, size_t radius);

  /**
   * Updates particle's position based on velocity
   */
  void UpdatePosition();

  /**
   * Updates particle's velocity based on attributes of other particle
   * @param particle current one is colliding with
   */
  void UpdateParticles(Particle& particle_in_contact);

  /**
   * Calculates distance between current particle and a given particle
   * @param particle which distance is calculated from
   * @return distance between current and given particle
   */
  double CalculateDistance(const Particle& other_particle);

  const glm::vec2& GetVelocity();

  const glm::vec2& GetPosition();

 private:
  /**
   * Calculates updated velocity for particle
   * @return updated particle velocity
   */
  glm::vec2 CalculateUpdatedVelocity(const Particle& particle1, const Particle& particle2) const;

  glm::vec2 velocity_;
  glm::vec2 position_;
  double kMass_;
  size_t kRadius_;
};

} //namespace ideal_gas

#endif //IDEAL_GAS_JACOBALBUS_INCLUDE_PARTICLE_H_
