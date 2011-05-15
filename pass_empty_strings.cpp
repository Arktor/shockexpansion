#include "shexp.hpp"
using namespace std;


string pass_empty_strings (ifstream& inp) throw (ShExpException)
{
  string buf (" \n");

  if (!inp)
    throw ShExpException ("Error: problem definition file is corrupted.\n");

  do
    {
      getline (inp, buf);
      if (inp.bad() || inp.fail() || inp.eof())
	throw ShExpException					\
	  ("Error: unexpected end of problem definition file.\n");
    }
  while (check_empty_string(buf));
  
  return buf;
}
