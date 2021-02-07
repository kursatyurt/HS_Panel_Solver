#ifndef BASE_INIT_H
#define BASE_INIT
#include <iostream>
#include <exception>
#include <vector>
#include "point.hpp"
#include "panel.hpp"
class BaseInitializer{
public:
 virtual void init_points(int &num_points,std::vector<Point> &Points) = 0;
 virtual void init_panels(std::vector<Point> &Points,std::vector<Panel> &Panels) = 0;
};


#endif 