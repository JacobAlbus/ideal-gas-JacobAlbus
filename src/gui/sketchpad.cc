#include <gui/sketchpad.h>

namespace ideal_gas {

namespace visualizer {

using glm::vec2;

Sketchpad::Sketchpad(const vec2& top_left_corner)
    : top_left_corner_(top_left_corner) {}

void Sketchpad::Draw() const {
  for(const Particle& particle : particles_) {
    ci::gl::color(particle.GetColor());
    const auto kRadius = static_cast<float>(particle.GetRadius());
    ci::gl::drawSolidCircle(particle.GetPosition(), kRadius);
  }
}

void Sketchpad::HandleBrush(const vec2& brush_screen_coords, ci::Rectf gas_box,
                            std::string& message, ParticleType particle_type) {
  double x_coord = brush_screen_coords.x;
  double y_coord = brush_screen_coords.y;

  message = std::to_string(particles_.size());

  if(x_coord >= (gas_box.getX1() + 5) && x_coord <= (gas_box.getX2() - 5)) {
    if(y_coord >= (gas_box.getY1() + 5) && y_coord <= (gas_box.getY2() - 5)) {
      glm::vec2 position(x_coord, y_coord);

      double x_velocity = (double)rand()/RAND_MAX*2.0-1.0;
      double y_velocity = (double)rand()/RAND_MAX*2.0-1.0;
      glm::vec2 velocity(x_velocity, y_velocity);

      Particle new_particle = Particle(velocity, position, particle_type);
      particles_.push_back(new_particle);
    }
  }
}

void Sketchpad::Clear() {
  particles_.clear();
}

std::vector<Particle>& Sketchpad::GetParticles() {
  return particles_;
}

}  // namespace visualizer

}  // namespace ideal_gas
