#include "shexp.hpp"
using namespace std;


void parse_geometry (ifstream& inp, vector<ShExpPanel>& airfoil)\
  throw (ShExpException)
{
  string buf, val_buf;
  stringstream valstr (val_buf);
  size_t npans = 0;
  ShExpNode node1 (-1.0, 0.0), node2;
  ShExpPanel pan (0.0, 0.0, 1.0, 0.0);

  try
    {
      buf = pass_empty_strings (inp);
      if (buf!="#geometry#")
	throw ShExpException ("Error: incorrect geometry definition.\n");
      buf = pass_empty_strings (inp);
      node2 = parse_geometry_point (buf);

      if (node2.x()!=0.0 || node2.y()!=0.0)
	throw ShExpException ("Error: incorrect first node placement.\n");

      npans++;
      airfoil.resize (npans);
      pan.set_nodes (node1, node2);
      airfoil[npans-1] = pan;

      while (!inp.eof())
	{
	  node1 = node2;
	  buf = pass_empty_strings (inp);
	  node2 = parse_geometry_point (buf);
	  npans++;
	  airfoil.resize (npans);
	  airfoil[npans-1] = ShExpPanel (node1, node2);
	}
    }
  catch (exception& e)
    {
      throw;
    }
  if (airfoil[airfoil.size()-1].x2()!=1.0 || airfoil[airfoil.size()-1].y2()!=0.0)
    throw ShExpException ("Error: incorrect last node placement.\n");
}