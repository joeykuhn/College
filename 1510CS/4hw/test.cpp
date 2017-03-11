#include <iostream>
#include "myStack.h"

int main()
{
  Stack<int> a;
  std::cout << "pushing 5" << std::endl;
  a.push(5);
  std::cout << "pushing 3" << std::endl;
  a.push(3);
  std::cout << "pushing 1" << std::endl;
  a.push(1);
  std::cout << "top is " << a.top() << std::endl;
  a.pop();
  std::cout << "top is " << a.top() << std::endl;
  a.pop();
  std::cout << "top is " << a.top() << std::endl;

  return 0;
}
