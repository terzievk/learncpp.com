#include <iostream>

void print(const char *str) {
  while (*str != '\0') {
    std::cout << *str;

    ++str;
  }
}

int main() {
  print("Hello, World!");

  std::cout << '\n';
}
