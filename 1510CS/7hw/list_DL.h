// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This is the file to include in your code if you want access to the
// complete DList template class

// First, get the declaration for the base list class
#include "list.h"

// This is the declaration for DList.
// double-liked nodes
template <typename E>
class DList: public List<E>{
private:
  Node<E> *head;       // Pointer to list header
  Node<E> *tail;       // Pointer to list tailer
  Node<E> *curr;       // Pointer ahead of current element
  int cnt;           // Size of list

  // Intialization helper method
  void init(){
    curr = head = new Node<E>;
    head->next = tail = new Node<E>(head, NULL);
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
  DList(int size=defaultSize){
    init();
  }

  // Destructor
  ~DList(){
    removeall();
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
    curr = tail->prev;
  }

  // Move curr one step right; no change if already at end
  void next(){
    if(curr != tail->prev){
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
    if(curr->next == tail){
      return NULL;
    }
    return curr->next->element;
  }

  // Below are those  methods that are significantly different from singly-liked list:
  // Move curr one step left; no change if already at front
  void prev(){
    if(curr != head){ // check we're not at the front
      curr = curr->prev;
    }
  }

  // Insert "it" after current position pointer
  void insert(const E& it){
    curr->next = curr->next->prev = new Node<E>(it, curr, curr->next);
    cnt++;
  }

  // Append "it" to the end of the list.
  void append(const E& it){
    tail->prev = tail->prev->next = new Node<E>(it, tail->prev, tail);
    cnt++;
  }

  // Remove and return current element
  E remove(){
    if(curr->next == tail){       // Nothing to remove
      return NULL;
    }
    E it = curr->next->element;    // Remember value
    Node<E>* ltemp = curr->next;   // Remember Node node
    curr->next->next->prev = curr;
    curr->next = curr->next->next;   // Remove curr from list
    delete ltemp;                    // Reclaim space
    cnt--;			     // Decrement the count

    return it;
  }
};
