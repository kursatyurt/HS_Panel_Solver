#include "Solver.hpp"

#include <iomanip>

void Solver::fill(const std::vector<Point> &Points,
                  const std::vector<Panel> &Panels, const double &AoA)
{
  this->A =
      arma::mat((Panels.size() + 1), (Panels.size() + 1), arma::fill::zeros);
  this->RHS = arma::vec(Panels.size() + 1, arma::fill::zeros);
  this->Solution = arma::vec(Panels.size() + 1, arma::fill::zeros);
  this->Sinf = arma::mat((Panels.size()), (Panels.size()), arma::fill::zeros);
  this->Ginf = arma::mat((Panels.size()), (Panels.size()), arma::fill::zeros);

  constexpr double pi2inv = 1. / (4 * acos(0.0));
  this->sinaoa = sin(AoA);
  this->cosaoa = cos(AoA);

  auto last = Panels.size();
  for (auto panel1 : Panels)
  {
    auto i = panel1.panel_num;
    for (auto panel2 : Panels)
    {
      auto j = panel2.panel_num;
      if (i == j)
      {
        this->Sinf(i, j) = 0.5;
        this->A(i, j) = 0.5;
      }
      else
      {
        auto dxj = panel1.xm - Points[j].x;
        auto dxjp = panel1.xm - Points[j + 1].x;
        auto dyj = panel1.ym - Points[j].y;
        auto dyjp = panel1.ym - Points[j + 1].y;
        auto bij = atan2(dyjp * dxj - dxjp * dyj, dxjp * dxj + dyjp * dyj);
        auto lnij =
            0.5 * log((dxjp * dxjp + dyjp * dyjp) / (dxj * dxj + dyj * dyj));
        auto cosij =
            panel1.costhe * panel2.costhe + panel1.sinthe * panel2.sinthe;
        auto sinij =
            panel1.sinthe * panel2.costhe - panel1.costhe * panel2.sinthe;

        this->A(i, j) = pi2inv * (sinij * lnij + cosij * bij);
        this->Sinf(i, j) = pi2inv * (sinij * lnij + cosij * bij);
        this->Ginf(i, j) = pi2inv * (-sinij * bij + cosij * lnij);
        this->A(i, last) += pi2inv * (cosij * lnij - sinij * bij);
        this->A(last, i) += pi2inv * (sinij * bij - cosij * lnij);
        this->A(last, last) += (pi2inv * (sinij * lnij + cosij * bij));
      }
    }
    this->RHS(i) = panel1.sinthe * this->cosaoa - panel1.costhe * this->sinaoa;
  }
  this->RHS(last) = -(Panels.front().costhe * this->cosaoa +
                      Panels.front().sinthe * this->sinaoa) -
                    (Panels.back().costhe * this->cosaoa +
                     Panels.back().sinthe * this->sinaoa);
}

void Solver::solve() { this->Solution = arma::solve(this->A, this->RHS); }

void Solver::calculateCp(const std::vector<Panel> &Panels,
                         std::vector<double> &cp)
{
  auto last = Panels.size();
  for (auto panel1 : Panels)
  {
    auto i = panel1.panel_num;
    auto Vtan = panel1.costhe * this->cosaoa + panel1.costhe * this->sinaoa;
    for (auto panel2 : Panels)
    {
      auto j = panel2.panel_num;
      Vtan = Vtan - this->Solution(j) * Ginf(i, j) +
             this->Solution(last) * Sinf(i, j);
    }
    cp[i] = 1.0 - Vtan * Vtan;
  }
}
