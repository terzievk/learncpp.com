#include <iostream>
#include <bitset>
#include <format>
#include <print>

int main()
{
  int x0{ 012 }; // 0 before the number means this is octal
  std::cout << x0 << '\n';

  int y{ 0xF }; // 0x before the number means this is hexadecimal
  std::cout << y << '\n';

  int bin{};    // assume 16-bit ints
  bin = 0x00FF; // assign binary 0000 0000 1111 1111 to the variable
  std::cout << bin << '\n';

  int bin2{};        // assume 16-bit ints
  bin2 = 0b11110000; // assign binary 0000 0000 1111 0000 to the variable
  std::cout << bin2 << '\n';

  int bin3 { 0b1011'0010 };  // assign binary 1011 0010 to the variable
  long value { 2'132'673'462 }; // much easier to read than 2132673462
  std::cout << bin3 << ' ' << value << '\n';

  int x { 12 };
  std::cout << x << '\n'; // decimal (by default)
  std::cout << std::hex << x << '\n'; // hexadecimal
  std::cout << x << '\n'; // now hexadecimal
  std::cout << std::oct << x << '\n'; // octal
  std::cout << std::dec << x << '\n'; // return to decimal
  std::cout << x << '\n'; // decimal

  // std::bitset<8> means we want to store 8 bits
  std::bitset<8> bin11{ 0b1100'0101 }; // binary literal for binary 1100 0101
  std::bitset<8> bin21{ 0xC5 }; // hexadecimal literal for binary 1100 0101

  std::cout << bin11 << '\n' << bin21 << '\n';
  // create a temporary std::bitset and print it
  std::cout << std::bitset<4>{ 0b1010 } << '\n';

  // C++20, {:b} formats the argument as binary digits
  std::cout << std::format("{:b}\n", 0b1010);

  // C++20, {:#b} formats the argument as 0b-prefixed binary digits
  std::cout << std::format("{:#b}\n", 0b1010);

  // C++23, format/print two arguments (same as above) and a newline
  std::println("{:b} {:#b}", 0b1010, 0b1010);

  return 0;
}
