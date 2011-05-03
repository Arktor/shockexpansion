#include "shexp.hpp"
using namespace std;


int main (int argc, char *argv[])
{
  vector<ShExpPanel> airfoil (1);
  ifstream inp_str (argv[1]);
  double q0;
  double cx = 0.0;
  double area_all = 0.0;

  if (!inp_str)
    {
      cout << "Error: couldn't open problem definition file.\n";
      return 1;
    }

  try
    {
      parse_problem_def (inp_str, airfoil[0]);
      q0 = 0.5*airfoil[0].ro()*airfoil[0].vel()*airfoil[0].vel();
      parse_geometry (inp_str, airfoil);

      for (unsigned int i=1; i<airfoil.size(); i++)
	{
	  area_all+=airfoil[i].ar();
	  if (fabs(airfoil[i].slp()-airfoil[i-1].slp())<0.00000001)
	    airfoil[i] = airfoil[i-1];
	  else if (airfoil[i].slp()<airfoil[i-1].slp())
	    solve_expansion (airfoil[i-1], airfoil[i], 1.4);
	  else
	    solve_shock (airfoil[i-1], airfoil[i], 1.4);
	  airfoil[i].set_cp ((airfoil[i].p()-airfoil[0].p())/q0);
	}
    }
  catch (exception &e)
    {
      cout << e.what();
      return 2;
    }
  
  for (unsigned int i=1; i<airfoil.size(); i++)
    cx+=2*airfoil[i].p()*airfoil[i].ar()*sin(airfoil[i].slp(RAD))/q0/area_all;
    
  cout << "Cx=" << cx << endl;
  return 0;
}
