#include <iostream>

class Cents
{
private:
  int m_cents{};
public:
  Cents(int cents=0)
  : m_cents{ cents }
  {
  }

  explicit operator int() const { return m_cents; } // now marked as explicit

  int getCents() const { return m_cents; }
  void setCents(int cents) { m_cents = cents; }
};

class Dollars
{
private:
  int m_dollars{};
public:
  Dollars(int dollars=0)
  : m_dollars{ dollars }
  {
  }

  operator Cents() const { return Cents { m_dollars * 100 }; }
};

void printCents(Cents cents)
{
  //  std::cout << cents;                   // no longer works because cents won't implicit convert to an int
  std::cout << static_cast<int>(cents); // we can use an explicit cast instead
}

int main()
{
  Dollars dollars{ 9 };
  printCents(dollars); // implicit conversion from Dollars to Cents okay because its not marked as explicit

  std::cout << '\n';

  return 0;
}
