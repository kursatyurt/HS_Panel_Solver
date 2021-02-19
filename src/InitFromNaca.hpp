#ifndef INIT_NACA_H
#define INIT_NACA_H
#include <armadillo>
#include <cmath>

#include "BaseInitializer.hpp"

class InitFromNaca : public BaseInitializer
{
public:
  void initPoints(std::vector<Point>&) override;
  void nacasym4(std::vector<Point>&,const arma::vec&,int,int);
};

#endif