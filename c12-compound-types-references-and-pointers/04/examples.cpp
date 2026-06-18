// #include <iostream>

// int main()
// {
//   short bombs { 1 };         // I can has bomb! (note: type is short)

//   const int& you { bombs };  // You can has bomb too (note: type is int&)
//   --bombs;                   // Bomb all gone

//   if (you)                   // You still has?
//     {
//       std::cout << "Bombs away!  Goodbye, cruel world.\n"; // Para bailar la bomba
//     }

//   return 0;
// }

// int g_x { 5 };

// int main()
// {
//   [[maybe_unused]] constexpr int& ref1 { g_x }; // ok, can bind to global

//   static int s_x { 6 };
//   [[maybe_unused]] constexpr int& ref2 { s_x }; // ok, can bind to static local

//   // int x { 6 };
//   // [[maybe_unused]] constexpr int& ref3 { x }; // compile error: can't bind to non-static object

//   return 0;
// }

int main()
{
  static const int s_x { 6 }; // a const int
  [[maybe_unused]] constexpr const int& ref2 { s_x }; // needs both constexpr and const

  return 0;
}
