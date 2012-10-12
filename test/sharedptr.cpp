#include <core/SharedPtr.h>

int main(int argc, char **argv)
{
  SharedPtr<int> b(new int(4));
  SharedPtr<int> c(b);

  b.reset();

  c = b;

  return 0;
}
