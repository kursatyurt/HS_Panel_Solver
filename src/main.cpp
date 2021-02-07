#include <iostream>
#include <armadillo>
#include <vector>
#include <memory>
#include "point.hpp"
#include "panel.hpp"
#include "InitFromFile.hpp"
int main(int argc, const char **argv) {
 
std::cout << "Welcome to Great HS Solver \n";
std::unique_ptr<BaseInitializer> pInit = std::make_unique<InitFromFile>();
std::vector<Point> Points;
std::vector<Panel> Panels; 
int x;


pInit->init_points(x,Points);
pInit->init_panels(Points,Panels);


return 0;
}

