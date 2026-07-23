#include <iostream>

// assume correct input
int getInteger() {
  std::cout << "Enter a single digit integer or -1 to quit: ";
  int x;
  std::cin >> x;
  return x;
}

int main() {
  constexpr int perfect[] {0, 1, 4, 9};

  while (true) {
    int x{getInteger()};

    if (x == -1) {
      break;
    }

    bool isPerfect{};
    for (int each : perfect) {
      if (x == each) {
        isPerfect = true;
        break;
      }
    }

    std::cout << x << " is" << (isPerfect ? "" : " not") << " a perfect square\n";
  }

  std::cout << "Bye\n";

  return 0;
}
