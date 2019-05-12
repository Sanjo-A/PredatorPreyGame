/************************************
*May 9, 2019
*Group 24
*Implementation of menu
*************************************/

#include "Menu.hpp"
#include <limits>
using std::cin;
using std::cout;
using std::endl;
/******************************************************************************
Name:		menuNumBugs(int rowSize, int colSize)
Called by: Menu class
Calls:		none
Passed:		int rowSize and int colSize
Returns:	void
Description:
This function displays range checked user options for number of ants and doodlebugs
placed on board.  User inputs are robustly validated and stored in numAnts and
numDoodlebugs private member variables contained in Menu class.  
******************************************************************************/
void Menu::menuNumBugs(int rowSize, int colSize)
{
    //input holds the user choice
    int input = 0;
    bool validation = false;
    //Keep repeating menu until user input is between 0 and limit (determined by previous user input for board size)
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
        //error message if char or string inputted
        else
        {
            std::cout << "Input failure, try again and make sure the input is an integer within the specified range." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        
    }while(validation == false);
    
    //Keep repeating menu until user input is between 0 and limit (determined by previous user input for board size)
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
        //error message if char or string inputted
        else
        {
            std::cout << "Input failure, try again and make sure the input is an integer within the specified range." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        
    }while(validation == true);
}
/******************************************************************************
Name:		getSteps()
Called by: Menu class
Calls:		none
Passed:		none
Returns:	int steps
Description:
This function displays range checked user options for number of steps.  The 
function returns the user choice of number of steps back to main where this
member function is originally called.  
******************************************************************************/
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
/******************************************************************************
Name:		playAgain()
Called by: Menu class
Calls:		none
Passed:		none
Returns:	int choice
Description:
This function displays range checked user options for whether to continue the 
simulation or exit the program.  Depending on user choice, function will return
the user choice back to main where this member function is originally called.
******************************************************************************/
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
//A getter function with no parameters and returns the numDoodlebugs integer
int Menu::getNumDoodlebugs()
{
    return numDoodlebugs;
}
//A gettter function with no parameters and returns the numAnts integer
int Menu::getNumAnts()
{
    return numAnts;
}
