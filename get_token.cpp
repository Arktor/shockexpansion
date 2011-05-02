#include "shexp.hpp"
using namespace std;


size_t get_token (const string& src, string& res,	\
		  size_t pos) throw (ShExpException)
{
  size_t cp = pos, tok_begin, tok_end;

  if (pos>=src.size())
    throw ShExpException ("Error: incorrect token position.\n");

  while (src[cp]==' ' || src[cp]=='\t' || src[cp]=='=')
    {
      cp++;

      if (cp>=src.size())
	throw ShExpException ("Token not found.\n");
    }

  tok_begin = cp;

  while (src[cp]!=' ' && src[cp]!='\t' && src[cp]!='\r' && src[cp]!='\n' && \
	 src[cp]!='\0' && src[cp]!='=' && cp<src.size())
    cp++;
	 
  tok_end = cp;
  res = src.substr (tok_begin, tok_end-tok_begin);
  return tok_end;
}
