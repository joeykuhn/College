// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Main program for the doubly-linked list class

// Include the supplementary classes
#include "book.h"
#include "compare.h"

// Include the node template class
#include "node_FL_DL.h"

// Include the list class
#include "list_DL.h"

// Generic list test commands
#include "ListTest.h"

// Main routine
int main(int argc, char **argv){
  // Declare some sample lists
  DList<Int*> L1;
  DList<Int*> L2(15);
  DList<Int> L3;

  ListTest<Int*, Int, DList<int> >(L1, L2, L3);
  return 0;
}
