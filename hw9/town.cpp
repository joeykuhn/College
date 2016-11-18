/*
Programmer: Joseph Kuhn
Teacher: Dr. Leopold
Date: 10/18/16
Purpose: To test three classes, a town class that is a 2D
array of characters representing a town, an activist with
dignity, toxicity, and a name, and a polluter. In this program,
the functionality of all three is tested.
*/

#include <iostream>
#include "town.h"

using namespace std;
///// iterates through the m_grid array until it hits the m_size selected, setting every object to '.'
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


///// Builds the town by putting walls on all of the edges of the town (the 0th row, the 0th column,
///// the last row, the last column) and then putting an exit in the middle of each wall.
void Town::build()
{
  for (int i = 0; i < m_size; i++)
  {
    m_grid[0][i] = 'W';
    m_grid[m_size-1][i] = 'W';
    m_grid[i][0] = 'W';
    m_grid[i][m_size-1] = 'W';
  }
  m_grid[0][m_size/2] = 'E';
  m_grid[m_size-1][m_size/2] = 'E';
  m_grid[m_size/2][0] = 'E';
  m_grid[m_size/2][m_size] = 'E';
  return;
}

Town::Town(const int size)
{
  m_size = size;
  clear();
  build();
}

void Town::setTile(int x, int y, char tile)
{ ///// sets the specific location on m_grid to tile.
  m_grid[x][y] = tile;
  return;
}
