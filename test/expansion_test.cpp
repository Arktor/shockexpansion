#include "../shexp.hpp"


int main ()
{
  ShExpPanel flow (-1.0, 1.0, 0.0, 1.0);
  ShExpPanel pan (0.0, 1.0, 1.0, 1.0-tan(10.0/57.2957795));
  const double k = 1.4;

  flow.set_mach (2.0);
  flow.set_p (100000.0);
  flow.set_ro (1.225);
  flow.set_a (sqrt(k*flow.p()/flow.ro()));
  flow.set_vel (flow.mach()*flow.a());
  std:: cout << pan.slp(DEG) << "\n";
  std:: cout << "V=" << flow.vel() << "\n";
  flow.set_u (flow.vel());
  flow.set_v (0.0);
  try
    {
      solve_expansion (flow, pan, k);
    }
  catch (std:: exception& e)
    {
      std:: cout << e.what() << "Terminating...";
      return 1;
    }
  std:: cout << "M=" << pan.mach() << "\n";
  return 0;
}
