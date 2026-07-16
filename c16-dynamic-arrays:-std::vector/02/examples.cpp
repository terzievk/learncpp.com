#include <iostream>
#include <vector>

int main() {
  std::vector primes { 2, 3, 5, 7, 11 }; // hold the first 5 prime numbers (as int)

  std::cout << "An int is " << sizeof(int) << " bytes\n";
  std::cout << &(primes[0]) << '\n';
  std::cout << &(primes[1]) << '\n';
  std::cout << &(primes[2]) << '\n';

  return 0;
}
