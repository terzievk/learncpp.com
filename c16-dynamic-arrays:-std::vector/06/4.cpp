#include <iostream>
#include <string_view>
#include <vector>

template <typename T>
T getValidNumber(std::string_view message, T lower, T upper);
template <typename T>
void printArray(const std::vector<T>& arr);
template <typename T>
int findIndex(const std::vector<T> &arr, T num);

int main() {
  std::vector arr{ 4.4, 6.6, 7.7, 3.3, 8.8, 2.2, 1.1, 9.9 };

  auto num { getValidNumber("Enter a number between 1 and 9: ", 1.0, 9.0) };

  printArray(arr);

  int index { findIndex(arr, num) };

  if (index != -1)
    std::cout << "The number " << num << " has index " << index << '\n';
  else
    std::cout << "The number " << num << " was not found\n";

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

template <typename T>
T getValidNumber(std::string_view message, T lower, T upper) {
  while (true) {
    std::cout << message;

    T x;
    std::cin >> x;

    if (clearFailedExtraction()) {
      continue;
    }

    ignoreLine(); // Remove any extraneous input

    if (x >= lower && x <= upper) {
      return x;
    }
  }
}

template <typename T>
int findIndex(const std::vector<T> &arr, T num) {
  for (auto i{0u}; i < arr.size(); ++i) {
    if (arr[i] == num) {
      return static_cast<int>(i);
    }
  }

  return -1;
}
