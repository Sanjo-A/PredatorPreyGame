/******************************************
*May 9th, 2019
*Group 24
*Implementation of Game
*******************************************/

#include <iostream>
#include "Game.hpp"
#include "Doodlebug.hpp"
#include "Ant.hpp"

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
    
    cout << endl;
	  for (int i = 0; i < size + 2; i++)
	  {
		  for (int j = 0; j < size + 2; j++)
		  {
			  cout << grid[i][j]->getType();
		  }
		  cout << endl;
	  }
  }
} 
    
