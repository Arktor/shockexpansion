#include "shexp.hpp"
using namespace std;


string pass_empty_strings (ifstream& inp) throw (ShExpException)
{
  string buf;

  while (buf.find_first_not_of(" \n\r\t\0")>=buf.size() && !inp.eof())
    {
      if ((!inp || inp.bad() || inp.fail()) && !inp.eof())
	throw ShExpException ("Error: problem definition file is corrupted.\n");
      getline (inp, buf);
    }
  return buf;
}
