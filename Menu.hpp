/******************************************
*May 9, 2019
*Group 24
*Header file for menu class
*******************************************/

#include <iostream>
#include "inputValidation.hpp"
#ifndef MENU_HPP
#define MENU_HPP

class Menu
{
private:
    int numDoodlebugs;
    int numAnts;
public:
    void menuNumBugs(int rowSize, int colSize, InputValidation); // this function displays how many ants and doodlebugs and stores the user input.
    
    int getSteps(InputValidation);
    int playAgain(InputValidation);
    
    int getNumDoodlebugs();
    int getNumAnts();
};

#endif
