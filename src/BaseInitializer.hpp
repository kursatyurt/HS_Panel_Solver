#ifndef BASE_INIT_H
#define BASE_INIT
#include <iostream>
#include <exception>
#include <vector>
#include "point.hpp"

class BaseInitializer{
public:
 virtual void init(int &num_points,std::vector<Point> &Points) = 0;
};


#endif 