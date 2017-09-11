// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Singly linked list node with freelist support
template <typename E>
class Node{
private:
  static Node<E> *freelist; // Reference to freelist head

public: // Encapsulation?? Node is a private member of the Linked List class
  E element;      // Value for this node
  Node *next;        // Pointer to next node in list

  // Constructor with value and optional pointer
  Node(const E &elemval, Node *nextval = NULL){
    element = elemval;
    next = nextval;
  }

  // Constructor with no initial element value and optional pointer
  Node(Node *nextval = NULL){
    next = nextval;
  }

  // Overloaded new operator -- new MUST RETURN VOID*
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
