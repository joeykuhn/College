/*
Programmer: Joseph Kuhn
Teacher: Dr. Leopold
Date: 10/18/16
Purpose: To test three classes, a town class that is a 2D
array of characters representing a town, an activist with
dignity, toxicity, and a name, and a polluter. In this program,
the functionality of all three is tested.
*/

#ifndef TOWN_H
#define TOWN_H

#include <iostream>
using namespace std;

const int TOWN_MAX_SIZE = 25;


class Town{
  private:
    //the actual character array holding all of the objects.
    int m_grid[TOWN_MAX_SIZE][TOWN_MAX_SIZE];
    // the actual size of the array that is being used
    short m_size;

   ///// Empties the array and sets each item to a period.
    void clear();
    ///// 'Builds' the town, by placing the walls and exits in the
    //////correct places.
    void build();

  public:
    ///// Default Constructor that sets the town to the size passed to it.
    Town(const int size = TOWN_MAX_SIZE);

   //////////
   // Preconditions: none
   // Postconditions: getSize is equal to the size of m_grid being used.
   // Purpose: An accessor function that returns the size of the array
   // being used.
   //////////
    int getSize() const {return m_size;}

    //////////
    // Preconditions: m_grid should be built. x and y
    // should be the respective coordinates of where
    // the array should be searched through.
    // Postconditions: getTile returns the character in the array
    // at [x][y].
    // Purpose: An accessor function that can be used to see values
    // at the requested place on the grid.
    //////////
    int getTile(int x, int y) const {return m_grid[x][y];}

    //////////
    // Preconditions: the town object should be built. x and y should
    // be the coordinates in the grid you wish to change, and tile
    // is what you wish to change it to.
    // Postconditions: the point on the grid x,y has been changed to
    // the value of tile.
    // Purpose: a Mutator function that changes a character in the
    // grid at the referenced point to the tile that is passed to it.
    //////////
    void setTile(int x, int y, int tile);

    //////////
    //Precondition: Town should be built before now.
    //Postcondition: Town has been output to outs, in a rows first
    // alignment.
    //Purpose: To output the contents of the grid.
    //////////
    friend ostream & operator<<(ostream &outs,const Town &a)
    {
      for ( int row = 0; row < a.getSize(); row++)
      {
        for (int col = 0; col < a.getSize(); col++)
          outs << a.getTile(row, col);
        outs << endl;
      }
      return outs;
    }
};

#endif
