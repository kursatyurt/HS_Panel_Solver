#ifndef PANEL_H
#define PANEL_H

#include <cmath>
#include <vector>
#include "point.hpp"

class Panel
{
public:
    int panel_num;
    double xm;
    double ym;
    double sinthe;
    double costhe;
    Panel(){};
    Panel(int i, const std::vector<Point> &point);
    void update(const std::vector<Point> &point);
};

#endi{
 
std::cout << "Welcome to Great HS Solver \n";
std::unique_ptr<BaseInitializer> pInit = std::make_unique<InitFromFile>();
std::vector<Point> Points;
std::vector<Panel> Panels; 

pInit->init_points(Points);
pInit->init_panels(Points,Panels);
 
double AoA; 
std::cout << "Please Enter AoA in Degree:\n" ;
std:: cin >> AoA; 
// Convert Angle to Radians
AoA = AoA * acos(0.0)/90 ;


std::unique_ptr<Solver> pSolver = std::make_unique<Solver>();
pSolver->fill(Points,Panels,AoA);
pSolver->solve();


return 0;
}
f