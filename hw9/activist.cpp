/*
Programmer: Joseph Kuhn
Teacher: Dr. Leopold
Date: 10/18/16
Purpose: To test three classes, a town class that is a 2D
array of characters representing a town, an activist with
dignity, toxicity, and a name, and a polluter. In this program,
the functionality of all three is tested.
*/

#include "activist.h"
#include <cstdlib>

void Activist::placeMeInMiddle(Town &town)
{
  // gets the size of the town
  int size = town.getSize();
  // sets x to half of the size of the town
  int x = size/2;
  //sets y to x
  int y = x;
  //changes the point in town at (x,y) to representation
  town.setTile(x, y, m_representation);
  // updates that activists personal location variable x
  m_x = x;
  // updates the activists personal location variable y
  m_y = y;
  return;
}

void Activist::randMove(Town &town)
{
      int tilePicked;
      ///// While the tile the activist is trying to move onto is obstructed, this will continue looping
      do
      {
           tilePicked = rand() % 4;
      } while(!move(tilePicked, town));
  return;
}

bool Activist::move(int choice, Town &town)
{
    char finalMove;
    // gets the tile north of the activist.
    char north = town.getTile(m_x, m_y+1);

    //gets the tile south of the activist.
    char south = town.getTile(m_x,m_y-1);

    // gets the tile east of the activist
    char east = town.getTile(m_x+1, m_y);

    //gets the tile west of the activist
    char west = town.getTile(m_x-1, m_y);

    //puts all of the directions into an array that works with the choice variable.
    char directions[4] = {north, south, east, west};

    if (directions[choice] != '.')
        // if the direction chosen is an obstacle, return false.
        return false;
    else
    {
         switch(choice)
         {///// each of these change the grid and the personal variables of the
           ///// activist based on which choice was picked.
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
