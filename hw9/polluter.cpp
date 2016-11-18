#include "polluter.h"

void Polluter::placeMe(const Town &town)
{
  int size = town.getSize();
  char x = rand % size;
  char y = rand % size;
  m_x = x;
  m_y = y;
  town.setTile(m_x, m_y, representation)
  return;
}

void Polluter::randMove(const Town &town)
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
