#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct StudentGrade {
  std::string name{};
  char grade{};
};

class GradeMap {
  std::vector<StudentGrade> map{};

public:
  GradeMap() {}

  char& operator[](std::string name) {
    auto pred {
      [=](const StudentGrade& student) {
        return student.name == name;
      }};

    auto found{ std::find_if(map.begin(), map.end(), pred) };

    if (found == map.end()) {
      map.emplace_back(name, 'F');
      return map.back().grade;
    }

    return found->grade;
  }
};

int main() {
  GradeMap grades{};

  grades["Joe"] = 'A';
  grades["Frank"] = 'B';

  std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
  std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

  return 0;
}
