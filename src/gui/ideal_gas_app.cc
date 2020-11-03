#include <gui/ideal_gas_app.h>

namespace ideal_gas {

namespace visualizer {

NaiveBayesApp::NaiveBayesApp() : sketchpad_(),
                                 particle_type_(ParticleType::kRed),
                                 gas_window_(ci::Rectf(kWindowSize / 4 - 200.0f,
                                                       kWindowSize / 2 - 300.0f,
                                                       kWindowSize / 4 + 200.0f,
                                                       kWindowSize / 2 + 300.0f)) {

  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
}

void NaiveBayesApp::update() {
  std::vector<Particle>& particles = sketchpad_.GetParticles();
  //TODO get better names
  for(auto& particle1 : particles) {
    particle1.UpdatePosition(gas_window_);
    for(auto& particle2 : particles) {
      particle1.UpdateVelocity(particle2);
    }
  }
}

void NaiveBayesApp::draw() {
  ci::Color8u background_color(0, 0, 0);
  ci::gl::clear(background_color);

  sketchpad_.Draw();

  ci::gl::drawStringCentered(
      message_,
      glm::vec2(kWindowSize / 2, kMargin / 2), ci::Color("white"));

  ci::gl::color(255, 255, 255);
  ci::gl::drawStrokedRect(gas_window_);
}

void NaiveBayesApp::mouseDown(ci::app::MouseEvent event) {
  size_t particle_count = sketchpad_.GetParticles().size();
  message_ = "Particle Count: " + std::to_string(particle_count);

  sketchpad_.HandleParticleBrush(event.getPos(), gas_window_, particle_type_);
}

void NaiveBayesApp::mouseDrag(ci::app::MouseEvent event) {
  size_t particle_count = sketchpad_.GetParticles().size();
  message_ = "Particle Count: " + std::to_string(particle_count);

  sketchpad_.HandleParticleBrush(event.getPos(), gas_window_, particle_type_);
}

void NaiveBayesApp::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_DELETE: {
      sketchpad_.Clear();
      size_t particle_count = sketchpad_.GetParticles().size();
      message_ = "Particle Count: " + std::to_string(particle_count);
      break;
    }
    case ci::app::KeyEvent::KEY_ESCAPE: {
      exit(0);
      break;
    }
    case ci::app::KeyEvent::KEY_SPACE: {
      if(particle_type_ == ParticleType::kBlue){
        particle_type_ = ParticleType::kRed;
      } else {
        particle_type_ = ParticleType::kBlue;
      }
    }
  }
}

}  // namespace visualizer

}  // namespace ideal_gas
