#include "BaseInitializer.hpp"

void BaseInitializer::init_panels(const std::vector<Point> &Points,
                                  std::vector<Panel> &Panels) {
  Panels.resize(Points.size() - 1);
  for (auto i = 0; i < Panels.size(); i++) {
    Panels[i] = Panel(i, Points);
  }
};
