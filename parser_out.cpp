#include "shexp.hpp"
using namespace std;


void parser_out (const ShExpPanel& pan, ofstream& out) throw (ShExpException)
{
  if (!out)
    throw ShExpException ("Error: bad stream for results output.\n");

  out.exceptions (ios_base:: badbit | ios_base:: failbit);
  out << scientific << setprecision (6);
  
  try
    {
      out << "\nPanel: " << pan.id() << endl;
      out << "----------------------------------------\n";
      out << "Node 1:       (" << pan.x1() << ":" << pan.y1() << ")\n";
      out << "Node 2:       (" << pan.x2() << ":" << pan.y2() << ")\n";
      out << "Slope:         " << setw(15) << pan.slp(RAD) << " [rad]\n";
      out << "Relative area: " << setw(15) << pan.ar() << endl;
      out << "----------------------------------------\n";
    }
  catch (ios_base:: failure)
    {
      throw;
    }
}
