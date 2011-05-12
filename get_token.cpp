#include "shexp.hpp"
#include <cstring>
using namespace std;


size_t get_token (const string& src, string& res,	\
		  size_t pos) throw (ShExpException)
{
  size_t cp = pos, tok_begin, tok_end;

  if (pos>=src.size())
    throw ShExpException ("Error: unexpected end of string.\n");

  while (strchr(" =\t", src[cp]) && cp<src.size())
    {
      cp++;

      if (cp>=src.size())
	throw ShExpException ("Error: unexpected end of string.\n");
    }

  tok_begin = cp;

  while (!strchr(" \t\r\n\0=", src[cp]) && cp<src.size())
    cp++;
	 
  tok_end = cp;
  res = src.substr (tok_begin, tok_end-tok_begin);
  return tok_end;
}
