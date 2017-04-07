#ifndef HEADER_H //ensures the header is only loaded once.
#define HEADER_H

#include <iostream>
#include <cstdlib>
using namespace std;


const int DATA_AMOUNT = 15;
const string NAMES[15] = {"Homer", "Maggie", "Bart", "Moe", "Barney", "Marge",
  "Cletus", "Snake", "Mr. Burns", "Dr. Nick", "Krusty the Clown", "Chief Wiggum",
  "Ralph Wiggum", "Skinner", "Lenny"};
/*
Purpose: To generate a random number of any type
Precondition: min and max must have a value.
Postcondition: randNum is equal to a random number equal to or between min and max
*/
template <typename T>
T randNum(const T min, const T max)
{
    return ((rand() % (max - min + 1)) + min);
}
/*
Purpose: to sort an array in descending order.
Precondition: the array must have  a greater than operator, the array must exist, and arraySize
must be an int and have a value > 0.
Postcondition: the array has been rearranged into descending order.
*/
template <typename T>
void sortArray(T a[], const int arraySize)
{
  T maxValue, temp;
  int maxPosition;
  for (int i = 0; i < arraySize-1; i++) //for everything in the array
  {
    //assumes the current value is the highest.
    //the function then iterates through everything past this address in the function.
    //If something is higher than the current value, it is remembered.
    //If something is higher than that, the value is changed to the new max.
    maxValue = a[i];
    maxPosition = i;
    for (int j = i+1; j < arraySize ; j++)
    {
      if (a[j] > maxValue)
      {
        maxValue = a[j];
        maxPosition = j;
      }
    }
    //Swaps the value of the current address with whatever we found to be the highest value.
    temp = a[i];
    a[i] = maxValue;
    a[maxPosition] = temp;
  }
  return;
}

struct Offender
{
    string name;
    int guilt;
    bool operator >(const Offender & other) const
    {
      return (guilt > other.guilt);
    }
};

struct Trash
{
  short sector;
  int weight;
  bool operator >(const Trash & other)
  {
    return (weight > other.weight);
  }
};
/*
Purpose: To create the two arrays, one Trash w[] and one Offender l[].
Precondition: a[] must be Trash and have values, l[] must be Offender and have values, n[]
must be type string, size must be the size of the databases and be an int. the databases have to be
the same size.
Postcondition:assigns each item in the Trash a sector randomly between 1 and 7, and a
random weight between 25 and 500. Each item in the Offender array is assigned a name from
the string array n[], and assigned a random guilt value between 100 and 10000.
each array is iterated through until it reaches size.
*/
void createArrays(Trash w[], Offender l[], const string n[], const int size);

/*
Purpose: to print an array of Trash. {See also: 1570 Student Roster}
Precondition: a[] must be an array of trash and size must be an int and be the size of the array.
Postcondition: the items in a have been printed in the fashion of "Sector " item.sector ": "
item.weight " lbs.".
*/
void printArray(Trash a[],const int size);

/*
Purpose: to print an array of Offenders. {MAGA}
Precondition: a must be an array of Offender, and size must be an int and be the size of the array.
Postcondition: The contents of Offender have been printed to the screen, in the fashion of
item.name, "guilt = " item.guilt.
*/
void printArray(Offender a[],const int size);

/*
Purpose: To calculate half the weight of all the trash, and then find who is responsible for it.
Precondition: a must be an array of Offender and have value, b must be an array of Trash
and have value. goal must be an int and have a value.
Postcondition:The least amount of people responsible for 50 percent of the trash have been output.
*/
void jumpToConclusions(Offender a[], Trash b[], int goal);

/*
Purpose: To calculate the total weight of the array a until address size is reached in a.
Precondition: a must be a Trash array and have values, size muzt be an int and less
than or equal to the number of items in the array.
Postcondition: calcWeight is equal to the total weight of items in a up to size.
*/
int calcWeight(const Trash a[],const int size);

/*
Purpose: to display each sector, all the trash in that sector, and the total trash in that sector.
Precondition: a must be an array of Trash, size must be an int and be less than or equal to
the size of a.
Postcondition: sectors 1-7 have been printed to the screen. in each sector, it lists all of the
piles of trash and their respective weights. the total weight of all the trash in the sector is also
displayed.
*/
void displaySectors(const int size, Trash a[]);

/*
Purpose: to get the sector requested from the user.
Precondition: None.
Postcondition: getSector is an int between 1 and 7.
*/
int getSector();

/*
Purpose:to take a users sector selection and display all the piles in that sector, then
take a users query for a pile in that sector and output the most likely person to have put that there.
Precondition: sector must be an int and be between 1 and 7. w must be an array of Trash and have
values. l must be an array of Offender and have value. size must be an int and be a value less than
the total size of the two databases. The databases must be the same size.
Postcondition: The sector the user selected has been output. The pile the user selected was
output as the responsibility of a person based on their guilt value and the weight of the trash
compared to the other piles.
*/
void pickTrash(int sector, Trash w[], Offender l[], int size);

/*
Purpose: to check that tested is between or equal to min and max.
Precondition: min, max, and tested must have values and be ints.
Postcondition: rangeCheck is equal to false if tested is within the range. This is because
it is used in while loops, and input is taken until it is within range. a message informing the user
they were not within the bounds and rangeCheck is true if tested is not between or equal to min and
max.
*/
bool rangeCheck(int min, int max, int tested);

#endif
