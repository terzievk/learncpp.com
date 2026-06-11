#include <iostream>

int main() {
  switch (2)
    {
    case 1:
      std::cout << 1 << '\n';
      break;
    case 2:
      std::cout << 2 << '\n'; // Execution begins here
      [[fallthrough]]; // intentional fallthrough -- note the semicolon to indicate the null statement
    case 3:
      std::cout << 3 << '\n'; // This is also executed
      break;
    }

  return 0;
}
