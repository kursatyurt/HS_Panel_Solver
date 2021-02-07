#ifndef SOLVER_H
#define SOLVER_H
#include <cmath>
#include <armadillo>
#include "panel.hpp"
#include "point.hpp"

class Solver
{
    arma::mat A;
    arma::vec RHS;
    arma::vec Solution;

public:
    void fill(const std::vector<Point> &Points, const std::vector<Panel> &Panels, const double &AoA);
    void solve();
};

#endif