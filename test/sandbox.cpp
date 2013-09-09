#include <components.h>
#include <core.h>
#include <parts.h>

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
  IndentWriter writer;

  Component cad = SMS4303RServo().getCrown(1);
  cad.rotate(180,0,0);
  writer << cad;


  ofstream file("sandbox.scad");
  file << writer;
  file.close();

  return 0;
}
