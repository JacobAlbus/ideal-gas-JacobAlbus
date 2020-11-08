#ifndef IDEAL_GAS_SRC_ENGINE_SIMULATION_H_
#define IDEAL_GAS_SRC_ENGINE_SIMULATION_H_

#include "engine/particle.h"
#include <iostream>
#include <map>

namespace ideal_gas {

//TODO change name
typedef std::map<ParticleType, std::vector<Particle>> particle_map;
typedef std::map<ParticleType, std::vector<size_t>> velocity_map;

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
   * Calculates the speed of each particle for each particle type and
   * bins them for a histogram
   */
  void UpdateSpeedHistograms();

  /**
   * Clears each vector in the particles map
   */
  void Clear();

  const particle_map& GetParticles() const;

  const velocity_map& GetSpeeds() const;

 private:
  /**
   * Calculates the speed of each particle in passed vector
   * @param vector of particles
   * @return sorted vector of speeds
   */
  std::vector<float> CalculateParticleSpeeds(const std::vector<Particle>& particles) const;

  /**
   *
   * @param vector
   * @return
   */
  float CalculateVectorRange(const std::vector<float>& speeds) const;

  const size_t kNumHistogramBins = 5;
  particle_map particles_;
  velocity_map particle_type_speeds_;
};
} // namespace ideal_gas


#endif //IDEAL_GAS_SRC_ENGINE_SIMULATION_H_
