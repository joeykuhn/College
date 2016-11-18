/*
Programmer: Joseph Kuhn
Teacher: Dr. Leopold
Date: 10/18/16
Purpose: To test three classes, a town class that is a 2D
array of characters representing a town, an activist with
dignity, toxicity, and a name, and a polluter. In this program,
the functionality of all three is tested.
*/

#ifndef ACTIVIST_H
#define ACTIVIST_H

#include <iostream>
#include <string>
#include "town.h"
using namespace std;

class Activist
{
private:
  ///// The toxicity of the activist
  float m_toxicity;
  ///// The dignity of the activist
  int m_dignity;
  ///// the x coordinate of the activist
  int m_x;
  ///// the y coordinate of the activist
  int m_y;
  ///// the representation of the activist on the grid
  char m_representation;
  ///// the state of the activist
  string m_state;
  ///// the name of the activist
  string m_name;

public:
  ///// Default constructor of the activist that takes a name
  // as the parameter and sets m_name equal to it, as well as
  // taking the representation as input but defaulting to 'A'.
  Activist(string name, char representation = 'A')
  {
    m_toxicity = .5;
    m_dignity = 100;
    m_x = -1;
    m_y = -1;
    m_representation = representation;
    m_state = "normal";
    m_name = name;
  }

  //////////
  // Preconditions: choice must be a number between 0-3 inclusive.
  // Postconditions: the activist has been moved to a nearby
  //  point on the grid based on the choice passed to it.
  // town has been updated to show the new location of the polluter
  // and it's previous location is a '.'. If the place requested to move is
  // not a period, move returns false. Otherwise, it updates the
  // activist and the town.
  // Purpose: to move the activist after checking it isn't
  // going to move onto an obstruction.
  //////////
  bool move(int choice, Town &town);

  //////////
  //Precondition: town should be built.
  //Postcondition: the activist's x and y coordinates are equal to
  // half the size of the size of the grid, and the grid displays them
  // there.
  //Purpose: to place the activist in the middle of the town, and have
  // its personal location as well as the town update to that information.
  //////////
  void placeMeInMiddle(Town &town);

  //////////
  //Precondition: town should be built. rand() must be seeded.
  //Postcondition: the activist's x and y coordinates are changed to
  // a point on the grid randomly north, south, east, or west. if
  // the point is obstructed, they cannot enter it. the grid is updated
  // to display their current location.
  //Purpose: To move the activist in a random direction that
  // is not an obstruction.
  //////////
  void randMove(Town &town);

    ///// overloaded operator for an easy way to check that status
    // of an activist
    friend ostream& operator <<(ostream &outs, const Activist &a)
    {
        outs << "Name: " << a.m_name << endl
                << "Location: (" << a.m_x << "," << a.m_y << ")\n"
                << "Toxicity: " << a.m_toxicity << endl
                << "Dignity: " << a.m_dignity << endl
                << "Status: " << a.m_state << endl;
        return (outs);
    }
};

#endif
