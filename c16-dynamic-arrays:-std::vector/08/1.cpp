#include <iostream>
#include <vector>

int main() {
  std::vector names{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};

  std::cout << "Enter a name: ";
  std::string name;
  std::cin >> name;

  for (const auto &n : names) {
    if (n == name) {
      std::cout << name << " was found\n";

      return 0;
    }
  }

  std::cout << name << " was not found\n";
}
