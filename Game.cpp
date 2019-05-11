/******************************************
*May 9th, 2019
*Group 24
*Implementation of Game
*******************************************/

#include <iostream>
#include "Game.hpp"
#include "Doodlebug.hpp"
#include "Ant.hpp"
#include "Critter.hpp"

using std::endl;
using std::cout;

void Game::gameflow(Critter*** grid, int steps)
{
  Doodlebug* doodle;
  Ant* antBug;

  for (int i = 0; i < steps; i++) //need to do the steps loop here, because the loop on main will ask if they want to play again.
  {
    for (int i = 0; i < 22; i++) //move doodlebugs
	{
		for (int j = 0; j < 22; j++) //checks all grid elements to find doodlebugs
		{
			if (grid[i][j]->getType() == 'X')
				grid[i][j]->move();
		}
	}

	for (int i = 0; i < 22; i++) //move ants
	{
		for (int j = 0; j < 22; j++) //checks all grid elements for ants
		{
			if (grid[i][j]->getType() == 'O')
				grid[i][j]->move();
		}
	}

	for (int i = 0; i < 22; i++) //starves doodlebugs
	{
		for (int j = 0; j < 22; j++)
		{
			if (grid[i][j]->getType() == 'X') //checks for doodlebug
			{
				if (grid[i][j]->getStarveCount() == 0) //if starve count = 0, removes doodlebug
					delete grid[i][j];
			}
		}
	}
	for (int i = 0; i < 22; i++) //breeds doodlebugs
	{
		for (int j = 0; j < 22; j++)
		{
			if (grid[i][j]->getType() == 'X') //checks for doodlebug
				grid[i][j]->breed();
		}
	}

	for (int i = 0; i < 22; i++) //breeds ants
	{
		for (int j = 0; j < 22; j++) //checks all grid elements for ants
		{
			if (grid[i][j]->getType() == 'O')
				grid[i][j]->breed();
		}
	}

	cout << endl;
	for (int i = 0; i < 22; i++) //display the grid
	{
		for (int j = 0; j < 22; j++)
		{
			cout << grid[i][j]->getType();
		}
		cout << endl;
	}
	cout << endl;
  }
}

