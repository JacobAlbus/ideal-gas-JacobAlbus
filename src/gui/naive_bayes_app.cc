#include <gui/naive_bayes_app.h>

namespace ideal_gas {

namespace visualizer {

NaiveBayesApp::NaiveBayesApp()
    : sketchpad_(glm::vec2(kMargin, kMargin), kImageDimension,
                 kWindowSize - 2 * kMargin) {
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
}

void NaiveBayesApp::update() {
  std::vector<Particle>& particles = sketchpad_.GetParticles();
  for(auto& particle : particles) {
    particle.UpdatePosition();
  }
}

void NaiveBayesApp::draw() {
  ci::Color8u background_color(255, 255 , 255);
  ci::gl::clear(background_color);

  sketchpad_.Draw();

  ci::gl::drawStringCentered(
      message_,
      glm::vec2(kWindowSize / 2, kMargin / 2), ci::Color("black"));
}

void NaiveBayesApp::mouseDown(ci::app::MouseEvent event) {
  sketchpad_.HandleBrush(event.getPos(), message_);
}

void NaiveBayesApp::mouseDrag(ci::app::MouseEvent event) {
  sketchpad_.HandleBrush(event.getPos(), message_);
}

void NaiveBayesApp::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_DELETE: {
      sketchpad_.Clear();
      break;
    }
    case ci::app::KeyEvent::KEY_ESCAPE: {
      exit(0);
    }
  }
}

}  // namespace visualizer

}  // namespace ideal_gas
