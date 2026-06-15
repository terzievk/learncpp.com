#include <type_traits> // for std::common_type

// harder to read (where is the name of the function in this mess?)
std::common_type_t<int, double> compare(int, double);

// easier to read (we don't have to read the return type unless we care)
auto compare(int, double) -> std::common_type_t<int, double>;

int main() {
  return 0;
}
