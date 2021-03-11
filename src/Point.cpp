#include "Point.hpp"

Point::Point() : x(0.0), y(0.0) {}
Point::Point(double a, double b) : x(a), y(b) {}

void Point::changeDelta(double dx, double dy)
{
    this->x += dx;
    this->y += dy;
}

void Point::setValues(double xn, double yn)
{
    this->x = xn;
    this->y = yn;
}
