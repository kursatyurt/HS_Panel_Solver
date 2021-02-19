#ifndef POINT_H
#define POINT_H

class Point
{
public:
    double x, y;
    Point();
    Point(double a, double b);
    void changeDelta(double dx, double dy);
    void setValues(double xn, double yn);
};

#endif
