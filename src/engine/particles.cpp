#include "engine/particles.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

namespace ideal_gas {

Particles::Particles(size_t num_particles) {
  for(size_t index = 0; index < num_particles; index++) {
    double x_velocity = (double)rand()/RAND_MAX*2.0-1.0;
    double y_velocity = (double)rand()/RAND_MAX*2.0-1.0;
    glm::vec2 velocity(x_velocity, y_velocity);

    double x_position = (double)rand()/RAND_MAX*2.0-1.0;
    double y_position = (double)rand()/RAND_MAX*2.0-1.0;
    glm::vec2 position(x_position, y_position);

    Particle new_particle = Particle(velocity, position, ParticleType::kRed);
    particles_.push_back(new_particle);
  }
}

}