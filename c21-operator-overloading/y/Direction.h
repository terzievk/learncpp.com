#ifndef DIRECTION_H_
#define DIRECTION_H_

#include <iostream>

using namespace std::string_view_literals;

class Direction {
 public:
  enum Type { up, down, left, right, maxDirections };

  static constexpr std::array allDirections{up, down, left, right};
  static_assert(allDirections.size() == maxDirections);

  static constexpr std::array directions{"up"sv, "down"sv, "left"sv, "right"sv};
  static_assert(directions.size() == maxDirections);

 private:
  Type direction{};

 public:
  Direction(Type direction) : direction{direction} {}

  Direction operator-();

  static Direction getRandom();

  friend std::ostream& operator<<(std::ostream& out, const Direction& d);
};

#endif  // DIRECTION_H_
