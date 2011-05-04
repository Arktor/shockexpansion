#include "shexp.hpp"
using namespace std;


int main (int argc, char *argv[])
{
  vector<ShExpPanel> airfoil (1);
  ifstream inp_str (argv[1]);
  ofstream out_str ("./out.dat");
  double q0;
  double cx = 0.0;
  double area_all = 0.0;

  cout  << scientific << setprecision (6);
  out_str << scientific << setprecision (6);

  if (!inp_str)
    {
      cout << "Error: couldn't open problem definition file.\n";
      return 1;
    }
  if (!out_str)
    {
      cout << "Error: couldn't create output file.\n";
      return 1;
    }
    
  cout << "----------------------------------------\n";
  cout << "----------------------------------------\n";
  cout << "Parsing problem definition...\n";
  cout << "----------------------------------------\n";
  out_str << "----------------------------------------\n";
  out_str << "----------------------------------------\n";
  out_str << "Parsing problem definition...\n";
  out_str << "----------------------------------------\n";

  try
    {
      parse_problem_def (inp_str, airfoil[0]);
      cout << "Mach number: " << setw(15) << airfoil[0].mach() << endl;
      cout << "Pressure:    " << setw(15) << airfoil[0].p() << " [Pa]\n";
      cout << "Density:     " << setw(15) << airfoil[0].ro() << " [kg*m^-3]\n";
      cout << "----------------------------------------\n";
      out_str << "Mach number: " << setw(15) <<	airfoil[0].mach() << endl;
      out_str << "Pressure:    " << setw(15) << airfoil[0].p() << " [Pa]\n";
      out_str << "Density:     " << setw(15) << airfoil[0].ro() << " [kg*m^-3]\n";
      out_str << "----------------------------------------\n";
      q0 = 0.5*airfoil[0].ro()*airfoil[0].vel()*airfoil[0].vel();
      parse_geometry (inp_str, airfoil);

        cout << "Parsed successfully.\n";
	cout << "Nodes:  " << airfoil.size() << endl;
	cout << "Panels: " << airfoil.size()-1 << endl;
	cout << "----------------------------------------\n";
	out_str << "Nodes:  " << airfoil.size() << endl;
	out_str << "Panels: "<< airfoil.size()-1 << endl;
	out_str << "----------------------------------------\n";

      for (unsigned i=1; i<airfoil.size(); i++)
	parser_out (airfoil[i], out_str);

      cout << "\nSOLVING\n";
      cout << "----------------------------------------\n";
      cout << "----------------------------------------\n";
      out_str << "----------------------------------------\n";
      out_str << "\nSOLVING\n";
      out_str << "----------------------------------------\n";
      out_str << "----------------------------------------\n";

      for (unsigned int i=1; i<airfoil.size(); i++)
	{
	  area_all+=airfoil[i].ar();
	  cout << "\nPanel: " << i << endl;
	  cout << "----------------------------------------\n";
	  if (fabs(airfoil[i].slp()-airfoil[i-1].slp())<0.00000001)
	    airfoil[i] = airfoil[i-1];
	  else if (airfoil[i].slp()<airfoil[i-1].slp())
	    solve_expansion (airfoil[i-1], airfoil[i], 1.4);
	  else
	    solve_shock (airfoil[i-1], airfoil[i], 1.4);
	  airfoil[i].set_cp ((airfoil[i].p()-airfoil[0].p())/q0);
	  solver_out (airfoil[i], out_str);
	}
    }
  catch (exception &e)
    {
      cout << e.what();
      cout << "Terminating...\n";
      terminate ();
    }
  cout << "\nSolving complete.\n\n";
  cout << "----------------------------------------\n";
  cout << "----------------------------------------\n";
  cout << "\nRESULTS.\n";
  cout << "----------------------------------------\n";
  out_str << "\nSolving complete.\n\n";
  out_str << "----------------------------------------\n";
  out_str << "----------------------------------------\n";
  out_str << "\nRESULTS.\n";
  out_str << "----------------------------------------\n";

  for (unsigned int i=1; i<airfoil.size(); i++)
    cx+=2*airfoil[i].p()*airfoil[i].ar()*sin(airfoil[i].slp(RAD))/q0;
    
  cout << "Cx=" << cx << endl;
  out_str << "Cx=" << cx << endl;
  inp_str.close ();
  out_str.close ();
  return 0;
}
