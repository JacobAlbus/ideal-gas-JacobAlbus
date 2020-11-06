#include <gui/simulation_ui.h>
#include <cinder/Rand.h>

namespace ideal_gas {

namespace visualizer {

using glm::vec2;

SimulationUI::SimulationUI() {
  simulation_ = Simulation();
}

void SimulationUI::Draw(const Simulation& simulation) const {
  const particle_map& particles = simulation.GetParticles();
  //TODO change name
  for(const auto& map_pair : particles){
    for(const Particle& particle : particles.at(map_pair.first)) {
      ci::gl::color(particle.GetColor());
      const auto kRadius = static_cast<float>(particle.GetRadius());
      ci::gl::drawSolidCircle(particle.GetPosition(), kRadius);
    }
  }
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

}  // namespace visualizer

}  // namespace ideal_gas
