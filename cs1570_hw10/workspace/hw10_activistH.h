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

#ifndef HEADER_ACT
#define HEADER_ACT

#include <iostream>
#include <cstdlib>
#include "hw10_townH.h"
#include "hw10_polluterH.h"
#include "hw10_rootH.h"
using namespace std;

//////////
// Initilzation of the minimum and maximum of the Dignity and Toxicity member
// variables
//////////
const float TOXICITY_MIN = 0;
const float TOXICITY_MAX = 3.0;
const int DIGNITY_MIN = 0;
const int DIGNITY_MAX = 100;

//////////
// Initilzation of the default Identifier for the ACtivist
//////////


//////////
// Initilzation of the list which contains the possible states of the pogram
//////////
const string STATES[3] = {"normal", "cool", "gone"};

//////////
// Initilzation of the default variables for each memeber variables in the
// activist class.
//////////
const float START_TOXICITY = .05;
const int START_DIGNITY = 100;
const int START_STATE = 0; //0 for normal, 1 for cool, 2 for gone
const int START_ROW_ACT = -1;
const int START_COLUMN_ACT = -1;
const char DEFAULT_IDENTIFIER_ACT = 'A';

class Activist
{
  private:
    //////////
    // Defining each of the private member variables for the class
    //////////
    float m_toxicity;
    int m_dignity;
    int m_column;
    int m_row;
    char m_id;
    int m_state; //0 for normal, 1 for cool, 2 for gone
    char m_curOn;
    
    string m_name;
    
    
    int myrand(const int minValue, const int maxValue)
    {
      return(rand() % (maxValue-minValue+1) + minValue);
    }
    
  public:
    //////////
    // Parameterized constructor for Activist which defaults ID to the
    // ID defined about the class definition.
    //////////
    Activist(string name, char id = DEFAULT_IDENTIFIER_ACT)
    {
      m_toxicity = START_TOXICITY;
      m_dignity = START_DIGNITY;
      m_state = START_STATE;
      m_row = START_ROW_ACT;
      m_column = START_COLUMN_ACT;
      m_id = id;
      m_state = START_STATE;
      m_curOn = EMPTY_IDENTIFIER;
      m_name = name;
    }

    //////////
    // Pre: STATES must contain the index m_state
    // Post: The function returns the string state of the instance of
    //       object
    // Desc: The function returns the current state of the activist instance.
    //////////
    string getState() const
    {
      return(STATES[m_state]);
    };
    
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
    // Desc: The function returns the current column of the activist instance.
    //////////
    int getColumn() const
    {
      return(m_column);
    }
     
     //////////
    // Pre: m_toxicity must be defined for the instance of the object.
    // Post: The function returns the float m_toxicty of the instance of
    //       object
    // Desc: The function returns the current toxicity of the activist instance.
    //////////    
    float getToxicity() const
    {
      return (m_toxicity);
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
    
    ///////////
    // Pre: m_dignity must be defined for an instance of the class
    // Post: Returns the current m_dignity value of the instance
    // Desc: This function returns the m_dignity value of the instance.
    ///////////
    int getDignity() const
    {
      return(m_dignity);
    };
    
    ///////////
    // Pre: newDig must be between DIGNITY_MIN AND DIGNITY_MAX.
    // Post: m_dignity value of the instance will be set to newDig.
    // Desc: The function changes the m_dignity value of the instance to newDig.
    ///////////
    void setDignity(const int newDig)
    {
      if(newDig <= DIGNITY_MAX && newDig >= DIGNITY_MIN)
      {
        m_dignity = newDig;
      }
      else if (newDig < DIGNITY_MIN)
      {
        m_dignity = DIGNITY_MIN;
      }
      else
      {
          cout << "I should never cout. dignity is: " << m_dignity << endl;
      }
      
      return;
    };
    
    //////////
    // Pre: town must be define and must be larger than 3x3. Should also have a
    //      center (odd size)
    // Post: The function will place the character indicator of the Activist
    //       in the middle of the town grid and will set the Activists Position
    //       (m_row and m_column) to the position of the character.
    // Description: The function sets the Activist row and column member
    //              variables to the center of town and place the character
    //              identifier in the enter of the town.
    //////////
    void placeMeInMiddle(Town &town);

    //////////
    // Pre: town must be defined and the activist must have a valid move in
    //      one of the cardinal directions (i.e a adjactent tile must have
    //      empty identifier)
    // Post: The function randomly decides a cardinal direcion to move the
    //       activist and moves the character identifier to that location on
    //       the grid.
    // Description: This function randomly moves the activist in one of the
    //              four cardinal directions if at least one movement is valid.
    //////////
    void decideDirection(Polluter &p, int& dy, int& dx);


    //////////
    // Pre: townMust be defined and newRow and newColumn must be within the
    //      grid size of town.
    // Post: The function sets the identifier in the current Activist position
    //       to EMPTY_IDENTIFIER and places the instance identiier dY rows
    //       and dX columns away. Also, sets the current position of the
    //       activist instance to the new position(i.e. changing m_row and
    //       m_column to accomodate)
    // Description: The function moves the Activist instance dY rows and dX
    //              columns away and sets the Activist instance's position
    //              to the new position
    //////////
    void move_to(Town &town, const int dY, const int dX);
    
    //////////
    // Pre: ostream must be open and every member variable within act must
    //      be defined.
    // Post: The function outputs and formats all of the Activist's member
    //       variables to the ostream o and returns the ostream for chaining.
    // Description: This function takes the information within act's member
    //              variables and outputs them to the ostream.
    //////////
    friend ostream& operator <<(ostream& o, const Activist& act);

    //////////
    // Pre: numOfRoots must be > 0 and rootEffects for each index must be
    //      defined.
    // Post: m_dignity has been changed by the value of 
    //       rootEffects[numOfRoots-1] and the activist is return for chaining.
    // Desc: This function changes the m_dignity value of the instance by the
    //       amount of effect that the root has been randomly assigned when
    //       it was evalutated.
    //////////
    Activist& operator +=(Root& root);
    
};

#endif
