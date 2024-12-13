#include "ulib/string.h"
#include <iostream>

int main() {
  char name[] = "George";
  auto cstr = ulib::string(name);
  std::cout << "char[] ctor: " << cstr << std::endl;

  std::string name1 = "Mihai";
  auto str = ulib::string(name);
  std::cout << "std::string ctor: " << name1 << std::endl;

  auto cstr2 = ulib::string(new char[]{"Andrei"});
  std::cout << "Assigning cstr2 = cstr --> Result: ";
  cstr = cstr2;
  std::cout << cstr << " = " << cstr2 << std::endl;

  auto myword = ulib::string("Germany");

  try {
    std::cout << myword[1] << std::endl;
  } catch (const std::out_of_range &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    myword[1] = 'b';
    std::cout << myword.c_str() << std::endl; // should print Gbermany, we replace myword[1] above
    myword[10]; // should print index out of range
    std::cout << std::endl;
  } catch (const std::out_of_range &e) {
    std::cerr << e.what() << std::endl;
  }

  ulib::string s1(new char[]{"Ion"});
  ulib::string s2(new char[]{"Travolta"});
  ulib::string s3 = ulib::string("Ion");

  s1 += s3;
  std::cout << "S1: " << s1 << " S3: " << s3 << std::endl;
  std::cout << (s1 > s3); // should print 1 (true)
}
