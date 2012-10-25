#include <components.h>
#include <core.h>

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
  IndentWriter writer;

  Component cube = Cube(5, 15, 3);
  Component cylinder1 = Cylinder(5,3).translate(-10,0,0);
  Component cylinder2 = Cylinder(5,3).translate(10,0,0);
  Component cylinder3 = Cylinder(5,3).translate(0,10,0);

  Component hull = cube + cylinder1 + cylinder2 + cylinder3;
  writer << hull;

  ofstream file("sandbox.scad");
  file << writer;
  file.close();

  return 0;
}
