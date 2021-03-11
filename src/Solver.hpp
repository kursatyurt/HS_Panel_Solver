#ifndef SOLVER_H
#define SOLVER_H
#include <cmath>
#include <armadillo>
#include "Panel.hpp"
#include "Point.hpp"

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
    std::vector<double> cp;
    void fill(const std::vector<Point> &Points, const std::vector<Panel> &Panels, const double &AoA);
    void solve();
    void calculateCp(const std::vector<Panel> &Panels, std::vector<double> &cp);
};

#endif