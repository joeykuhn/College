// From the software distribution accompanying the textbook
// "A Practical introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Original program for testing the Binary Search Tree (BST) implementation
// which was a dictionary, and thus can be used with the hash table

#include "book.h"
#include "hashdict.h"

int main()
{
  // can make value a non-pointer, but the NULL checks break
  hashdict<int, string*> intDict(1000, -1, -2);

  intDict.insert(700, new string("Lettuce"));
  intDict.insert(350, new string("Apple"));
  intDict.insert(201, new string("Orange"));
  intDict.insert(170, new string("Starfruit"));
  intDict.insert(151, new string("Beet"));
  intDict.insert(190, new string("Radish"));
  intDict.insert(1000, new string("Cucumber"));
  intDict.insert(900, new string("Kale"));
  intDict.insert(950, new string("Rutabaga"));
  intDict.insert(10, new string("Pumpkin"));
  intDict.insert(300, new string("Carrot"));

  cout << "intDict size is: " << intDict.size() << endl;
  cout << endl;

  cout << "find 10: " << *(intDict.find(10)) << endl;

  intDict.insert(130, new string("Papaya"));
  cout << "intDict size is: " << intDict.size() << endl;

  return 0;
}
