#include "gui/naive_bayes_app.h"

using ideal_gas::visualizer::NaiveBayesApp;

void prepareSettings(NaiveBayesApp::Settings* settings) {
  //TODO change for testing
  srand((unsigned int)time(NULL));
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(NaiveBayesApp, ci::app::RendererGl, prepareSettings);

