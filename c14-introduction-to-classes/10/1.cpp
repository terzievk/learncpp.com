#include <iostream>

class Ball {
  std::string color;
  double radius {};

public:
  Ball(std::string_view c, double r):
    color{c}, radius{r} {}

  const std::string& getColor() const {
    return color;
  }

  double getRadius() const {
    return radius;
  }
};

void print(const Ball& b) {
  std::cout << "Ball(" << b.getColor() << ", " << b.getRadius() << ")\n";
}

int main() {
  Ball blue { "blue", 10.0 };
  print(blue);

  Ball red { "red", 12.0 };
  print(red);

  return 0;
}
