#include <array>
#include <iostream>

template <typename T, auto N> // now using auto to deduce type of N
void passByRef(const std::array<T, N>& arr)
{
  static_assert(N != 0); // fail if this is a zero-length std::array

  std::cout << arr[0] << '\n';
}

int main()
{
  std::array arr{ 9, 7, 5, 3, 1 }; // use CTAD to infer std::array<int, 5>
  passByRef(arr);  // ok: compiler will instantiate passByRef(const std::array<int, 5>& arr)

  std::array arr2{ 1, 2, 3, 4, 5, 6 }; // use CTAD to infer std::array<int, 6>
  passByRef(arr2); // ok: compiler will instantiate passByRef(const std::array<int, 6>& arr)

  std::array arr3{ 1.2, 3.4, 5.6, 7.8, 9.9 }; // use CTAD to infer std::array<double, 5>
  passByRef(arr3); // ok: compiler will instantiate passByRef(const std::array<double, 5>& arr)

  return 0;
}
