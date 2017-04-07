/*
Programmer: Joey Kuhn
Teacher: Dr. Leopold
Date: 10/13/2016
Purpose: To operate Lisa's vending Machine
*/
#include "header.h"
using namespace std;

const string ITEM1NAME = "Ginko Root";//The values for the items.
const float ITEM1PRICE = 4.5;
const int ITEM1AMOUNT = 5;
const string ITEM2NAME = "Mandrake Root";
const float ITEM2PRICE = 1.23;
const int ITEM2AMOUNT = 12;
const string ITEM3NAME = "Ginseng Root";
const float ITEM3PRICE = 2.39;
const int ITEM3AMOUNT = 12;
const string ITEM4NAME = "Square Root";
const float ITEM4PRICE = 99.98;
const int ITEM4AMOUNT = 12;
const string ITEM5NAME = "Vitamin R Root";
const float ITEM5PRICE = 4.5;
const int ITEM5AMOUNT = .78;

//All of the "fun" random outputs
const string QUOTE1 = "No, you really want ";
const string QUOTE2 =
"As my uncle Hal would say, \"I can't do that for you, Dave. You want \"";
const string QUOTE3 =
"Only a loooooser would want THAT.  Try this instead: ";
const string QUOTE4 = "WRONG!  I'm sure you meant to pick ";
const string QUOTE5 = "PPpfffffttt.  I think you need ";
const string QUOTE6 = "Only idiots choose that.  Better to have some ";
const string QUOTE7 =
"Tss, you must be Homer! Only Homer would want that. Lisa's preference is ";

int main()
{
  srand(time(NULL)); //Seeding fo rthe random number generator
  int userSelection = 0;//What the user selects
  int truSelect = 0; //What the machine selects
  int realSelect = 0; //What is selected between the above two
  float total = 0.0; //Running count of money owed
  cout.setf(ios::fixed);//Magic code
  cout.setf(ios::showpoint);
  cout.precision(2);
  string userName = getName(); //Gets the users name
  greetUser(userName); //Greets the user with their own name
  Item items[5] = {{ITEM1NAME,ITEM1PRICE,ITEM1AMOUNT},
  {ITEM2NAME,ITEM2PRICE,ITEM2AMOUNT},
  {ITEM3NAME,ITEM3PRICE,ITEM3AMOUNT}, {ITEM4NAME,ITEM4PRICE,ITEM4AMOUNT},
  {ITEM5NAME,ITEM5PRICE,ITEM5AMOUNT}}; //Initializes items into an array
  string quotes[8] = {QUOTE1, QUOTE2, QUOTE3, QUOTE4, QUOTE5, QUOTE6, QUOTE7};
  while (realSelect != 6) //While the selection is not quit
  {
    printMenu(items); //Print the menu
    cin >> userSelection; //Get what user wants to get
    while (userSelection < 0 || userSelection > 6) //Checks range
    {
      cout << "Read the screen, buddy." << endl;
      cin >> userSelection;
    }
    truSelect = randomNum(1,7); // Picks the machines input
    while(truSelect == 7) //While the machine picks an invalid input
    {
      cout << "You think I can choose 7 for you? No way, hombre." << endl;
      truSelect = randomNum(1,7); //picks a new number
    }
    if (truSelect == 6) //If the machine picks the quit option
    {
      break; //break out of the while loop
    }
    //Checks what the user input vs the machines input and outputs appropriate
    //snarky line
    realSelect = reallyWant(userSelection, truSelect, quotes, items);
    //Takes whatever the real input is and picks correct item
    getSelection(total, realSelect, items[realSelect-1]);

  }
  //Gets the users subtotal, adds appropriate tax,
  //and checks the user paid enough
  getMoney(total);
  return 0; //Ends this god forsaken program
}
