// Name: Joseph Kuhn
// Section: B

#ifndef MYBSTree_H
#define MYBSTree_H

#include <algorithm>

#include "abstractbstree.h"

template <typename T>
class BSTNode
{
public:
  T m_data;
  BSTNode *m_right;
  BSTNode *m_left;

  BSTNode(const T& x, BSTNode* r = NULL, BSTNode* l = NULL)
  {
    m_data = x;
    m_right = r;
    m_left = l;
  }

  ~BSTNode()
  {
    m_right = NULL;
    m_left = NULL;
  }

};

template <typename T>
class MyBSTree: public AbstractBSTree<T> {
private:
  BSTNode<T> *m_root;
  int m_size;

  void clearHelp(BSTNode<T>* &t)
  {
    if (t == NULL)
      return;
    clearHelp(t->m_left);
    clearHelp(t->m_right);
    delete t;
    t = NULL;
  }

  int heightHelp(BSTNode<T> *t) const
  {
    if (t == NULL)
      return 0;
    return (1 + max(heightHelp(t->m_left), heightHelp(t->m_right)));
  }

  const BSTNode<T> *getMaxHelp(BSTNode<T> *t) const
  {
    if (!t->m_right)
      return t;
    else
      return (getMaxHelp(t->m_right));
  }

  const BSTNode<T> *getMinHelp(BSTNode<T> *t) const
  {
    if (t->m_left == NULL)
      return t;
    else
      return getMinHelp(t->m_left);
  }

  const int findHelp(const BSTNode<T> *t, const T& x, int num = 1) const
  {
    if (t == NULL)
    {
      return (-1 * num);
    }
    if (t->m_data < x)
    {
      return (findHelp(t->m_right, x, num + 1));
    }
    else if (t->m_data > x)
    {
      return (findHelp(t->m_left, x, num + 1));
    }
    else
      return num;



  }

  BSTNode<T> * insertHelp(BSTNode<T>* t, const T& x)
  {
    if (t == NULL)
    {
      return new BSTNode<T>(x, NULL, NULL);
    }

    if (findHelp(m_root, x) > 0)
    {
      return t;
    }

    if (t->m_data > x)
      t->m_left = insertHelp(t->m_left, x);
    else if (t->m_data < x)
      t->m_right = insertHelp(t->m_right, x);
    return t;

  }

  BSTNode<T> *removeHelp(BSTNode<T> *t, const T& x)
  {

    if (t == NULL)
      return NULL;
    else if (x < t->m_data)
      t->m_left = removeHelp(t->m_left, x);
    else if (x > t->m_data)
      t->m_right = removeHelp(t->m_right, x);
    else
    {
      if (t->m_left == NULL && t->m_right == NULL)
      {
        delete t;
        t = NULL;
      }
      else if(t->m_left == NULL)
      {
        BSTNode<T> *temp = t;
        t = t->m_right;
        delete temp;
      }
      else if (t->m_right == NULL)
      {
        BSTNode<T> *temp = t;
        t = t->m_left;
        delete temp;
      }
      else
      {
        const BSTNode<T> *temp = t;
        temp = getMaxHelp(t->m_left);
        t->m_data = temp->m_data;
        t->m_left = removeHelp(t->m_left, temp->m_data);
      }
    }
    return t;
  }

  BSTNode<T> *deleteMin(BSTNode<T> *t)
  {
    if (!t->m_left)
    {
      return t->m_right;
    }
    else
    {
      t->m_left = deleteMin(t->m_left);
      return t;
    }
  }


public:

  MyBSTree<T>()
  {
    m_root = NULL;
    m_size = 0;
  }

  MyBSTree<T>(const MyBSTree<T> &rhs)
  {
    copyHelper(rhs.m_root, m_root);
    m_size = rhs.m_size;
  }

  BSTNode<T>& operator=(const MyBSTree<T> &rhs)
  {
    copyHelper(rhs.m_root, m_root);
    m_size = rhs.m_size;
  }

  ~MyBSTree<T>()
  {
    clearHelp(m_root);
  }

  void copyHelper(BSTNode<T>* t1, BSTNode<T>* &t2)
  {
    if (t1 == NULL)
      t2 = NULL;
    else{
      t2 = new BSTNode<T>(t1->m_data);
      copyHelper(t1->m_left, t2->m_left);
      copyHelper(t1->m_right, t2->m_right);
    }
  }

  int size() const
  {
    return m_size;
  }

  bool isEmpty() const
  {
    if (m_size == 0)
      return true;
    return false;
  }

  int height() const
  {
     return heightHelp(m_root);
  }

  const T& getMax() const throw(Oops)
  {
    if (isEmpty())
      throw(Oops("OOPS! : Tree is Empty!!"));
    return getMaxHelp(m_root)->m_data;
  }

  const T& getMin() const throw(Oops)
  {
    if (isEmpty())
      throw(Oops("OOPS! : Tree is Empty!!"));
    return getMinHelp(m_root)->m_data;
  }

  int find(const T& x) const
  {
    return findHelp(m_root, x);
  }

  void clear()
  {
    clearHelp(m_root);
    m_size = 0;
  }

  void insert(const T& x)
  {
    m_root = insertHelp(m_root, x);
    m_size++;
  }

  void remove(const T &x)
  {
    int temp = findHelp(m_root, x);
    if (temp > 0)
    {
      m_root = removeHelp(m_root, x);
      m_size--;
    }
  }

  void preOrderHelp(BSTNode<T> *t) const
  {
    if (t != NULL)
    {
      std::cout << t->m_data << " ";
      preOrderHelp(t->m_left);
      preOrderHelp(t->m_right);
    }
  }

  void postOrderHelp(BSTNode<T>* t) const
  {
    if (t != NULL)
    {
      postOrderHelp(t->m_left);
      postOrderHelp(t->m_right);
      std::cout << t->m_data << " ";
    }
  }

  void printPreOrder()  const
  {
    preOrderHelp(m_root);

  }

  void printPostOrder() const
  {
    postOrderHelp(m_root);
  }

  void print() const
  {
     printHelp(m_root,0);
  }

  void printHelp(const BSTNode<T> *t, int pad) const
  {
    string s(pad, ' ');
    if (t == NULL)
      std::cout << std::endl;
    else{
      printHelp(t->m_right, pad+4);
      std::cout << s << t->m_data << std::endl;
      printHelp(t->m_left, pad+4);
    }

  }

};



#endif
