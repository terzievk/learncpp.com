#include <iostream>

struct Point
{
  double x {};
  double y {};
};

struct Triangle
{
  Point* a {};
  Point* b {};
  Point* c {};
};

struct Paw
{
  int claws{};
};

struct Animal
{
  std::string name{};
  Paw paw{};
};

int main()
{
  Point a {1,2};
  Point b {3,7};
  Point c {10,2};

  Triangle tr { &a, &b, &c };
  Triangle* ptr {&tr};

  // ptr is a pointer to a Triangle, which contains members that are pointers to a Point
  // To access member y of Point c of the Triangle pointed to by ptr, the following are equivalent:

  // access via operator.
  std::cout << (*(*ptr).c).y << '\n'; // ugly!

  // access via operator->
  std::cout << ptr -> c -> y << '\n'; // much nicer

  Animal puma{ "Puma", { 5 } };

  Animal* ptr2{ &puma };

  // ptr is a pointer, use ->
  // paw is not a pointer, use .

  std::cout << (ptr2->paw).claws << '\n';
  std::cout << ptr2->paw.claws << '\n';


}
