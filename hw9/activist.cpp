#include "activist.h"

void Town::placeMeInMiddle(const Town &town)
{
  size = town.getSize();
  char x = (size+1)/2, y = x;
  town.setTile((x, y, m_representation));
  m_x = x;
  m_y = y;
  return;
}

void Activist::randMove(const Town &town)
{
  int tilePicked = rand() % 4;
  switch(tilePicked)
  {
    case 0;
        m_x += 1;
        town.setTile(m_x, m_y, representation);
        break;
    case 1;
        m_x -= 1;
        town.setTile(m_x, m_y, representation);
        break;
    case 2;
        m_y += 1;
        town.setTile(m_x, m_y, representation);
        break;
    case 3;
        m_y -= 1;
        town.setTile(m_x, m_y, representation);
        break;
  }
  return;
}

ostream& operator <<(ostream &outs, const Activist &a)
{
  outs << "Name: " << a.m_name << endl
       << "Location: (" << a.m_x << "," << a.m_y << ")\n"
       << "Toxicity: " << a.m_toxicity << endl
       << "Dignity: " << a.m_dignity << endl
       << "Status: " << a.m_state << endl;
  return outs;
}
