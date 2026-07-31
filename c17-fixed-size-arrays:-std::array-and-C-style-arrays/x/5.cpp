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

void testDeck() {
  Deck deck{};
  std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

  deck.shuffle();
  std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';
}

namespace Settings {
  constexpr int bustValue{21};
  constexpr int stopDrawingValue{17};
}


struct Player {
  int score{};
};

// learncpp.com Ch. 9.5
void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// learncpp.com Ch. 9.5
// returns true if extraction failed, false otherwise
bool clearFailedExtraction() {
  if (!std::cin) {
    if (std::cin.eof()) {    // If the stream was closed
      std::exit(0);  // Shut down the program now
    }

    // Let's handle the failure
    std::cin.clear();  // Put us back in 'normal' operation mode
    ignoreLine();      // And remove the bad input

    return true;
  }

  return false;
}

char getPlayerMove() {
  std::string_view message {
    "(h) to hit, or (s) to stand: "};

  while (true) {
    std::cout << message;
    message = "That is invalid input. Try again: ";

    char c{};
    std::cin >> c;

    if (clearFailedExtraction()) {
      continue;
    }

    ignoreLine(); // Remove any extraneous input

    if (c == 'h' || c == 's') {
      return c;
    }
  }
}

// return false if player goes bust
bool playerTurn(Deck& deck, Player& player) {
  // player's turn
  while (true) {
    if (player.score > Settings::bustValue) {
      return false;
    }

    if (getPlayerMove() == 's') {
      return true;
    }

    Card card = deck.dealCard();
    player.score += card.value();
    std::cout << "You were dealt: " << card << ". You now have: " << player.score << '\n';
  }
}

// return false if dealer goes bust
bool dealerTurn(Deck& deck, Player& dealer) {
  // dealer's turn
  while (Settings::stopDrawingValue > dealer.score) { // those two are swapped (see below)
    Card card = deck.dealCard();
    dealer.score += card.value();
    std::cout << "The dealer flips a: " << card << ". They now have: " << dealer.score << '\n';
  }
  // (Settings::stopDrawingValue > dealer.score) works fine
  // but (dealer.score < Settings::stopDrawingValue) doesn't work well on cpp-ts-mode
  // because ts-mode messes up the parsing since c++ can be ambiguous
  // without type context


  if (dealer.score > Settings::bustValue) {
    std::cout << "The dealer went bust!\n";
    return false;
  }

  return true;
}

// return true if player wins
bool play() {
  Deck deck{};
  deck.shuffle();

  Player dealer{};
  Player player{};

  dealer.score += deck.dealCard().value();

  player.score += deck.dealCard().value();
  player.score += deck.dealCard().value();

  std::cout << "The dealer is showing: " << dealer.score << '\n';
  std::cout << "You have score: " << player.score << '\n';

  // if player goes bust, dealer wins
  if (!playerTurn(deck, player)) {
    return false;
  }

  // if dealer goes bust, player wins
  if (!dealerTurn(deck, dealer)) {
    return true;
  }

  return player.score >= dealer.score;
}

int main() {
  if (play()) {
    std::cout << "You win!\n";
  } else {
    std::cout << "You lose!\n";
  }
}
