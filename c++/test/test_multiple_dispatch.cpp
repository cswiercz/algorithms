#include "algorithms/multiple_dispatch.hpp"

#include <iostream>

int main(int argc, char** argv)
{
  std::unique_ptr<Shape> p_r1(new Rectangle);
  std::unique_ptr<Shape> p_r2(new Rectangle);
  std::unique_ptr<Shape> p_e1(new Ellipse);

  // yes, using unique_ptr<>.get() can be dangerous...for now this is just for
  // demonstration purposes.
  std::cout << "Dynamic type dispatch\n";
  p_r1->Intersect(p_e1.get());
  p_r1->Intersect(p_r2.get());

  return 0;
}
