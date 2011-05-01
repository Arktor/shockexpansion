#include <iostream>
#include "../shexppanel.hpp"


int main ()
{
  ShExpPanel panel (0.0, 0.0, 1.0, 1.0);
  ShExpNode node1 (0.0, 0.0);
  ShExpNode node2 (2.0, 1.0);
  
  std:: cout << "x1=" << panel.x1() << " y1=" << panel.y1() << "\nx2=" <<\
    panel.x2() << " y2=" << panel.y2() << "\nslp=" << panel.slp(DEG) << "\n";

  try
    {
      panel.set_nodes (0.0, 0.0, 1.0, 0.0);
    }
  catch (std:: exception &e)
    {
      std:: cout << e.what ();
    }

  std:: cout << "x1=" << panel.x1() << " y1=" << panel.y1() << "\nx2=" <<\
    panel.x2() << " y2=" << panel.y2() << "\nslp=" << panel.slp(DEG) << "\n";

  return 0;
}
