/************************************
*May 9, 2019
*Group 24
*Implementation of menu
*************************************/

#include "Menu.hpp"
using std::cin;
using std::cout;
using std::endl;
void Menu::menuNumBugs(int rowSize, int colSize)
{
    //input holds the user choice
    int input = 0;
    bool validation = false;
    //Keep repeating menu until user input is between 1 and 5 inclusive
    do
    {
        std::cout << "Enter number of ants in grid [0..." << rowSize*colSize << "]" << endl;
        if (std::cin >> input)
        {
            if(input >= 0 && input <= (rowSize*colSize))
            {
                //Store user input
                numAnts = input;
                validation = true;
            }
        }
        else
        {
            std::cout << "Input failure, try again and make sure the input is an integer within the specified range." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        
    }while(validation == false);
    
    //Keep repeating menu until user input is between 1 and 5 inclusive
    do
    {
        std::cout << "Enter number of doodlebugs in grid [0..." << (rowSize*colSize - numAnts) << "]" << endl;
        if (std::cin >> input)
        {
            if(input >= 0 && input <= (rowSize*colSize - numAnts))
            {
                //Store user input
                numDoodlebugs = input;
                validation = false;
            }
        }
        else
        {
            std::cout << "Input failure, try again and make sure the input is an integer within the specified range." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        
    }while(validation == true);
}
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
  
  while (steps > 1 && steps < 5000) //will run until user enters int in the specified range
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
int Menu::getNumDoodlebugs()
{
    return numDoodlebugs;
}
int Menu::getNumAnts()
{
    return numAnts;
}
