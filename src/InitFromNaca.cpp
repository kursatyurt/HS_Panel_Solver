#include "InitFromNaca.hpp"



void InitFromNaca::initPoints(std::vector<Point> &Points)
{
  int NACA, num_panel;
  std::cout << "NACA Airfoil (4-5 Digit), Number of Panels: \n";
  std::cin >> NACA >> num_panel;

  if (NACA > 99999 || NACA < 1)
    ;
  {
    std::runtime_error("Invalid Airfoil Selection!.");
  }

  // Decompose it
  int a = NACA / 10000;
  int b = (NACA / 1000) % 10;
  int c = (NACA / 100) % 10;
  int d = (NACA / 10) % 10;
  int e = NACA % 10;

  if (a == 0 && b == 0 && c == 0) // 4-DIGIT SYMMETRIC AIRFOIL
  {
    nacasym4(Points, num_panel, d, e);
  }
  else // 4- DIGIT NON SYMMETRIC AIRFOIL
  {
    nacaun4(Points, num_panel, b, c, d, e);
  }
  //  else  // 5 - DIGIT AIRFOIL
  //  {naca5(Point,dist,a,b,c,d,e)}
};



void InitFromNaca::nacaun4(std::vector<Point> &Points, const int num_panel, const int b, const int c, const int d, const int e)
{

  double m = 0.01 * static_cast<double>(b);
  double p = 0.1 * static_cast<double>(c);
  double t = 0.1 * static_cast<double>(d) + 0.01 * static_cast<double>(e);

  int lower_panel = num_panel / 2;
  int upper_panel = num_panel - lower_panel;

  Points.resize(num_panel + 1);

  auto dist = arma::linspace(2. * acos(0.0), 0, lower_panel + 1);
  dist = 0.5 * (1. - cos(dist));

  int i = 0;
  double xp, yp;
  double yt, theta;

  for (double x : dist)
  {
    yt = calc_y_t(x, t);
    theta = calcTheta(m, p, x);
    xp = x + yt * sin(theta);
    yp = calc_y_c(m, p, x) - yt * cos(theta);
    Points[i].setValues(xp, yp);
    i++;
  }

  dist = arma::linspace(dist[lower_panel - 3], 2. * acos(0.0), upper_panel);
  dist = 0.5 * (1. - cos(dist));

  for (double x : dist)
  {
    yt = calc_y_t(x, t);
    theta = calcTheta(m, p, x);
    xp = x - yt * sin(theta);
    yp = calc_y_c(m, p, x) + yt * cos(theta);
    Points[i].setValues(xp, yp);
    i++;
  }
}

void InitFromNaca::nacasym4(std::vector<Point> &Points, const int num_panel, int d, int e)
{
  double t = 0.1 * static_cast<double>(d) + 0.01 * static_cast<double>(e);

  int lower_panel = num_panel / 2;
  int upper_panel = num_panel - lower_panel;

  Points.resize(num_panel + 1);

  auto dist = arma::linspace(2. * acos(0.0), 0, lower_panel + 1);
  dist = 0.5 * (1. - cos(dist));

  int i = 0;
  for (double x : dist)
  {
    Points[i].setValues(x, -calc_y_t(x, t));
    i++;
  }

  dist = arma::linspace(dist[lower_panel - 3], 2. * acos(0.0), upper_panel);
  dist = 0.5 * (1. - cos(dist));

  for (double x : dist)
  {
    Points[i].setValues(x, calc_y_t(x, t));
    i++;
  }
}

double calc_y_t(double x, const double t)
{
  const double a0 = 0.2969, a1 = -.126, a2 = -0.3516, a3 = 0.2843, a4 = -0.1036;
  double y_t = 5. * t * (a0 * std::sqrt(x) + a1 * x + a2 * x * x + a3 * x * x * x + a4 * x * x * x * x);
  return y_t;
}

double calcTheta(double m, double p, double x)
{
  double theta;
  if (x <= p)
  {
    theta = atan(2. * m / (p * p) * (p - x));
  }
  else
  {
    theta = atan(2. * m / ((1. - p) * (1. - p)) * (p - x));
  }
  return theta;
};

double calc_y_c(double m, double p, double x)
{
  double yc;
  if (x <= p)
  {
    yc = m / (p * p) * (2. * p * x - x * x);
  }
  else
  {
    yc = m / ((1. - p) * (1. - p)) * ((1. - 2. * p) + 2. * p * x - x * x);
  }
  return yc;
};