#include <iomanip>  // for std::setw (which sets the width of the subsequent output)
#include <iostream>
#include <climits>  // for CHAR_BIT

int main() {
  std::cout << "A byte is " << CHAR_BIT << " bits\n\n"

  << std::left // left justify output

  << std::setw(16) << "bool:"        << sizeof(bool)        << " bytes\n"
  << std::setw(16) << "char:"        << sizeof(char)        << " bytes\n"
  << std::setw(16) << "short:"       << sizeof(short)       << " bytes\n"
  << std::setw(16) << "int:"         << sizeof(int)         << " bytes\n"
  << std::setw(16) << "long:"        << sizeof(long)        << " bytes\n"
  << std::setw(16) << "long long:"   << sizeof(long long)   << " bytes\n"
  << std::setw(16) << "float:"       << sizeof(float)       << " bytes\n"
  << std::setw(16) << "double:"      << sizeof(double)      << " bytes\n"
  << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";

  return 0;
}
