#include "shexp.hpp"
#include <cstdlib>
using namespace std;


ShExpNode parse_geometry_point (const string& str) throw (ShExpException)
{
  size_t pos;
  string buf;
  double x_buf, y_buf;
  ShExpNode new_node (0.0, 0.0);

  try
    {
      pos = get_token (str, buf, 0);
      if (buf.find_first_not_of("0123456789.Ee-+")<buf.size())
	throw ShExpException ("Error: incorrect geometry definition.\n");
      x_buf = atof (buf.c_str());
      pos = get_token (str, buf, pos);
      if (buf.find_first_not_of("0123456789.Ee-+")<buf.size())
	throw ShExpException ("Error: incorrect geometry definition.\n");
      y_buf = atof (buf.c_str());
    }
  catch (exception& e)
    {
      throw;
    }
  new_node.set_x (x_buf);
  new_node.set_y (y_buf);
  return new_node;
}
