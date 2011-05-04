#include "shexp.hpp"
using namespace std;


void solver_out (const ShExpPanel& pan, ofstream& out) throw (ShExpException)
{
  if (!out)
    throw ShExpException ("Error: bad stream for results output.\n");

  out.exceptions (ios_base:: badbit | ios_base:: failbit);
  out << scientific << setprecision (6);
  
  try
    {
      out << "\nPanel: " << pan.id() << endl;
      out << "----------------------------------------\n";
      out << "Mach number:          " << setw(15) << pan.mach() << endl;
      out << "pressure:             " << setw(15) << pan.p() << " [Pa]\n";
      out << "pressure coefficient: " << setw(15) << pan.cp() << endl;
      out << "density:              " << setw(15) << pan.ro() << " [kg*m^-3]\n";
      out << "velocity:             " << setw(15) << pan.vel() << " [m*s^-2]\n";
      out << "velocity u:           " << setw(15) << pan.u() << " [m*s^-2]\n";
      out << "velocity v:           " << setw(15) << pan.v() << " [m*s^-2]\n";
      out << "local speed of sound: " << setw(15) << pan.a() << " [m*s^-2]\n";
      out << "----------------------------------------\n";
    }
  catch (ios_base:: failure)
    {
      throw;
    }
}
