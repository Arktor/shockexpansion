#include <iostream>
#include "../shexpnode.hpp"


int main ()
{
  ShExpNode node (0.0, 0.0);

  std:: cout << "x=" << node.x() << " y=" << node.y() << "\n";
  node.set_x (1.0);
  node.set_y (1.0);
  std:: cout << "x=" << node.x() << " y=" << node.y() << "\n";

  return 0;
}
