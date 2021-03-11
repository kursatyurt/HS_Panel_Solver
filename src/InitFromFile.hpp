#ifndef INIT_FILE_H
#define INIT_FILE_H

#include "BaseInitializer.hpp"
#include <fstream>
#include <string>

class InitFromFile : public BaseInitializer
{
public:
  void initPoints(std::vector<Point> &Points) override;
};

#endif
