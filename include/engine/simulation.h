#ifndef IDEAL_GAS_SRC_ENGINE_SIMULATION_H_
#define IDEAL_GAS_SRC_ENGINE_SIMULATION_H_

#include "engine/particle.h"
#include <iostream>

namespace ideal_gas {

class Simulation {
 public:
  Simulation();
 private:
  std::vector<Particle> particles_;

};
} // namespace ideal_gas


#endif //IDEAL_GAS_SRC_ENGINE_SIMULATION_H_
