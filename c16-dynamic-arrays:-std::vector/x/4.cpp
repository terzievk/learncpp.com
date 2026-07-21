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
  if (v.empty()) {
    std::cout << "With empty array there is no min and max\n";
    return;
  }

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

std::vector<int> readVectorOfIntegers() {
  std::cout << "Enter numbers to add (use -1 to stop): ";
  int x;
  std::cin >> x;

  if (x == -1) {
    return {};
  }

  std::vector<int> v;
  while (x != -1) {
    v.push_back(x);
    std::cin >> x;
  }

  return v;
}

int main() {
  std::vector v1{readVectorOfIntegers()};

  print(v1);
}
