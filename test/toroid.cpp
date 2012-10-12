#include <components/Circle.h>
#include <components/Toroid.h>
#include <core/Component.h>
#include <core/Component2D.h>
#include <core/IndentWriter.h>

#include <iostream>

int main(int argc, char **argv)
{
  IndentWriter writer;
  Component2D circle(Circle::create(1.0).translate(2, 0, 0));
  Component toroid(circle.rotateExtrudedCopy());

  writer << toroid;

  Component toroid2(Toroid(2.0, 1.0));

  writer << toroid2;
  std::cout << writer;

  return 0;
}
