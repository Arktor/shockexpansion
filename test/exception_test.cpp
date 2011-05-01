#include <iostream>
#include "../shexpexception.hpp"


void bad_func ();


int main ()
{
  try
    {
      bad_func ();
    }
  catch (std:: exception& e)
    {
      std:: cout << e.what();
    }
  return 0;
}


void bad_func ()
{
  throw ShExpException ("Fail! Ho ho ho!.");
}
