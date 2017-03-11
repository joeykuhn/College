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
#include "hw10_activistH.h"
#include "hw10_polluterH.h"
#include "hw10_townH.h"
#include "hw10_rootH.h"
#include <cstdlib>

void Activist::placeMeInMiddle(Town &town)
{
  m_row = town.getRows() / 2;
  m_column = town.getColumns() / 2;

  town.setCharIdentifier(m_row, m_column, m_id);

  return;
}

void Activist::move_to(Town &town, const int dY, const int dX)
{
  const char ID = town.getCharIdentifier(m_row + dY, m_column + dX);
  town.setCharIdentifier(m_row, m_column, m_curOn);
  (ID == DEFAULT_ROOT_IDENTIFIER)? m_curOn = EMPTY_IDENTIFIER : m_curOn = ID;
  m_row += dY;
  m_column += dX;
  town.setCharIdentifier(m_row, m_column , m_id);
  
  return;
}



void Activist::decideDirection(Polluter &p, int& dY, int& dX)
{
  dY = 0;
  dX = 0;
  int direction = 0;
  if(getState() == "cool")
  {
    direction = myrand(1,4);
  }
  else if(getState() == "normal")
  {
    if(abs(p.getRow() - m_row) > abs(p.getColumn() - m_column))
    {
      if ((p.getRow() - m_row) < 0)
          direction = 1;
      else
          direction = 2;
    }
    else if(abs(p.getColumn() - m_column) > abs(p.getRow() - m_row))
    {
      if ((p.getColumn() - m_column) < 0)
          direction = 3;
      else
          direction = 4;
    }
    else
    {
      int choice = rand() % 2;
      if (choice == 0)
      {
        (p.getRow() < m_row)? (direction = 1): (direction = 2);
      }
      else
      {
        (p.getColumn() < m_column)? (direction = 3): (direction = 4);
      }
    }
    
  }
  switch(direction)
  {
    case 1:
      dY = -1;
      break;

    case 2:
      dY = 1;
      break;

    case 3:
      dX = -1;
      break;

    case 4:
      dX = 1;
      break;
  }
  
  return;

}

ostream& operator <<(ostream& o, const Activist& act)
{
  o << "Information about Activist " << act.m_name << ": " << endl << endl
    << "  Toxicity: " << act.m_toxicity << endl
    << "  Dignity: " << act.m_dignity << endl
    << "  State: " << act.getState() << endl
    << "  Position: (" << act.m_row << "," << act.m_column << ")" << endl
    << "  Currently on: " << act.m_curOn << endl;
  return(o);
}

Activist& Activist::operator +=(Root& root)
{
  m_toxicity += root.getEffect();
  root.changeNumOfRoots(-1);
  if (m_toxicity > .25)
  {
        m_state = 2;
  }
  else if(m_toxicity > .08)
  {
        m_state = 1;
  }
  return(*this);
}