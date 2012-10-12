#include <components/Cube.h>
#include <core/IndentWriter.h>

#include <iostream>

int main(int argc, char **argv)
{
  IndentWriter writer(8);
  
  writer << "Hola mundo" << std::endl;
  
  writer.indent();
  writer << 1 << ", " << 1.0 << std::endl;
  writer.unindent();

  {
    IndentBlock block(writer);
    writer << 2 << ", " << 2.0 << std::endl;
  }
  
  writer << "Adios mundo" << std::endl;

  std::cout << writer;

  return 0;
}
