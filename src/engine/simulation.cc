#include "engine/simulation.h"
#include <math.h>
#include <algorithm>

namespace ideal_gas {

//TODO implement proper enum iterator
Simulation::Simulation() {
  std::vector<Particle> empty_particle;
  std::pair<ParticleType, std::vector<Particle>> particle_pair;

  particle_pair = std::make_pair(ParticleType::kRed, empty_particle);
  particles_.insert(particle_pair);
  particle_pair = std::make_pair(ParticleType::kBlue, empty_particle);
  particles_.insert(particle_pair);
  particle_pair = std::make_pair(ParticleType::kGreen, empty_particle);
  particles_.insert(particle_pair);

  std::vector<size_t> empty_speed;
  for(size_t i = 0; i < kNumHistogramBins; i++) {
    empty_speed.push_back(0);
  }
  std::pair<ParticleType, std::vector<size_t>> speed_pair;

  speed_pair = std::make_pair(ParticleType::kRed, empty_speed);
  particle_type_speeds_.insert(speed_pair);
  speed_pair = std::make_pair(ParticleType::kBlue, empty_speed);
  particle_type_speeds_.insert(speed_pair);
  speed_pair = std::make_pair(ParticleType::kGreen, empty_speed);
  particle_type_speeds_.insert(speed_pair);
}

void Simulation::ManageParticles(ci::Rectf gas_window) {
  //TODO change name
  for(const auto& map_pair1 : particles_){
    ParticleType particle_type1 = map_pair1.first;
    for(Particle& particle : particles_[particle_type1]) {
      particle.UpdatePosition(gas_window);

      for(const auto&  map_pair2 : particles_) {
        ParticleType particle_type2 = map_pair2.first;
        for(auto& particle_in_contact : particles_[particle_type2]) {
          particle.UpdateVelocity(particle_in_contact);
        }
      }
    }
  }
}

void Simulation::UpdateSpeedHistograms() {
  for(const auto& map_pair : particles_){
    ParticleType particle_type = map_pair.first;
    std::vector<Particle> particles = particles_.at(particle_type);
    std::vector<float> speeds = CalculateParticleSpeeds(particles);

    float hist_interval = CalculateVectorRange(speeds);
    for(size_t index = 0; index < kNumHistogramBins; index++) {
      particle_type_speeds_.at(particle_type)[index] = 0;

      for(float speed : speeds) {
        if(speed >= (hist_interval * index) && speed <= (hist_interval * (index + 1))) {
          particle_type_speeds_.at(particle_type)[index]++;
        }
      }
    }
  }
}

std::vector<float> Simulation::CalculateParticleSpeeds(const std::vector<Particle>& particles) const {
  std::vector<float> speeds;

  for(const auto& particle : particles) {
    glm::vec2 position = particle.GetPosition();
    float speed = sqrt(pow(position[0], 2) + pow(position[1], 2));
    speeds.push_back(speed);
  }

  return speeds;
}

float Simulation::CalculateVectorRange(const std::vector<float>& speeds) const {
  float min = std::numeric_limits<float>::max();
  float max = std::numeric_limits<float>::min();

  for(float speed : speeds) {
    if(speed < min) {
      min = speed;
    } else if(speed > max) {
      max = speed;
    }
  }

  return (max - min) / kNumHistogramBins;
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

const velocity_map& Simulation::GetSpeeds() const{
  return particle_type_speeds_;
}

} // namespace ideal_gas