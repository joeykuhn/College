// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This is the file to include in your code if you want access to the
// complete LList template class

// First, get the declaration for the base list class
#include "list.h"

// This is the declaration for LList.
// Nodeed list implementation
template <typename E>
class LList: public List<E>{
private:
  Node<E> *head;       // Pointer to list header
  Node<E> *tail;       // Pointer to last element
  Node<E> *curr;       // Pointer ahead of current element
  int cnt;           // Size of list

  // Intialization helper method
  void init(){
    curr = tail = head = new Node<E>;
    cnt = 0;
  }

  // Remove all nodes
  void removeall(){
    while(head != NULL){
      curr = head;
      head = head->next;
      delete curr;
    }
  }

public:
  // Constructor
  LList(int size=defaultSize){
    init();
  }

  // Destructor
  ~LList(){
    removeall();
    cout << "derived destructor called" << endl;
  }

  // Clear list
  void clear(){
    removeall();
    init();
  }

  // Place curr at list start
  void moveToStart(){
    curr = head;
  }

  // Place curr at list end
  void moveToEnd(){
    curr = tail;
  }

  // Move curr one step right; no change if already at end
  void next(){
    if(curr != tail){
      curr = curr->next;
    }
  }

  // Return length
  int length() const{
    return cnt;
  }

  // Return the position of the current element
  int currPos() const{
    Node<E> *temp = head;
    int i;

    for (i=0; curr != temp; i++){
      temp = temp->next;
    }

    // Works the same:
    //for (i=0; curr != temp; temp = temp->next){
    //  i++;
    //}

    return i;
  } /** Can we make this more efficient? */

  // Move toward end of list to "pos" position
  void moveToPos(int pos){
    Assert((pos>=0)&&(pos<=cnt), "Position out of range");
    curr = head;

    for(int i=0; i<pos; i++){
      curr = curr->next;
    }
  } /** Can we make moveToPos more efficient? */

  // Return current element
  const E& getValue() const{
    Assert(curr->next != NULL, "No value");
    return curr->next->element;
  }

  // Move curr one step left; no change if already at front
  void prev(){
    if(curr == head){ // check we're not at the front
      return;
    }
    Node<E>* temp = head;

    // March to end of list until we find the previous element
    while (temp->next!=curr){
      temp=temp->next;
    }

    curr = temp;
  }

  // Insert "it" after current position pointer
  void insert(const E& it){
    curr->next = new Node<E>(it, curr->next);

    if(tail == curr){
      tail = curr->next;
    }  // New tail

    cnt++;
  }

  // Append "it" to the end of the list.
  void append(const E& it){
    tail = tail->next = new Node<E>(it, NULL);
    cnt++;
  }

  // Remove and return current element
  E remove(){
    Assert(curr->next != NULL, "No element");
    E it = curr->next->element;      // Remember value so we can return it
    Node<E>* ltemp = curr->next;     // Remember Node node so we can delete it

    if(tail == curr->next){ // If you're at the end, reset tail
      tail = curr;
    }

    curr->next = curr->next->next;   // Remove curr from list
    delete ltemp;                    // Reclaim space
    cnt--;			     // Decrement the count

    return it;
  }
};
