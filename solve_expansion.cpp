#include "shexp.hpp"


double exp_equation (double pan_slp, double mach1, double mach2,	\
		     double k)
{
  const double cpl1 = sqrt ((k+1)/(k-1));
  return asin(1/mach2) - asin(1/mach1) + pan_slp +	\
    cpl1*(atan(cpl1/sqrt(mach1*mach1-1)) - atan(cpl1/sqrt(mach2*mach2-1)));
}


void solve_expansion (const ShExpPanel& pan_left, ShExpPanel& pan_right,	\
		      double k) throw (ShExpException)
{
  double mach1 = pan_left.mach ();
  double p1 = pan_left.p ();
  double ro1 = pan_left.ro ();
  double slp = pan_right.slp (RAD) - pan_left.slp (RAD);
  double mach_prev = mach1, mach_cur, mach_new;
  double res_prev, res_new;
  int niter = 0;
  const double eps = 0.000001;

  if ((1 + 0.5*(k-1)*mach1*slp)<=0.0)
    throw ShExpException ("Error: too large angle. Vacuum at the panel.\n");

  std:: cout << "\n-------------------------------------\n";
  std:: cout << "*************************************\n";
  std:: cout << "-------------------------------------\n";
  std:: cout << "Solving expansion wave equation:\n";
  std:: cout << "-------------------------------------\n";
  std:: cout << "Mach number: " << mach1 << "\nRelative slope (rad): "	\
	     << slp << "\n" << "Convergence criterion: Res=" << eps << "\n";
  std:: cout << "-------------------------------------\n";
  std:: cout << "Convergence history:\n";
  std:: cout << "-------------------------------------\n";

  mach_cur = mach1/(1 + 0.5*(k-1)*mach1*slp);
  mach_new = mach_cur - exp_equation(slp, mach1, mach_cur, k)*	\
	(mach_cur-mach_prev)/(exp_equation(slp, mach1, mach_cur, k)-	\
			    exp_equation(slp, mach1, mach_prev, k));
  res_new = fabs(exp_equation(slp, mach1, mach_new, k));

  std:: cout << "Iteration#" << niter << ": " << "Res=" << res_new << "\n";

  while (res_new>eps)
    {
      mach_prev = mach_cur;
      mach_cur = mach_new;
      mach_new = mach_cur - exp_equation(slp, mach1, mach_cur, k)*	\
	(mach_cur-mach_prev)/(exp_equation(slp, mach1, mach_cur, k)-	\
			    exp_equation(slp, mach1, mach_prev, k));
      res_prev = res_new;
      res_new = fabs(exp_equation(slp, mach1, mach_new, k));
      niter++;
      std:: cout << "Iteration#" << niter << ": " << "Res=" << res_new << "\n";

      if (res_new>=res_prev)
	throw ShExpException ("Error: couldn't solve shock equation.\n");
    }
  std:: cout << "-------------------------------------\n";
  std:: cout << "Convergence criterion reached.\n";
  std:: cout << "-------------------------------------\n";
  std:: cout << "Results:\n";
  std:: cout << "-------------------------------------\n";

  pan_right.set_mach (mach_new);
  pan_right.set_wave_slp (pan_right.slp() + asin(1.0/mach_new));
  pan_right.set_p (p1*pow((1+0.5*(k-1)*mach1*mach1)/			\
			  (1+0.5*(k-1)*mach_new*mach_new), k/(k-1)));
  pan_right.set_ro (ro1*pow((1+0.5*(k-1)*mach1*mach1)/			\
			  (1+0.5*(k-1)*mach_new*mach_new), 1.0/(k-1)));
  pan_right.set_a (sqrt(k*pan_right.p()/pan_right.ro()));
  pan_right.set_vel (pan_right.mach()*pan_right.a());
  pan_right.set_u (pan_right.vel()*cos(pan_right.slp(RAD)));
  pan_right.set_v (pan_right.vel()*sin(pan_right.slp(RAD)));

  std:: cout << "Shock wave slope (rad): " << pan_right.wave_slp(RAD) << "\n";
  std:: cout << "Velocity: " << pan_right.vel() << " [m*s^-1]\n";
  std:: cout << "Mach number: " << pan_right.mach() << "\n";
  std:: cout << "Pressure: " << pan_right.p() << " [Pa]\n";
  std:: cout << "-------------------------------------\n";
  std:: cout << "*************************************\n";
  std:: cout << "-------------------------------------\n";
}
