#ifndef SOLVER_H
#define SOLVER_H
#include <cmath>
#include <armadillo>
#include "panel.hpp"
#include "point.hpp"

class Solver
{
    arma::mat A;
    arma::mat Sinf;
    arma::mat Ginf;
    arma::vec RHS;
    arma::vec Solution;
    double cosaoa;
    double sinaoa;

public:
    arma::vec cp; 
    void fill(const std::vector<Point> &Points, const std::vector<Panel> &Panels, const double &AoA);
    void solve();
    void calculate_cp(const std::vector<Panel> &Panels);
};

#endif