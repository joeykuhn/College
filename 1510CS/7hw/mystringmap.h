#ifndef MY_STRING_MAP_H
#define MY_STRING_MAP_H

#include "abstractstringmap.h"
#include "node.h"

const int PRIME = 13;

template <typename T>
class MyStringMap : public AbstractStringMap<T> {
public:

  MyStringMap(){
    m_size = 0;
    m_tableSize = 1;
    m_max = 4;
    m_table = new Node<T>*[4];
    for (int i = 0; i < 4; i++)
    {
      m_table[i] = NULL;
    }
  }

  ~MyStringMap(){
    clear();
    for (int i = 0; i < m_max; i++){
      delete m_table[i];
    }
    delete[] m_table;
    m_table = NULL;
  }



  int size() const;
  bool isEmpty() const;
  const T& valueOf(const string& key) const throw (Oops);
  void clear();
  void clearHelp(Node<T>* &t);
  void insert(const string& key, const T& val);
  void remove(const string& k);
  void print() const;
  void grow();


private:
  int hash(const string &s) const;
  int m_size;
  int m_max;
  int m_tableSize;
  Node<T> **m_table;

};

template <typename T>
int MyStringMap<T>::size() const{
  return m_size;
}
template <typename T>
bool MyStringMap<T>::isEmpty() const{
  if (m_size == 0)
    return true;
  return false;
}

template <typename T>
const T& MyStringMap<T>::valueOf(const string& key) const throw(Oops){
  int pos = hash(key) % m_max;
  Node<T> *temp = m_table[pos];
  while (temp != NULL && temp->key != key){
    temp = temp->next;
  }
  if (temp != NULL && temp->key == key){
    return temp->element;
  }
  else{
    throw Oops("Key Not Found!!");
  }
}

template <typename T>
void MyStringMap<T>::clear(){
  for (int i = 0; i < m_max; i++){
     if (m_table[i] != NULL){
      clearHelp(m_table[i]);
    }
  }
}

template <typename T>
void MyStringMap<T>::insert(const string& key, const T& val){
  Node<T> *n = new Node<T>;
  n->key = key;
  n->element = val;
  n->next = NULL;
  if (m_max == m_size){
    grow();
  }
  int pos = hash(key) % m_max;
  if (m_table[pos] == NULL){
    m_table[pos] = n;
    m_tableSize++;
    m_size++;
  }
  else{
    Node<T> *temp = m_table[pos];
    while (temp->next != NULL)
    {
      if (temp->key == key)
      {
        temp->element = val;
        delete n;
        return;
      }
      temp = temp->next;
    }
    if (temp->key == key)
    {
      temp->element = val;
      delete n;
      return;
    }
    temp->next = n;
    m_size++;
  }
  n = NULL;
}

template <typename T>
void MyStringMap<T>::remove(const string& k){
  int pos = hash(k) % m_max;
  if (m_table[pos] == NULL){
    return;
  }
  else if (m_table[pos]->next == NULL && m_table[pos]->key == k){
    delete m_table[pos];
    m_table[pos] = NULL;
    return;
  }
  Node<T> *temp1;
  Node<T> *temp2;
  temp2 = m_table[pos];
  temp1->next = temp2;
  while (temp2 != NULL && temp2->key != k){
    temp2 = temp2->next;
    temp1->next = temp2;
  }
  if (temp2->key == k)
  {
    temp1->next = temp2->next;
    if (temp2 == m_table[pos]){
      m_table[pos] = m_table[pos]->next;
    }
    delete temp2;
    return;
  }
}

template <typename T>
void MyStringMap<T>::print() const{
  for (int i = 0; i < m_max; i++){
    for (Node<T> *temp = m_table[i]; temp != NULL; temp = temp->next){
        std::cout << "< " << temp->key << ", " << temp->element << " >" << std::endl;
    }
  }
}

template <typename T>
int MyStringMap<T>::hash(const string &s) const{
  int total = 0;
  for (unsigned int i = 0; i < s.length(); i++)
  {
    total += s[i];
    total * PRIME;
  }

  return total;
}

template <typename T>
void MyStringMap<T>::grow(){
  Node<T> **tempArray;
  m_max *= 2;
  tempArray = new Node<T>*[m_max];

  for (int i = 0; i < m_max; i++){
    tempArray[i] = NULL;
  }
  for (int i = 0; i < m_max/2; i++){
    for (Node<T> *temp = m_table[i]; temp != NULL; temp = temp->next){
      int pos = hash(temp->key) % m_max;
      Node<T> *n = new Node<T>;
      n->key = temp->key;
      n->element = temp->element;
      n->next = NULL;
      if (tempArray[pos] == NULL){
        tempArray[pos] = n;
      }
      else{
          Node<T>* tempA = tempArray[pos];
          while (tempA->next != NULL){
            tempA = tempA->next;
          }
          tempA->next = n;
      }
    }
  }
  for (int i = 0; i < m_max/2; i++)
  {
    if (m_table[i] != NULL)
    {
      clearHelp(m_table[i]);
    }
  }
  delete[] m_table;
  m_table = tempArray;

  tempArray = NULL;
}

template <typename T>
void MyStringMap<T>::clearHelp(Node<T>* &t){
  if (t->next != NULL)
  {
    clearHelp(t->next);
  }
  delete t;
  t = NULL;
}

#endif /* end of include guard: MY_STRING_MAP_H */
