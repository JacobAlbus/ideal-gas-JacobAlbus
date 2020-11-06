#pragma once
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "simulation_ui.h"
#include "engine/particle.h"

namespace ideal_gas {

namespace visualizer {

/**
 * Allows a user to visualize particle collisions in an ideal system
 */
class IdealGasApp : public ci::app::App {
 public:
  IdealGasApp();

  /**
   * Draws the particles and various UI elements
   */
  void draw() override;

  /**
   * Updates the positions and velocities of particles
   */
  void update() override;

  /**
   * Calls methods when mouse is clicked on screen
   * @param event object containing mouse coords
   */
  void mouseDown(ci::app::MouseEvent event) override;

  /**
   * Calls methods when mouse is dragged across screen
   * @param event object containing mouse coords
   */
  void mouseDrag(ci::app::MouseEvent event) override;

  /**
   * Calls methods depending on which key is pressed
   * @param event object containing pressed key
   */
  void keyDown(ci::app::KeyEvent event) override;

  const float kWindowSize = 875;
  const float kGasWindowWidth = 200;
  const float kGasWindowHeight = 300;
  const double kMargin = 20;

 private:
  //TODO is this too implementation specific?
  /**
   * Counts up all the particles that exist in simulation and  updates particle_count_
   * @return count of all particles in simulation
   */
  size_t CountParticles();

  /**
   * Rotates between particle types
   */
  void SwitchParticleType();

  size_t particle_count_;
  ParticleType particle_type_;
  ci::Rectf gas_window_;
  std::string particle_count_message_;
  std::string particle_type_message_;
  SimulationUI simulation_ui_;
  Simulation simulation_;
};

}  // namespace visualizer

}  // namespace ideal_gas
