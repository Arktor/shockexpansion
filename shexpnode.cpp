#include "shexpnode.hpp"


ShExpNode:: ShExpNode (double new_x, double new_y) throw ()
{
  x_coordinate = new_x;
  y_coordinate = new_y;
}


ShExpNode& ShExpNode:: set_x (double new_x) throw ()
{
  x_coordinate = new_x;
  return *this;
}


ShExpNode& ShExpNode:: set_y (double new_y) throw ()
{
  y_coordinate = new_y;
  return *this;
}
