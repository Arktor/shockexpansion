#include <iostream>
#include <iomanip>
#include <cmath>
#include "shexpexception.hpp"
#include "shexpnode.hpp"
#include "shexppanel.hpp"


double shock_equation (double pan_slp, double wave_slp, double mach,	\
		       double k);
void solve_shock (const ShExpPanel& pan_left, ShExpPanel& pan_right,	\
		  double k) throw (ShExpException);
double exp_equation (double pan_slp, double mach1, double mach2,	\
		     double k);
void solve_expansion (const ShExpPanel& pan_left, ShExpPanel& pan_right,	\
		      double k) throw (ShExpException);
