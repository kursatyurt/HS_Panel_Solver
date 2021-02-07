#include <iostream>
#include <armadillo>
#include <vector>
#include <memory>
#include "point.hpp"
#include "InitFromFile.hpp"
int main(int argc, const char **argv) {
 
std::cout << "Welcome to Great HS Solver \n";
std::unique_ptr<BaseInitializer> pInit = std::make_unique<InitFromFile>();
std::vector<Point> Points;
int x;
bInit->init(x,Points);

return 0;
}

