#include <components/RegularPiramid.h>
#include <components/RegularPrism.h>
#include <core/IndentWriter.h>

#include <iostream>

int main(int argc, char **argv)
{
  IndentWriter writer;
  Component prism(RegularPrism(5, 5.0, 5.0));

  writer << prism;

  std::cout << writer;

	return 0;
}
