#include <iostream>
#include <string>
#include "myLib.h"

class Counter
{
public:
  Counter(int num)
  {
    this->_counter = num;
  };

  std::string yell();

  void increment()
  {

    this->_counter++;
  }

  int getCount()
  {
    return this->_counter;
  }

private:
  int _counter;
};

int main()
{
  int a = 2;
  for (int i = 0; i < 10; i++)
  {
    a++;
    std::cout << a << std::endl;
  }
  drawLine();
  saySomething();
  drawLine();

  Counter countee(0);
  countee.increment();
  std::cout << countee.getCount() << std::endl;

  std::cout << countee.yell();

  return 0;
}

std::string Counter::yell()
{
  return "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
};
