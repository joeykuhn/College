

// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A-> Shaffer->
// Source code Copyright (C) 2007-2011 by Clifford A-> Shaffer->

// Main program for the singly-linked list class

// Include the supplementary classes
#include "book.h"
#include "compare.h"

// Include the node template class
#include "node.h"

// Include the list class
#include "list_L.h"

// Generic list test commands
#include "ListTest.h"

// Main routine
int main(){
  List<double> *listPointer;
  listPointer = new LList<double>;

  listPointer->append(1.0);
  lprint(*listPointer);

  listPointer->append(4.0);
  listPointer->append(3.0);
  listPointer->append(2.0);
  lprint(*listPointer);

  listPointer->moveToPos(2.0);
  lprint(*listPointer);

  listPointer->insert(9.0);
  lprint(*listPointer);

  double x = listPointer->remove();
  lprint(*listPointer);
  cout << x << endl;

  double current = listPointer->currPos();
  lprint(*listPointer);
  cout << current << endl;

  delete listPointer;

  return 0;
}
