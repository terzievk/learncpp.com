#include <iostream>
#include <cassert>

void printAsBinary(int x) {
  assert((x > 0 && x < 256));

  int i {1 << 8};

  // that's awful...
  // but I just learned about the "operator," and wanted to have some fun
  while (i >>= 1, x)
    std::cout << (x >= i ? (x -= i, '1') : '0');
}

int main() {
  int x;
  std::cin >> x;

  printAsBinary(x);
  std::cout << std::endl;

  return 0;
}
