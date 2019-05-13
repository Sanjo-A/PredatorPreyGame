/************************************
*May 9, 2019
*Group 24
*Implementation of menu
*************************************/

#include "Menu.hpp"
#include "inputValidation.hpp"
using std::cin;
using std::cout;
using std::endl;

void Menu::menuNumBugs(int rowSize, int colSize, InputValidation valid)
{

    std::cout << "Enter number of ants in grid [0..." << rowSize*colSize << "]" << endl;
    numAnts=valid.intValidation(0, rowSize*colSize);
    

    std::cout << "Enter number of doodlebugs in grid [0..." << (rowSize*colSize - numAnts) << "]" << endl;
    numDoodlebugs=valid.intValidation(0, (rowSize*colSize - numAnts) );

}

int Menu::getSteps(InputValidation valid)
{
  int steps = 0;
  cout << "How many steps would you like to run?" << endl;
    steps = valid.intValidation(1,5000);
  return steps;
}

int Menu::playAgain(InputValidation valid) //function to see if user wants to run again
{
  int choice = 0;
  cout << "Would you like to play again? Please enter 1 for yes and 2 for no." << endl;
  choice = valid.intValidation(1,2);  
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
