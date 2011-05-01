#ifndef SHEXPNODEHPP
#define SHEXPNODEHPP


///
/// Class representing a single node in the numerical interpretation
/// of an airfoil.
///

class ShExpNode
{
  double x_coordinate;
  double y_coordinate;

public:
  ShExpNode (double new_x = 0.0, double new_y = 0.0) throw ();
  double x () const throw ();
  double y () const throw ();
  ShExpNode& set_x (double new_x) throw ();
  ShExpNode& set_y (double new_y) throw ();
};


inline double ShExpNode:: x () const throw ()
{
  return x_coordinate;
}


inline double ShExpNode:: y () const throw ()
{
  return y_coordinate;
}


#endif
