#include "shexp.hpp"
using namespace std;


string pass_empty_strings (ifstream& inp) throw (ShExpException)
{
  string buf (" \n");

  if (!inp)
    throw ShExpException ("Error: problem definition file is corrupted.\n");

  while (buf.find_first_not_of(" \n\r\t\0")>=buf.size() && !inp.eof())
    getline (inp, buf);
  
  return buf;
}
