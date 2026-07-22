#include <array>
#include <iostream>

struct House
{
  int number{};
  int stories{};
  int roomsPerStory{};
};

int main()
{
  // constexpr std::array<House, 3> houses {{ // note double braces
  //                                          { 13, 1, 7 },
  //                                          { 14, 2, 5 },
  //                                          { 15, 2, 4 }
  // }};

  constexpr std::array<House, 3> houses {
    13, 1, 7,
    14, 2, 5,
    15, 2, 4
  };


  for (const auto& house : houses)
    {
      std::cout << "House number " << house.number
      << " has " << (house.stories * house.roomsPerStory)
      << " rooms.\n";
    }

  return 0;
}
