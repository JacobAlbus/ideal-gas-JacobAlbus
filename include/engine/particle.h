#ifndef IDEAL_GAS_JACOBALBUS_INCLUDE_PARTICLE_H_
#define IDEAL_GAS_JACOBALBUS_INCLUDE_PARTICLE_H_

#include <vector>
#include "cinder/gl/gl.h"

namespace ideal_gas {

enum ParticleType {
  kRed,
  kBlue,
  kGreen,
  kDefault,
};

class Particle {
 public:
  /**
   * Instantiates Particle with velocity, position, and mass
   * @param initial velocity of particle
   * @param initial position of particle
   * @param mass of particle
   */
  Particle(const glm::vec2& velocity,
           const glm::vec2& position,
           ParticleType type);

  /**
   * Updates particle's position based on velocity
   * @param dimensions of window, used to make sure particle is within window
   */
  void UpdatePosition(ci::Rectf gas_box);

  /**
   * Updates particle's velocity based on attributes of other particle
   * @param particle current one is colliding with
   */
  void UpdateVelocity(Particle& particle_in_contact);

  /**
   * Calculates distance between current particle and a given particle
   * @param particle which distance is calculated from
   * @return distance between current and given particle
   */
  double CalculateDistance(const Particle& other_particle) const;

  const glm::vec2& GetVelocity() const;

  const glm::vec2& GetPosition() const;

  size_t GetRadius() const;

  double GetMass() const;

  const ci::Color& GetColor() const;

 private:
  /**
   * Checks to see if particle's are in contact with each other
   * @param A particle object
   * @param Another particle object
   * @return boolean corresponding to whether or not particles are in contact
   */
  bool IsParticlesInContact(const Particle& particle_in_contact) const;

  /**
   * Checks to see if particle's are heading towards each other
   * @param A particle object
   * @param Another particle object
   * @return boolean corresponding to whether or not
   *         particles are heading towards each other
   */
  bool IsParticlesMovingCloser(const Particle& particle_in_contact) const;

  /**
   * Calculates updated velocity for particle
   * @return updated particle velocity
   */
  glm::vec2 CalculateUpdatedVelocity(const Particle& particle_in_contact);

  glm::vec2 velocity_;
  glm::vec2 position_;
  double mass_;
  size_t radius_;
  ci::Color particle_color_;
};

} //namespace ideal_gas

#endif //IDEAL_GAS_JACOBALBUS_INCLUDE_PARTICLE_H_
