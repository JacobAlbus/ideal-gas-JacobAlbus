#pragma once
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "sketchpad.h"
#include "engine/particle.h"

namespace ideal_gas {

namespace visualizer {

/**
 * Allows a user to visualize particle collisions in an ideal system
 */
class NaiveBayesApp : public ci::app::App {
 public:
  NaiveBayesApp();

  //TODO documentations?
  void draw() override;
  void update() override;
  void mouseDown(ci::app::MouseEvent event) override;
  void mouseDrag(ci::app::MouseEvent event) override;
  void keyDown(ci::app::KeyEvent event) override;

  const double kWindowSize = 875;
  const double kMargin = 20;

 private:
  ParticleType particle_type_;
  ci::Rectf gas_window_;
  std::string message_;
  Sketchpad sketchpad_;
};

}  // namespace visualizer

}  // namespace ideal_gas
