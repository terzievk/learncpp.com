#include <cstddef>
#include <iostream>
#include <string>
#include <string_view>
#include <limits>

#include "Random.h"

namespace Wordlist {
  const std::vector<std::string_view> words {
    "mystery", "broccoli", "account", "almost",
    "spaghetti", "opinion", "beautiful", "distance", "luggage"};

  std::string_view pickRandomWord() {
    return words[Random::get(0uz, words.size() - 1uz)];
  }
}

class Session {
  static constexpr int lettersInTheAlphabet{26};
  std::string_view word{Wordlist::pickRandomWord()};
  std::string guessedWordSoFar{};
  std::string wrongGuessesString{};
  int wrongGuessesLeft{};
  std::vector<bool> used{std::vector<bool> (lettersInTheAlphabet)};

  void ignoreLine() const;
  bool clearFailedExtraction() const;

  void printWelcome() const;
  void printHint() const;

  char getLetter() const;
  int getPositiveInteger() const;

  bool hasBeenUsed(char c) const;
  void markUsed(char c);

  bool updateGuessWordSoFar(char c);

public:
  Session();

  void play();
};

int main() {
  Session session{};
  session.play();
}

void Session::printHint() const {
  std::cout << "The word: " << guessedWordSoFar << ' ';
  std::cout << "Wrong guesses: " << wrongGuessesString << '\n';
}

void Session::ignoreLine() const {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool Session::clearFailedExtraction() const {
  if (!std::cin) {
    if (std::cin.eof()) {
      std::exit(0);
    }

    std::cin.clear();
    ignoreLine();

    return true;
  }

  return false;
}

void Session::printWelcome() const {
  std::cout
  << "Welcome to C++man (a variant of Hangman)\n"
  << "To win: guess the word. To lose: run out of pluses.\n";
}

char Session::getLetter() const {
  while (true) {
    std::cout << "Enter your next letter: ";
    char c{};
    std::cin >> c;

    if (clearFailedExtraction()) {
      std::cout << "That wasn't a valid input. Try again.\n";
      continue;
    }

    ignoreLine(); // Remove any extraneous input

    if (c < 'a' || c > 'z') {
      std::cout << "That wasn't a valid input. Try again.\n";
      continue;
    }

    return c;
  }
}

int Session::getPositiveInteger() const {
  while (true) {
    std::cout << "How many wrong guesses do you want: ";
    int x{};
    std::cin >> x;

    if (clearFailedExtraction()) {
      std::cout << "That wasn't a valid input. Try again.\n";
      continue;
    }

    ignoreLine(); // Remove any extraneous input

    if (x <= 0) {
      std::cout << "That wasn't a valid input. Try again.\n";
      continue;
    }

    return x;
  }
}


bool Session::hasBeenUsed(char c) const {
  return used[static_cast<size_t>(c - 'a')];
}

void Session::markUsed(char c) {
  used[static_cast<size_t>(c - 'a')] = true;
}

bool Session::updateGuessWordSoFar(char c) {
  bool hasUpdated{};
  for (auto i{0uz}; i < word.size(); ++i) {
    if (word[i] == c) {
      guessedWordSoFar[i] = c;
      hasUpdated = true;
    }
  }
  return hasUpdated;
}


Session::Session() {
  printWelcome();

  for ([[maybe_unused]] char c : word) {
    guessedWordSoFar += "_";
  }

  std::cout << '\n';

  wrongGuessesLeft = getPositiveInteger();

  for (int i{}; i < wrongGuessesLeft; ++i) {
    wrongGuessesString += '+';
  }
}

void Session::play() {
  while (wrongGuessesLeft) {
    std::cout << '\n';
    printHint();

    char c{getLetter()};

    while (hasBeenUsed(c)) {
      std::cout << "You already guessed that. Try again.\n";
      c = getLetter();
    }

    std::cout << "You entered: " << c << '\n';

    markUsed(c);

    if (!updateGuessWordSoFar(c)) {
      std::cout << "No, '" << c << "' is not in the word!\n";

      wrongGuessesString[static_cast<size_t>(wrongGuessesLeft - 1)] = c;
      --wrongGuessesLeft;

      continue;
    }

    std::cout << "Yes, '" << c << "' is in the word!\n";

    if (guessedWordSoFar == word) {
      std::cout << "You won! The word was: " << word << '\n';
      return;
    }
  }

  std::cout << "You lost! The word was: " << word << '\n';
}
