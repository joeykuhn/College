///////////
//Name: Joey Kuhn
//Teacher: Patrick Taylor
//Purpose: To analyze an input of a lake and coordinates to where bombs are thrown, and calculating how many fish are ~~exploded~~ caught.
///////////

// Standard header includes
#include <iostream>
using namespace std;

int main()
{
  int numRows = 0, numColumns = 0, posX = 0, posY = 0, totalFishes = 0, numTrials = 0, a = 0;
  cin >> numTrials; //Gets the number of trials to be run
  for (int i = 0; i < numTrials; i++)
  {
    cin >> numRows >> numColumns; //Gets the number of rows and columns for the current pond.
     int **pond = new int *[numRows]; // Initializing a pointer to an array of pointers that is numRows long.
     for (int j = 0; j < numRows; j++)
    {
      //This makes the arrays of the arrays of pointers mentioned above as wide as they should be.
       pond[j] = new int [numColumns];
    }
    for (int k = 0; k < numRows; k++)
    {
      for (int l = 0; l < numColumns; l++)
      {
        //this iterates through every point in the array and assigns it the value input of the lake.
         cin >> a;
         pond[k][l] = a;
       }
    }
     for (int m = 0; m < 3; m++)
     {
       //Gets the coordinates of where the bomb will be thrown
        cin >> posX >> posY;
        // This loop iterates through the 5x5 block around the point above. It
        // adds all the values to the running total of fish caught and then
        // sets the value to 0.
        for (int xRow = (posX - 2); xRow < (posX + 3); xRow++)
        {
          for (int xCol = (posY - 2); xCol < (posY+3); xCol++)
          {
            totalFishes+= pond[xRow][xCol];
            pond[xRow][xCol] = 0;
          }
        }
     }
    cout << "#" << i << ": Bender catches " << totalFishes << " fish." << endl;
    totalFishes = 0; // Resets the running total fo rthe next loop through.
    for (int o = 0; o < numRows; o++)
    {
      delete[] pond[o]; //clears the memory away from the pointers in the array
      // pond.
    }
    // Clears the memory of the array pond.
    delete[] pond;
    pond = NULL;
  }

  return 0;
}
