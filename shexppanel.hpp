#ifndef SHEXPPANELHPP
#define SHEXPPANELHPP


#include "shexpexception.hpp"
#include "shexpnode.hpp"


enum AngleFormat {DEG, RAD};

///
/// Class representing a single panel in the numerical
/// interpretation of an airfoil. Position and orientation
/// of each panel is calculated basing on its boundary nodes
/// coordinates.
///

class ShExpPanel
{
  unsigned int id_number;
  ShExpNode node_left;
  ShExpNode node_right;
  double slope;
  double velocity;
  double velocity_u;
  double velocity_v;
  double speed_of_sound;
  double mach_number;
  double density;
  double pressure;
  double temperature;
  double pressure_coefficient;
  double wave_slope;
  double area;

 public:
  ShExpPanel () throw ();
  ShExpPanel (ShExpNode node1, ShExpNode node2) throw (ShExpException);
  ShExpPanel (double x1, double y1, double x2,	double y2)\
    throw (ShExpException);
  unsigned int id () const throw ();
  double x1 () const throw (); //< Returns x coordinate of the first (left) node.
  double x2 () const throw (); //< Returns x coordinate of the second (right) node.
  double y1 () const throw (); //< Returns y coordinate of the first (left) node.
  double y2 () const throw (); //< Returns y coordinate of the second (right) node.
  ShExpNode node1 () const throw (); //< Returns the left node.
  ShExpNode node2 () const throw (); //< Returns the right node.
  double slp (AngleFormat sf = RAD) const throw ();
  double ar () const throw ();
  double vel () const throw ();
  double u () const throw ();
  double v () const throw ();
  double a () const throw (); //< Returns speed of sound on the panel.
  double mach () const throw (); //< Returns Mach number of the flow on the panel.
  double ro () const throw (); //< Returns density on the panel.
  double p () const throw (); //< Returns pressure on the panel.
  double t () const throw (); //<Returns temperature on the panel.
  double cp () const throw (); //< Returns pressure coefficient on the panel.
  
  //< Returns a shock wave or expansion wave slope on the panel.

  double wave_slp (AngleFormat sf = RAD) const throw ();
  void set_nodes (ShExpNode new_node1, ShExpNode new_node2)	\
    throw (ShExpException);
  void set_nodes (double x1, double y1, double x2, double y2)\
    throw (ShExpException);
  ShExpPanel& set_id (unsigned int new_id) throw (ShExpException);
  ShExpPanel& set_vel (double new_vel) throw (ShExpException);
  ShExpPanel& set_u (double new_u) throw (ShExpException);
  ShExpPanel& set_v (double new_v) throw ();
  ShExpPanel& set_a (double new_a) throw (ShExpException);
  ShExpPanel& set_mach (double new_mach) throw (ShExpException);
  ShExpPanel& set_ro (double new_ro) throw (ShExpException);
  ShExpPanel& set_p (double new_p) throw (ShExpException);
  ShExpPanel& set_t (double new_t) throw (ShExpException);
  ShExpPanel& set_cp (double new_cp) throw ();
  ShExpPanel& set_wave_slp (double new_wave_slp) throw ();
};


inline unsigned int ShExpPanel:: id () const throw ()
{
  return id_number;
}


inline double ShExpPanel:: x1 () const throw ()
{
  return node_left.x();
}


inline double ShExpPanel:: x2 () const throw ()
{
  return node_right.x();
}


inline double ShExpPanel:: y1 () const throw ()
{
  return node_left.y();
}


inline double ShExpPanel:: y2 () const throw ()
{
  return node_right.y();
}


inline double ShExpPanel:: ar () const throw ()
{
  return area;
}


inline ShExpNode ShExpPanel:: node1 () const throw ()
{
  return node_left;
}


inline ShExpNode ShExpPanel:: node2 () const throw ()
{
  return node_right;
}


inline double ShExpPanel:: vel () const throw ()
{
  return velocity;
}


inline double ShExpPanel:: u () const throw ()
{
  return velocity_u;
}


inline double ShExpPanel:: v () const throw ()
{
  return velocity_v;
}


inline double ShExpPanel:: a () const throw ()
{
  return speed_of_sound;
}


inline double ShExpPanel:: mach () const throw ()
{
  return mach_number;
}


inline double ShExpPanel:: ro () const throw ()
{
  return density;
}


inline double ShExpPanel:: p () const throw ()
{
  return pressure;
}


inline double ShExpPanel:: t () const throw ()
{
  return temperature;
}


inline double ShExpPanel:: cp () const throw ()
{
  return pressure_coefficient;
}


#endif
