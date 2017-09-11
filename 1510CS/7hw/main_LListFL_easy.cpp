// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Main program for the singly-linked list class with freelist

// Include the supplementary classes
#include "book.h"
#include "compare.h"

// Include the node template class
#include "node_FL.h"

// Include the list class
#include "list_L.h"

// Generic list test commands
#include "ListTest.h"

// Main routine
int main(){
  LList<double> listOfDoubles;
  listOfDoubles.append(1.0);
  lprint(listOfDoubles);

  listOfDoubles.append(4.0);
  listOfDoubles.append(3.0);
  listOfDoubles.append(2.0);
  lprint(listOfDoubles);

  listOfDoubles.moveToPos(2.0);
  lprint(listOfDoubles);

  listOfDoubles.insert(9.0);
  lprint(listOfDoubles);

  double x = listOfDoubles.remove();
  lprint(listOfDoubles);
  cout << x << endl;

  double current = listOfDoubles.currPos();
  lprint(listOfDoubles);
  cout << current << endl;

  return 0;
}
