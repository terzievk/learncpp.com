#include <iostream>
#include <vector>

void passByRef(const std::vector<int>& arr) // we must explicitly specify <int> here
{
  std::cout << arr[0] << '\n';
}

int main()
{
  std::vector primes{ 2, 3, 5, 7, 11 };
  passByRef(primes);

  std::cout << sizeof(primes) << '\n';;

  return 0;
}
