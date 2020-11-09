#include <gui/simulation_ui.h>
#include <cinder/Rand.h>

namespace ideal_gas {

namespace visualizer {

//TODO fix magic
//TODO why can't I instantiate with kNumHistBins
SimulationUI::SimulationUI() : kNumHistogramBins(8), simulation_(8),
                               kRedHistogramWindow(kWindowSize / 1.38f,
                                                   kWindowSize / 3.97f,
                                                   kWindowSize / 1.38f,
                                                   kWindowSize / 3.97f),
                               kBlueHistogramWindow(kWindowSize / 1.38f,
                                                    kWindowSize / 1.78f,
                                                    kWindowSize / 1.38f,
                                                    kWindowSize / 1.78f),
                               kGreenHistogramWindow(kWindowSize / 1.38f,
                                                     kWindowSize / 1.13f,
                                                     kWindowSize / 1.38f,
                                                     kWindowSize / 1.13f) {}

void SimulationUI::UpdateSimulation(const ci::Rectf& gas_window) {
  simulation_.UpdateParticles(gas_window);
  simulation_.UpdateSpeedHistograms();
}

void SimulationUI::RenderDynamicObjects() const {
  const std::vector<Particle>& particles = simulation_.GetParticles();

  for(const Particle& particle : particles) {
    ci::gl::color(particle.GetColor());
    const auto kRadius = static_cast<float>(particle.GetRadius());
    ci::gl::drawSolidCircle(particle.GetPosition(), kRadius);
  }

  const speed_histograms_t& speed_histograms = simulation_.GetSpeedHistograms();

  ci::gl::color(1, 0, 0);
  RenderHistograms(kRedHistogramWindow, speed_histograms.at(ParticleType::kRed));

  ci::gl::color(0, 0, 1);
  RenderHistograms(kBlueHistogramWindow, speed_histograms.at(ParticleType::kBlue));

  ci::gl::color(0, 1, 0);
  RenderHistograms(kGreenHistogramWindow, speed_histograms.at(ParticleType::kGreen));
}

void SimulationUI::HandleParticleBrush(const glm::vec2& brush_screen_coords,
                                       const ci::Rectf& gas_window,
                                       ParticleType particle_type) {
  float x_coord = brush_screen_coords.x;
  float y_coord = brush_screen_coords.y;

  if(IsBrushInsideWindow(x_coord, y_coord, gas_window)) {
    glm::vec2 position(x_coord, y_coord);

    float x_velocity = ci::randFloat(-2, 2);
    float y_velocity = ci::randFloat(-2, 2);
    glm::vec2 velocity(x_velocity, y_velocity);

    Particle new_particle = Particle(velocity, position, particle_type);
    simulation_.AddParticle(new_particle);
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
    //TODO fix magic
    auto bin_height = static_cast<float>(bin_counts[index] * 2);
    float bin_spacing = 8.0f + static_cast<float>(index * 18);

    ci::gl::drawSolidRect(ci::Rectf(hist_window.getX1() - 8.0f + static_cast<float>(index * 18),
                                    hist_window.getY1() - bin_height,
                                    hist_window.getX2() + bin_spacing,
                                    hist_window.getY2()));
  }
}

void SimulationUI::ClearSimulation() {
  simulation_.Clear();
}

const std::vector<Particle> & SimulationUI::GetSimulationParticles() {
  return simulation_.GetParticles();
}

}  // namespace visualizer

}  // namespace ideal_gas
