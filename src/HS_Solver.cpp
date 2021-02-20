#include <armadillo>
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

#include <exception>

#include "InitFromFile.hpp"
#include "InitFromNaca.hpp"
#include "Panel.hpp"
#include "Point.hpp"
#include "Solver.hpp"
#include "DataWriters.hpp"
int main(int argc, const char **argv) {
  std::cout << "Welcome to Great HS Solver \n";
  std::unique_ptr<BaseInitializer> pInit; 
  
  std::cout << "Enter Selection Airfoil: 1) From File 2) From NACA Digits" << std::endl;
  int selection;
  std::cin >> selection;
  switch (selection){
    case 1:
      pInit = std::make_unique<InitFromFile>();
      break;
    default:
      pInit = std::make_unique<InitFromNaca>();
      break;
  }



  std::vector<Point> Points;
  std::vector<Panel> Panels;

  pInit->initPoints(Points);
  pInit->initPanels(Points, Panels);
  std::vector<double> cp(Panels.size(), 0.);

  double AoA;
  std::cout << "Please Enter AoA in Degree:\n";
  std::cin >> AoA;
  // Convert Angle to Radians
  AoA = AoA * acos(0.0) / 90;

  std::unique_ptr<Solver> pSolver = std::make_unique<Solver>();
  pSolver->fill(Points, Panels, AoA);
  pSolver->solve();
  pSolver->calculateCp(Panels, cp);

  DataWriters* dw;
  dw->cpWriter(cp,Panels);

  return 0;
}
