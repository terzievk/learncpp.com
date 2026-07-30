#include <algorithm>
#include <cassert>
#include <iostream>
#include <array>
#include <string_view>

#include "Random.h"

using namespace std::string_view_literals;

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

  static constexpr std::array allRanks {
    ace, two, three, four, five, six, seven,
    eight, nine, ten, jack, queen, king
  };

  static constexpr std::array allSuits {
    clubs, diamonds, hearts, spades
  };

  static constexpr std::array rankCode {
    "A"sv, "2"sv, "3"sv, "4"sv, "5"sv, "6"sv, "7"sv,
    "8"sv, "9"sv, "T"sv, "J"sv, "Q"sv, "K"sv
  };

  static constexpr std::array suitCode {
    "C"sv, "D"sv, "H"sv, "S"sv
  };

  // assume blackjack values and Ace - 11
  static constexpr std::array rankValues {
    11, 2, 3, 4, 5, 6,7, 8, 9, 10, 10, 10, 10
  };

  static_assert(std::size(allRanks) == ranks_count);
  static_assert(std::size(allSuits) == suits_count);
  static_assert(std::size(rankCode) == ranks_count);
  static_assert(std::size(suitCode) == suits_count);
  static_assert(std::size(rankValues) == ranks_count);

  Rank rank{};
  Suit suit{};

  int value() const {
    return rankValues[rank];
  }

  friend std::ostream& operator<<(std::ostream& out, const Card &card) {
    out << rankCode[card.rank] << suitCode[card.suit];
    return out;
  }
};

class Deck {
  static constexpr int deckSize{52};
  std::array<Card, deckSize> cards{};
  std::array<Card, deckSize>::size_type nextCardIndex{};

public:
  Deck() {
    auto current{0uz};
    for (auto suit : Card::allSuits) {
      for (auto rank : Card::allRanks) {
        cards[current].suit = suit;
        cards[current].rank = rank;
        ++current;
      }
    }
  }

  Card dealCard() {
    assert(nextCardIndex < deckSize && "Out of cards!");

    return cards[nextCardIndex++];
  }

  void shuffle() {
    std::shuffle(cards.begin(), cards.end(), Random::mt);

    nextCardIndex = 0;
  }
};

void testPrint() {
  // Print one card
  Card card { Card::five, Card::hearts };
  std::cout << card << '\n';

  // Print all cards
  for (auto suit : Card::allSuits)
        for (auto rank : Card::allRanks)
          std::cout << Card { rank, suit } << ' ';
  std::cout << '\n';
}

int main() {
  Deck deck{};
  std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

  deck.shuffle();
  std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';
}
