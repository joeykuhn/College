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
#include "hw10_polluterH.h"

void Polluter::placeMe(Town &town)
{
  do
  {
    m_row = myrand(1,town.getRows()-2);
    m_column = myrand(1,town.getColumns()-2);
  }
  while(!town.isValidMove(m_row,m_column));

  town.setCharIdentifier(m_row, m_column, m_id);

  return;
}

void Polluter::move_to(Town &town, const int dY, const int dX)
{
  if (m_curOn == COP_IDENTIFIER)
  {
    return;
  }
  const char ID = town.getCharIdentifier(m_row + dY, m_column + dX);
  if( ID == DEFAULT_ROOT_IDENTIFIER || 
      ID == EMPTY_IDENTIFIER || 
      ID == COP_IDENTIFIER)
  {
    town.setCharIdentifier(m_row, m_column, m_curOn);
    m_curOn = ID;
    m_row += dY;
    m_column += dX;
    town.setCharIdentifier(m_row, m_column , m_id);
  }
  
  return;
}

void Polluter::decideDirection(int& dY, int& dX)
{
  const int direction = myrand(1,4);
  switch(direction)
  {

    case 1:
      dY = 1;
      break;

    case 2:
      dX = 1;
      break;

    case 3:
      dY = -1;
      break;

    case 4:
      dX = -1;
      break;
  }
  
  return;
}

void Polluter::randMove(Town& town)
{
  int dX = 0;
  int dY = 0;
  decideDirection(dY, dX);
  
  move_to(town, dY, dX);
  
  return;
}

ostream& operator <<(ostream& o, const Polluter& pol)
{
  o << "Information about Polluter " << pol.m_name << ": " << endl;
  return(o);
}
