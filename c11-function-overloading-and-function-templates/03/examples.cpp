#include <iostream>

// void foo(char x ) {
//   std::cout << x << '\n';
// }

void foo(int x ) {
  std::cout << x << '\n';
}


void foo(double x) {
  std::cout << x << '\n';
}

int main() {
  foo('a');  // promoted to match foo(int)
  foo(true); // promoted to match foo(int)
  foo(4.5f); // promoted to match foo(double)

  return 0;
}
