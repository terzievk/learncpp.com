#include <iostream>

enum class Animal {
  pig,
  chicken,
  goat,
  cat,
  dog,
  duck
};

constexpr std::string_view getAnimalName(Animal animal) {
  using enum Animal;

  switch(animal) {
  case pig:     return "pig";
  case chicken: return "chicken";
  case goat:    return "goat";
  case cat:     return "cat";
  case dog:     return "dog";
  case duck:    return "duck";
  default: return "???";
  }
}


constexpr void printNumberOfLegs(Animal animal) {
  using enum Animal;


  std::cout << "A " << getAnimalName(animal) << " has ";

  switch(animal) {
  case pig:
  case goat:
  case cat:
  case dog:
    std::cout << "4";
    break;

  case duck:
  case chicken:
    std::cout << "2";
    break;

  default:
    exit(1);
  }

  std::cout << " legs.\n";
}


int main() {
  Animal a {1};
  printNumberOfLegs(a);

  Animal b {4};
  printNumberOfLegs(b);

  printNumberOfLegs(Animal {3});

  return 0;
}
