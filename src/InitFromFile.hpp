#ifndef INIT_FILE_H
#define INIT_FILE_H

#include "BaseInitializer.hpp"

class InitFromFile : public BaseInitializer
{
  public:  
  void init(int &num_points,std::vector<Point> &Points);
};

#endif 