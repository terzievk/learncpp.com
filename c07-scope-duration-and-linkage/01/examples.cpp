#include <iostream>

int main() {
  //  for (int i{}; {std::cout << "here\n"; i < 10}; ++i) {
  // ^ this doesn't work tho

  for (int i{}; std::cout << "here\n", i < 10; ++i) {
    std::cout << "a\n";
  }

  return 0;
}
