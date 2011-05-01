#include <cmath>
#include "shexppanel.hpp"


ShExpPanel:: ShExpPanel (ShExpNode node1, ShExpNode node2) \
  throw (ShExpException)
  : node_left (), node_right ()
{
  if (node1.x()>=node2.x() || node1.y()<0 || node2.y()<0)
    throw ShExpException ("Incorrect panel nodes coordinates.\n");

  node_left = node1;
  node_right = node2;
  slope = atan ((node_right.y()-node_left.y())/(node_right.x()-node_left.x()));
}


ShExpPanel:: ShExpPanel (double x1, double y1, double x2,  double y2)	\
  throw (ShExpException)
  : node_left (), node_right ()
{
  if (x1>=x2 || y1<0 || y2<0)
    throw ShExpException ("Incorrect panel nodes coordinates.\n");

  node_left.set_x (x1);
  node_left.set_y (y1);
  node_right.set_x (x2);
  node_right.set_y (y2);
  slope = atan ((node_right.y()-node_left.y())/(node_right.x()-node_left.x()));
}


double ShExpPanel:: slp (AngleFormat sf) const throw ()
{
  if (sf==RAD)
    return slope;
  else
    return slope*57.295779513;
}


double ShExpPanel:: wave_slp (AngleFormat sf) const throw ()
{
  if (sf==RAD)
    return wave_slope;
  else
    return wave_slope*57.295779513;
}


void ShExpPanel:: set_nodes (ShExpNode new_node1, ShExpNode new_node2) \
  throw (ShExpException)
{
  if (new_node1.x()>=new_node2.x() || new_node1.y()<0 || new_node2.y()<0)
    throw ShExpException ("Incorrect panel nodes coordinates.\n");
  
  node_left = new_node1;
  node_right = new_node2;
  slope = atan ((node_right.y()-node_left.y())/(node_right.x()-node_left.x()));
}


void ShExpPanel:: set_nodes (double x1, double y1, double x2, double y2)	\
  throw (ShExpException)
{
  if (x1>=x2 || y1<0 || y2<0)
    throw ShExpException ("Incorrect panel nodes coordinates.\n");
  
  node_left.set_x (x1);
  node_left.set_y (y1);
  node_right.set_x (x2);
  node_right.set_y (y2);
  slope = atan ((node_right.y()-node_left.y())/(node_right.x()-node_left.x()));
}


ShExpPanel& ShExpPanel:: set_vel (double new_vel) throw (ShExpException)
{
  if (new_vel<=0)
    throw ShExpException ("Error: not positive velocity value.\n");

  velocity = new_vel;
  return *this;
}


ShExpPanel& ShExpPanel:: set_u (double new_u) throw (ShExpException)
{
  if (new_u<0)
    throw ShExpException ("Error: negative velocity u value.\n");

  velocity_u = new_u;
  return *this;
}


ShExpPanel& ShExpPanel:: set_v (double new_v) throw ()
{
  velocity_v = new_v;
  return *this;
}


ShExpPanel& ShExpPanel:: set_a (double new_a) throw (ShExpException)
{
  if (new_a<=0)
    throw ShExpException ("Error: not positive speed of sound value.\n");

  speed_of_sound = new_a;
  return *this;
}


ShExpPanel& ShExpPanel:: set_mach (double new_mach) throw (ShExpException)
{
  if (new_mach<=1)
    throw ShExpException ("Error: subsonic flow.\n");

  mach_number = new_mach;
  return *this;
}


ShExpPanel& ShExpPanel:: set_ro (double new_ro) throw (ShExpException)
{
  if (new_ro<=0)
    throw ShExpException ("Error: negative density value.\n");

  density = new_ro;
  return *this;
}


ShExpPanel& ShExpPanel:: set_p (double new_p) throw (ShExpException)
{
  if (new_p<=0)
    throw ShExpException ("Error: negative pressure value.\n");

  pressure = new_p;
  return *this;
}


ShExpPanel& ShExpPanel:: set_cp (double new_cp) throw (ShExpException)
{
  if (new_cp<=0)
    throw ShExpException ("Error: negative pressure coefficient value.\n");

  pressure_coefficient = new_cp;
  return *this;
}


ShExpPanel& ShExpPanel:: set_wave_slp (double new_wave_slp) throw ()
{
  wave_slope = new_wave_slp;
  return *this;
}


ShExpPanel& ShExpPanel:: set_f_x (double new_f_x) throw ()
{
  force_x = new_f_x;
  return *this;
}


ShExpPanel& ShExpPanel:: set_f_y (double new_f_y) throw ()
{
  force_y = new_f_y;
  return *this;
}
