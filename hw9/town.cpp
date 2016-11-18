#include <iostream>
#include "town.h"

using namespace std;

void Town::clear()
{
  for (int i = 0; i < m_size; i++)
  {
    for (int j = 0; j < m_size; j++)
    {
      m_grid[i][j] = '.';
    }
  }
  return;
}

void Town::build()
{
  for (int i = 0; i < m_size; i++
  {
    m_grid[0][i] = 'W';
    m_grid[m_size-1][i] = 'W';
    m_grid[i][0] = 'W';
    m_grid[i][m_size-1] = 'W';
  }
  m_grid[0][(m_size+1)/2] = 'E';
  m_grid[m_size-1][(m_size+1)/2] = 'E';
  m_grid[(m_size+1)/2][0] = 'E';
  m_grid[(m_size+1)/2][m_size-1] = 'E';
  return;
}

Town::Town(const int size)
{
  m_size = size;
  clear();
  build();
}

void Town::setTile(char x, char y, char tile)
{
  m_grid[x][y] = tile;
  return;
}

ostream& operator<<(ostream &outs, const Town a)
{
  for ( int row = 0; row < a.m_size; row++)
  {
    for (int col = 0; col < a.m_size; col++)
      outs << a.m_grid[row][col];
    outs << endl;
  }
  return outs;
}
