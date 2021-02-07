#ifndef INIT_FILE_H
#define INIT_FILE_H

#include "BaseInitializer.hpp"

class InitFromFile : public BaseInitializer
{
public:
  void init_points(std::vector<Point> &Points);
  void init_panels(const std::vector<Point> &Points, std::vector<Panel> &Panels);
};

#endif