// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This is the file to include in your code if you want access to the
// complete AList template class

// First, get the declaration for the base list class

#include "list.h"

// This is the declaration for AList.
// Array-based list implementation
template <typename E>
class AList : public List<E>{
private:
  int maxSize;        // Maximum size of list
  int listSize;       // Actual number of list items now
  int curr;           // Position of current element
  E *listArray;    // Array holding list elements

public:
  // Constructor
  AList(int size=4){
    maxSize = size;
    listSize = curr = 0;
    listArray = new E[maxSize]; // user can specify size
  }

  // Destructor
  ~AList(){
    delete[] listArray;
  }

  // Reinitialize the list
  void clear(){
    delete[] listArray;            // Remove the array
    listSize = curr = 0;            // Reset the size
    listArray = new E[maxSize];  // Recreate array
  }

  // Insert "it" at current position -- remember image?
  void insert(const E& it)
  {

    for(int i=listSize; i>curr; i--){ // Shift elements up
      listArray[i] = listArray[i-1];  //   to make room
    }

    listArray[curr] = it;
    listSize++;                       // Increment list size
  }

  /** How many steps does it take to insert for lists
  of size: 1,2,3,4,5,6,... ? At head? Near tail? On average?
  */

  // Append "it" to end of list
  void append(const E& it){
    listArray[listSize++] = it; // two in one!
  }

  /** How many steps does it take to append for lists
  of size: 1,2,3,4,5,6,... ?
  */

  // Remove and return the current element.
  E remove(){
    E it = listArray[curr];           // Copy the element

    for(int i=curr; i<listSize-1; i++){  // Shift them down
      listArray[i] = listArray[i+1];
    }

    listSize--;                          // Decrement size
    return it;
  }

  /** How many steps does it take to remove for lists
  of size: 1,2,3,4,5,6,... ? At head? Near tail? On average?
  */

  // Reset position
  void moveToStart(){
    curr = 0;
  }

  // Set current to end
  void moveToEnd(){
    curr = listSize;
  }

  // Back up
  void prev(){
    if(curr != 0){
      curr--;
    }
  }

  // Next
  void next(){
    if(curr < listSize){
      curr++;
    }
  }

  // Return list size
  int length() const{
    return listSize;
  }

  // Return current position
  int currPos() const{
    return curr;
  }

    /** How many steps do the above take for lists
  of size: 1,2,3,4,5,6,...? Near head? Near tail? On average?
  */

  // Set current list position to "pos"
  void moveToPos(int pos){
    curr = pos;
  }

  // Return current element
  const E& getValue() const{
    return listArray[curr];
  }

  /** Can we combine these last two for anything useful? */
};
