#include <algorithm>
#include <iostream>
#include <string>

int main() {
  std::cout << "How many names do you wish to enter?\n";
  int count{};
  std::cin >> count;

  std::string* names{ new std::string[count]{} };

  for (int i{}; i < count; ++i) {
    std::cout << "Enter name #" << i + 1 << ": ";
    std::cin >> names[i];
  }

  std::sort(names, names + count);

  std::cout << "Here is your sorted list:\n";

  for (int i{}; i < count; ++i) {
    std::cout << "Name #" << i + 1 << ": " << names[i] << '\n';
  }

  delete[] names;
}
