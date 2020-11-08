#ifndef IDEAL_GAS_SRC_ENGINE_SIMULATION_H_
#define IDEAL_GAS_SRC_ENGINE_SIMULATION_H_

#include "engine/particle.h"
#include <iostream>
#include <map>

namespace ideal_gas {

//TODO change name
typedef std::map<ParticleType, std::vector<size_t>> speed_histograms_t;

class Simulation {
 public:
  /**
   * Instantiates the Simulation class
   */
  Simulation();

  /**
   * Updates the position and velocity of each particle
   */
  void ManageParticles(ci::Rectf gas_window);

  /**
   * Adds a particle to the simulation
   * @param particle object to be added to simulation
   */
  void AddParticle(const Particle& particle);

  /**
   * Updates histogram bins for each particle type
   */
  void UpdateSpeedHistograms();

  /**
   * Clears all particles from simulation
   */
  void Clear();

  const std::vector<Particle>& GetParticles() const;

  const speed_histograms_t& GetSpeedHistograms() const;

 private:
  /**
   * Calculates the speed of each particle
   * @return sorted vector of speeds
   */
  std::vector<float> CalculateParticleSpeeds() const;

  /**
   * Calculates the range of particle speeds
   * @param vector of speeds of each particle
   * @return range of speeds
   */
  float CalculateParticleSpeedRange(const std::vector<float>& speeds) const;

  const size_t kNumHistogramBins;
  std::vector<Particle> particles_;
  speed_histograms_t speed_histograms_;
};
} // namespace ideal_gas


#endif //IDEAL_GAS_SRC_ENGINE_SIMULATION_H_
