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
#include <cstdlib>
#include <iostream>
#include "hw10_townH.h"
#include "hw10_rootH.h"
#include "hw10_activistH.h"
#include "hw10_polluterH.h"

bool moveHandler(Town &town, Activist& act, Root r[], Polluter& p, const int dY, 
                 const int dX, const int copDigLoss, const int wallDigloss,
                 int statCount[], float &toxicity, const char pID)
{
  
  const int newY = act.getRow() + dY;
  const int newX = act.getColumn() + dX;
  const char action = town.getCharIdentifier(newY, newX);

  if (action == WALL_IDENTIFIER)
  {
    act.setDignity((act.getDignity()-wallDigloss));
    if(act.getDignity() < DIGNITY_MIN)
    {
      act.setDignity(DIGNITY_MIN);
    }
    return false;
  }
  else if (action == EMPTY_IDENTIFIER)
  {
    act.move_to(town, dY, dX);
    return false;
  }
  else if (action == EXIT_IDENTIFIER)
  {
    town.setCharIdentifier(act.getRow(), act.getColumn(), EMPTY_IDENTIFIER);
    statCount[0] += 1;
    toxicity += act.getToxicity();
    return true;
  }
  else if (action == pID)
  {
    statCount[1] += 1;
    toxicity += act.getToxicity();
    return true;
  } 
  else if (action == DEFAULT_ROOT_IDENTIFIER)
  {
    act += r[r[0].getNumOfRoots()-1];
    act.move_to(town, dY, dX);
    return false;
  } 
  else if (action == COP_IDENTIFIER)
  {
    act.setDignity((act.getDignity() - copDigLoss));
    if(act.getDignity() < DIGNITY_MIN)
    {
      act.setDignity(DIGNITY_MIN);
    }
    act.move_to(town, dY, dX);
    return false;
  }
}

void displayScore(const int score[], const float toxicity, const int days)
{
  float total = 0;
  for(int i = 0; i < 4; i++)
  {
    total += score[i];
  }
  cout << "Percentage of times Lisa exited town: "
       <<  score[0]/total * 100<< "%" << endl
       << "Percentage of times Lisa caught Homer: " 
       << score[1]/total * 100<< "%" << endl
       << "Percentage of times Lisa died of indignity: " 
       << score[2]/total * 100 << "%" << endl
       << "Percentage of times Lisa became overintoxicated: " 
       << score[3]/total * 100 << "%" << endl
       << "Average Toxicity: " << toxicity/days << endl;
  return;
}

void simulation(const int gridSize, const int numRoots, const int numCops,
                const int numDays, const int digLoss_Wall, 
                const int digLoss_Cop, int scoreArray[])
{
  float totalToxicity = 0;
  for (int k = 0; k < numDays; k++)
  {
    Town springfield(gridSize);
    Polluter homer("Homer", 'H');
    homer.placeMe(springfield);
    Activist lisa("Lisa", 'L');
    lisa.placeMeInMiddle(springfield);
    Root r[numRoots];
    r[0].setNumOfRoots(numRoots);
    springfield.placeRoots(gridSize,numRoots);
    springfield.placeCops(gridSize, numCops);
    bool didDisplay = false;
    bool endDay = false;
    
    while(!endDay)
    {
      if(lisa.getState() == "gone")
      {
        scoreArray[3] += 1;
        totalToxicity += lisa.getToxicity();
        endDay = true;
        break;
      }
      else if(lisa.getDignity() <= 0)
      {
        scoreArray[2] += 1;
        totalToxicity += lisa.getToxicity();
        endDay = true;
        break;
      }
      
      homer.randMove(springfield);
      
      int dY = 0;
      int dX = 0;
      lisa.decideDirection(homer, dY, dX);
      endDay = moveHandler(springfield, lisa, r, homer, dY, dX, 
                           digLoss_Cop, digLoss_Wall, scoreArray,
                           totalToxicity, homer.getID());
      
      if (k < 2)
      {
        if (!didDisplay)
        {
          cout << endl << "---------- Day " << k+1 <<": ----------" 
               << endl << endl;
               
          didDisplay = true;
        }
        
        cout << springfield;
      }
    }
  }
    
    displayScore(scoreArray, totalToxicity, numDays);
  
  return;
}

