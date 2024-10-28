#include "assignment_1/ex1_1.cpp"
#include "assignment_1/ex1_2.cpp"
#include "assignment_1/ex1_3.cpp"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  std::vector<int> grades = {2, 4, 6, 8, 10};
  std::vector<int> newGrades(grades.size());

  std::transform(grades.cbegin(), grades.cend(), grades.begin(),
                 [](int x) { return x * x; });

  for (int grade : grades) {
    std::cout << grade << " ";
  }
}
