#include <iostream>
#include "mybstree.h"

int main()
{
  MyBSTree<int> tree;
  std::cout << "size: " << tree.size() << std::endl;

  if (tree.isEmpty())
    std::cout << "tree is empty." << std::endl;
  else
    std::cout << "tree is not empty." << std::endl;

  std::cout << "Height: " << tree.height() << std::endl;

  tree.insert(10);

  std::cout << "size: " << tree.size() << std::endl;

  if (tree.isEmpty())
    std::cout << "tree is empty." << std::endl;
  else
    std::cout << "tree is not empty." << std::endl;

  std::cout << "Height: " << tree.height() << std::endl;

  tree.insert(9);
  tree.insert(11);
  tree.insert(8);
  tree.insert(1);
  tree.insert(3);
  tree.insert(50);

  std::cout <<"size should be: 7" << std::endl;
  std::cout << "size: " << tree.size() << std::endl;

  std::cout << "Height: " << tree.height() << std::endl;

  try{
  std::cout << std::endl
            << "Max should be: 50" << std::endl
            << "Max: " << tree.getMax() << std::endl;
  }catch(Oops a)
  {
    a.getMsg();
  }

  try{
  std:cout << std::endl
           << "Min should be: 1" << std::endl
           << "Min: " << tree.getMin() << std::endl;
  }catch(Oops a)
  {
    a.getMsg();
  }

  tree.clear();

  std::cout << std::endl << "tree is cleared." << std::endl << std::endl;

  tree.height();

  tree.insert(5);
  tree.insert(10);

  std::cout << std::endl
            << "removing 10"
            << std::endl;
  tree.remove(10);



  return 0;
}
