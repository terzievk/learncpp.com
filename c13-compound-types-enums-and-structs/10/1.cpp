#include <iostream>

struct Data {
  int ads{};
  int clicked{};
  double earnings{};
};

void printData(const Data& data) {
  std::cout << data.ads << ' ' << data.clicked << ' ' << data.earnings << ' '
  << data.ads * data.clicked * data.earnings / 100 << '\n';  // delete by 100 (%)
}

Data readData() {
  Data data{};
  std::cin >> data.ads >> data.clicked >> data.earnings;

  return data;
}

int main() {
  Data data{readData()};

  printData(data);
  return 0;
}
