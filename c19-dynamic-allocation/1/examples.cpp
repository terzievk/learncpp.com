#include <iostream>

int main() {
  int* ptr{ new int{7} };

  std::cout << *ptr << '\n';

  delete ptr;
}
