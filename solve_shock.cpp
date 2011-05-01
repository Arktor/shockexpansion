#include "shexp.hpp"


using namespace std;


double shock_equation (double pan_slp, double wave_slp, double mach,	\
		       double k)
{
  double cpl1 = 2.0*(sin(wave_slp)*sin(wave_slp) - 1/mach/mach)/(k+1);
  return tan(pan_slp) - cpl1/(tan(wave_slp)*(1-cpl1));
}


void solve_shock (const ShExpPanel& pan_left, ShExpPanel& pan_right,	\
		  double k) throw (ShExpException)
{
  double mach1 = pan_left.mach ();
  double vel1 = pan_left.vel ();
  double p1 = pan_left.p ();
  double ro1 = pan_left.ro ();
  double slp = pan_right.slp (RAD) - pan_left.slp (RAD);
  double cpl1;
  double slp_prev = slp, slp_cur, slp_new;
  double res_prev, res_new;
  int niter = 0;
  const double eps = 0.000001;
  
  cout << "------------------------------\n";
  cout << "------------------------------\n";
  cout << "Solving shock wave equation:\n";
  cout << "------------------------------\n";
  cout << "Mach number: " << scientific << setprecision (5) << mach1 << endl;
  cout << "Relative slope: " << slp << " [rad]" << endl;
  cout << "Convergence criterion: Res = " << eps << endl;
  cout << "------------------------------\n";
  cout << "Convergence history:\n";
  cout << "------------------------------\n";
  
  slp_cur = 0.25*slp*(k+1) + sqrt(pow(0.25*slp*(k+1), 2)+1/mach1/mach1);
  slp_new = slp_cur - shock_equation(slp, slp_cur, mach1, k)*\
    (slp_cur-slp_prev)/(shock_equation(slp, slp_cur, mach1, k)-		\
			shock_equation(slp, slp_prev, mach1, k));
  res_new = fabs(shock_equation(slp, slp_new, mach1, k));

  cout << "Iteration#" << niter << ": " << "Res = " << res_new << endl;

  while (res_new>eps)
    {
      slp_prev = slp_cur;
      slp_cur = slp_new;
      slp_new = slp_cur - shock_equation(slp, slp_cur, mach1, k)*	\
	(slp_cur-slp_prev)/(shock_equation(slp, slp_cur, mach1, k)-	\
			    shock_equation(slp, slp_prev, mach1, k));
      res_prev = res_new;
      res_new = fabs(shock_equation(slp, slp_new, mach1, k));
      niter++;
      cout << "Iteration#" << niter << ": " << "Res = " << res_new << endl;

      if (res_new>=res_prev)
	throw ShExpException ("Error: couldn't solve shock equation.\n");
    }
  cout << "------------------------------\n";
  cout << "Convergence criterion reached.\n";
  cout << "------------------------------\n";
  cout << "Results:\n";
  cout << "------------------------------\n";

  cpl1 = 2.0*(sin(slp_new)*sin(slp_new) - 1/mach1/mach1)/(k+1);
  pan_right.set_wave_slp (slp_new + pan_left.slp());
  pan_right.set_u (pan_left.u() - vel1*cpl1);
  pan_right.set_v (pan_left.v() + vel1*cpl1/tan(slp_new));
  pan_right.set_vel (sqrt(pan_right.u()*pan_right.u() +		\
			  pan_right.v()*pan_right.v()));
  pan_right.set_ro (ro1*(k+1)/(k-1)/(1+2/(k-1)/(mach1*mach1*sin(slp_new)* \
						sin(slp_new)))); 
  pan_right.set_p (p1+ro1*vel1*vel1*cpl1);
  pan_right.set_a (sqrt(k*pan_right.p()/pan_right.ro()));
  pan_right.set_mach (pan_right.vel()/pan_right.a());
  pan_right.set_u (pan_right.vel()*cos(pan_right.slp(RAD)));
  pan_right.set_v (pan_right.vel()*sin(pan_right.slp(RAD)));

  cout << "Shock wave slope: " << pan_right.wave_slp(RAD) << " [rad]\n";
  cout << "Velocity: " << pan_right.vel() << " [m*s^-1]\n";
  cout << "Mach number: " << pan_right.mach() << "\n";
  cout << "Pressure: " << pan_right.p() << " [Pa]\n";
  cout << "------------------------------\n";
  cout << "------------------------------\n";
}
