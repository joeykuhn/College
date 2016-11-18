#ifndef ACTIVIST_H
#define ACTIVIST_H

#include <iostream>
#include <string>

class Activist
{
private:
  float m_toxicity;
  int m_dignity;
  char m_x;
  char m_y;
  const char m_representation = 'A';
  string m_state;
  string m_name;

public:
  Activist(string name,string representation = 'A')
  {
    m_toxicity = .5;
    m_dignity = 100;
    m_x = -1;
    m_y = -1;
    m_representation = representation;
    m_state = "normal";
    m_name = name;
  }

  void placeMeInMiddle(const Town &town);
  void randMove(const Town &town);

  friend ostream& operator <<(ostream &outs, const Activist &a);

};

#endif
