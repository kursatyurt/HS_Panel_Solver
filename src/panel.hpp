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

#endif