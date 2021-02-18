#ifndef BASE_INIT_H
#define BASE_INIT_H
#include <iostream>
#include <exception>
#include <vector>
#include "point.hpp"
#include "panel.hpp"
class BaseInitializer
{
public:
    virtual ~BaseInitializer () {};
    virtual void init_points(std::vector<Point> &Points) = 0;
    void init_panels(const std::vector<Point> &Points, std::vector<Panel> &Panels);
};

#endif