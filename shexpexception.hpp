#ifndef SHEXPEXCEPTIONHPP
#define SHEXPEXCEPTIONHPP


#include <exception>
#include <string>


class ShExpException: public std:: exception
{
  std:: string message;

public:
  ShExpException (const char *error_message) throw ();
  ShExpException (const ShExpException& orig) throw ();
  virtual const char* what () const throw ();
  ShExpException& operator= (const ShExpException& right) throw ();
  virtual ~ShExpException () throw (){}
};


#endif
