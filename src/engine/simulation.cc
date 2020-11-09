#include "engine/simulation.h"
#include <algorithm>

namespace ideal_gas {

Simulation::Simulation(size_t num_histogram_bins) :
                       kNumHistogramBins(num_histogram_bins) {

  //instantiates vector representing histogram bins for each particle type
  std::vector<size_t> empty_speed;
  for(size_t i = 0; i < kNumHistogramBins; i++) {
    empty_speed.push_back(0);
  }

  std::pair<ParticleType, std::vector<size_t>> histogram_pair;
  //TODO implement proper enum iterator
  histogram_pair = std::make_pair(ParticleType::kRed, empty_speed);
  speed_histograms_.insert(histogram_pair);
  histogram_pair = std::make_pair(ParticleType::kBlue, empty_speed);
  speed_histograms_.insert(histogram_pair);
  histogram_pair = std::make_pair(ParticleType::kGreen, empty_speed);
  speed_histograms_.insert(histogram_pair);
}

void Simulation::UpdateParticles(ci::Rectf gas_window) {
  for(Particle& particle : particles_) {
    particle.UpdatePosition(gas_window);

    for(Particle& particle_in_contact : particles_) {
      particle.UpdateVelocity(particle_in_contact);
    }
  }
}

void Simulation::UpdateSpeedHistograms() {
  std::vector<float> speeds = CalculateParticleSpeeds();
  float hist_interval = CalculateParticleSpeedRange(speeds);

  for(const auto& map_pair : speed_histograms_) {
    ParticleType particle_type = map_pair.first;

    for(size_t bin_index = 0; bin_index < kNumHistogramBins; bin_index++) {
      speed_histograms_.at(particle_type)[bin_index] = 0;

      for(size_t particle_index = 0; particle_index < particles_.size(); particle_index++) {
        float speed = speeds[particle_index];
        const Particle& particle = particles_[particle_index];

        if(particle.GetType() == particle_type){
          float lower = hist_interval * bin_index;
          float upper = hist_interval * (bin_index + 1);
          if(speed >= lower && speed <= upper) {
            speed_histograms_.at(particle_type)[bin_index]++;
          }
        }
      }
    }
  }
}

std::vector<float> Simulation::CalculateParticleSpeeds() const {
  std::vector<float> speeds;

  for(const auto& particle : particles_) {
    glm::vec2 velocity = particle.GetVelocity();
    float speed = sqrt(pow(velocity[0], 2) + pow(velocity[1], 2));
    speeds.push_back(speed);
  }

  return speeds;
}

float Simulation::CalculateParticleSpeedRange(const std::vector<float>& speeds) const {
  float min = std::numeric_limits<float>::max();
  float max = std::numeric_limits<float>::min();

  for(float speed : speeds){
    if(speed < min) {
      min = speed;
    } else if(speed > max) {
      max = speed;
    }
  }

  return (max - min) / kNumHistogramBins;
}

void Simulation::AddParticle(const Particle &particle) {
  particles_.push_back(particle);
}

void Simulation::Clear() {
  particles_.clear();
}

const std::vector<Particle>& Simulation::GetParticles() const {
  return particles_;
}

const speed_histograms_t& Simulation::GetSpeedHistograms() const{
  return speed_histograms_;
}

} // namespace ideal_gas