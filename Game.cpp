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
  ant* buggy;
  
  for (int i = 0; i < steps; i++)
  {
    
