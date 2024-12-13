#include <iostream>

#include "String.h"

/*
--- ASSIGNMENT 4 ---
6. Write a main function to test your String class.
Create multiple String objects and demonstrate their independence using
the copy constructor and modification of individual characters.
*/

int main() {
  const String s1("Hello"); // string obj1
  String s2("World");       // string obj2
  String s3("Bona sera!");  // string obj3
                            //

  // display how the instantiated objects look like before alteration (the data
  // they currently hold)
  std::cout << "Before assignment:\n";
  std::cout << "s1: ";
  s1.display();
  std::cout << "\ns2: ";
  s2.display();
  std::cout << "\ns3: ";
  s3.display();

  // modify/reassign the objects (copy constructor)
  s3 = s2;
  s2 = s1;

  // display how the instantiated objects look like after alteration (new data)
  std::cout << "\n\nAfter assignment:\n";
  std::cout << "s1: ";
  s1.display();
  std::cout << "\ns2: ";
  s2.display();
  std::cout << "\ns3: ";
  s3.display();

  // append character 'k' at position 2 in object 3 (s3)
  std::cout << "\n\nAfter appending character 'k' at position 2 in s3:";
  s3.appendChar('k', 2);
  std::cout << "\ns3: ";
  s3.display();

  return 0;
}
