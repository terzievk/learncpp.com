#include <iostream>

int main() {
  int s;
  std::cin >> s;
  int l;
  std::cin >> l;

  if (s > l) {
    int y{s};
    s = l;
    l = y;
  }

  std::cout << s << ' ' << l << '\n';
}
