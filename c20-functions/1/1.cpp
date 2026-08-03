#include <cassert>
#include <cstdlib> // for std::exit
#include <functional>
#include <ios>
#include <iostream>
#include <limits> // for std::numeric_limits

// input validation is based on learncpp.com Ch. 9.5

void ignoreLine();
// returns true if extraction failed, false otherwise
bool clearFailedExtraction();
int getInt();
char getOperator();

int add(int x, int y) {
  return x + y;
}

int subtract(int x, int y) {
  return x - y;
}

int multiply(int x, int y) {
  return x * y;
}

int divide(int x, int y) {
  assert(y != 0 && "Can't divide by zero!");
  return x / y;
}

using ArithmeticFunction = std::function<int (int, int)>;

ArithmeticFunction getArithmeticFunction(char op) {
  switch (op) {
  case '+': return add;
  case '-': return subtract;
  case '*': return multiply;
  case '/': return divide;
  default:
    assert("Invalid operation!");
    return nullptr;
  }
}

int main() {
  int x{ getInt() };
  char operation{ getOperator() };
  int y{ getInt() };

  std::cout << "x: " << x << '\n';
  std::cout << "operation: " << operation << '\n';
  std::cout << "y: " << y << '\n';
  return 0;
}

void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// returns true if extraction failed, false otherwise
bool clearFailedExtraction() {
  if (!std::cin) {
    // if the stream was closed
    if (std::cin.eof()) {
      std::exit(0);
    }

    // back to normal
    std::cin.clear();
    // remove bad input
    ignoreLine();

    return true;
  }

  return false;
}

int getInt() {
  while (true) {
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    if (clearFailedExtraction()) {
      std::cout << "Oops, that input is invalid.  Please try again.\n";
      continue;
    }

    // remove bad input after the integer
    ignoreLine();
    return x;
  }
}

char getOperator() {
  while (true) {
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char operation{};
    std::cin >> operation;

    // Check whether the user entered meaningful input
    switch (operation)
      {
      case '+':
      case '-':
      case '*':
      case '/':
        ignoreLine(); // remove any extraneous input (only if extraction succeded)
        return operation; // Return the entered char to the caller
      default: // Otherwise tell the user what went wrong
        std::cout << "Oops, that input is invalid.  Please try again.\n";
      }
  }
}
