#include <components/RoundedCube.h>
#include <components/RoundedCylinder.h>
#include <components/RoundedTablet.h>
#include <core/Component.h>
#include <core/IndentWriter.h>

#include <iostream>

int main(int argc, char **argv)
{
  IndentWriter writer;

  Component roundedTablet(RoundedTablet(5.0, 5.0, 1.0, 1.0));
  writer << roundedTablet;

  Component roundedCube(RoundedCube(5.0, 5.0, 5.0, 1.0));
  writer << roundedCube;

  Component roundedCylinder(RoundedCylinder(5.0, 5.0, 1.0));
  writer << roundedCylinder;

  Component roundedConicalFrustum(RoundedCylinder(7.0, 5.0, 5.0, 1.0));
  writer << roundedConicalFrustum;

  std::cout << writer;

  return 0;
}
