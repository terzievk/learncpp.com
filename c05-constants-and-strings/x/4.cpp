#include <iostream>

int main() {
  std::cout << "Enter the name of person #1: ";
  std::string n1{};
  std::getline(std::cin >> std::ws, n1);
  std::cout << "Enter the age of " << n1 << " : ";
  int a1{};
  std::cin >> a1;

  std::cout << "Enter the name of person #2: ";
  std::string n2{};
  std::getline(std::cin >> std::ws, n2);
  std::cout << "Enter the age of " << n2 << " : ";
  int a2{};
  std::cin >> a2;

  if (a1 >= a2) {
    std::cout << n1 << " (" << a1 << ") is older than "
    << n2 << " (" << a2 << ")\n";
  } else {
    std::cout << n2 << " (" << a2 << ") is older than "
    << n1 << " (" << a1 << ")\n";
  }

  return 0;
}
