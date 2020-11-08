#include <gui/simulation_ui.h>
#include <cinder/Rand.h>
#include "gui/ideal_gas_app.h"

namespace ideal_gas {

namespace visualizer {

using glm::vec2;

SimulationUI::SimulationUI() {}

void SimulationUI::Draw(const Simulation& simulation) const {
  const particle_map& particles = simulation.GetParticles();
  const velocity_map& particle_type_speeds = simulation.GetSpeeds();

  //TODO change name
  for(const auto& map_pair : particles){
    ParticleType particle_type = map_pair.first;
    for(const Particle& particle : particles.at(particle_type)) {
      ci::gl::color(particle.GetColor());
      const auto kRadius = static_cast<float>(particle.GetRadius());
      ci::gl::drawSolidCircle(particle.GetPosition(), kRadius);
    }

  }
  const float kWindowSize = 875;

  ci::Rectf red_hist_window(kWindowSize / 1.40f,
                             kWindowSize / 3.97f,
                             kWindowSize / 1.40f,
                             kWindowSize / 3.97f);
  ci::gl::color(1, 0, 0);
  RenderHistograms(red_hist_window, particle_type_speeds.at(ParticleType::kRed));

  ci::Rectf blue_hist_window(kWindowSize / 1.40f,
                              kWindowSize / 1.78f,
                              kWindowSize / 1.40f,
                              kWindowSize / 1.78f);
  ci::gl::color(0, 0, 1);
  RenderHistograms(blue_hist_window, particle_type_speeds.at(ParticleType::kBlue));

  ci::Rectf green_hist_window(kWindowSize / 1.40f,
                              kWindowSize / 1.13f,
                              kWindowSize / 1.40f,
                              kWindowSize / 1.13f);
  ci::gl::color(0, 1, 0);
  RenderHistograms(green_hist_window, particle_type_speeds.at(ParticleType::kGreen));
}

void SimulationUI::HandleParticleBrush(const vec2& brush_screen_coords,
                                       const ci::Rectf& gas_window,
                                       ParticleType particle_type,
                                       Simulation& simulation) {
  double x_coord = brush_screen_coords.x;
  double y_coord = brush_screen_coords.y;

  if(IsBrushInsideWindow(x_coord, y_coord, gas_window)) {
    glm::vec2 position(x_coord, y_coord);

    float x_velocity = ci::randFloat(-2, 2);
    float y_velocity = ci::randFloat(-2, 2);
    glm::vec2 velocity(x_velocity, y_velocity);

    Particle new_particle = Particle(velocity, position, particle_type);
    simulation.AddParticle(new_particle, particle_type);
  }
}

bool SimulationUI::IsBrushInsideWindow(double x_coord, double y_coord,
                                    const ci::Rectf &gas_window) const {
  return x_coord >= gas_window.getX1() &&
         x_coord <= gas_window.getX2() &&
         y_coord >= gas_window.getY1() &&
         y_coord <= gas_window.getY2();
}

void SimulationUI::RenderHistograms(const ci::Rectf& hist_window,
                                    const std::vector<size_t>& bin_counts) const {
  for(size_t index = 0; index < bin_counts.size(); index++) {
    size_t bin_count = bin_counts[index];
    ci::gl::drawSolidRect(ci::Rectf(hist_window.getX1() - 7.5f + static_cast<float>(index * 20),
                                    hist_window.getY1() - static_cast<float>(bin_count * 2),
                                    hist_window.getX2() + 7.5f + static_cast<float>(index * 20),
                                    hist_window.getY2()));
  }
}

}  // namespace visualizer

}  // namespace ideal_gas
