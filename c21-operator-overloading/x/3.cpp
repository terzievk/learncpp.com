#include <cassert>
#include <iostream>

class IntArray {
  int* data{};
  int size{};

  void copy(const IntArray &array);

public:
  explicit IntArray(int size);
  IntArray(const IntArray &array);
  IntArray &operator=(const IntArray &array);
  ~IntArray() { delete[] data; }

  int& operator[](int index);

  friend std::ostream &operator<<(std::ostream &out, const IntArray &array);
};

IntArray fillArray();

int main() {
  IntArray a{ fillArray() };

  std::cout << a << '\n';

  auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
  a = ref;

  IntArray b(1);
  b = a;

  a[4] = 7;

  std::cout << b << '\n';

  return 0;
}

IntArray fillArray() {
  IntArray a(5);

  a[0] = 5;
  a[1] = 8;
  a[2] = 2;
  a[3] = 3;
  a[4] = 6;

  return a;
}

void IntArray::copy(const IntArray &array) {
  delete[] data;

  size = array.size;

  if (!size) {
    data = nullptr;
    return;
  }

  data = new int[size];

  for (int i{}; i < size; ++i) {
    data[i] = array.data[i];
  }
}


IntArray::IntArray(int size) : size{size} {
  assert(size >= 0);

  if (size) {
    data = new int[size];
  } else {
    data = nullptr;
  }
}

IntArray::IntArray(const IntArray &array) {
  copy(array);
}

IntArray& IntArray::operator=(const IntArray &array) {
  if (this == &array) {
    return *this;
  }

  copy(array);

  return *this;
}

int& IntArray::operator[](int index) {
  assert(index >= 0 && index < size);

  return data[index];
}

std::ostream &operator<<(std::ostream &out, const IntArray &array) {
  for (int i{}; i < array.size; ++i) {
    out << array.data[i] << ' ';
  }
  return out;
}
