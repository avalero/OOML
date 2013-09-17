#include <components.h>
#include <core.h>
#include <parts.h>
#include <components/CylindricalSection.h>

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
  IndentWriter writer;

  Component cad = CylindricalSection(30,40,85,10,100,false);

  writer << cad;

  ofstream file("sandbox.scad");
  file << writer;
  file.close();

  return 0;
}
