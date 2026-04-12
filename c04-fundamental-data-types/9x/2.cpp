#include <iostream>

char readOp();
double readDouble();

int main() {
  double x{readDouble()};
  double y{readDouble()};

  char c{readOp()};

  if (c == '+') {
    std::cout << x << " + " << y << " is " << x + y << '\n';
  } else if (c == '-') {
    std::cout << x << " - " << y << " is " << x - y << '\n';
  } else if (c == '*') {
    std::cout << x << " * " << y << " is " << x * y << '\n';
  } else if (c == '/' && y != 0) {
    std::cout << x << " / " << y << " is " << x / y << '\n';
  } else {
    std::cerr << "Invalid op\n";
    return 1;
  }

  return 0;
}

double readDouble() {
  std::cout << "Enter a double value: ";

  double x;
  std::cin >> x;

  return x;
}

char readOp() {
  std::cout << "Enter +, -, * or /: ";

  char x;
  std::cin >> x;

  return x;
}
