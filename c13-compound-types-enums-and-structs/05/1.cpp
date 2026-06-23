#include <iostream>

enum Color {
  red,
  green,
  blue
};

std::string_view colorToString(Color c) {
  if (c == red) {
    return "red";
  }

  if (c == green) {
    return "green";
  }

  if (c == blue) {
    return "blue";
  }

  return "???";
}

Color stringToColor(std::string_view sv) {
  if (sv == "red") {
    return red;
  }

  if (sv == "green") {
    return green;
  }

  if (sv == "blue") {
    return blue;
  }

  exit(1);
}

std::ostream& operator<<(std::ostream& out, const Color& c) {
  return out << colorToString(c);
}

std::istream& operator>>(std::istream& in, Color& c) {
  std::string s;
  std::cin  >> s;

  c = stringToColor(s);
  return in;
}

int main() {
  Color c{red};

  std::cin >> c;

  std::cout << c << '\n';
  return 0;
}
