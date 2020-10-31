#ifndef IDEAL_GAS_INCLUDE_PARTICLES_H_
#define IDEAL_GAS_INCLUDE_PARTICLES_H_

#include <particle.h>
#include <vector>

namespace ideal_gas {

class Particles{
 public:
  Particles(size_t num_particles);
 private:
  /**
   * Finds all particles given one is currently colliding with
   * @param given particle
   * @return vector of particles given one is colliding with
   */
  std::vector<Particle>& FindCollidedParticles(const Particle& particle);

  std::vector<Particle> particles_;
};

}
#endif //IDEAL_GAS_INCLUDE_PARTICLES_H_
