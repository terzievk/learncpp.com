#include <algorithm>
#include <iostream>
#include <string_view>

struct Student {
  std::string_view name{};
  int points{};
};

std::array<Student, 8> arr{
  { { "Albert", 3 },
    { "Ben", 5 },
    { "Christine", 2 },
    { "Dan", 8 }, // Dan has the most points (8).
    { "Enchilada", 4 },
    { "Francis", 1 },
    { "Greg", 3 },
    { "Hagrid", 5 } }
};

int main() {
  auto comp {
    [](const auto &a, const auto &b) {
      return a.points < b.points;
    } };

  Student best {*std::max_element(arr.begin(), arr.end(), comp)};

  std::cout << best.name << '\n';
}
