#include <gui/sketchpad.h>

namespace ideal_gas {

namespace visualizer {

using glm::vec2;

Sketchpad::Sketchpad(const vec2& top_left_corner, size_t num_pixels_per_side,
                     double sketchpad_size, double brush_radius)
    : top_left_corner_(top_left_corner),
      num_pixels_per_side_(num_pixels_per_side),
      pixel_side_length_(sketchpad_size / num_pixels_per_side),
      brush_radius_(brush_radius) {}

void Sketchpad::Draw() const {
  for(const Particle& particle : particles_) {
    ci::gl::color(0, 0 , 0);
    const auto kRadius = static_cast<float>(particle.GetRadius());
    ci::gl::drawSolidCircle(particle.GetPosition(), kRadius);
  }
}

void Sketchpad::HandleBrush(const vec2& brush_screen_coords, std::string& message) {
  double x_coord = brush_screen_coords.x;
  double y_coord = brush_screen_coords.y;
  glm::vec2 position(x_coord, y_coord);

  double x_velocity = (double)rand()/RAND_MAX*2.0-1.0;
  double y_velocity = (double)rand()/RAND_MAX*2.0-1.0;
  glm::vec2 velocity(x_velocity, y_velocity);

  message = "position: (" + std::to_string(x_coord) + ", " + std::to_string(y_coord) + ")  " +
      "velocity: (" + std::to_string(x_velocity) + ", " + std::to_string(y_velocity) + ") " + std::to_string(particles_.size());

  Particle new_particle = Particle(velocity, position, ParticleType::kRed);
  particles_.push_back(new_particle);
}

void Sketchpad::Clear() {
  particles_.clear();
}

std::vector<Particle>& Sketchpad::GetParticles() {
  return particles_;
}

}  // namespace visualizer

}  // namespace ideal_gas
