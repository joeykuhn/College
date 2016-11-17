#include <iostream>
#include "header.h"
using namespace std;

void createArrays(Trash w[], Offender l[], const string n[], const int size)
{
  for (int i = 0; i < size; i++) //for everything in the array
  {
    w[i].sector = randNum(1,7); //set the sector to a random number between 1 and 7
    w[i].weight = randNum(25, 500);//set the weight to a random number between 25 and 500
    l[i].name = n[i]; //set the name of the offender to its corresponding person on the list
    l[i].guilt = randNum(100,10000); //the persons guilt is a random number between 100 and 10000
  }
  return;
}

void printArray(Trash a[],const int size)
{
  for (int i = 0; i < size - 1; i++)
  {//outputs the sector of each item in the array, as well as the weight of that pile
    cout << "Sector " << a[i].sector << ": weight " << a[i].weight << "lbs." << endl;
  }
  return;
}

void printArray(Offender a[],const int size)
{
  for (int i = 0; i < size - 1; i++)
  { //Prints every name in the array, followed by their guilt value.
    cout << a[i].name << ", guilt = " << a[i].guilt << "." << endl;
  }
  return;
}

void jumpToConclusions(Offender a[], Trash b[], int goal)
{
  int i = 0;
  int temp = 0;
  do {
    temp += b[i].weight; //temp is increased by the value so the total can be calculated
    i++;
  } while(temp < goal); //runs the loop until temp is larger than goal
  cout << "The guiltiest offenders responsible for trash are: " << endl;
  printArray(a, i+1); //prints the array from the beginning until we reach the goal
  return;
}

int calcWeight(const Trash a[],const int size)
{
  int total = 0;
  for (int i = 0; i< size; i++)
  {
    total += a[i].weight; //adds the weight of each item until i reaches size
  }
  return (total);
}

void displaySectors(const int size, Trash a[])
{
  for (int i = 0; i < 7; i++) //for each sector
  {
    int totalWeight = 0;
    cout << "Sector " << i+1 << "." << endl;
     for (int j = 0; j < size; j++)
     {
       if (a[j].sector == i) //if the item has the same sector as the one we are looking for
       {
         cout << "Pile " << j+1 << ": " << a[j].weight << endl; //outputs weight of each pile in sector
         totalWeight += a[j].weight; //adds weight to totalWeight so it can be remembered
       }
     }
     cout << "Total weight: " << totalWeight; //outputs total weight of all trash in sector
  }
  return;
}

int getSector()
{
  int input;
  do
  {
    cin >> input;
  }
  while(rangeCheck(0, 7, input)); //checks to make sure input is valid
  return input;
}

void pickTrash(int sector, Trash w[], Offender l[], int size)
{
  short input;
  int runningTotal = 0;
  for (int j = 0; j < size ; j++)
  {//goes through the whole array and outputs the weight of the trash in that sector
    if (w[j].sector == sector)
    {
      cout << "Trash weight: " << w[j].weight << endl; //
     runningTotal += w[j].weight;
    }
  }
  cout << "Total weight of trash in Sector "
  << sector << " is: " << runningTotal << endl;
  do {
    cout << "Please input the weight of the trash pile you would like to examine."
    << endl;
    cin >> input;
  } while(rangeCheck(25,500,input)); //makes sure the input is within range
  for (int i = 0; i < size; i++)
  /*
  If the weight of the object is less than the input, it has reached the first possible person who
  could have put the trash there. the else ensures the program outputs someone if
  the input is less than every person in the array.
  */
    if (w[i].weight < input)
    {
      cout << "The likely offender is " << l[i].name << "." << endl;
      return;
    }
    else if (i == size-1)
    {
      cout << "The likely offender is " << l[i].name << "." << endl;
      return;
    }
}

bool rangeCheck(int min, int max, int tested)
{//if the value we are testing is equal to or between the minimum and maximum, return false.
  //It returns false because this function is used to break out of while loops.
  if (tested >= min && tested <= max)
      return 0;
  else
  {
      cout << "That is not within the acceptable range!" << endl;
      return 1;
  }
}
