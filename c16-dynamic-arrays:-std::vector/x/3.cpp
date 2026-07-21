#include <cstddef>
#include <iostream>
#include <vector>
#include <utility>  // std::pair

template <typename T>
std::pair<size_t, size_t>
getMinMaxIndices(const std::vector<T> &v) {
  auto minIndex{0uz};
  auto maxIndex{0uz};
  auto min{v[0]};
  auto max{v[0]};

  for (auto i{0uz}; i < v.size(); ++i) {
    if (v[i] < min) {
      minIndex = i;
      min = v[i];
    }

    if (v[i] > max) {
      maxIndex = i;
      max = v[i];
    }
  }

  return {minIndex, maxIndex};
}

template <typename T>
void print(const std::vector<T> &v) {
  std::cout << "With array: (";

  bool firstComma{true};
  for (const auto &x : v) {
    if (firstComma) {
      std::cout << ' ' << x;
      firstComma = false;
    } else {
      std::cout << ", " << x;
    }
  }

  std::cout << " ):\n";

  auto minMaxPair{getMinMaxIndices(v)};

  std::cout << "The min element has index "
  << minMaxPair.first
  << " and value " << v[minMaxPair.first] << '\n';

  std::cout << "The max element has index "
  << minMaxPair.second
  << " and value " << v[minMaxPair.second] << '\n';
}

int main() {
  std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
  std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };

  print(v1);

  std::cout << '\n';

  print(v2);
}
