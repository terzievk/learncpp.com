#include <iostream>
#include <array>
#include <optional>
#include <string_view>

namespace Animal {
  enum Animal {
    chicken,
    dog,
    cat,
    elephant,
    duck,
    snake,
    animals_count
  };

  struct Data {
    int numberOfLegs{};
    std::string_view name{};
    std::string_view sound{};
  };

  constexpr std::array animals {
    chicken, dog, cat, elephant, duck, snake};

  constexpr std::array animalsData {
    Data {2, "chicken", "cluck"},
    Data {4, "dog", "woof"},
    Data {4, "cat", "meow"},
    Data {4, "elephant", "pawoo"},
    Data {2, "duck", "quack"},
    Data {0, "snake", "hissss"}
  };

  static_assert(animals.size() == animals_count);
  static_assert(animalsData.size() == animals_count);

  constexpr std::optional<Animal> findAnimal(std::string_view animal) {
    for (auto i{0uz}; i < animalsData.size(); ++i) {
      if (animal == animalsData[i].name) {
        return static_cast<Animal>(i);
      }
    }

    return {};
  }

  void printAnimal(Animal animal) {
    auto current{animalsData[animal]};
    std::cout << "A " << current.name << " has "
    << current.numberOfLegs << " and says " << current.sound << ".\n";
  }

  void run(std::optional<Animal> animal) {
    if (!animal) {
      std::cout << "That animal couldn't be found.\n";
    } else {
      printAnimal(*animal);
    }

    std::cout << '\n';
    std::cout << "Here is the data for the rest of the animals:\n";
    for (const auto &each : animals) {
      if (!animal || each != *animal) {
        printAnimal(each);
      }
    }
  }

} // namespace Animal

int main() {
  std::cout << "Enter an animal: ";
  std::string animal{};
  std::cin >> animal;

  run(Animal::findAnimal(animal));
}
