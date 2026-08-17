#ifndef DIRECTION_H_
#define DIRECTION_H_

#include <iostream>
#include <string_view>

class Direction {
 public:
  enum Type { up, down, left, right, maxDirections };

  static constexpr std::array allDirections{up, down, left, right};
  static_assert(allDirections.size() == maxDirections);

  static constexpr std::array directions{
      std::string_view{"up"}, std::string_view{"down"},
      std::string_view{"left"}, std::string_view{"right"}};
  static_assert(directions.size() == maxDirections);

 private:
  Type direction{};

 public:
  Direction(Type direction) : direction{direction} {}

  Direction operator-();

  Direction::Type getDirection() const { return direction; }

  static Direction getRandom();

  friend std::ostream& operator<<(std::ostream& out, const Direction& d);
};

#endif  // DIRECTION_H_
