// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test program for checking syntax of a hash table-based dictionary

#include "book.h"
#include "hashdict.h"

int main(){

  // Hash table with int keys and values as pointers to int
  hashdict<int, int*> intDict(1000, -1, -2);
  int* val;

  intDict.insert(10, new int(10));
  intDict.insert(11, new int(20));
  intDict.insert(8898, new int(5216));

  if((val = intDict.find(10)) != NULL)
    cout << "Found value " << *val << " to match key value 10" << endl;
  else
    cout << "Nothing found to match key value 10" << endl;

  // Hash table with int keys and values as pointers to char
  hashdict<char*, char*> strDict(1000, "", "TOMB");
  char* str;

  strDict.insert("Name1", "Address1");
  strDict.insert("Name2", "Address2");
  strDict.insert("Name3000", "Address3000");
  //strDict.remove("Name3000");

  if((str = strDict.find("Name3000")) != NULL)
    cout << "Found value " << str << " to match key value Name2" << endl;
  else
    cout << "Nothing found to match key value hello" << endl;
}
