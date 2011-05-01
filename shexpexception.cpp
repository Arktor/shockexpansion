#include "shexpexception.hpp"


ShExpException:: ShExpException (const char *error_message) throw ()
  : message (error_message)
{}


ShExpException:: ShExpException (const ShExpException& orig) throw ()
  :message ()
{
  this->message = orig.message;
}


ShExpException& ShExpException:: operator= (const ShExpException& right)\
  throw ()
{
  this->message = right.message;
  return *this;
}


const char* ShExpException:: what () const throw ()
{
  return message.data ();
}


