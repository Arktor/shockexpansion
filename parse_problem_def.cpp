#include "shexp.hpp"
using namespace std;


void parse_problem_def (ifstream& inp, ShExpPanel& flow_pan)
  throw (ShExpException)
{
  string buf;
  double mach_number;
  double pressure;
  double density;
  
  try
    {
      buf = pass_empty_strings (inp);
      mach_number = parse_mach_number (buf);
      buf = pass_empty_strings (inp);
      pressure = parse_pressure (buf);
      buf = pass_empty_strings (inp);
      density = parse_density (buf);
    }
  catch (exception& e)
    {
      throw;
    }
  flow_pan.set_mach (mach_number);
  flow_pan.set_p (pressure);
  flow_pan.set_ro (density);
  flow_pan.set_a (sqrt(1.4*pressure/density));
  flow_pan.set_u (flow_pan.a()*flow_pan.mach());
  flow_pan.set_v (0.0);
  flow_pan.set_vel (flow_pan.u());
  flow_pan.set_cp (0.0);
}
