#include <iostream>

int main() {
  int x { 4 };
  if (x) // nonsensical, but for the sake of example...
    std::cout << "hi\n";
  else
    std::cout << "bye\n";

  return 0;
}
