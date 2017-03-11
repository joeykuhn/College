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
#ifndef HEADER_ROOT
#define HEADER_ROOT

#include <iostream>
#include <cstdlib>


const int MAX_ROOTS = 20;

const int ROOTNEGMIN = 10;
const int ROOTNEGMAX = 1;
const int ROOTPOSMIN = 5;
const int ROOTPOSMAX = 10;

using namespace std;

class Root
{
  private:
    //////////
    // Initialization of the private class variables
    //////////
    string m_desc;
    float m_effect;
    
 
    
    //////////
    // Initialization of static variable which will keep track of all class
    // data for overloading += operator.
    // Actual values defined in hw10_rootF.cpp
    //////////
    static int numOfRoots;
    
  public:
    
    //////////
    // Default constructor for the Root Class
    //////////
    Root()
    {
      int choice = myrand(0,1);
      if (choice == 1)
      {
        m_desc = "truffle";
        m_effect = myrand(ROOTPOSMIN, ROOTPOSMAX);
        m_effect = m_effect / 100;
        numOfRoots++;
      }
      else
      {
        m_desc = "square";
        m_effect = myrand(ROOTNEGMIN, ROOTNEGMAX);
        m_effect = m_effect / 1000 * -1;
        numOfRoots++;
      }
    }
    
    float getEffect()
    {
      return m_effect;
    }
    
    //////////
    // Pre: Root must have a m_desc and an m_effect.
    // Post: m_desc and m_effect data of the instance is printed to the stream.
    // Desc: This function prints the data of the root to the stream.
    //////////
    int myrand(const int minValue, const int maxValue)
    {
      return(rand() % (maxValue-minValue+1) + minValue);
    }
    
    //////////
    // Pre: numOfRoots must be declared and must be called on an instance of
    //      the root class.
    // Post: Returns the numOfRoots of the instance of the class
    // Desc: This function is an accessor for the numOfRoots member variable.
    //////////
    int getNumOfRoots()
    {
         return (numOfRoots);
    }
    
    //////////
    // Pre: numOfRoots must be declared and must be called on an instance of
    //      the root class.
    // Post: numOfRoots has been set to the parameter num 
    // Desc: This function is a mutator for the numOfRoots member variable.
    //////////
    void setNumOfRoots(const int num)
    {
      numOfRoots = num;
      return;
    }
    
    //////////
    // Pre: numOfRoots must be declared and must be called on an instance of
    //      the root class.
    // Post: numOfRoots has been changed by the delta parameter 
    // Desc: This function is a mutator for the numOfRoots member variable,
    //       adding or subtracting the delta from numOfRoots.
    //////////
    void changeNumOfRoots(const int delta)
    {
      numOfRoots += delta;
      return;
    }
    
    //////////
    // Pre: m_desc and m_effect must be defined.
    // Post: The m_desc and m_effect information has been inserted into
    //       the ostream parameter o.
    // Desc: This function formats and inserts information about the root to
    //       the ostream.
    //////////
    friend ostream& operator<<(ostream& o, const Root& root);
};

#endif
