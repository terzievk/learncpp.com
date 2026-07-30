#include <iostream>
struct Card {
  enum Rank {
    ace,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ranks_count
  };

  enum Suit {
    clubs,
    diamonds,
    hearts,
    spades,
    suits_count
  };

  Rank rank{};
  Suit suit{};
};

int main() {
  std::cout << "Hiya!\n";
}
