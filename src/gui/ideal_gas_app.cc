#include <gui/ideal_gas_app.h>

namespace ideal_gas {

namespace visualizer {

IdealGasApp::IdealGasApp() : simulation_ui_(),
                             particle_type_(ParticleType::kRed),
                             gas_window_(ci::Rectf(kWindowSize / 4 - kGasWindowWidth,
                                                   kWindowSize / 2 - kGasWindowHeight,
                                                   kWindowSize / 4 + kGasWindowWidth,
                                                   kWindowSize / 2 + kGasWindowHeight)) {
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
  simulation_ = Simulation();
}

//TODO create a simulation class to handle particle interactions and store particles
void IdealGasApp::update() {
  simulation_.ManageParticles(gas_window_);
}

void IdealGasApp::draw() {
  ci::Color8u background_color(0, 0, 0);
  ci::gl::clear(background_color);

  simulation_ui_.Draw(simulation_);

  ci::gl::drawStringCentered(
      message_,
      glm::vec2(kWindowSize / 2, kMargin / 2), ci::Color("white"));

  ci::gl::color(255, 255, 255);
  ci::gl::drawStrokedRect(gas_window_);
}

void IdealGasApp::mouseDown(ci::app::MouseEvent event) {
  //TODO fix size count
  size_t particle_count = simulation_.GetParticles().size();
  message_ = "Particle Count: " + std::to_string(particle_count);

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
      //TODO fix size count
      size_t particle_count = simulation_.GetParticles().size();
      message_ = "Particle Count: " + std::to_string(particle_count);
      break;
    }
    case ci::app::KeyEvent::KEY_ESCAPE: {
      exit(0);
      break;
    }
    //TODO make it not so "hard-coded"
    case ci::app::KeyEvent::KEY_SPACE: {
      switch(particle_type_){
        case ParticleType::kRed:
          particle_type_ = ParticleType::kBlue;
          break;
        case ParticleType::kBlue:
          particle_type_ = ParticleType::kGreen;
          break;
        case ParticleType::kGreen:
          particle_type_ = ParticleType::kRed;
          break;
      }
    }
  }
}

}  // namespace visualizer

}  // namespace ideal_gas
