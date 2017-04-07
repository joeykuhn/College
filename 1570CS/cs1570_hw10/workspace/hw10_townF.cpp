/*
Programmers: Kevin Schoonover and Joey Kuhn
Teacher: Dr. Leopold
Section: 1D
Date: 11/18/2016
Description: This program simulates an activist and a polluter fighting for
             world domination within a town designated by different character
             identifiers. This program works by spawning a activist in the
             center of the town and a polluter randomly in the town grid within
             the edges designated by walls and exits. Then, the cops and roots
             are randomly generated within the town. After the generation occurs
             the simulation begins, with the polluter moving randomly and the
             activist moving towards the polluter. If the polluter lands on a
             they are 'arrested' and cannot move for the remainder of the day.
             If the activist lands on a cop or wall, the activist loses dignity.
             If the activists lands on a root, the activist gains or loses
             intoxication. Depending on the Activists toxicity, the movement
             algorithm of the activist changes. Will Eric get this far? The
             world may never know. After all these actions occur, i.e. 
             intoxication or dignity get too high/lopw or the activist catches
             the pollutor or the activist leaves the town through an exit, the 
             day ends and the next begins until the simulation ends. GG CS 1570.
*/

#include "hw10_townH.h"

Town::Town(const int grid)
{
  if(grid <= MAX && grid <= MAX)
  {
    m_townSize_r = grid;
    m_townSize_c = grid;
    clear();
    build(grid, grid);
  }
  else
  {
    cout << "[Error] Initializing town class with variable > MAX, please "
         << "try again." << endl;
  }
}

void Town::clear()
{
  for(int i = 0; i < MAX; i++)
  {
    for(int j = 0; j < MAX; j++)
    {
      m_townSpace[i][j] = EMPTY_IDENTIFIER;
    }
  }

  return;
}

void Town::build(const int rows, const int columns)
{
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < columns; j++)
    {
      if(i == 0 || j == 0 || i == (rows - 1) || j == (columns - 1))
      {
        if(i == (rows - 1)/2 || j == (columns - 1)/2)
        {
          m_townSpace[i][j] = EXIT_IDENTIFIER;
        }
        else
        {
          m_townSpace[i][j] = WALL_IDENTIFIER;
        }
      }
    }
  }

  return;
}

ostream& operator <<(ostream &out, const Town& town)
{
  for(int i = 0; i < town.m_townSize_r; i++)
  {
    for(int j = 0; j < town.m_townSize_c; j++)
    {
      cout <<town.m_townSpace[i][j] << " ";
    }

    cout << endl;
  }

  return(out);
}
