/*
Programmer: Joseph Kuhn
Teacher: Dr. Leopold
Date: 10/18/16
Purpose: To test three classes, a town class that is a 2D
array of characters representing a town, an activist with
dignity, toxicity, and a name, and a polluter. In this program,
the functionality of all three is tested.
*/

#ifndef POLLUTER_H
#define POLLUTER_H

#include <iostream>
#include "town.h"
using namespace std;

class Polluter
{
  private:
    // The name of the polluter
    string m_name;
    // The x coordinate of the polluter
    int m_x;

    // The y coordinate of the polluter
    int m_y;

    // The representation of the polluter on the grid
    int m_representation;

  public:
    // Default constructor that sets the name to the parameter passed to it
    // and the representation passed to it, defaulting to 'P'.
    Polluter(string name, int representation = 'P')
    {
      m_name = name;
      m_representation = representation;
      m_x = -1;
      m_y = -1;
    }

    //////////
    // Preconditions: choice must be a number between 0-3 inclusive.
    // Postconditions: the polluter has been moved to a nearby
    //  point on the grid based on the choice passed to it.
    // town has been updated to show the new location of the polluter
    // and it's previous location is a '.'. If the place requested to move is
    // not a period, move returns false. Otherwise, it updates the
    // polluter and the town.
    // Purpose: to move the polluter after checking it isn't
    // going to move onto an obstruction.
    //////////
    bool move(int choice, Town &town);

    //////////
    // Preconditions: town should be built, rand() must be seeded.
    // Postconditions: the town has been updated to reflect
    // the polluters new location. the polluters personal location
    // has been updated as well.
    // Purpose: to pick a random place for the polluter to move that
    // is not an obstruction.
    //////////
    void randMove(Town &town);

    //////////
    // Preconditions: town should be built.
    // Postconditions: the polluter's location is somewhere random on
    // the map that was a period. the grid also has  a representation
    // of the polluter on the map in that position.
    // Purpose: To place the polluter somewhere randomly on the map.
    //////////
    void placeMe(Town &town);
};

#endif
