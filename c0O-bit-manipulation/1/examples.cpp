#include <bitset>
#include <iostream>

int main()
{
  [[maybe_unused]] constexpr int  isHungry   { 0 };
  [[maybe_unused]] constexpr int  isSad      { 1 };
  [[maybe_unused]] constexpr int  isMad      { 2 };
  [[maybe_unused]] constexpr int  isHappy    { 3 };
  [[maybe_unused]] constexpr int  isLaughing { 4 };
  [[maybe_unused]] constexpr int  isAsleep   { 5 };
  [[maybe_unused]] constexpr int  isDead     { 6 };
  [[maybe_unused]] constexpr int  isCrying   { 7 };

  std::bitset<8> me{ 0000'0101 }; // we need 8 bits, start with bit pattern 0000 0101
  me.set(isHappy);      // set bit position 3 to 1 (now we have 0000 1101)
  me.flip(isLaughing);  // flip bit 4 (now we have 0001 1101)
  me.reset(isLaughing); // set bit 4 back to 0 (now we have 0000 1101)

  std::cout << "All the bits: " << me << '\n';
  std::cout << "I am happy: " << me.test(isHappy) << '\n';
  std::cout << "I am laughing: " << me.test(isLaughing) << '\n';

  return 0;
}
