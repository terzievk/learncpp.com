#include <iostream>

class Ball {
  std::string color {"black"};
  double radius {10.0};

public:
  Ball(double r): Ball{std::string{"black"}, r} {}
  Ball(const std::string& col = std::string{"black"}, double r = 10.0): color{col}, radius{r} {}

};

int main() {
  Ball def{};
  Ball blue{ "blue" };
  Ball twenty{ 20.0 };
  Ball blueTwenty{ "blue", 20.0 };

  return 0;
}
