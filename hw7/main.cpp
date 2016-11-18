/*
Programmer: Joey Kuhn
Teacher: Dr. Leopold
Date: 10/24/2016
Purpose: To display two databases and have a user request to see specific
results.
*/
#include <iostream> //Standard includes
#include <ctime>// for srand()
#include "header.h"
using namespace std;

int main()
{
  srand(time(NULL)); //seeds the random function
  Trash wiggumData[DATA_AMOUNT]; //Initializes the databases to their constant size
  Offender lisaData[DATA_AMOUNT];

  int sectorPicked; //To be used later to control flow of the program
  char wantToQuit;
  cout << "Welcome to the Database of Guilt! Are you ready to feel bad?" << endl;
  createArrays(wiggumData, lisaData, NAMES, DATA_AMOUNT); //creates the arrays
  sortArray(wiggumData, DATA_AMOUNT); //sorts Wiggum's array
  sortArray(lisaData, DATA_AMOUNT); //sorts Lisa's array
  printArray(wiggumData, DATA_AMOUNT); //prints Wiggum's array
  printArray(lisaData, DATA_AMOUNT);//prints Lisas array
  cout << "The top two guiltiest people in Springfield are: " << endl;
  printArray(lisaData, 3); //prints the two guiltiest (first two in sorted array) people.
  // calculates who is responsible for half of the trash in town.
  jumpToConclusions(lisaData, wiggumData, (calcWeight(wiggumData, DATA_AMOUNT))/2);
  do
  {
    cout << "Please select a sector to examine.(select 0 to quit)" << endl;
    sectorPicked = getSector(); //Its set to variable to check if user wnats to quit
    if (sectorPicked == 0) //if the user wants to exit, break out of the while loop.
      break;
    //finds the trash according to what the user inputs and outputs the likely offender.
    pickTrash(sectorPicked, wiggumData, lisaData, DATA_AMOUNT);
    do//asks user if they want to quit and checks to make sure input is valid.
    {
      cout << "Would you like to continue using the database?(y or n):";
      cin >> wantToQuit;
    } while(wantToQuit != 'y' && wantToQuit != 'n'); //While the inputs not y or n
  }while(wantToQuit == 'y');//while the user wants to keep querying
  cout << "Thank you for using Chief Wiggum's/Lisa Simpson's database!\n";
  return 0;
}
