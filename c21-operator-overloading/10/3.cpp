#include <iostream>
#include <memory>
#include <string>
#include <string_view>

class MyString {
  std::string str{};

public:
  MyString(std::string_view str): str{str} {}

  friend std::ostream &operator<<(std::ostream &out, const MyString &str) {
    return out << str.str;
  }

  std::string_view operator()(int pos, int count) const {
    return std::string_view{str}.substr(static_cast<size_t>(pos), static_cast<size_t>(count));
  }
};

int main() {
  MyString s { "Hello, world!" };
  std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

  return 0;
}
