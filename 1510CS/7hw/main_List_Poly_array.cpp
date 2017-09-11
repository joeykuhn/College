

// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A-> Shaffer->
// Source code Copyright (C) 2007-2011 by Clifford A-> Shaffer->

// Main program for the singly-linked list class

// Include the supplementary classes
#include "book.h"
#include "compare.h"

// Include the node template class
#include "node_FL.h"

// Include the list class
#include "list_L.h"
#include "list_A.h"

// Generic list test commands
#include "ListTest.h"

// Main routine
int main(){
  List<double> *listOfLists[2];
  listOfLists[0] = new LList<double>;
  listOfLists[1] = new AList<double>;

  for(int i=0; i < 2; i++)
  {
    cout << "Version: " << i+1 << endl;
    listOfLists[i]->append(1.0);
    lprint(*listOfLists[i]);

    listOfLists[i]->append(4.0);
    listOfLists[i]->append(3.0);
    listOfLists[i]->append(2.0);
    lprint(*listOfLists[i]);

    listOfLists[i]->moveToPos(2.0);
    lprint(*listOfLists[i]);

    listOfLists[i]->insert(9.0);
    lprint(*listOfLists[i]);

    double x = listOfLists[i]->remove();
    lprint(*listOfLists[i]);
    cout << endl;
  }

  return 0;
}
