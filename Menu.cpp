/************************************
*May 9, 2019
*Group 24
*Implementation of menu
*************************************/

#include "Menu.hpp"
using std::cin;
using std::cout;
using std::endl;

int Menu::getSteps()
{
  int steps = 0;
  cout << "How many steps would you like to run?" << endl;
  cin >> steps;
  
  while (!cin) //will run until user enters an int
  {
    cout << "That is not an integer. Please try again." << endl;
    cin.clear();
    cin.ignore();
    cin >> steps;
  }
  
  while (steps < 1 && steps > 5000) //will run until user enters int in the specified range
  {
    cout << "Please enter an integer between 1 and 5000." << endl;
    cin.clear();
    cin.ignore();
    cin >> steps;
  }
  
  cout << "Please hit enter between each step." << endl;
  return steps;
}

int Menu::playAgain() //function to see if user wants to run again
{
  int choice = 0;
  cout << "Would you like to play again? Please enter 1 for yes and 2 for no." << endl;
  cin >> choice;
 
  while (!cin)
  {
    cout << "That is not a valid choice. Please try again." << endl;
    cin.clear();
    cin.ignore();
    cin >> choice;
  }
 
  while (choice != 1 && choice != 2) //only lets user enter 1 or 2 for choice
  {
    cout << "That is not a valid choice. Please try again." << endl;
    cin.clear();
    cin.ignore();
    cin >> choice;
  }
  
  return choice;
}
