#include <iostream>
#include "mystringmap.h"

int main()
{
  MyStringMap<int> a;

  a.insert("a", 0);

  a.insert("c", 3);

  a.insert("d", 4);

  a.insert("e", 5);

  a.insert("f", 6);

  a.insert("a", 0);

  std::cout << "a? " << a.valueOf("a") << std::endl;



  a.print();

  a.remove("f");

  a.print();

  return 0;
}
