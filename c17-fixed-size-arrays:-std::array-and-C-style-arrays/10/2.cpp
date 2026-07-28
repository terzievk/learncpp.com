#include <iostream>

void printReverse(const char *str) {
  if (*str == '\0') {
    return;
  }

  printReverse(str + 1);
  std::cout << *str;
}

int main() {
  printReverse("Hello, World!");

  std::cout << '\n';
}
