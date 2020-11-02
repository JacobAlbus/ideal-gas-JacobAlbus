#include <gui/ideal_gas_app.h>

namespace ideal_gas {

namespace visualizer {

NaiveBayesApp::NaiveBayesApp()
    : sketchpad_(glm::vec2(kMargin, kMargin)) {
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
  gas_box = ci::Rectf(getWindowWidth()/4-200.0f,
                      getWindowHeight()/2-300.0f,
                      getWindowWidth()/4+200.0f,
                      getWindowHeight()/2+300.0f);
  particle_type_ = ParticleType::kRed;
}

void NaiveBayesApp::update() {
  std::vector<Particle>& particles = sketchpad_.GetParticles();
  //TODO get better names
  for(auto& particle1 : particles) {
    particle1.UpdatePosition(gas_box);
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
  ci::gl::drawStrokedRect(gas_box);
}

void NaiveBayesApp::mouseDown(ci::app::MouseEvent event) {
  sketchpad_.HandleBrush(event.getPos(), gas_box, message_, particle_type_);
}

void NaiveBayesApp::mouseDrag(ci::app::MouseEvent event) {
  sketchpad_.HandleBrush(event.getPos(), gas_box, message_, particle_type_);
}

void NaiveBayesApp::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_DELETE: {
      sketchpad_.Clear();
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
