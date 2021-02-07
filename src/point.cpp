#include "point.hpp"

Point::Point () : x(0.0), y(0.0) {}
Point::Point (double a, double b) 
{
   set_values(a,b);
}

void Point::change_delta(double dx, double dy)
{
    this->x += dx;
    this->y += dy;
}

void Point::set_values(double xn, double yn)
{
    this->x = xn;
    this->y = yn;
}

