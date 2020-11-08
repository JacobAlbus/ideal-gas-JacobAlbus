#include <gui/ideal_gas_app.h>

namespace ideal_gas {

namespace visualizer {

IdealGasApp::IdealGasApp() : simulation_(),
                             simulation_ui_(),
                             particle_type_(ParticleType::kRed),
                             particle_count_(0),
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
  particle_count_ = CountParticles();
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

  ci::gl::color(255, 255, 255);
  ci::gl::drawStrokedRect(ci::Rectf(kWindowSize / (3.0f/4.0f) - kGasWindowWidth,
                                    kWindowSize / 6 - kGasWindowHeight,
                                    kWindowSize / (3.0f/4.0f) + kGasWindowWidth,
                                    kWindowSize / 6 + kGasWindowHeight));

  ci::gl::color(255, 255, 255);
  ci::gl::drawStrokedRect(ci::Rectf(kWindowSize / (3.0f/4.0f) - kGasWindowWidth,
                                    kWindowSize / 2 - kGasWindowHeight,
                                    kWindowSize / (3.0f/4.0f) + kGasWindowWidth,
                                    kWindowSize / 2 + kGasWindowHeight));

  ci::gl::color(255, 255, 255);
  ci::gl::drawStrokedRect(ci::Rectf(kWindowSize / (3.0f/4.0f) - kGasWindowWidth,
                                    kWindowSize / 2 - kGasWindowHeight,
                                    kWindowSize / (3.0f/4.0f) + kGasWindowWidth,
                                    kWindowSize / 2 + kGasWindowHeight));
}

void IdealGasApp::mouseDown(ci::app::MouseEvent event) {
  particle_count_message_ = "Particle Count: " + std::to_string(particle_count_);

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
      particle_count_message_ = "Particle Count: " + std::to_string(particle_count_);
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

void IdealGasApp::SwitchParticleType(){
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
  size_t particle_count = 0;
  const particle_map& particles = simulation_.GetParticles();

  for(const auto& map_pair : particles){
    particle_count += particles.at(map_pair.first).size();
  }

  return particle_count;
}

}  // namespace visualizer

}  // namespace ideal_gas
