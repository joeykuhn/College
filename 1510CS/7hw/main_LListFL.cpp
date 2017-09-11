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
int main(int argc, char **argv){
  // Declare some sample lists
  LList<Int*> L1;
  LList<Int*> L2(15);
  LList<Int> L3;

  ListTest<Int*, Int, LList<int> >(L1, L2, L3);
  return 0;
}
