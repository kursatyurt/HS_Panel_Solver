#include "InitFromNaca.hpp"

void InitFromNaca::initPoints(std::vector<Point> &Points){
  int NACA, num_panel;
  std::cout << "NACA Airfoil (4-5 Digit), Number of Panels: \n";
  std::cin >> NACA >> num_panel; 
  
  if (NACA > 99999 || NACA < 1);
  {std::runtime_error("Invalid Airfoil Selection!.");}
  
  // Create a cosine-distribution

  auto dist = arma::linspace(0,2.*acos(0.0),num_panel/2+1);
  dist = 0.5* (1. - cos(dist));  
  
  // Decompose it 
  int a = NACA/10000;
  int b = (NACA/1000)%10;
  int c = (NACA/100)%10;
  int d = (NACA/10)%10;
  int e = NACA%10;


  if (a == 0 && b == 0 && c ==0) // 4-DIGIT SYMMETRIC AIRFOIL
  {nacasym4(Points,dist,d,e);}
//  else if  // 4- DIGIT NON SYMMETRIC AIRFOIL 
//  {naca4(Points,dist,b,c,d,e)}
//  else  // 5 - DIGIT AIRFOIL
//  {naca5(Point,dist,a,b,c,d,e)}
 
};


double y_t_sym(double x,const double t) {
  const double a0=0.2969, a1=-.126, a2=0.3516, a3=0.2843, a4=0.1036;
  double y_t = 5.*t*(a0*std::sqrt(x)-a1*x-a2*x*x+a3*x*x*x-a4*x*x*x*x);
  return y_t;
}

void InitFromNaca::nacasym4(std::vector<Point> &Points,const arma::vec &dist,int d,int e){
  
  double t = d*10 + e;
  
  int i=0;
  for (auto x : dist)
  {
    Points.emplace_back(x,y_t_sym(x,t));
  }
}