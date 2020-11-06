#pragma once
#include "cinder/gl/gl.h"
#include "engine/simulation.h"

namespace ideal_gas {

namespace visualizer {

class SimulationUI {
 public:
  SimulationUI();

  /**
   * Displays the current state of the sketchpad in the Cinder application.
   */
  void Draw(const Simulation& simulation) const;

  /**
   * Creates Particle Objects at passed in window coords
   * @param coordinates where particle is to be created
   * @param window where particles are allowed to be created
   * @param type of particle to be created
   */
  void HandleParticleBrush(const glm::vec2& brush_screen_coords,
                           const ci::Rectf& gas_window,
                           ParticleType particle_type,
                           Simulation& simulation);

 private:
  /**
   * Checks to see if Brush Coords are within the window
   * @param x coordinate of brush
   * @param y coordinate of brush
   * @param dimensions of window to be within
   * @return true or false depending on if the brush is within the coords
   */
  bool IsBrushInsideWindow(double x_coord, double y_coord,
                           const ci::Rectf& gas_window) const;

  Simulation simulation_;
};

}  // namespace visualizer

}  // namespace ideal_gas
