#include <iostream>
#include <cstdlib>
#include "header.h"
using namespace std;

void greetUser(const string u)
{ //Welcomes user by name
  cout << "Hello, " << u << ". Welcome to Lisa's Vending Machine." << endl;
  return;
}

string getName()
{
  string name;
  cout << "What is your name?:";
  cin >> name; //user inputs name to be used in greeting
  return name;
}

void printMenu(Item a[])
{
  cout << "    Roots 'n Stuff" << endl
  << "-------------------" << endl;
  cout << "1. Ginko Root ($4.50)";
  if (a[0].amount == 0) //If the item is out of stock
    cout << "(NO LONGER AVAILABLE)" << endl;
  else
    cout << endl;
  cout << "2. Mandrake Root ($1.23)";
  if (a[1].amount == 0)
    cout << "(NO LONGER AVAILABLE)" << endl;
  else
    cout << endl;
  cout << "3. Ginseng Root ($2.39)";
  if (a[2].amount == 0)
    cout << "(NO LONGER AVAILABLE)" << endl;
  else
    cout << endl;
  cout << "4. Square Root ($99.98)";
  if (a[3].amount == 0)
    cout << "(NO LONGER AVAILABLE)" << endl;
  else
    cout << endl;
  cout << "5. Vitamin R ($0.78)";
  if (a[4].amount == 0)
    cout << "(NO LONGER AVAILABLE)" << endl;
  else
    cout << endl;
  cout << "6. Quit" << endl;
  return;
}

void getSelection(float & subtotal,const int pick, Item & x)
{
  if (pick == 6) //if selection is 6, break out of the function
    return;
  if (!x.amount) //If the item is out
  {
    cout << "We are out, friendo." << endl;
    return;
  }
  int requested = checkReq(quantity()); //Check the quantity and cout correction
  if (requested > x.amount)
  {//If the amount requested is more than whats in stock
    cout << "I don't have that many! You will get " << x.amount <<
    " and be charged " << (x.amount * x.price) << "." << endl;
    subtotal += (x.amount*x.price); //Charges them for all of whats left
    x.amount = 0; //sets the amount of the item to 0
    return;
  }
  else
  {
    x.amount -= requested;//amount loses amount requested
    subtotal += (requested*x.price); //total increases by amount times price
    cout << "amount of " << x.name << " is " << x.amount << endl;
    return;
  }
}

int quantity()
{
  int amount;
  cout << "How much do you want?" << endl;
  cin >> amount; //Gets the users requested amount
  return amount; //(even if we are just going to ignore it later)
}

void getMoney(float sub)
{
  float input;
  float roundTax;
  int tax;
  if (sub < 100) //if the subtotal is less than 100 buckaronis
    tax = 50;
  else if (sub <= 300) //or if 100 <= subtotal <= 300
  {
    tax = 27;
  }
  else
    tax = 2;
  cout << "Subtotal: " << sub << endl;
  cout << "Tax rate is " << tax << "%." << endl;
  roundTax = ((tax*sub)/100);
  sub += roundTax; //total is total + tax
  cout << "Your total is " << sub << "." << endl;
  do{
    cout << "Please pay what is due." << endl;
    cin >> input;
  }while(input < sub); //takes input until they pay enough
  cout << "Your change is " << (input - sub) << ". Have a nice day." << endl;
  return;
}

void goodBye()
{
  cout << "Goodbye! Thank you for using Lisa's Vending Machine!" << endl;
  return;
}

bool rangecheck(const int from,const int to,const int input)
{
  if (input < from || input > to) //if the number is between from and to
    return 0; //return false
  else
    return 1; //return True
}

int randomNum(int min, int max)
{//return a random number between min and max
  return ((rand() % (max - min + 1)) + min);
}

int reallyWant(const int user, int otherInput,
               const string q[], const Item i[])
{
  int x = randomNum(0,6); //gets a random number between 0 and 6
  cout << "The random number picked (0,6) is " << x << endl;
  if (user == otherInput) //if the user and machine input are the same
  {
    cout << "Fine! ... but you're gonna be sorry." << endl;
      return user;
  }
  else
  {
    cout << q[x] << i[otherInput].name << endl;
    return otherInput;
  }
}

int checkReq(int user)
{//gets a number between 1 and twice what the user wants
  int mine = randomNum(1, (2*user));
  if (user == mine) //if the two are the same
    {
      cout << "I can do that..." << endl;
      return user;
    }
  else if(user > mine) //If the user's is greater
  {
    cout << "That's waayy too much for you. You want " << mine << ".\n";
    return mine;
  }
  else //if the users is less
  {
    cout << "Naw naw naw, you need " << mine << "." << endl;
    return mine;
  }
}
