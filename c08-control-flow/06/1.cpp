#include <iostream>

int calculate(int x, int y, char op) {
  switch (op) {
  case '+':
    return x + y;
  case '-':
    return x - y;
  case '*':
    return x * y;
  case '/':
    return x / y;
  case '%':
    return x % y;
  default:
    std::cout << "invalid operation\n";
    return -1;
  }
}

int main() {
  std::cout << "Enter x, op, y\n";
  int x;
  std::cin >> x;

  char op;
  std::cin >> op;

  int y;
  std::cin >> y;

  std::cout << calculate(x, y, op) << '\n';
  return 0;
}
