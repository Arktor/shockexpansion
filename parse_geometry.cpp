#include "shexp.hpp"
using namespace std;


void parse_geometry (ifstream& inp, vector<ShExpPanel>& airfoil)\
  throw (ShExpException)
{
  string buf, val_buf;
  stringstream valstr (val_buf);
  size_t npans = 1;
  int nnodes = 1;
  ShExpNode node1 (-1.0, 0.0), node2;
  ShExpPanel pan (0.0, 0.0, 1.0, 0.0);

  cout << "----------------------------------------\n";
  cout << "Parsing airfoil geometry...\n";
  cout << "----------------------------------------\n";

  try
    {
      buf = pass_empty_strings (inp);

      if (buf!="#geometry#")
	throw ShExpException ("Error: incorrect geometry definition.\n");
      
      buf = pass_empty_strings (inp);
      node2 = parse_geometry_point (buf);

      if (node2.x()!=0.0 || node2.y()!=0.0)
	throw ShExpException ("Error: incorrect first node placement.\n");

      airfoil[npans-1].set_nodes (node1, node2);
      
      while (!inp.bad() && !inp.fail() && !inp.eof())
	{
	  getline (inp, buf);
	  if (!check_empty_string(buf))
	    {
	      node1 = node2;
	      node2 = parse_geometry_point (buf);
	      npans++;
	      nnodes++;
	      airfoil.resize (npans);
	      airfoil[npans-1] = ShExpPanel (node1, node2);
	      airfoil[npans-1].set_id (npans-1);
	      cout << buf << endl;
	      cout << airfoil[npans-1].x1() << ";" << airfoil[npans-1].y1() << "  ";
	      cout << airfoil[npans-1].x2() << ";" << airfoil[npans-1].y2() << endl;
	    }
	}
      cout << airfoil.size() << endl;
      cout << airfoil[airfoil.size()-1].y2() << endl;
      if (airfoil[airfoil.size()-1].x2()!=1.0 ||\
	  airfoil[airfoil.size()-1].y2()!=0.0)
	throw ShExpException ("Error: incorrect last node placement.\n");
    }
  catch (exception& e)
    {
      throw;
    }
}
