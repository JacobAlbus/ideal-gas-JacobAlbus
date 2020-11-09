#pragma once
#include "cinder/gl/gl.h"
#include "engine/simulation.h"

namespace ideal_gas {

namespace visualizer {

class SimulationUI {
 public:
  SimulationUI();

  /**
   * Updates Particle Positions and Velocities and Updates Speed Histograms
   * @param rect object representing the bounds of the particle window/box
   */
  void UpdateSimulation(const ci::Rectf& gas_window);

  /**
   * Renders Particles and Histograms
   */
  void RenderDynamicObjects() const;

  /**
   * Creates Particle Objects at passed in window coords
   * @param coordinates where particle is to be created
   * @param window where particles are allowed to be created
   * @param type of particle to be created
   */
  void HandleParticleBrush(const glm::vec2& brush_screen_coords,
                           const ci::Rectf& gas_window,
                           ParticleType particle_type);

  /**
   * Clears Simulation Object of all particles
   */
  void ClearSimulation();

  const std::vector<Particle>& GetSimulationParticles();

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

  /**
   * Renders speed histograms inside of their respective windows
   * @param hist_window
   * @param bin_counts
   */
  void RenderHistograms(const ci::Rectf& hist_window, const std::vector<size_t>& bin_counts) const;

  Simulation simulation_;

  const float kWindowSize = 875;
  const size_t kNumHistogramBins;

  const ci::Rectf kRedHistogramWindow;
  const ci::Rectf kBlueHistogramWindow;
  const ci::Rectf kGreenHistogramWindow;
};

}  // namespace visualizer

}  // namespace ideal_gas
