#include "../shexp.hpp"
using namespace std;


int main ()
{
  string str ("density = 1.225");
  double val;

  val = parse_density (str);
  cout << scientific << setprecision(3) << val;

  return 0;
}
  
