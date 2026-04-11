#include <iostream>

void print(int x) {
  std::cout << x;
}

// fyi: the assignment was to make this weird
int main() {
  std::cout << "Enter a single character: ";
  char c;
  std::cin >> c;

  std::cout << "You entered '" << c << "', which has ASCII code ";
  print(c);
  std::cout << ".\n";

  return 0;
}
