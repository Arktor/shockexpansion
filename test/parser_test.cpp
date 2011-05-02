#include "../shexp.hpp"
using namespace std;


int main ()
{
  ifstream inp ("airfoil.dat");
  ShExpPanel flow (-1.0, 0.0, 0.0, 0.0);
  vector<ShExpPanel> airfoil;

  parse_problem_def (inp, flow);
  airfoil.resize (1);
  airfoil[0] = flow;
  parse_geometry (inp, airfoil);

  for (unsigned int i=0; i<airfoil.size(); i++)
    {
      cout << scientific << setprecision(3) << airfoil[i].x1() << ' ' << \
	airfoil[i].y1() << ' ' << airfoil[i].x2() << ' ' << airfoil[i].y2() \
	   << endl;
    }

  return 0;
}
  
