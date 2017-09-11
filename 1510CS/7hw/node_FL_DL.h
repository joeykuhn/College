// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Doubly-linked list Node node with freelist support
template <typename E>
class Node{
private:
  static Node<E> *freelist; // Reference to freelist head

public: // Encapsulation?? Node is a private member of the Linked List class
  E element;      // Value for this node
  Node *next;        // Pointer to next node in list
  Node *prev;         // Pointer to previous node

  // Constructor with value and pointers
  Node(const E &elemval, Node *prevp, Node *nextp){
    element = elemval;
    prev = prevp;
    next = nextp;
  }

  // Constructor with no initial element value and optional pointers
  Node(Node *prevp = NULL, Node *nextp = NULL){
    prev = prevp;
    next = nextp;
  }

  // Overloaded new operator
  void * operator new(size_t){
    if(freelist == NULL){ // Create space
      return ::new Node;
    }

    Node<E> *temp = freelist; // Can grab front of freelist, but freelist is still hanging on
    freelist = freelist->next; // Set new front of freelist to be old second, cutting the freelist free
    return temp;                 // Return the Node
  }

  // Overloaded delete operator
  void operator delete(void *ptr){
    ((Node<E>*)ptr)->next = freelist; // Assign freelist pointer to the node being deleted
    freelist = (Node<E>*)ptr; // Add the old freelist to the node being deleted now at the start of the freelist
  }
};

// The freelist head pointer is actually created here, why?
template <typename E>
Node<E> *Node<E>::freelist = NULL;
