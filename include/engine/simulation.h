#ifndef IDEAL_GAS_SRC_ENGINE_SIMULATION_H_
#define IDEAL_GAS_SRC_ENGINE_SIMULATION_H_

#include "engine/particle.h"
#include <iostream>
#include <map>

namespace ideal_gas {

class Simulation {
 public:
  /**
   * Instantiates the Simulation class with an empty map of particles
   */
  Simulation();


  /**
   * Updates the position and velocity of each particle
   */
  void ManageParticles(ci::Rectf gas_window);

  /**
   * Adds a particle to the map
   * @param particle object to be added to map
   */
  void AddParticle(const Particle& particle, ParticleType particle_type);

  /**
   * Clears each vector in the particles map
   */
  void Clear();

  const std::map<ParticleType, std::vector<Particle>>& GetParticles() const;

 private:
  std::map<ParticleType, std::vector<Particle>> particles_;
};
} // namespace ideal_gas


#endif //IDEAL_GAS_SRC_ENGINE_SIMULATION_H_
