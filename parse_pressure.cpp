#include "shexp.hpp"
using namespace std;


double parse_pressure (const string& str) throw (ShExpException)
{
  size_t pos;
  double press_val;
  string buf;

  try
    {
      pos = get_token (str, buf, 0);
      if (buf!="pressure")
	throw ShExpException ("Error: incorrect pressure definition.\n");
      pos = get_token (str, buf, pos);
      if (buf.find_first_not_of("0123456789.Ee-+")<buf.size())
	throw ShExpException ("Error: incorrect pressure definition.\n");
    }
  catch (exception& e)
    {
      throw;
    }
  stringstream bufstr (buf);
  bufstr.exceptions (ios_base::badbit | ios_base::failbit);
  try
    {
      bufstr >> press_val;
    }
  catch (ios_base::failure)
    {
      throw ShExpException ("Error: incorrect pressure definition.\n");
    }
  return press_val;
}
