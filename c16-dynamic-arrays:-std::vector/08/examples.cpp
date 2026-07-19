#include <iostream>
#include <cxxabi.h>
#include <vector>
#include <ranges>
#include <string_view>

int main() {
  std::vector fibonacci { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

  std::size_t length { fibonacci.size() };
  for (auto index{0uz}; index < length; ++index) {
    std::cout << fibonacci[index] << ' ';
    std::cout << abi::__cxa_demangle(typeid(index).name(), nullptr, nullptr, 0) << '\n';
  }

  std::cout << '\n';

  std::vector<std::string_view> words{ "Alex", "Bobby", "Chad", "Dave" }; // sorted in alphabetical order

  for (const auto& word : std::views::reverse(words)) // create a reverse view
    std::cout << word << ' ';

  std::cout << '\n';

  return 0;
}
