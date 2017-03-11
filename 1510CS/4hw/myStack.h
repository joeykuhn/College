#include <iostream>
#include "abstractstack.h"

template <typename T>
class Stack : public AbstractStack<T> {
private:
  int m_max;
  int m_top;
  T* m_data;

public:
  Stack();
  bool isEmpty() const;
  const T& top() const throw ( Oops );
  void push(const T& x);
  void pop();
  void clear();
  ~Stack();
  void grow();

};

template <typename T>
Stack<T>::Stack()
{
  m_max = 1;
  m_top = 0;
  m_data = new T[1];
}

template <typename T>
bool Stack<T>::isEmpty() const
{
  if (m_top == 0)
  {
    return true;
  }
  return false;
}

template <typename T>
const T& Stack<T>::top() const throw ( Oops )
{
   if (m_top < 0)
   {
     throw (Oops("Tried to look at top while stack is empty"));
   }
 return (m_data[m_top-1]);
}

template <typename T>
void Stack<T>::push(const T& x)
{
  if (m_top == m_max)
  {
    grow();
  }
  m_data[m_top++] = x;
}

template <typename T>
void Stack<T>::pop()
{
  if (m_top == 0)
    return;
  m_top--;
  return;
}

template <typename T>
void Stack<T>::clear()
{
  delete[] m_data;
  m_max = 1;
  m_top = 0;
  m_data = new T [1];
}

template <typename T>
Stack<T>::~Stack()
{
  m_top = 0;
  m_max = 0;
  delete[] m_data;
  m_data = NULL;
}

template <typename T>
void Stack<T>::grow()
{
  T* tempArray;

  tempArray = new T [m_max*2];
  for (int i = 0; i < m_top+1; i++)
  {
    tempArray[i] = m_data[i];
  }
  delete[] m_data;
  m_data = tempArray;
  m_max *= 2;
  tempArray = NULL;

  return;
}
