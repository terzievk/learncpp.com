// define our own Pair type
template <typename T, typename U>
struct Pair
{
  T first{};
  U second{};
};

int main()
{
  [[maybe_unused]]  Pair<int, int> p1{ 1, 2 }; // ok: we're explicitly specifying the template arguments
  [[maybe_unused]]  Pair p2{ 1, 2 };           // compile error in C++17 (okay in C++20)

  return 0;
}
