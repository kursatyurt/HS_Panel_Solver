#ifndef POINT_H
#define POINT_H

class Point
{
public:
    double x, y;
    Point();
    Point(double a, double b);
    void change_delta(double dx, double dy);
    void set_values(double xn, double yn);
};

#endif
