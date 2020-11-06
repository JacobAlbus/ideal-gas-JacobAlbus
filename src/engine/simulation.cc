#include "engine/simulation.h"

namespace ideal_gas {

Simulation::Simulation() {
  std::vector<Particle> empty;
  std::pair<ParticleType, std::vector<Particle>> new_pair;
  //TODO implement proper enum iterator
  new_pair = std::make_pair(ParticleType::kRed, empty);
  particles_.insert(new_pair);
  new_pair = std::make_pair(ParticleType::kBlue, empty);
  particles_.insert(new_pair);
  new_pair = std::make_pair(ParticleType::kGreen, empty);
  particles_.insert(new_pair);
}

void Simulation::ManageParticles(ci::Rectf gas_window) {
  //TODO change name
  for(const auto& map_pair : particles_){

    for(Particle& particle : particles_.at(map_pair.first)) {
      particle.UpdatePosition(gas_window);

      for(auto& particle_in_contact : particles_[ParticleType::kRed]) {
        particle.UpdateVelocity(particle_in_contact);
      }
    }
  }
}

void Simulation::AddParticle(const Particle &particle,
                             ParticleType particle_type) {
  particles_[particle_type].push_back(particle);
}

void Simulation::Clear() {
  for(const auto& particle_type : particles_){
    particles_[particle_type.first].clear();
  }
}

const particle_map& Simulation::GetParticles() const {
  return particles_;
}


} // namespace ideal_gas