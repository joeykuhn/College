#ifndef HEADER_H
#define HEADER_H
#include <iostream> //Standard include
#include <ctime>
#include <cstdlib>
using namespace std;

struct Item {
  string name;
  float price;
  int amount;
};

/*
Purpose: To greet the user
Precondition: u needs to be a string that holds the user's name
Postcondition: A greeting is output to the screen
*/
void greetUser(const string u);

/*
Purpose: To get the users name from input
Precondition: none
Postcondition: The users name is returned
*/
string getName();

/*
Purpose: To print the menu to the screen
Precondition: a[] is an array of type Item, the Items in the array must
have amounts
Postcondition: The full menu has been printed to the screen, as well as
if it is NO LONGER AVAILABLE.
*/
void printMenu(Item a[]);

/*
Purpose: get the real selection, take however much they want to get of it,
change the amount based on that, change the total based on the price and amount.
Precondition: subtotal, pick, and x must be initialized. pick must be between
1 and 6. x must be type Item.
Postcondition: the .amount in Item x is changed and the total has changed.
*/
void getSelection(float & subtotal,const int pick, Item & x);

/*
Purpose: gets the user's input for how much they want
Precondition: none
Postcondition: quantity returns how much the user wants
*/
int quantity();

/*
Purpose: outputs how much money the user needs to pay including tax, and
makes sure the user inputs enough.
Precondition: sub is a float and has a value
Postcondition: the user has input their total
*/
void getMoney(float sub);

/*
Purpose: says goodbye to the user
Precondition:none
Postcondition: a goodbye has been output to the screen
*/
void goodBye();

/*
Purpose: checks the range of an input
Precondition: input, from, and to all have values
Postcondition: the function returns false if the input is outside the range and
true if it is inside the range
*/
bool rangecheck(const int from,const int to,const int input);

/*
Purpose:Generates a random number between two numbers
Precondition: min and max are ints and have a value
Postcondition: a random number has been generated between min and max
*/
int randomNum(const int min, const int max);

/*
Purpose: To check if the user's input is the same as the machines and
output the appropriate string if true. if false, change the input to
the machines input and output a snarky comment.
Precondition: user and otherInput must be ints. q[] must be an array of strings,
and i[] mus tbe an array of Items.
Postcondition: outputs a snarky comment and returns the selection.
*/
int reallyWant(const int user, int otherInput,
               const string q[], const Item i[]);

/*
Purpose:check how much the user requested and changes it if it is different
from the machines, after outputting a snarky comment
Precondition: user has a value and is an int
Postcondition: outputs a snarky comment and the function returns the
machines requested amount unless the users == the machines.
*/
int checkReq(int user);

#endif
