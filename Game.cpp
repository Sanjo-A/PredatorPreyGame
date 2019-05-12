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

void Game::gameflow(Critter*** &grid, int steps, int size)
{
	std::cin.get();	//test (press enter for next move)

	for (int k = 0; k < steps; k++) //need to do the steps loop here, because the loop on main will ask if they want to play again.
	{
		//age every critter (also resets "moved")
		for (int i = 1; i < size + 1; i++)
		{
			for (int j = 1; j < size + 1; j++)
			{
				grid[i][j]->age();
			}
		}
		//move doodlebugs
		for (int i = 1; i < size + 1; i++)
		{
			for (int j = 1; j < size + 1; j++)
			{
				//checks all grid elements to find doodlebugs that hasn't moved this turn
				if (grid[i][j]->getType() == 'X' && grid[i][j]->getMoved() == false)
				{
					char doodMove = grid[i][j]->move(); //generates an U,D,L,R direction
					if (doodMove == 'U') //if doodlebug is to move up
					{
						delete grid[i - 1][j]; //deletes the Critter in the space about to be occupied
						grid[i - 1][j] = new Doodlebug; //generates a new doodlebug in the space

						grid[i - 1][j]->setType(grid[i][j]->getType());
						grid[i - 1][j]->setBreedCount(grid[i][j]->getBreedCount()); //carries over breed count
						grid[i - 1][j]->setStarveCount(grid[i][j]->getStarveCount()); //carries over starve

						delete grid[i][j]; //deletes location just moved from
						grid[i][j] = new Critter; //replaces the old spot with an empty space
					}

					else if (doodMove == 'D') //if doodlebug is to move down, the rest of the functions are the same
					{
						delete grid[i + 1][j];
						grid[i + 1][j] = new Doodlebug;

						grid[i + 1][j]->setType(grid[i][j]->getType());
						grid[i + 1][j]->setBreedCount(grid[i][j]->getBreedCount());
						grid[i + 1][j]->setStarveCount(grid[i][j]->getStarveCount());

						delete grid[i][j];
						grid[i][j] = new Critter;
					}

					else if (doodMove == 'L') //moves doodlebug left
					{
						delete grid[i][j - 1];
						grid[i][j - 1] = new Doodlebug;

						grid[i][j - 1]->setType(grid[i][j]->getType());
						grid[i][j - 1]->setBreedCount(grid[i][j]->getBreedCount());
						grid[i][j - 1]->setStarveCount(grid[i][j]->getStarveCount());

						delete grid[i][j];
						grid[i][j] = new Critter;
					}

					else if (doodMove == 'R') //moves doodlebug right
					{
						delete grid[i][j + 1];
						grid[i][j + 1] = new Doodlebug;

						grid[i][j + 1]->setType(grid[i][j]->getType());
						grid[i][j + 1]->setBreedCount(grid[i][j]->getBreedCount());
						grid[i][j + 1]->setStarveCount(grid[i][j]->getStarveCount());

						delete grid[i][j];
						grid[i][j] = new Critter;
					}
					setGrid(grid, size); //sets directions in the grid
				}
			}
		}
		//move ants
		for (int i = 1; i < size + 1; i++)
		{
			for (int j = 1; j < size + 1; j++) 
			{
				//checks all grid elements for ants that hasn't moved this turn
				if (grid[i][j]->getType() == 'O' && grid[i][j]->getMoved() == false)
				{
					char antMove = grid[i][j]->move();
					if (antMove == 'U') //these work the same as the doodlebug move functions
					{
						delete grid[i - 1][j];
						grid[i - 1][j] = new Ant;

						grid[i - 1][j]->setType(grid[i][j]->getType());
						grid[i - 1][j]->setBreedCount(grid[i][j]->getBreedCount());

						delete grid[i][j];
						grid[i][j] = new Critter;
					}

					else if (antMove == 'D')
					{
						delete grid[i + 1][j];
						grid[i + 1][j] = new Ant;

						grid[i + 1][j]->setType(grid[i][j]->getType());
						grid[i + 1][j]->setBreedCount(grid[i][j]->getBreedCount());

						delete grid[i][j];
						grid[i][j] = new Critter;
					}

					else if (antMove == 'L')
					{
						delete grid[i][j - 1];
						grid[i][j - 1] = new Ant;

						grid[i][j - 1]->setType(grid[i][j]->getType());
						grid[i][j - 1]->setBreedCount(grid[i][j]->getBreedCount());

						delete grid[i][j];
						grid[i][j] = new Critter;
					}

					else if (antMove == 'R')
					{
						delete grid[i][j + 1];
						grid[i][j + 1] = new Ant;

						grid[i][j + 1]->setType(grid[i][j]->getType());
						grid[i][j + 1]->setBreedCount(grid[i][j]->getBreedCount());

						delete grid[i][j];
						grid[i][j] = new Critter;
					}

					setGrid(grid, size);
				}
			}
		}
		//starves doodlebugs
		for (int i = 1; i < size + 1; i++)
		{
			for (int j = 1; j < size + 1; j++)
			{
				if (grid[i][j]->getType() == 'X') //checks for doodlebug
				{
					if (grid[i][j]->getStarveCount() == 0) //if starve count = 0, removes doodlebug
					{
						delete grid[i][j];
						grid[i][j] = new Critter; //changed from new Doodlebug to new Critter
					}
				}
				setGrid(grid, size);
			}
		}
		//breeds doodlebugs
		for (int i = 1; i < size + 1; i++)
		{
			for (int j = 1; j < size + 1; j++)
			{
				if (grid[i][j]->getType() == 'X' && grid[i][j]->getBreedCount() == 0) //checks for doodlebug
				{
					char doodBreed = grid[i][j]->breed();
					if (doodBreed == 'U')
					{
						delete grid[i - 1][j]; //deletes the empty critter
						grid[i - 1][j] = new Doodlebug; //adds a new Doodlebug to that location
					}

					else if (doodBreed == 'D')
					{
						delete grid[i + 1][j];
						grid[i + 1][j] = new Doodlebug;
					}

					else if (doodBreed == 'L')
					{
						delete grid[i][j - 1];
						grid[i][j - 1] = new Doodlebug;
					}

					else if (doodBreed == 'R')
					{
						delete grid[i][j + 1];
						grid[i][j + 1] = new Doodlebug;
					}
					setGrid(grid, size);
				}
			}
		}
		//breeds ants
		for (int i = 1; i < size + 1; i++)
		{
			for (int j = 1; j < size + 1; j++) //checks all grid elements for ants
			{
				if (grid[i][j]->getType() == 'O' && grid[i][j]->getBreedCount() == 0)
				{
					char antBreed = grid[i][j]->breed();
					if (antBreed == 'U')
					{
						delete grid[i - 1][j]; //deletes empty critter
						grid[i - 1][j] = new Ant; //adds a new ant to the location
					}

					else if (antBreed == 'D')
					{
						delete grid[i + 1][j];
						grid[i + 1][j] = new Ant;
					}

					else if (antBreed == 'L')
					{
						delete grid[i][j - 1];
						grid[i][j - 1] = new Ant;
					}

					else if (antBreed == 'R')
					{
						delete grid[i][j + 1];
						grid[i][j + 1] = new Ant;
					}
					setGrid(grid, size);
				}
			}
		}
		//display the grid at the end of each step
		cout << endl;
		for (int i = 0; i < size + 2; i++) 
		{
			for (int j = 0; j < size + 2; j++)
			{
				cout << grid[i][j]->getType();
			}
			cout << endl;
		}
		cout << endl;
		std::cin.get();	//"press enter to continue"
	}
}

void Game::setGrid(Critter*** &grid, int size)
{
	for (int i = 0; i < size + 2; i++)
	{
		for (int j = 0; j < size + 1; j++)
		{
			//set all the "right" relationships, except the rightmost ones
			grid[i][j]->right = grid[i][j + 1]->getType();
		}
		for (int j = 1; j < size + 2; j++)
		{
			//set all the "left" relationships, except the leftmost ones
			grid[i][j]->left = grid[i][j - 1]->getType();
		}
		//set the leftmost relationship
		grid[i][0]->left = 'N';
		//set the rightmost relationship
		grid[i][size + 1]->right = 'N';
	}
	for (int j = 0; j < size + 2; j++)
	{
		for (int i = 0; i < size + 1; i++)
		{
			//set all the "down" relationships, except the downmost ones
			grid[i][j]->down = grid[i + 1][j]->getType();
		}
		
		for (int i = 1; i < size + 2; i++)
		{
			//set all the "up" relationships, except the upmost ones
			grid[i][j]->up = grid[i - 1][j]->getType();
		}
		
		//set the upmost relationship
		grid[0][j]->up = 'N';
		//set the downmost relationship
		grid[size + 1][j]->down = 'N';
	}
}
