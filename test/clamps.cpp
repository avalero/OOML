#include <components/Cube.h>
#include <components/Cylinder.h>
#include <core/IndentWriter.h>
#include <core/Difference.h>
#include <core/Union.h>
#include <core/Intersection.h>
#include <components/RoundedTablet.h>

#include <iostream>

int main(int argc, char **argv)
{
  IndentWriter writer;

  Component main_body = RoundedTablet(70,38,6,3,true,true,true,true,20);
  Component main_hole = RoundedTablet(60,30,6.2,1,true,true,true,true,20);
  Component small_hole = RoundedTablet(16,30,6.2,1,true,true,true,true,20);
  main_body.translate(-5,0,0);
  main_hole.translate(-26,0,0);
  small_hole.translate(17,0,0);

  Component body = main_body - main_hole - small_hole;

  Component ext_ring = Cylinder(9,6,50,true);
  ext_ring.translate(30,19,0);

  Component int_ring = Cylinder(5,6.2,50,true);
  int_ring.translate(30,19,0);

  Component clamp = body + ext_ring - int_ring;

  writer << clamp;
	std::cout << writer;

  return 0;
}
