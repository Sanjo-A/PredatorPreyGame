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
	for (int i = 1; i < size + 1; i++)
	{
		for (int j = 1; j < size + 1; j++)
		{
			grid[i][j]->age();
		}
	}

	for (int i = 0; i < steps; i++) //need to do the steps loop here, because the loop on main will ask if they want to play again.
	{
		for (int i = 1; i < size + 1; i++) //move doodlebugs
		{
			for (int j = 1; j < size + 1; j++) //checks all grid elements to find doodlebugs
			{
				if (grid[i][j]->getType() == 'X')
				{
					char doodMove = grid[i][j]->move();
					if (doodMove == 'U')
					{
						//delete grid[i - 1][j];
						grid[i - 1][j] = new Doodlebug;

						grid[i - 1][j] = grid[i][j];

						delete grid[i][j];
						grid[i][j] = new Critter;
					}

					else if (doodMove == 'D')
					{
						//delete grid[i + 1][j];
						grid[i + 1][j] = new Doodlebug;

						grid[i + 1][j] = grid[i][j];

						delete grid[i][j];
						grid[i][j] = new Critter;

					}

					else if (doodMove == 'L')
					{
						//delete grid[i][j - 1];
						grid[i][j - 1] = new Doodlebug;

						grid[i][j - 1] = grid[i][j];

						delete grid[i][j];
						grid[i][j] = new Critter;

					}

					else if (doodMove == 'R')
					{
						//delete grid[i][j + 1];
						grid[i][j + 1] = new Doodlebug;

						grid[i][j + 1] = grid[i][j];

						delete grid[i][j];
						grid[i][j] = new Critter;

					}
					setGrid(grid, size);
				}
			}
		}

		cout << "move doodlebugs:" << endl;
		for (int i = 0; i < size + 2; i++) //display the grid
		{
			for (int j = 0; j < size + 2; j++)
			{
				cout << grid[i][j]->getType();
			}
			cout << endl;
		}
		cout << endl;


		for (int i = 1; i < size + 1; i++) //move ants
		{
			for (int j = 1; j < size + 1; j++) //checks all grid elements for ants
			{
				if (grid[i][j]->getType() == 'O')
				{
					char antMove = grid[i][j]->move();
					if (antMove == 'U')
					{
						//delete grid[i - 1][j];
						grid[i - 1][j] = new Ant;

						grid[i - 1][j] = grid[i][j];

						delete grid[i][j];
						grid[i][j] = new Critter;
					}

					else if (antMove == 'D')
					{
						//delete grid[i + 1][j];
						grid[i + 1][j] = new Ant;

						grid[i + 1][j] = grid[i][j];

						delete grid[i][j];
						grid[i][j] = new Critter;

					}

					else if (antMove == 'L')
					{
						//delete grid[i][j - 1];
						grid[i][j - 1] = new Ant;

						grid[i][j - 1] = grid[i][j];

						delete grid[i][j];
						grid[i][j] = new Critter;

					}

					else if (antMove == 'R')
					{
						//delete grid[i][j + 1];
						grid[i][j + 1] = new Ant;

						grid[i][j + 1] = grid[i][j];

						delete grid[i][j];
						grid[i][j] = new Critter;

					}

					setGrid(grid, size);

					cout << "move ants:" << endl;
					for (int i = 0; i < size + 2; i++) //display the grid
					{
						for (int j = 0; j < size + 2; j++)
						{
							cout << grid[i][j]->getType();
						}
						cout << endl;
					}
					cout << endl;
				}
			}
		}

		cout << "move ants:" << endl;
		for (int i = 0; i < size + 2; i++) //display the grid
		{
			for (int j = 0; j < size + 2; j++)
			{
				cout << grid[i][j]->getType();
			}
			cout << endl;
		}
		cout << endl;


		for (int i = 1; i < size + 1; i++) //starves doodlebugs
		{
			for (int j = 1; j < size + 1; j++)
			{
				if (grid[i][j]->getType() == 'X') //checks for doodlebug
				{
					if (grid[i][j]->getStarveCount() == 0) //if starve count = 0, removes doodlebug
					{
						delete grid[i][j];
						grid[i][j] = new Critter;
					}
				}
				setGrid(grid, size);
			}
		}

		cout << "starves doodlebugs:" << endl;
		for (int i = 0; i < size + 2; i++) //display the grid
		{
			for (int j = 0; j < size + 2; j++)
			{
				cout << grid[i][j]->getType();
			}
			cout << endl;
		}
		cout << endl;


		for (int i = 1; i < size + 1; i++) //breeds doodlebugs
		{
			for (int j = 1; j < size + 1; j++)
			{
				if (grid[i][j]->getType() == 'X') //checks for doodlebug
				{
					if (grid[i][j]->getBreedCount() == 0)
					{
						char doodBreed = grid[i][j]->breed();
						if (doodBreed == 'U')
						{
							//delete grid[i - 1][j];
							grid[i - 1][j] = new Doodlebug;
						}

						else if (doodBreed == 'D')
						{
							//delete grid[i + 1][j];
							grid[i + 1][j] = new Doodlebug;
						}

						else if (doodBreed == 'L')
						{
							//delete grid[i][j - 1];
							grid[i][j - 1] = new Doodlebug;
						}

						else if (doodBreed == 'R')
						{
							//delete grid[i][j + 1];
							grid[i][j + 1] = new Doodlebug;
						}
						setGrid(grid, size);
					}
				}
			}
		}

		cout << "breeds doodlebugs:" << endl;
		for (int i = 0; i < size + 2; i++) //display the grid
		{
			for (int j = 0; j < size + 2; j++)
			{
				cout << grid[i][j]->getType();
			}
			cout << endl;
		}
		cout << endl;


		for (int i = 1; i < size + 1; i++) //breeds ants
		{
			for (int j = 1; j < size + 1; j++) //checks all grid elements for ants
			{
				if (grid[i][j]->getType() == 'O')
				{
					if (grid[i][j]->getBreedCount() == 0)
					{
						char antBreed = grid[i][j]->breed();
						if (antBreed == 'U')
						{
							delete grid[i - 1][j];
							grid[i - 1][j] = new Ant;
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
		}

		cout << "breeds ants:" << endl;
		for (int i = 0; i < size + 2; i++) //display the grid
		{
			for (int j = 0; j < size + 2; j++)
			{
				cout << grid[i][j]->getType();
			}
			cout << endl;
		}
		cout << endl;


		//cout << endl;
		//for (int i = 0; i < size + 2; i++) //display the grid
		//{
		//	for (int j = 0; j < size + 2; j++)
		//	{
		//		cout << grid[i][j]->getType();
		//	}
		//	cout << endl;
		//}
		//cout << endl;
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
