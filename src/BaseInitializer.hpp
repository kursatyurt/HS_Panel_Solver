#ifndef BASE_INIT_H
#define BASE_INIT_H
#include <iostream>
#include <exception>
#include <vector>
#include "Point.hpp"
#include "Panel.hpp"
class BaseInitializer
{
public:
    virtual ~BaseInitializer () {};
    virtual void initPoints(std::vector<Point> &Points) = 0;
    void initPanels(const std::vector<Point> &Points, std::vector<Panel> &Panels);
};

#endif