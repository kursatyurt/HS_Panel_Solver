#include "solver.hpp"

void Solver::fill(const std::vector<Point> &Points, const std::vector<Panel> &Panels, const double &AoA)
{
  this->A = arma::mat((Panels.size() + 1), (Panels.size() + 1), arma::fill::zeros);
  this->RHS = arma::vec(Panels.size() + 1, arma::fill::zeros);
  this->Solution = arma::vec(Panels.size() + 1, arma::fill::zeros);
  const auto pi2inv = 1. / (4 * acos(0.0));

  for (auto panel1 : Panels)
  {
    auto i = panel1.panel_num;
    for (auto panel2 : Panels)
    {
      auto j = panel2.panel_num;
      if (i == j)
      {
        this->A(i, j) = 0.5;
      }
      else
      {
        auto dxj = panel1.xm - Points[j].x;
        auto dxjp = panel1.xm - Points[j + 1].x;
        auto dyj = panel1.ym - Points[j].y;
        auto dyjp = panel1.ym - Points[j + 1].y;
        auto bij = atan2(dyjp * dxj - dxjp * dyj, dxjp * dxj + dyjp * dyj);
        auto lnij = 0.5 * log((dxjp * dxjp + dyjp * dyjp) / (dxj * dxj + dyj * dyj));
        auto cosij = panel1.costhe * panel2.costhe + panel1.sinthe * panel2.sinthe;
        auto sinij = panel1.sinthe * panel2.costhe - panel1.costhe * panel2.sinthe;

        this->A(i, j) = pi2inv * (sinij * lnij + cosij * bij);
        this->A(i, Panels.size()) += pi2inv * (cosij * lnij - sinij * bij);
        this->A(Panels.size(), Panels.size()) += pi2inv * (sinij * lnij + cosij * bij);
        this->A(Panels.size(), j) += pi2inv * (sinij * bij - cosij * lnij);
      }
    }
    this->RHS(i) = sin(panel1.sinthe - AoA);
  }
}

void Solver::solve()
{

  this->Solution = arma::solve(this->A, this->RHS);
}