#include <iostream>

double gravity {9.8};

double getHeight();
double calcHeight(int s, double height);
void print(int s, double height);

int main() {
  double height{getHeight()};

  print(0, height);
  print(1, height);
  print(2, height);
  print(3, height);
  print(4, height);
  print(5, height);

  return 0;
}

double getHeight() {
  std::cout << "Enter the height of the tower in meters: ";

  double x;
  std::cin >> x;

  return x;
}

double calcHeight(int s, double height) {
  double h{height - gravity * s * s / 2};

  if (h >= 0) {
    return h;
  }

  return 0;
}

void print(int s, double height) {
  double h{calcHeight(s, height)};

  if (h > 0.0) {
    std::cout << "At " << s << " seconds, the ball is at height: "
    << calcHeight(s, height) << " meters\n";
  } else {
    std::cout << "At " << s << " seconds, the ball is on the ground.\n";
  }
}
