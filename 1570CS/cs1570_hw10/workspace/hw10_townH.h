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

#ifndef HEADER_TOWN
#define HEADER_TOWN

#include <iostream>
#include <cstdlib>
using namespace std;

//////////
// Initilization of the defaults for the member variables of the Town class
//////////
const int MAX = 25;
const char WALL_IDENTIFIER = 'W';
const char EXIT_IDENTIFIER = 'E';
const char EMPTY_IDENTIFIER = ' ';
const char COP_IDENTIFIER = 'C';
const char DEFAULT_ROOT_IDENTIFIER = 'R';


class Town
{
  private:
    //////////
    // Initilization of the private member variables for the Town cass
    //////////
    short m_townSize_r;
    short m_townSize_c;
    char m_townSpace[MAX][MAX];

    //////////
    // Pre: Town must be of size > 1 and <= MAX
    // Post: Every index of the townSpace will be set to a EMPTY_IDENTIFIER.
    // Desc: The function clears the town by setting every index to an
    //       EMPTY_IDENTIFIER
    //////////
    void clear();

    //////////
    // Pre: Town must be of size > 1, rows and columns cannot be greater than
    //      MAX
    // Post: The function will set the entire borders of the town will walls
    //       signified by WALL_IDENTIFIER expect for the centers of the
    //       perimeter which will be set to EXIT_IDENTIFIER.
    // Desc: This function builds the borders of the town using WALL_IDENTIFIER
    //       and EXIT_IDENTIFIER. The exit will be in the center of each border
    //       while the wall fills the rest of the border.
    //////////
    void build(const int rows, const int columns);

  public:
    //////////
    // Parameterized constructor for the Town class
    // Pre: grid must be <= MAX
    // Post: The town will be cleared and rebuilt according to the size
    //       specified in grid
    // Description: The function clears and builds the new Town according to the
    //              grib parameter.
    //////////
    Town(const int grid = MAX);

    //////////
    // Pre: town must have valid characters occupying each space to be printed.
    // Post: Every index within m_townSize_r and m_townSize_c will be printed
    //       to the ostream
    // Desc: The function will print the current state of the Town grid.
    //////////
    friend ostream& operator <<(ostream& out, const Town& town);

    //////////
    // Pre: m_townSize_r must be defined
    // Post: Returns m_townSize_r.
    // Desc: The function returns the amount of Rows in the instance of the Town
    //////////
    short getRows() const
    {
      return m_townSize_r;
    }

    //////////
    // Pre: m_townSize_c must be defined
    // Post: Returns m_townSize_c.
    // Desc: The function returns the amount of Columns in the instance of the
    //       Town
    //////////
    short getColumns() const
    {
      return m_townSize_c;
    }

    //////////
    // Pre: row and column must be <= m_townSize_r and m_townSize_c respectively
    //      and town must be defined.
    // Post: The character identifer of position townSpace[row][column] has been
    //       change to the identifer
    // Desc: The function sets the character identifer passed by parameter into
    //       the position townSpace[row][column].
    //////////
    void setCharIdentifier(const int row, const int column, char identifier)
    {
      if(m_townSize_r >= row && m_townSize_r >= column)
      {
        m_townSpace[row][column] = identifier;
      }

      return;
    }

    //////////
    // Pre: row and column must be <= m_townSize_r and m_townSize_c respectively
    // Post: Returns whether or not the identifier in spot
    //       townSpace[row][column] is character
    // Desc: The function returns the amount of Rows in the instance of the Town
    //////////
    bool isChar(const int row, const int column, const char character) const
    {
      if(m_townSpace[row][column] == character)
      {

        return(true);
      }

      return(false);
    }
    
    //////////
    // Pre: row and column must within MAX.
    // Post: returns the character identifier located on 
    //       m_townSpace[row][column]
    // Desc: The function returns the character identifier that is located on
    //       m_townSpace[row][column]
    //////////
    char getCharIdentifier(const int row, const int column)
    {
        return(m_townSpace[row][column]);
    }

    //////////
    // Pre: row and column must be <= m_townSize_r and m_townSize_c respectively
    // Post: The function returns whether a Class is able to move to
    //       townSpace[row][column] (i.e. that space is empty)
    // Desc: The function returns the amount of Rows in the instance of the Town
    //////////
    bool isValidMove(const int row, const int column) const
    {
      if(row <= m_townSize_r && column <= m_townSize_c)
      {
        if(m_townSpace[row][column] == EMPTY_IDENTIFIER || 
           m_townSpace[row][column] == COP_IDENTIFIER)
        {
          return true;
        }
      }

      return false;
    }
    
    //////////
    // Pre: The town must have enough opens spots remaining, marked by
    //      EMPTY_IDENTIFIER, to place roots.
    // Post: The town has been populated with character identifier equal to 
    //       number of rootsNeeded with the DEFAULT_ROOT_IDENTIFIER.
    // Desc: This function places the amount of rootsNeeded in the town grid.
    //////////
    void placeRoots(const int size, const int rootsNeeded)
    {
      for (int i = 0; i < rootsNeeded; i++)
      {
        int xChoice, yChoice;
        do
        {
          xChoice = rand() % size;
          yChoice = rand() % size;        
        }while(m_townSpace[xChoice][yChoice] != EMPTY_IDENTIFIER);
        m_townSpace[xChoice][yChoice] = DEFAULT_ROOT_IDENTIFIER;
      }
    
      return;
    }
    
    //////////
    // Pre: The town must have enough opens spots remaining, marked by
    //      EMPTY_IDENTIFIER, to place cops.
    // Post: The town has been populated with character identifier equal to 
    //       number of copsNeeded with the COP_IDENTIFIER.
    // Desc: This function places the amount of copsNeeded in the town grid.
    //////////
    void placeCops(const int size, const int copsNeeded)
    {
      for (int i = 0; i < copsNeeded; i++)
      {
        int xChoice, yChoice;
        do
        {
          xChoice = rand() % size;
          yChoice = rand() % size;        
        }while(m_townSpace[xChoice][yChoice] != EMPTY_IDENTIFIER);
        m_townSpace[xChoice][yChoice] = COP_IDENTIFIER;        
      }
    }

};



#endif
