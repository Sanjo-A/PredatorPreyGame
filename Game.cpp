/******************************************
*May 9th, 2019
*Group 24
*Implementation of Game
*******************************************/

#include <iostream>
#include "game.hpp"
#include "doodlebug.hpp"
#include "ant.hpp"

using std::endl;

game::game()
{

}

void game::gameflow(int steps)
{
  doodlebug* doodle;
  ant* antBug;
  
  for (int i = 0; i < steps; i++) //need to do the steps loop here, because the loop on main will ask if they want to play again.
  {
    doodle->move();
    doodle->breed();
    
    int isDoodStarving = doodle->getStarveCount();
    if (isDoodStarving == 0)
      //something to delete the doodlebug
      
    antBug->move();
    antBug->breed();
    
    
