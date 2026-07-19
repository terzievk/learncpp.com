#include <iostream>
#include <string_view>
#include <vector>

template <typename T>
bool isValueInArray(const std::vector<T>& arr, std::string_view name) {
  for (const auto &element : arr) {
    if (element == name) {
      return true;
    }
  }

  return false;
}
int main() {
  std::vector names{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};

  std::cout << "Enter a name: ";
  std::string name;
  std::cin >> name;

  std::cout << name << " was" << (isValueInArray(names, name) ? "" : " not") << " found\n";
}
