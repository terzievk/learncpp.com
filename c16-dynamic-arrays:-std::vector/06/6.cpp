#include <cassert>
#include <iostream>
#include <string_view>
#include <vector>

int main() {
  std::vector<int> divisors{3, 5, 7, 11, 13, 17, 19};
  std::vector<std::string_view> words {
    "fizz", "buzz", "pop", "bang", "jazz", "pow",
    "boom"
  };

  assert(divisors.size() == words.size());

  int n{21};

  for (int i{1}; i <= n; ++i) {
    bool hasDivisor{false};

    for (auto j{0u}; j < divisors.size(); ++j) {
      if (i % divisors[j] == 0) {
        std::cout << words[j];

        hasDivisor = true;
      }
    }

    if (!hasDivisor) {
      std::cout << i;
    }

    std::cout << '\n';
  }

  return 0;
}
