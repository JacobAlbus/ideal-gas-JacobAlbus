#include <gui/sketchpad.h>
#include <cinder/Rand.h>

namespace ideal_gas {

namespace visualizer {

using glm::vec2;

Sketchpad::Sketchpad() {}

void Sketchpad::Draw() const {
  for(const Particle& particle : particles_) {
    ci::gl::color(particle.GetColor());
    const auto kRadius = static_cast<float>(particle.GetRadius());
    ci::gl::drawSolidCircle(particle.GetPosition(), kRadius);
  }
}

void Sketchpad::HandleParticleBrush(const vec2& brush_screen_coords,
                                    const ci::Rectf& gas_window,
                                    ParticleType particle_type) {
  double x_coord = brush_screen_coords.x;
  double y_coord = brush_screen_coords.y;

  if(IsBrushInsideWindow(x_coord, y_coord, gas_window)) {
    glm::vec2 position(x_coord, y_coord);

    float x_velocity = ci::randFloat(-2, 2);
    float y_velocity = ci::randFloat(-2, 2);
    glm::vec2 velocity(x_velocity, y_velocity);

    Particle new_particle = Particle(velocity, position, particle_type);
    particles_.push_back(new_particle);
  }
}

bool Sketchpad::IsBrushInsideWindow(double x_coord, double y_coord,
                                    const ci::Rectf &gas_window) const {
  if(x_coord >= gas_window.getX1() && x_coord <= gas_window.getX2()) {
    if(y_coord >= gas_window.getY1() && y_coord <= gas_window.getY2()) {
      return true;
    }
  }

  return false;
}

void Sketchpad::Clear() {
  particles_.clear();
}

std::vector<Particle>& Sketchpad::GetParticles() {
  return particles_;
}

}  // namespace visualizer

}  // namespace ideal_gas
