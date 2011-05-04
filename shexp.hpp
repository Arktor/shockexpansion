#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "shexpexception.hpp"
#include "shexpnode.hpp"
#include "shexppanel.hpp"


// Parser functions

size_t get_token (const std::string& src, std::string& res,		\
		  size_t pos) throw (ShExpException);
std::string pass_empty_strings (std::ifstream& inp) throw (ShExpException);
double parse_mach_number (const std::string& str) throw (ShExpException);
double parse_density (const std::string& str) throw (ShExpException);
double parse_pressure (const std::string& str) throw (ShExpException);
ShExpNode parse_geometry_point (const std::string& str) throw (ShExpException);
void parse_problem_def (std::ifstream& inp, ShExpPanel& flow_pan)
  throw (ShExpException);
void parse_geometry (std::ifstream& inp, std::vector<ShExpPanel>& airfoil) \
  throw (ShExpException);


// Solver functions

double shock_equation (double pan_slp, double wave_slp, double mach,	\
		       double k);
double exp_equation (double pan_slp, double mach1, double mach2,	\
		     double k);
void solve_shock (ShExpPanel& pan_left, ShExpPanel& pan_right,	\
		  double k) throw (ShExpException);
void solve_expansion (const ShExpPanel& pan_left, ShExpPanel& pan_right,	\
		      double k) throw (ShExpException);

// Output functions

void parser_out (const ShExpPanel& pan, std::ofstream& out)	\
  throw (ShExpException);
void solver_out (const ShExpPanel& pan, std::ofstream& out)	\
  throw (ShExpException);
