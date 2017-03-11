#include "myStack.h"
#include <sstream>
#include <cstdlib>

int calculate(const int x, const int y, const char& z);
bool compareParens(const char x, const char y);

int main()
{
  string s,t = "";

  Stack<int> intStack;
  Stack<char> operStack;
  Stack<char> brackStack;

  int numRuns = 1;

  while(true)
  {
    getline(cin, s);
    if (s == ".")
    {
      break;
    }
    istringstream inputstr(s);

    for (int i = 0; i < (s.length()/2)+1; i++)
    {
      inputstr >> t;
      if (t == "}" || t == ")" || t == "]")
      {
        t = t.c_str();
        if (compareParens(brackStack.top(), t[0]))
        {
          int k = intStack.top();
          intStack.pop();
          int j = intStack.top();
          intStack.pop();
          intStack.push(calculate(j, k, operStack.top()));
          operStack.pop();
          brackStack.pop();
        }

      }

      else if (t == "{" || t == "(" || t == "[")
      {
        std::cout << "t is " << t << "and in brackstack" << std::endl;
        t = t.c_str();
        brackStack.push(t[0]);
      }
      else if(t == "+" || t == "-" || t == "*" || t == "/" || t == "%")
      {
        std::cout << "t is " << t << "and in operstack" << std::endl;
        t = t.c_str();
        operStack.push(t[0]);
      }
      else
      {
        std::cout << "t is " << t << "and in intstack" << std::endl;

        intStack.push(atoi(t.c_str()));
      }
    }
    if (operStack.isEmpty() && brackStack.isEmpty())
    {
      std::cout << "#" << numRuns << " : " << intStack.top() << std::endl;
      numRuns++;
    }
    else
    {
      std::cout << "#" << numRuns << " : INVALID!" << std::endl;
    }
    intStack.clear();
    operStack.clear();
    brackStack.clear();

  }

  return 0;
}

int calculate(const int x, const int y, const char& z)
{
  switch (z)
  {
    case '+':
        std::cout << "+calculated " << (x+y) << std::endl;
        return (x+y);
    case '-':
        std::cout << "-calculated " << (x-y) << std::endl;
        return (x-y);
    case '*':
        std::cout << "*calculated " << (x*y) << std::endl;
        return (x*y);
    case '/':
        std::cout << "/calculated " << (x/y) << std::endl;
        return (x/y);
    case '%':
        std::cout << "%calculated " << (x%y) << std::endl;
        return (x%y);
  }
}

bool compareParens(const char x, const char y)
{
  if (x == '{' && y == '}')
    return true;
  else if (x == '(' && y == ')')
    return true;
  else if (x == '[' && y == ']')
    return true;
  else
    return false;
}
