#include <iostream>

// ask the user to enter 3 values and print them in a specific format
int main() {
  std::cout << "Enter three numbers: ";

  int x{}, y{}, z{};
  std::cin >> x >> y >> z;

  std::cout << "You entered " << x << ", " << y << ", " << z<< ".\n";

  return 0;
}
