#include <array>  // for std::array
#include <vector> // for std::vector

int main()
{
  [[maybe_unused]] std::array<int, 5> a {};  // a std::array of 5 ints

  std::vector<int> b(5);    // a std::vector of 5 ints (for comparison)

  return 0;
}
