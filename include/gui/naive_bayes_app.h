#pragma once
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "sketchpad.h"
#include "engine/particle.h"

namespace ideal_gas {

namespace visualizer {

/**
 * Allows a user to draw a digit on a sketchpad and uses Naive Bayes to
 * classify it.
 */
class NaiveBayesApp : public ci::app::App {
 public:
  NaiveBayesApp();

  void draw() override;
  void mouseDown(ci::app::MouseEvent event) override;
  void mouseDrag(ci::app::MouseEvent event) override;
  void keyDown(ci::app::KeyEvent event) override;

  const double kWindowSize = 875;
  const double kMargin = 40;
  const size_t kImageDimension = 28;

 private:
  std::string message_ = "rando particle";
  std::vector<ideal_gas::Particle> particles_;
  Sketchpad sketchpad_;
  int current_prediction_ = -1;
};

}  // namespace visualizer

}  // namespace ideal_gas
