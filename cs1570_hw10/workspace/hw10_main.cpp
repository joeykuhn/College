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

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

#include "hw10_rootH.h"
#include "hw10_townH.h"
#include "hw10_activistH.h"
#include "hw10_polluterH.h"
#include "hw10_header.h"


using namespace std;


int main()
{
  /////
  // Initialization of the variable which stores how many items we need to read
  // from the configuration files
  /////
  const int numConfig = 6;
  
  /////
  // Settings up our configuration file to be read from
  /////
  ifstream curFile;
  curFile.clear();
  curFile.open("configuration.dat");

  /////
  // Index 0: Grid Size.
  // Index 1: Number of Roots.
  // Index 2: Number of Cops.
  // Index 3: Number of Days.
  // Index 4: Dignity Loss for hitting wall.
  // Index 5: Dignity Loss for landing on Cop.
  /////
  int configData[numConfig];
  
  /////
  // Reads all of the necessary configuration data from the configuration files
  /////
  for(int i = 0; i < numConfig; i++)
  {
      curFile >> configData[i];
  }
  /////
  // Closing file to prevent memory leaks.
  /////
  curFile.close();
  
  /////
  // The array which will store the data from the result of each run.
  // Index 0: Amount of times the Activist exits town.
  // Index 1: Amount of times the Activist catches polluter.
  // Index 2: Amount of times the Activist dies of supreme indignity.
  // Index 3: Amount of times the Activist becomes over-intoxicated by roots.
  //////
  int scoreArray[4] = {0,0,0,0};
  
  // Seed the random number generator
  srand(time(NULL));
  
  /////
  // Run the simulation with the parameters specified in the configuration file
  /////
  simulation(configData[0], configData[1], configData[2], configData[3],
                  configData[4], configData[5], scoreArray);
  
  return 0;
}
