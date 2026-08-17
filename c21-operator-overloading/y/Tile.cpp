#include "Tile.h"

std::ostream& operator<<(std::ostream& out, const Tile& tile) {
  int value{tile.getNum()};

  // double padding if single digit
  out << (value < 10 ? "  " : " ");

  // don't print the zero
  if (value == 0) {
    return out << "  ";
  }

  return out << value << ' ';
}
