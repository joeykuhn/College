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
#ifndef HEADER_POL
#define HEADER_POL

#include <cstdlib>
#include "hw10_townH.h"

using namespace std;

//////////
// Defaults for the classes' member variables
//////////
const char DEFAULT_IDENTIFIER_POL = 'P';
const int START_ROW_POL = -1;
const int START_COLUMN_POL = -1;

class Polluter
{
  private:
    //////////
    // Initialization of the private class variables
    //////////
    string m_name;
    int m_row;
    int m_column;
    char m_id;
    char m_curOn;
    
    int myrand(const int minValue, const int maxValue)
    {
      return(rand() % (maxValue-minValue+1) + minValue);
    }

  public:

    //////////
    // Parameterized constructor for the Polluter class which changes the
    // Polluters name.
    //////////
    Polluter(string name, char id = DEFAULT_IDENTIFIER_POL)
    {
      m_name = name;
      m_row = START_ROW_POL;
      m_column = START_COLUMN_POL;
      m_id = id;
      m_curOn = EMPTY_IDENTIFIER;
    }
    
    //////////
    // Pre: m_row must be defined
    // Post: the function returns the int m_row of the instance of the object
    // Desc: The function returns the current row of the activist instance.
    //////////
    int getRow() const
    {
      return(m_row);
    }
    
        //////////
    // Pre: m_column must be defined for the object
    // Post: The function returns the int m_column of the instance of
    //       object
    // Desc: The function returns the current column of the polluter instance.
    //////////
    int getColumn() const
    {
      return(m_column);
    }
    
    /////////
    // Pre: m_id must be defined for the object
    // Post: the function returns a char equal to the m_id of the object that
    //      called it.
    // Desc: returns the ID of the object calling the function.
    //////////
    char getID() const
    {
      return(m_id);
    }
    
    void decideDirection(int & dY, int  &dX );

    //////////
    // Pre: town must be defined and there must be one space wthin the grid
    //      which has EMPTY_IDENTIFIER as its identifier
    // Post: the Polluter instance's identifier will be placed randomly within
    //       the confines of the walls of the grid on a valid location(location
    //       wihch has an EMPTY_IDENTIFIER)
    // Desc: This function randomly places the Polluter instance's identifier
    //       within the confines of the grid on its own tile.
    //////////
    void placeMe(Town &town);
    
    //////////
    // Pre: town must be defined and the Polluter must have a valid move in
    //      one of the cardinal directions (i.e a adjacent tile must have
    //      empty identifier)
    // Post: The function randomly decides a cardinal direcion to move the
    //       Polluter and move the character identifier to that location on
    //       the grid.
    // Description: This function randomly moves the Polluter in one of the
    //              four cardinal directions if at least one movement is valid.
    //////////
    void randMove(Town& town);

    //////////
    // Pre: townMust be defined and newRow and newColumn must be within the
    //      grid size of town.
    // Post: The function sets the identifier in the current Polluter position
    //       to EMPTY_IDENTIFIER and places the instance identiier dY rows
    //       and dX columns away. Also, sets the current position of the
    //       Polluter instance to the new position(i.e. changing m_row and
    //       m_column to accomdiate)
    // Description: The function moves the Polluter instance dY rows and dX
    //              columns away and sets the Polluter instance's position
    //              to the new position
    //////////
    void move_to(Town &town, const int dY, const int dX);

    //////////
    // Pre: ostream must be open and every member variable within pol must
    //      be defined.
    // Post: The function outputs and formats all of the Polluter's member
    //       variables to the ostream o and returns the ostream for chaining.
    // Description: This function takes the information within pol's member
    //              variables and outputs them to the ostream.
    //////////
    friend ostream& operator <<(ostream& o, const Polluter& pol);
};

#endif
