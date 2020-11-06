#include "engine/simulation.h"

namespace ideal_gas {

Simulation::Simulation() {
  std::vector<Particle> empty;
  std::pair<ParticleType, std::vector<Particle>> new_pair;

  new_pair = std::make_pair(ParticleType::kRed, empty);
  particles_.insert(new_pair);
  new_pair = std::make_pair(ParticleType::kBlue, empty);
  particles_.insert(new_pair);
  new_pair = std::make_pair(ParticleType::kGreen, empty);
  particles_.insert(new_pair);
}

//TODO implement proper enum iterator
void Simulation::ManageParticles(ci::Rectf gas_window) {
  for(auto& particle : particles_[ParticleType::kRed]) {
    particle.UpdatePosition(gas_window);
    for(auto& particle_in_contact : particles_[ParticleType::kRed]) {
      particle.UpdateVelocity(particle_in_contact);
    }
  }

  for(auto& particle : particles_[ParticleType::kBlue]) {
    particle.UpdatePosition(gas_window);
    for(auto& particle_in_contact : particles_[ParticleType::kRed]) {
      particle.UpdateVelocity(particle_in_contact);
    }
  }

  for(auto& particle : particles_[ParticleType::kGreen]) {
    particle.UpdatePosition(gas_window);
    for(auto& particle_in_contact : particles_[ParticleType::kRed]) {
      particle.UpdateVelocity(particle_in_contact);
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

const std::map<ParticleType, std::vector<Particle>> & Simulation::GetParticles() const {
  return particles_;
}


} // namespace ideal_gas