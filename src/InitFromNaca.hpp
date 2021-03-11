#ifndef INIT_NACA_H
#define INIT_NACA_H
#include <armadillo>
#include <cmath>

#include "BaseInitializer.hpp"

class InitFromNaca : public BaseInitializer
{
public:
  void initPoints(std::vector<Point> &) override;
  void nacasym4(std::vector<Point> &, const int, const int, const int);
  void nacaun4(std::vector<Point> &, const int, const int, const int, const int, const int);
};

double calc_y_t(double, const double);
double calcTheta(double, double, double);
double calc_y_c(double, double, double);

#endif