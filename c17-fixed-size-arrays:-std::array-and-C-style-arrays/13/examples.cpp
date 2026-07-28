#include <array>
#include <iostream>
#include <functional>

// An alias template to allow us to define a one-dimensional std::array using two dimensions
template <typename T, std::size_t Row, std::size_t Col>
using ArrayFlat2d = std::array<T, Row * Col>;

// A modifiable view that allows us to work with an ArrayFlat2d using two dimensions
// This is a view, so the ArrayFlat2d being viewed must stay in scope
template <typename T, std::size_t Row, std::size_t Col>
class ArrayView2d
{
private:
  // You might be tempted to make m_arr a reference to an ArrayFlat2d,
  // but this makes the view non-copy-assignable since references can't be reseated.
  // Using std::reference_wrapper gives us reference semantics and copy assignability.
  std::reference_wrapper<ArrayFlat2d<T, Row, Col>> m_arr {};

public:
  ArrayView2d(ArrayFlat2d<T, Row, Col> &arr)
  : m_arr { arr }
  {}

  // Get element via single subscript (using operator[])
  T& operator[](int i) { return m_arr.get()[static_cast<std::size_t>(i)]; }
  const T& operator[](int i) const { return m_arr.get()[static_cast<std::size_t>(i)]; }

  // // Get element via 2d subscript (using operator(), since operator[] doesn't support multiple dimensions prior to C++23)
  // T& operator()(int row, int col) { return m_arr.get()[static_cast<std::size_t>(row * cols() + col)]; }
  // const T& operator()(int row, int col) const { return m_arr.get()[static_cast<std::size_t>(row * cols() + col)]; }


  // in C++23, you can uncomment these since multidimensional operator[] is supported
  T& operator[](int row, int col) { return m_arr.get()[static_cast<std::size_t>(row * cols() + col)]; }
  const T& operator[](int row, int col) const { return m_arr.get()[static_cast<std::size_t>(row * cols() + col)]; }

  int rows() const { return static_cast<int>(Row); }
  int cols() const { return static_cast<int>(Col); }
  int length() const { return static_cast<int>(Row * Col); }
};

int main()
{
  // Define a one-dimensional std::array of int (with 3 rows and 4 columns)
  ArrayFlat2d<int, 3, 4> arr {
    1, 2, 3, 4,
    5, 6, 7, 8,
    9, 10, 11, 12 };

  // Define a two-dimensional view into our one-dimensional array
  ArrayView2d<int, 3, 4> arrView { arr };

  // print array dimensions
  std::cout << "Rows: " << arrView.rows() << '\n';
  std::cout << "Cols: " << arrView.cols() << '\n';

  // print array using a single dimension
  for (int i=0; i < arrView.length(); ++i)
    std::cout << arrView[i] << ' ';

  std::cout << '\n';

  // print array using two dimensions
  for (int row=0; row < arrView.rows(); ++row)
    {
      for (int col=0; col < arrView.cols(); ++col)
        std::cout << arrView[row, col] << ' ';
      std::cout << '\n';
    }

  std::cout << '\n';

  return 0;
}
