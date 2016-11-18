/*
Programmer: Joseph Kuhn
Teacher: Dr. Leopold
Date: 10/18/16
Purpose: To test three classes, a town class that is a 2D
array of characters representing a town, an polluter with
dignity, toxicity, and a name, and a polluter. In this program,
the functionality of all three is tested.
*/

#include "polluter.h"
#include <cstdlib>

void Polluter::placeMe(Town &town)
{
  int size = town.getSize(); // gets the size of the town
  int x;
  int y;
  do{
    ///// while the point in the town that is randomly picked is not a period,
    //this continues looping.
    x = rand() % size;
    y = rand() % size;
  }while( town.getTile(x,y) != '.');
  m_x = x;
  m_y = y;
  town.setTile(m_x, m_y, m_representation);
  return;
}

void Polluter::randMove(Town &town)
{
      int tilePicked;
      do
      {///// While the tile being moved to is an obstruction this continues
        // looping.
           tilePicked = rand() % 4;
      } while(!move(tilePicked, town));
  return;
}

bool Polluter::move(int choice, Town &town)
{
    int north = town.getTile(m_x, m_y+1);
    // gets the tile north of the polluter.

    int south = town.getTile(m_x,m_y-1);
    //gets the tile south of the polluter.

    int east = town.getTile(m_x+1, m_y);
    // gets the tile east of the polluter

    int west = town.getTile(m_x-1, m_y);
    //gets the tile west of the polluter

    int directions[4] = {north, south, east, west};
    //puts all of the directions into an array that works with the choice variable.

    if (directions[choice] != '.')
    ///// if the polluter is trying to move onto a square that is a period, the
    // function breaks.
        return false;
    else
    {///// each of these change the grid and the personal variables of the
      ///// polluter based on which choice was picked.
         switch(choice)
         {
              case 0:
                  town.setTile(m_x, m_y, '.');
                  m_y += 1;
                  town.setTile(m_x, m_y, m_representation);
                  break;
              case 1:
                  town.setTile(m_x,m_y,'.');
                  m_y -= 1;
                  town.setTile(m_x, m_y, m_representation);
                  break;
              case 2:
                  town.setTile(m_x,m_y,'.');
                m_x += 1;
                town.setTile(m_x, m_y, m_representation);
                break;
              case 3:
                  town.setTile(m_x,m_y,'.');
                m_x -= 1;
                town.setTile(m_x, m_y, m_representation);
                break;
        }
    }
    return true;
}
