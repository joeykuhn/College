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
#ifndef HEADER_H
#define HEADER

using namespace std;

//////////
// @Pre: scoreArray must be the same size as the amount of statistics the user
//       wishes to collect. numRoots + numCops cannot exceed the number of 
//       tiles in the gridSize after the walls and exits are inserted.
// @Post: The function will return the results of the number of times an 
//        activist exitted the town, became overly intoxicated by roots, died
//        of dignity, or caught the pollutor by reference in scoreArray.
// @Desc: This function simulates an average day for the Activist and only ends
//        when one of the conditions mentioned in Post happens. The Activist
//        randomly moves throughout the town, using an action upon the various 
//        objects such as roots, cops, towns, or exits until the day ends with 
//        a previous condition.
//////////
void simulation(const int gridSize, const int numRoots, const int numCops,
                const int numDays, const int digLoss_Wall, 
                const int digLoss_Cop, int scoreArray[]);
//////////
// Pre: Town must be of size act.getRow() + dy and act.getColum + dX,
//      statCount must the length of the number of statistics the user
//      wishes to collect, and copDigLoss and wallDigLoss cannot be
//      negative.
// Post: The user has attempted to move/moved to their new position on the
//       town grid and commit whatever action corresponds to the character
//       identifier is on act.getRow() + dy and act.getColum + dX.
//       (i.e. if the identifier was WALL_IDENIFIER, the activist would
//        lose dignity specified in wallDigLoss, etc.). Moreover,
//        the function returns a bool whether or not the simulation should
//        immediately end depending on the action(DOES NOT ACCOUNT FOR THE
//        ACTIVIST BEING DRUNK, ETC.)
// Desc: The function handles the movement of the activist, all of the 
//       different interactions that happens with the movement of the
//       activist, and determines whether the action the activist made
//       should end that specific day of the simulation.
//////////
bool moveHandler(Town &town, Activist& act, Polluter& p, const int dY, 
                 const int dX, const int copDigLoss, const int wallDigloss,
                 int statCount[]);
//////////
// Pre: The score array must be defined and must have values of index 0-3
// Post: The function outputs the percentages of each of the win conditions
//       that happened over the course of the simulation (i.e. the activist
//       catches the pollutor, the activist exits the town, the activist
//       becomes over-intoxicated, or the activist dies of indignity.
// Desc: The function displays the percentanges of each of the different
//       scoring events to the user.
void displayScore(const int score[]);

#endif
