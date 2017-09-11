/*
Programmer: Joey Kuhn
Teacher: Patrick Taylor
Date: 02/10/2017
*/

#include <iostream>

  template <typename T>
  void ArrayList<T>::grow()
  {
    T *tempArray;
    if (m_max == 0)
    {
      m_max++;
    }
    m_max *= 2;
    tempArray = new T  [m_max];
    for (int i = 0; i < m_max; i++)
    {
      std::cout << "set " << i << " to null" << std::endl;
      tempArray[i] = NULL;
    }
    if (m_size != 0){
      for (int i = 0; i < m_max/2; i++)
      {
        tempArray[i] = m_data[i];
      }
    }

    delete[] m_data;

    m_data = tempArray;

    tempArray = NULL;
    
    return;
  }

  template <typename T>
  void ArrayList<T>::shrink()
  {
    T *tempArray;

    tempArray = new T [m_max/2];

    for (int i = 0; i < m_size; i++)
      tempArray[i] = m_data[i];

    delete[] m_data;

    m_data = tempArray;

    m_max /= 2;

    tempArray = NULL;

    return;
  }

  template <typename T>
  ArrayList<T>::~ArrayList()
  {
    m_size = 0;
    m_max = 0;
    delete[] m_data;
    m_data = NULL;
  }

  template <typename T>
  ArrayList<T> & ArrayList<T>::operator=(const ArrayList<T>& rhs)
  {
    m_size = rhs.m_size;
    m_max = rhs.m_max;
    m_data = new T [rhs.m_max];
    for (int i = 0; i < rhs.m_size; i++)
    {
      m_data[i] = rhs.m_data[i];
    }

    return (*this);
  }

  template <typename T>
  ArrayList<T>::ArrayList(const ArrayList<T>& cpy)
  {
    m_data = new T [cpy.max()];
    for (int i = 0; i < cpy.size(); i++)
    {
      m_data[i] = cpy.m_data[i];
    }
    m_size = cpy.size();
    m_max = cpy.max();
  }

  template <typename T>
  int ArrayList<T>::size() const
  {
       return m_size;
  }

  template<typename T>
  const T& ArrayList<T>::first() const
  {

    if (m_size == 0)
      return m_errobj;

    return (m_data[0]);
  }

  template <typename T>
  T& ArrayList<T>::operator[](int i)
  {
    if (i > m_max)
      std::cout << "!-- ERROR : PANIC in ARRAYLIST!!.[]  (index out of bounds)" << std::endl;
      return m_errobj;
    std::cout << "bracket: " << i << std::endl;
    return (m_data[i]);
  }

  template <typename T>
  const T& ArrayList<T>::operator[](int i) const
  {
    return (m_data[i]);
  }

  template <typename T>
  int ArrayList<T>::find(const T& x) const
  {
    for (int i = 0; i < m_size; i++)
    {
      if (m_data[i] == x)
        return i;
    }
    return (-1);

  }

  template<typename T>
  void ArrayList<T>::clear()
  {
    m_max = 0;
    m_size = 0;
    delete[] m_data;
    m_data = NULL;
    return;
  }


  template <typename T>
  void ArrayList<T>::insert(const T& x, int i)
  {
    std::cout << "size of array: " << m_size << std::endl << "max of array: " << m_max << std::endl;
    if (m_size == m_max)
    {
      grow();
    }
    std::cout << "size of array: " << m_size << std::endl << "max of array: " << m_max << std::endl;
    if ( i > m_max)
    {
      std::cout << "!-- ERROR : PANIC in ARRAYLIST!!.insert()  (index out of bounds)" << std::endl;
      return;
    }

    for (int j = (m_size - 1); j >= i; j--)
    {
      m_data[j+1] = m_data[j];
    }
    m_data[i] = x;
    m_size++;
    return;
  }

  template <typename T>
  void ArrayList<T>::remove(int i)
  {
    if (i > m_size)
    {
      std::cout <<  "!-- ERROR : PANIC in ARRAYLIST!!.remove()  (index out of bounds)" << std::endl;
    }
    if (m_size < (m_max/4))
    {
      shrink();
    }
    for (int j = i; j < (m_size); j++)
    {
      m_data[j] = m_data[j+1];
    }

    m_size--;
    return;
  }
