#include <components/Cube.h>
#include <core/IndentWriter.h>
#include <core/Union.h>
#include <parts/BallWheelHolder.h>

#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
  IndentWriter writer;

  Component cube(Cube(10, 10, 10));
  writer << cube;

  std::cout << writer;

  return 0;
}
