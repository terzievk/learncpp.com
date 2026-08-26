#include <iostream>
#include <ostream>
#include <string>
#include <string_view>

class Fruit {
  std::string name{};
  std::string color{};

 public:
  Fruit(std::string_view name, std::string_view color)
      : name{name}, color{color} {}

  std::string_view getName() const { return name; }
  std::string_view getColor() const { return color; }
};

class Apple : public Fruit {
  double fiber{};

 public:
  Apple(std::string_view name, std::string_view color, double fiber)
      : Fruit{name, color}, fiber{fiber} {}

  double getFiber() const { return fiber; }

  friend std::ostream& operator<<(std::ostream& out, const Apple& apple);
};

class Banana : public Fruit {
 public:
  Banana(std::string_view name, std::string_view color) : Fruit{name, color} {}

  friend std::ostream& operator<<(std::ostream& out, const Banana& banana);
};

int main() {
  const Apple a{"Red delicious", "red", 4.2};
  std::cout << a << '\n';

  const Banana b{"Cavendish", "yellow"};
  std::cout << b << '\n';

  return 0;
}

std::ostream& operator<<(std::ostream& out, const Apple& apple) {
  return out << "Apple(" << apple.getName() << ", " << apple.getColor() << ", "
             << apple.getFiber() << ')';
}

std::ostream& operator<<(std::ostream& out, const Banana& banana) {
  return out << "Banana(" << banana.getName() << ", " << banana.getColor()
             << ')';
}
