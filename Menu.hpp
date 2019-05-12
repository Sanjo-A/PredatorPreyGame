/******************************************
*May 9, 2019
*Group 24
*Header file for menu class
*******************************************/

#include <iostream>
#ifndef MENU_HPP
#define MENU_HPP

class Menu
{
  private:
      int numDoodlebugs;
      int numAnts;
  public:
      void menuNumBugs(int rowSize, int colSize); // this function displays how many ants and doodlebugs and stores the user input.

      int getSteps();
      int playAgain();
  
      int getNumDoodlebugs();
      int getNumAnts();
};

#endif
