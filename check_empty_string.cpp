#include "shexp.hpp"
using namespace std;


bool check_empty_string (string& str) throw ()
{
  if (str.find_first_not_of(" \n\r\t\0")>=str.size())
    return true;
  else
    return false;
}
