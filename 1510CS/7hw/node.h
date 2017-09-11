// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Singly linked list node
template <typename E>
class Node{
public: // Encapsulation?? Node is a private member of the Linked List class
  E element;      // Value for this node
  std::string key;
  Node *next;        // Pointer to next node in list

  // Constructor with value and optional pointer
  Node(const E &elemval, const std::string keyval, Node *nextval = NULL){
    element = elemval;
    key = keyval;
    next = nextval;
  }

  // Constructor with no initial element value and optional pointer
  Node(Node *nextval = NULL){
    next = nextval;
  }

  ~Node(){
    next = NULL;
  }

  template <typename U>
  friend std::ostream& operator<< (std::ostream& out, const Node<U>& node);
};

template <typename E>
std::ostream& operator<< (std::ostream& out, const Node<E>& node){
    out << node.key << ", " << node.element;
    return out;
  }
