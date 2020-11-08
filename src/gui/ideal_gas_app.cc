#include <gui/ideal_gas_app.h>

namespace ideal_gas {

namespace visualizer {

IdealGasApp::IdealGasApp() : simulation_(),
                             simulation_ui_(),
                             particle_type_(ParticleType::kRed),
                             particle_count_message_("Particle Count: 0"),
                             particle_type_message_("Brush Particle Type: Red"),
                             gas_window_(ci::Rectf(kWindowSize / 4 - kGasWindowWidth,
                                                   kWindowSize / 2 - kGasWindowHeight,
                                                   kWindowSize / 4 + kGasWindowWidth,
                                                   kWindowSize / 2 + kGasWindowHeight)) {
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
}

void IdealGasApp::update() {
  simulation_.ManageParticles(gas_window_);
  simulation_.UpdateSpeedHistograms();
}

void IdealGasApp::draw() {
  ci::Color8u background_color(0, 0, 0);
  ci::gl::clear(background_color);

  simulation_ui_.Draw(simulation_);

  ci::gl::drawStringCentered(
      particle_count_message_,
      glm::vec2(kWindowSize / 2, kMargin / 2), ci::Color("white"));
  ci::gl::drawStringCentered(
      particle_type_message_,
      glm::vec2(kWindowSize / 2, kMargin/ 0.75), ci::Color("white"));

  ci::gl::color(255, 255, 255);
  ci::gl::drawStrokedRect(gas_window_);

  ci::gl::color(1, 0, 0);
  //TODO magic numbers
  ci::gl::drawStrokedRect(ci::Rectf(kWindowSize / 1.25f - kHistogramWindowSize,
                                    kWindowSize / 6.0f - kHistogramWindowSize,
                                    kWindowSize / 1.25f + kHistogramWindowSize,
                                    kWindowSize / 6.0f + kHistogramWindowSize));

  ci::gl::color(0, 0, 1);
  ci::gl::drawStrokedRect(ci::Rectf(kWindowSize / 1.25f - kHistogramWindowSize,
                                    kWindowSize / 2.1f - kHistogramWindowSize,
                                    kWindowSize / 1.25f + kHistogramWindowSize,
                                    kWindowSize / 2.1f + kHistogramWindowSize));

  ci::gl::color(0, 1, 0);
  ci::gl::drawStrokedRect(ci::Rectf(kWindowSize / 1.25f - kHistogramWindowSize,
                                    kWindowSize / 1.25f - kHistogramWindowSize,
                                    kWindowSize / 1.25f + kHistogramWindowSize,
                                    kWindowSize / 1.25f + kHistogramWindowSize));
}

void IdealGasApp::mouseDown(ci::app::MouseEvent event) {
  size_t particle_count = simulation_.GetParticles().size();
  particle_count_message_ = "Particle Count: " + std::to_string(particle_count);

  simulation_ui_.HandleParticleBrush(event.getPos(), gas_window_,
                                     particle_type_, simulation_);
}

void IdealGasApp::mouseDrag(ci::app::MouseEvent event) {
  mouseDown(event);
}

void IdealGasApp::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_DELETE: {
      simulation_.Clear();
      particle_count_message_ = "Particle Count: 0";
      break;
    }
    case ci::app::KeyEvent::KEY_ESCAPE: {
      exit(0);
      break;
    }
    case ci::app::KeyEvent::KEY_SPACE: {
      SwitchParticleType();
    }
  }
}

void IdealGasApp::SwitchParticleType() {
  //TODO make it not so "hard-coded"
  switch(particle_type_){
    case ParticleType::kRed:
      particle_type_ = ParticleType::kBlue;
      particle_type_message_ = "Brush Particle Type: Blue";
      break;
    case ParticleType::kBlue:
      particle_type_ = ParticleType::kGreen;
      particle_type_message_ = "Brush Particle Type: Green";
      break;
    case ParticleType::kGreen:
      particle_type_ = ParticleType::kRed;
      particle_type_message_ = "Brush Particle Type: Red";
      break;
  }
}

size_t IdealGasApp::CountParticles() {
  return simulation_.GetParticles().size();
}

}  // namespace visualizer

}  // namespace ideal_gas
