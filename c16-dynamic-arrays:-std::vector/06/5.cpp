#include <iostream>
#include <vector>

template <typename T> T findMax(std::vector<T> &data) {
  if (!data.size()) {
    return T{};
  }

  T max{data[0]};

  for (auto i{1u}; i < data.size(); ++i) {
    if (data[i] > max) {
      max = data[i];
    }
  }

  return max;
}

int main() {
  std::vector data1 { 84, 92, 76, 81, 56 };
  std::cout << findMax(data1) << '\n';

  std::vector data2 { -13.0, -26.7, -105.5, -14.8 };
  std::cout << findMax(data2) << '\n';

  std::vector data4 { -13.0};
  std::cout << findMax(data4) << '\n';


  std::vector<int> data3 { };
  std::cout << findMax(data3) << '\n';

  return 0;
}
