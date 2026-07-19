#include <cassert>
#include <iostream>
#include <vector>

namespace Animals {
  enum Animals {
    chicken,
    dog,
    cat,
    elephant,
    duck,
    snake,
    maxAnimalsCount
  };

  std::vector legs{2, 4, 4, 4, 2, 0};
}

int main() {
  assert(Animals::legs.size() == Animals::maxAnimalsCount);

  std::cout << "The elephant has " << Animals::legs[Animals::elephant] << " legs\n";
}
