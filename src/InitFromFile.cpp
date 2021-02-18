#include "InitFromFile.hpp"

void InitFromFile::init_points(std::vector<Point> &Points) {
  std::cout << "Please Enter Input Filename: \n";
  std::string file;
  std::cin >> file;
  std::fstream input_file(file, std::ios::in);
  if (!input_file.is_open()) {
    throw std::runtime_error("Input File Cannot Found");
  }
  int num_points;
  input_file >> num_points;
  Points.resize(num_points);
  double x = 0, y = 0;
  for (int i = 0; i < num_points; i++) {
    input_file >> x >> y;
    Points[i].set_values(x, y);
  }

  input_file.close();
};
