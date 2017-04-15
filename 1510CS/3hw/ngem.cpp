#include "linkedlist.h"
#include <string>
#include <algorithm>

void cmdInterpreter(const std::string& cmd,  LinkedList<char> linkedl[]);
char transcribe(const char& c);

int main()
{
  LinkedList<char> structures[5];
  std::string s = "";
  std::string cmd = "";

  for (int i = 0; i < 5; i++)
  {
    std::getline(std::cin, s);
    for (int j = 0; j < s.length(); j++)
    {
      structures[i].insert_back(s[j]);
    }
  }



  while (std::cin >> cmd)
  {
    cmdInterpreter(cmd, structures);
  }

  return 0;
}


void cmdInterpreter(const std::string& cmd, LinkedList<char> linkedl[])
{
  if (cmd == "append")
  {

    int id = 0;
    std::string str = "";
    std::cin >> id >> str;
    for (int i = 0; i < str.length(); i++)
    {
      if (str[i] != 'P' && str[i] != 'O' && str[i] != 'K' && str[i] != 'B' && str[i] != 'Y' && str[i] != 'T' && str[i] != 'M' || id > 5)
      {
        std::cout << "ERROR! append: invalid parameters." << std::endl;
        return;
      }
    }
    for (int i = 0; i < str.length(); i++)
    {
      linkedl[id].insert_back(str[i]);
    }


  }
  else if(cmd == "trim")
  {
    int id = 0,start = 0;
    std::cin >> id >> start;
    if (id > 5 || start > linkedl[id].size())
    {
      std::cout << "ERROR! trim: invalid parameters." << std::endl;
      return;
    }
    for (int i = linkedl[id].size(); i > start ;i-- )
    {
      linkedl[id].remove_back();
    }
  }
  else if(cmd == "clip")
  {
    int id = 0, start = 0, stop = 0;
    std::cin >> id >> start >> stop;
    if (id > 5 || start > linkedl[id].size() || stop > linkedl[id].size() || start < 0 || stop < 0)
    {
      std::cout << "ERROR! clip: invalid parameters." << std::endl;
      return;
    }
    for (int i = start; i < stop + 1 ; i++ )
    {
      linkedl[id].remove(linkedl[id].getAtPtr(start));
    }
  }
  else if(cmd == "slice")
  {
    int id = 0, start = 0, stop = 0;
    std::cin >> id >> start >> stop;
    if (id > 5 || start > linkedl[id].size() || stop > linkedl[id].size() || start < 0 || stop < 0)
    {
      std::cout << "ERROR! slice: invalid parameters." << std::endl;
      return;
    }
    for (int i = 0; i < start; i++)
    {
      linkedl[id].remove_front();
    }
    for (int i = linkedl[id].size();i > (stop - start + 1); i--)
    {
      linkedl[id].remove_back();
    }
  }
  else if(cmd == "copy")
  {
    int id1 = 0, id2 = 0;
    std::cin >> id1 >> id2;
    if (id1 > 5 || id2 > 5)
    {
      std::cout << "ERROR! copy: invalid parameters." << std::endl;
      return;
    }
    linkedl[id2] = linkedl[id1];
  }
  else if(cmd == "swap")
  {
     int id1, id2, start1, start2;
     std::cin >> id1 >> start1 >> id2 >> start2;
     int size1 = linkedl[id1].size();
     int size2 = linkedl[id2].size();
     if (id1 > 5 || id2 > 5 || start1 > size1 || start2 > size2 || start1 < 0 || start2 < 0)
     {
       std::cout << "ERROR! swap: invalid parameters." << std::endl;
       return;
     }
     for (int i = start1; i < size1; i++ )
     {
       linkedl[id2].insert_back((linkedl[id1].getAtPtr(i))->m_data);
     }
     for (int i = start2; i < size2; i++ )
     {
       linkedl[id1].insert_back((linkedl[id2].getAtPtr(i))->m_data);
     }
    for (int i = start1; i < size1; i++)
     {
       linkedl[id1].remove(linkedl[id1].getAtPtr(start1));
     }
     for (int i = start2; i < size2; i++)
     {
       linkedl[id2].remove(linkedl[id2].getAtPtr(start2));
     }
  }
  else if(cmd == "transcribe")
  {
    int id = 0;
    std::cin >> id;
    int size = linkedl[id].size();
    if (id > 5)
    {
      std::cout << "ERROR! swap: invalid parameters." << std::endl;
      return;
    }
    for (int i = size-1; i >= 0; i--)
    {
      (linkedl[id].getAtPtr(i))->m_data = transcribe((linkedl[id].getAtPtr(i))->m_data);
      linkedl[id].insert_back((linkedl[id].getAtPtr(i))->m_data);
      linkedl[id].remove(linkedl[id].getAtPtr(i));
    }

  }
  else if(cmd == "print")
  {
    for (int i = 0; i < 5; i++)
    {
      std::cout << "#" << i << ", " << linkedl[i].size() << ": " << linkedl[i] << std::endl;
    }
    std::cout << std::endl;
  }
}

char transcribe(const char& c)
{
  switch(c)
  {
    case 'P': return ('Y');
    case 'O': return ('T');
    case 'K': return ('M');
    case 'Y': return ('P');
    case 'M': return ('K');
    case 'T': return ('O');
    default: return ('B');
  }
}
