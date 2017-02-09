/* @file: arraylist.h
 * Definition of templated class ArrayList
 * Implementation of the List ADT
 * @C - Galaxy Express Softworks
 *
 * Version 17.1.0
 */

#include <iostream>
#include "arraylist.h"
  // Purpose: Increases size of storage array
  // Postconditions: a new array of size m_max*2 is allocated,
  //     and m_data is copied to it.
  //     m_max is set to the size of this new storage array
  template <typename T>
  void ArrayList<T>::grow()
  {
    T * tempArray;

    tempArray = new T * [m_max*2];

    for (int i = 0; i < m_size; i++)
      tempArray[i] = m_data[i];

    delete[] m_data;

    m_data = tempArray;

    m_max *= 2;

    delete tempArray;

    return;
  }


  // Purpose: Decreases size of storage array
  // Postconditions: a new array of size m_max/2 is allocated,
  //     and m_data is copied to it.
  //     m_max is set to the size of this new storage array
  template <typename T>
  void ArrayList<T>::shrink()
  {
    T * tempArray;

    tempArray = new T * [m_max/2];

    for (int i = 0; i < m_size; i++)
      tempArray[i] = m_data[i];

    delete[] m_data;

    m_data = tempArray;

    m_max /= 2;

    delete tempArray;

    return;
  }

  // Purpose: Destructor
  // Postconditions: current size and maximum size set to 0,
  //                 data deallocated and set to NULL
  template <typename T>
  ArrayList<T>::~ArrayList()
  {
    m_size = 0;
    m_max = 0;
    delete[] m_data;
    m_data = NULL;
  }

  // Purpose: Operator=, performs a deep copy of 'rhs' into 'this' ArrayList
  // Parameters: rhs : ArrayList to be copied
  // Returns: *this
  // Postconditions: rhs == this
  template <typename T>
  ArrayList<T> & ArrayList<T>::operator=(const ArrayList<T>& rhs)
  {
    for (int i = 0; i < rhs.m_size; i++)
    {
      m_data[i] = rhs.m_data[i];
    }
    m_size = rhs.m_size;
    m_max = rhs.m_max;

    return (*this);
  }

  // Purpose: Copy Constructor
  // Parameters: cpy = ArrayList to be copied
  // Postconditions: current size, maximum size, and elements same as cpy
  template <typename T>
  ArrayList<T>::ArrayList(const ArrayList<T>& cpy)
  {
    for (int i = 0; i < m_size; i++)
    {
      cpy.m_data[i] = m_data[1];
    }
    cpy.m_size = m_size;
    cpy.m_max = m_max;
  }

  // Purpose: Accessor function for the number of elements in the list
  // Returns: number of elements in the list
  template <typename T>
  int ArrayList<T>::size() const
  {
       return m_size;
  }

  // Purpose: Accessor function for the first element of the list
  // Returns: the first element in the list
  template<typename T>
  const T& ArrayList<T>::first() const
  {
    return (m_data[0]);
  }

  // Purpose: return a read-and-write reference to the element at
  // the specified position
  // Parameters: i is 0-based index into the ArrayList
  // Returns: the element at position i in the ArrayList
  template <typename T>
  T& ArrayList<T>::operator[](int i)
  {
    return (m_data[i]);
  }

  // Purpose: return a read-only reference to the element at
  // the specified position
  // Parameters: i is 0-based index into the ArrayList
  // Returns: the element at position i in the ArrayList
  template <typename T>
  const T& ArrayList<T>::operator[](int i) const
  {
    return (m_data[i]);
  }

  // Purpose: finds an element in the ArrayList
  // Parameters: 'x' is value to be found in the ArrayList
  // Returns: the position of the first occurrance of 'x' in the list,
  //          or -1  if 'x' is not found.
  template <typename T>
  int ArrayList<T>::find(const T& x) const
  {
    for (int i = 0; i < m_size; i++)
    {
      if (m_data[i] == x)
        return x;
    }
    return (-1);

  }






  // Purpose: Clears the ArrayList
  // Postconditions: current size and maximum size set to 0,
  //                 elements are deallocated and data is set to NULL
  template<typename T>
  void ArrayList<T>::clear()
  {
    m_max = 0;
    m_size = 0;
    delete[] m_data;
    delete m_data;
    m_data = NULL;
    return;
  }

  // Purpose: puts the value x at the end of an ArrayList
  // Parameters: x is value to be added to ArrayList
  // Postconditions: current size is incremented by 1
  //     If max size is reached, the storage wrray is grown.
  template <typename T>
  void ArrayList<T>::insert_back(const T& x)
  {
    m_data[m_size+1] = x;
    return;
  }

  // Purpose: puts the value x at the position i in the  ArrayList
  // Parameters: x is value to be added to ArrayList
  //             i is the position to insert x at
  // Postconditions: current size is incremented by 1
  //     If max size is reached, the storage array is grown().
  template <typename T>
  void ArrayList<T>::insert(const T& x, int i)
  {
    m_size++;
    if (m_size > m_max)
    {
      grow();
    }
    m_data[i] = x;
    return;
  }

  // Purpose: Removes the element at index i in the array
  // Parameters: i, the index of the element to remove
  // Postconditions: if the size of the list is greater than 0
  //     size is decremented by one.
  //     if the size of the list less than 1/4 the max size,
  //     the storage array is shrunk.
  template <typename T>
  void ArrayList<T>::remove(int i)
  {
    m_size--;
    if (m_size < (m_max/4))
    {
      shrink();
    }
    for (int j = m_size; j != i; j--)
    {
      m_data[j] = m_data[j-1];
    }
    return;
  }

  /*
   * ----- Complex Mutator Operations -----
   */

  // Purpose: swaps two elements of the array
  // Parameters: i, k, two positions on the Arraylist
  // Postconditions: the elements at positions i and k swap positions
  void swap(int i, int k);

  // Purpose: appends two lists
  // Parameters: alist, a list to appended to the end of 'this' list
  // Postconditions: current size is incremented by size of alist
  //     the elements of alist are appended to the elements of 'this'
  void append(const ArrayList<T>& alist);

  // Purpose: Reverses an ArrayLost
  // Postconditions: the elements in the list are now reversed.
  void reverse();


  /*
   * ----- Complex Accessors Operations -----
   */

  // Purpose: prints the ArrayList
  friend std::ostream& operator<< <> (std::ostream& out,
                                      const ArrayList<T>& alist);
};



// BONUS, BONUS, BONUS !!!
// This is the function to pretty print the lists
// -----------------  Friend Function to Print  -----------------
// Purpose: prints an ArrayList
template <typename T>
std::ostream& operator<< (std::ostream& out, const ArrayList<T>& alist)
{
  out << "[ ";
  for (int i=0; i < alist.m_size; i++){
    out << alist.m_data[i] << ", ";
  }
  out << "]";
  return out;
}
