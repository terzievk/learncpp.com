#include <iostream>

// tiles are in the format:
// _ _ a _  or  _ a b _  where a/b are single digits
class Tile {
  int value{};

public:
  explicit Tile(int value = 0): value{value} {}
  int getNum() const {return value;}
  bool isEmpty() const {return value == 0;}

};

std::ostream &operator<<(std::ostream &out, const Tile &tile) {
  int value{tile.getNum()};

  // double padding if single digit
  out << (value < 10 ? "  " : " ");

  // don't print the zero
  if (value == 0) {
    return out << "  ";
  }

  return out << value << ' ';
}


int main() {
  Tile tile1{ 10 };
  Tile tile2{ 8 };
  Tile tile3{ 0 };  // the missing tile
  Tile tile4{ 1 };

  // to make it easy to see how many spaces are in the next line
  std::cout << "0123456789ABCDEF\n";
  std::cout << tile1 << tile2 << tile3 << tile4 << '\n';

  std::cout << std::boolalpha
  << tile1.isEmpty() << ' ' << tile3.isEmpty() << '\n';

  std::cout << "Tile 2 has number: " << tile2.getNum()
  << "\nTile 4 has number: " << tile4.getNum() << '\n';

  return 0;
}
