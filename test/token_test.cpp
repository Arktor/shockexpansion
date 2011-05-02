#include "../shexp.hpp"
using namespace std;


int main ()
{
  string str ("Find me a token please.");
  string buf;
  size_t pos = 0;

  pos = get_token (str, buf, pos);
  cout << buf;
  pos = get_token (str, buf, pos);
  cout << buf;
  pos = get_token (str, buf, pos);
  cout << buf << endl;

  return 0;
}
  
