#include <iostream>
#include <vector>

// Implement printArray() here
template <typename T>
void printArray(const std::vector<T>& arr);

int readNumber();

int main() {
  int x{readNumber()};

  std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

  printArray(arr); // use function template to print array

  for (auto i{0u}; i < arr.size(); ++i) {
    if (arr[i] == x) {
      std::cout << "The number " << x << " has index " << i << '\n';

      return 0;
    }
  }

  std::cout << "The number " << x << " was not found\n";

  return 0;
}

// Ch 9.5
void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Ch 9.5
// returns true if extraction failed, false otherwise
bool clearFailedExtraction() {
  // Check for failed extraction
  if (!std::cin) {  // If the previous extraction failed
    if (std::cin.eof()) {  // If the stream was closed
      std::exit(0); // Shut down the program now
    }

    // Let's handle the failure
    std::cin.clear(); // Put us back in 'normal' operation mode
    ignoreLine();     // And remove the bad input

    return true;
  }

  return false;
}

// Implement printArray() here
template <typename T>
void printArray(const std::vector<T>& arr) {
  for (auto i{0u}; i < arr.size(); ++i) {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
}

int readNumber() {
  while (true) {
    int x;

    std::cout << "Enter a number between 1 and 9: ";
    std::cin >> x;

    if (clearFailedExtraction()) {
      continue;
    }

    ignoreLine(); // Remove any extraneous input

    if (x >= 1 && x <= 9) {
      return x;
    }
  }
}
