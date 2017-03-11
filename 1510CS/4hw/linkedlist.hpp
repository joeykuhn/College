template <class T>
LinkedList<T>::LinkedList()
{
  m_size = 0;
  m_head = NULL;
  m_back = NULL;
}

template <class T>
LinkedList<T>::~LinkedList()
{
  clear();
}

template <class T>
const LinkedList<T>&LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
  clear();
  if (rhs.m_head == NULL)
  {
    return (*this);
  }
  m_head = new Node<T>(rhs.m_head->m_data, NULL);
  m_back = m_head;
  Node<T> *temp = rhs.m_head->m_next;
  for (;temp != NULL;temp = temp->m_next)
  {
    insert_back(temp->m_data);
  }
  m_size = rhs.m_size;
  return (*this);
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
{
  Node<T> *temp = rhs.m_head->m_next;
  m_head = new Node<T>(rhs.m_head->m_data, NULL);
  m_back = m_head;
  while (temp != NULL)
  {
    insert_back(temp->m_data);
    temp = temp->m_next;
  }
}

template <class T>
int LinkedList<T>::size() const
{
  return (m_size);
}

template <class T>
bool LinkedList<T>::isEmpty() const
{
  if (m_head == NULL)
  {
    return true;
  }
  return false;
}

template <class T>
Node<T>* LinkedList<T>::getFirstPtr()
{
  return (m_head);
}

template <class T>
const Node<T>* LinkedList<T>::getFirstPtr() const
{
  const Node<T> *temp = m_head;
  return (temp);
}

template <typename T>
Node<T>* LinkedList<T>::getLastPtr()
{
  return (m_back);
}

template <class T>
Node<T>* LinkedList<T>::getAtPtr(int i)
{
  Node<T> *temp = m_head;
  for (int x = 0; x != i ; x++)
  {
    temp = temp->m_next;
  }
  return (temp);
}

template <class T>
void LinkedList<T>::clear()
{
  int size = m_size;
  for (int i = 0; i < size; i++)
  {
    remove_front();
  }
  m_size = 0;
  return;
}

template <class T>
void LinkedList<T>::insert_front(const T& x)
{
  if (m_head == NULL)
  {
    m_head = new Node<T>(x, NULL);
    m_back = m_head;
  }
  else
  {
    Node<T> *temp = new Node<T>(x,m_head);
    m_head = temp;
  }
  m_size++;
}

template <class T>
void LinkedList<T>::insert_back(const T& x)
{
  if (m_head == NULL)
  {
    m_head = new Node<T>(x, NULL);
    m_back = m_head;
    m_size++;
  }
  else
  {
    m_back->m_next = new Node<T>(x, NULL);
    m_back = m_back->m_next;
    m_size++;
  }
  return;
}

template <class T>
void LinkedList<T>::insert(const T& x, Node<T>* pos)
{
  Node<T> *temp = m_head;
  while (m_head->m_next != pos)
  {
    m_head = m_head->m_next;
  }
  m_head->m_next = new Node<T>(x, m_head->m_next);
  m_head = temp;
  m_size++;
}

template <class T>
void LinkedList<T>::remove_front()
{
  if (m_head == NULL)
  {
    return;
  }
  Node<T> *temp = m_head;
  m_head = m_head->m_next;
  delete temp;
  temp = NULL;
  m_size--;
  return;
}

template <class T>
void LinkedList<T>::remove_back()
{
  if (m_head == NULL)
  {
    return;
  }
  Node<T> *temp = getAtPtr(m_size-2);
  delete m_back;
  m_back = temp;
  m_back->m_next = NULL;
  m_size--;
  return;
}

template <class T>
void LinkedList<T>::remove(Node<T>* pos)
{
  if (m_head == pos)
  {
    m_head = m_head->m_next;
    delete pos;
    m_size--;
    return;
  }
  Node<T> *temp = m_head;
  while (temp->m_next != pos)
  {
    temp = temp->m_next;
  }
  temp->m_next = temp->m_next->m_next;
  m_size--;
  delete pos;

}

template <class T>
bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const
{
  Node<T> *temp1 = m_head;
  Node<T> *temp2 = rhs.m_head;
  while (temp1->m_next != NULL && temp2->m_next != NULL)
  {
    if (temp1->m_data != temp2->m_data)
    {
      return false;
    }
    else
    {
      temp1 = temp1->m_next;
      temp2 = temp2->m_next;
    }
  }
  if (m_size == rhs.m_size)
    return true;
  return false;

}

template <typename T>
std::ostream& operator<< (std::ostream& out, const LinkedList<T>& list)
{
  const Node<T> *temp = list.getFirstPtr();
  for (;temp;temp = temp->m_next)
  {
    out << temp->m_data;
  }
  return (out);
}
