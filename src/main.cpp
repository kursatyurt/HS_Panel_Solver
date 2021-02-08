#include <iostream>
#include <armadillo>
#include <vector>
#include <memory>
#include <cmath>
#include "point.hpp"
#include "panel.hpp"
#include "solver.hpp"
#include "InitFromFile.hpp"
int main(int argc, const char **argv)
{

  std::cout << "Welcome to Great HS Solver \n";
  std::unique_ptr<BaseInitializer> pInit = std::make_unique<InitFromFile>();
  std::vector<Point> Points;
  std::vector<Panel> Panels;

  pInit->init_points(Points);
  pInit->init_panels(Points, Panels);

  double AoA;
  std::cout << "Please Enter AoA in Degree:\n";
  std::cin >> AoA;
  // Convert Angle to Radians
  AoA = AoA * acos(0.0) / 90;

  std::unique_ptr<Solver> pSolver = std::make_unique<Solver>();
  pSolver->fill(Points, Panels, AoA);
  pSolver->solve();
  pSolver->calculate_cp(Panels);

  return 0;
}
