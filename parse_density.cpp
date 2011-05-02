#include "shexp.hpp"
using namespace std;


double parse_density (const string& str) throw (ShExpException)
{
  size_t pos;
  double dens_val;
  string buf;

  try
    {
      pos = get_token (str, buf, 0);
      if (buf!="density")
	throw ShExpException ("Error: incorrect density definition.\n");
      pos = get_token (str, buf, pos);
      if (buf.find_first_not_of("0123456789.Ee-+")<buf.size())
	throw ShExpException ("Error: incorrect density definition.\n");
    }
  catch (exception& e)
    {
      throw;
    }
  stringstream bufstr (buf);
  bufstr.exceptions (ios_base::badbit | ios_base::failbit);
  try
    {
      bufstr >> dens_val;
    }
  catch (ios_base::failure)
    {
      throw ShExpException ("Error: incorrect density definition.\n");
    }
  return dens_val;
}
