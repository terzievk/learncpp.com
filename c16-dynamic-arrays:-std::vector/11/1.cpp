#include <iostream>
#include <vector>

void print(const std::vector<int> &stack) {
  std::cout << "(Stack:";

  if (stack.empty()) {
    std::cout << " empty";
  }

  for (int element : stack) {
    std::cout << ' ' << element;
  }

  std::cout << ")\n";
}

int main() {
  std::vector<int> stack;
  print(stack);

  stack.push_back(1);
  print(stack);

  stack.push_back(2);
  print(stack);

  stack.push_back(3);
  print(stack);

  stack.pop_back();
  print(stack);

  stack.push_back(4);
  print(stack);

  stack.pop_back();
  print(stack);

  stack.pop_back();
  print(stack);

  stack.pop_back();
  print(stack);


}
