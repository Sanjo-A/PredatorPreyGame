/******************************************************************************
 * Program Name: Group Project
 * Author: Sae Hyoung Oh
 * Date: 5/6/2019
 * Description:
 * This is the main function to test the Critter class and its derived classes.
 * Example codes included.
 *****************************************************************************/
#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include "Edge.hpp"
#include "Game.hpp"
#include "Menu.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

//function prototypes
char read(Critter *obj);
void setGrid(Critter*** &grid, int size);
void initializeBoard(Critter*** &grid, int size);

/******************************************************************************
Name:		main()
Called by:	N/A
Calls:		Ant(), Critter(), Doodlebug(), read(), setGrid()
Passed:		N/A
Returns:	int
Description:
This is the main function to test the Critter class and its derived classes.
Example codes included.
******************************************************************************/
int main()
{
	int size = 20;		//size of the board

	//create a dynamic 2D array for critters
	Critter ***grid = new Critter**[size + 2];	//add 2 for the edges

	for (int i = 0; i < size + 2; i++)
	{
		grid[i] = new Critter*[size + 2];		//add 2 for the edges
	}
	//initiate the Critters with base class (also serves as empty)
	for (int i = 1; i < size + 1; i++)
	{
		for (int j = 1; j < size + 1; j++)
		{
			grid[i][j] = new Critter;
		}
	}
	//initiate the edges with Edge class
	for (int i = 0; i < size + 2; i++)	//left edge
	{
		grid[i][0] = new Edge;
	}
	for (int i = 0; i < size + 2; i++)	//right edge
	{
		grid[i][size + 1] = new Edge;
	}
	for (int i = 1; i < size + 1; i++)	//top edge
	{
		grid[0][i] = new Edge;
	}
	for (int i = 1; i < size + 1; i++)	//bottom edge
	{
		grid[size + 1][i] = new Edge;
	}

	////assign derived classes to different elements in the array to imitate move()
	//delete grid[1][1];
	//delete grid[1][2];
	//delete grid[5][5];
	//delete grid[10][10];
	//grid[1][1] = new Ant;
	//grid[1][2] = new Doodlebug;
	//grid[5][5] = new Ant;
	//grid[10][10] = new Doodlebug;

	//define linked-classes-relationship before and/or after each move()

	Game game;
	Menu menu;
	int choice = 1;
	do
	{
		int steps = menu.getSteps();
		initializeBoard(grid, size);

		for (int i = 0; i < 20 + 2; i++)
		{
			for (int j = 0; j < 20 + 2; j++)
			{
				cout << grid[i][j]->getBugType();
			}
			cout << endl;
		}

		setGrid(grid, size);
		std::cin.get();	//test (press enter for next move)

		game.gameflow(grid, steps, size);
		choice = menu.playAgain();
	} while (choice == 1);

	//print the grid
	cout << endl;
	for (int i = 0; i < size + 2; i++)
	{
		for (int j = 0; j < size + 2; j++)
		{
			cout << grid[i][j]->getBugType();
		}
		cout << endl;
	}
	cout << endl;

	////check if reading worked, using read(). Pass the linked object.
	//	//should be 'L'
	//cout << "grid[1][1]: " << read(grid[1][1]) << endl;
	////should be '*'
	//cout << "grid[0][1]: " << read(grid[1][1]->left) << endl;
	////should be '*'
	//cout << "grid[1][0]: " << read(grid[1][1]->up) << endl;
	////should be 'X'
	//cout << "grid[1][2]: " << read(grid[1][1]->right) << endl;
	////should be ' '
	//cout << "grid[2][1]: " << read(grid[1][1]->down) << endl;
	////should be 'L'
	//cout << "grid[1][2]->move(): " << grid[1][2]->move() << endl;
	////should be 'D'
	//cout << "grid[1][1]->move(): " << grid[1][1]->move() << endl;
	////should be random
	//cout << "grid[5][5]->move(): " << grid[5][5]->move() << endl;
	////should be random
	//cout << "grid[10][10]->move(): " << grid[10][10]->move() << endl;

	//deallocate dynamic array
	for (int i = 0; i < size + 2; i++)
	{
		delete[] grid[i];
		grid[i] = nullptr;
	}
	delete[] grid;
	grid = nullptr;

	return 0;
}

/******************************************************************************
Name:		read()
Called by:	N/A
Calls:		N/A
Passed:		Critter* obj
Returns:	char
Description:
This returns the type of the object passed. This may be necessary for the
linked-class mechanics to work.
******************************************************************************/
char read(Critter* obj)
{
	return obj->getBugType();
}

/******************************************************************************
Name:		setGrid()
Called by:	N/A
Calls:		N/A
Passed:		Critter*** grid, int size
Returns:	void
Description:
This sets the linked-class-relationship between the Critter class objects
inside the array.
******************************************************************************/
void setGrid(Critter*** &grid, int size)
{
	for (int i = 0; i < size + 2; i++)
	{
		for (int j = 0; j < size + 1; j++)
		{
			//set all the "right" relationships, except the rightmost ones
			grid[i][j]->right = grid[i][j + 1]->getBugType();
		}
		for (int j = 1; j < size + 2; j++)
		{
			//set all the "left" relationships, except the leftmost ones
			grid[i][j]->left = grid[i][j - 1]->getBugType();
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
			grid[i][j]->down = grid[i + 1][j]->getBugType();
		}
		for (int i = 1; i < size + 2; i++)
		{
			//set all the "up" relationships, except the upmost ones
			grid[i][j]->up = grid[i - 1][j]->getBugType();
		}
		//set the upmost relationship
		grid[0][j]->up = 'N';
		//set the downmost relationship
		grid[size + 1][j]->down = 'N';
	}
}
/******************************************************************************
 Name:        InitializeBoard()
 Called by:    N/A
 Calls:        N/A
 Passed:        Critter*** grid, int size
 Returns:    void
 Description:
 This randomly places five DoodleBug and 100 Ants within the array bounds.
 Note: Sections that are commented out are used to test the function by
 printing our grid and counting number of doodlebugs and ants placed on
 grid.
 ******************************************************************************/
void initializeBoard(Critter*** &grid, int size)
{
	//these int variables will hold randomly rolled column and rows with the bounds of a 20x20 array
	int randomColumn;
	int randomRow;
	//numAnts and numDoodle are counters that keep track of how many of each critter derived class are placed in array
	int numAnts = 100;
	int numDoodle = 5;
	RNG randRoll;

	//place ants on array
	for (int counter = 0; counter < numAnts; counter++)
	{
		do {
			//generate a random number between 0 to 19
			randomRow = randRoll.intGen(1, 20);
			randomColumn = randRoll.intGen(1, 20);
			//keep rolling a new random number until a space occupied by a critter is found.
		} while (grid[randomRow][randomColumn]->getBugType() != ' ');

		//delete the critter placed in the array
		delete grid[randomRow][randomColumn];

		//create an ant in the same deleted critter location
		grid[randomRow][randomColumn] = new Ant;


	}
	/*
	cout << endl;
	for (int i = 0; i < 20 + 2; i++)
	{
		for (int j = 0; j < 20 + 2; j++)
		{
			cout << grid[i][j]->getType();
		}
		cout << endl;
	}
	cout << endl;
	 */

	 //place DoodleBugs on array
	for (int counter = 0; counter < numDoodle; counter++)
	{
		do {
			//generate a random number between 0 to 19
			randomRow = randRoll.intGen(1, 20);
			randomColumn = randRoll.intGen(1, 20);
			//keep rolling a new random number until a space occupied by a critter and not an ant is found.
		} while (grid[randomRow][randomColumn]->getBugType() != ' ');

		//delete the critter placed in the array
		delete grid[randomRow][randomColumn];

		//create an ant in the same deleted critter location
		grid[randomRow][randomColumn] = new Doodlebug;

		/*
		cout << endl;
		for (int i = 0; i < 20 + 2; i++)
		{
			for (int j = 0; j < 20 + 2; j++)
			{
				cout << grid[i][j]->getType();
			}
			cout << endl;
		}
		cout << endl;
	}
		 */
		 //int antNumber = 0;
		 //int doodleNumber = 0;

		//cout << endl;
		//cout << endl;

		//cout << "Number of Ants: " << antNumber << endl;
	   // cout << "Number of Doodle: " << doodleNumber << endl;
	}
}
