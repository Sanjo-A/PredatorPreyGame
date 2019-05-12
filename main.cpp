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
void initializeGrid(Critter*** &grid, int size);
void setGrid(Critter*** &grid, int size);
void placeCritters(Critter*** &grid, int size, int numAntz, int numDoodle);
void printGrid(Critter*** &grid, int size);

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
	cout << "**********************************************" << endl;
	cout << "Welcome to the predator vs. prey game!" << endl;
	cout << "Today we see doodlebugs face off against ants." << endl;
	cout << "**********************************************" << endl;
	cout << endl;
	
	cout << "***EXTRA CREDIT: User Set Grid Size, # Ant, # Doodlebugs***" << endl << endl;
	
	int size = 20;		//size of the board

	//create a dynamic 2D array for critters
	Critter ***grid = new Critter**[size + 2];	//add 2 for the edges

	for (int i = 0; i < size + 2; i++)
	{
		grid[i] = new Critter*[size + 2];		//add 2 for the edges
	}


	Game game;
	Menu menu;
	
	initializeGrid(grid,size); //fill board with critters
	
	menu.menuNumBugs(30,30); //Sanjo, this is where you pass (row, column ints) based on user choice.
	
	placeCritters(grid, size, menu.getNumAnts(), menu.getNumDoodlebugs()); //fills the board with random ants and doodlebugs

	cout << "Move 0: "; // displays initial move
	printGrid(grid, size); //prints the board before any steps have occured
	
	int choice = 1;
	do //do while loop to continue running loop until user wants to quit
	{
		int steps = menu.getSteps(); //grabs number of steps to run
		setGrid(grid, size); //sets directions on board
		std::cin.get();	//test (press enter for next move)

		game.gameflow(grid, steps, size); //the function the has move, breed, starve
		choice = menu.playAgain(); //asks if the user wants to play again
	} while (choice == 1);


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

void initializeGrid(Critter*** &grid, int size)
{
	//initialize the Critters with base class (also serves as empty)
	for (int i = 1; i < size + 1; i++)
	{
		for (int j = 1; j < size + 1; j++)
		{
			grid[i][j] = new Critter;
		}
	}
	//initialize the edges with Edge class
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
/******************************************************************************
 Name:        placeCritters()
 Called by:    N/A
 Calls:        N/A
 Passed:        Critter*** grid, int size, int numDoodle, int numAntz
 Returns:    void
 Description:
 This randomly places user defined number of Doodlebugs and 100 Ants within
 the array bounds.
 Note: Sections that are commented out are used to test the function by
 printing our grid and counting number of doodlebugs and ants placed on
 grid.
 ******************************************************************************/
void placeCritters(Critter*** &grid, int size, int numAntz, int numDoodle)
{
	//these int variables will hold randomly rolled column and rows with the bounds of a 20x20 array
	int randomColumn;
	int randomRow;
	//numAnts and numDoodle are counters that keep track of how many of each critter derived class are placed in array

	RNG randRoll;

	//place ants on array
	for (int counter = 0; counter < numAntz; counter++)
	{
		do {
			//generate a random number between 0 to 19
			randomRow = randRoll.intGen(1, 20);
			randomColumn = randRoll.intGen(1, 20);
			//keep rolling a new random number until a space occupied by a critter is found.
		} while (grid[randomRow][randomColumn]->getType() != ' ');

		//delete the critter placed in the array
		delete grid[randomRow][randomColumn];

		//create an ant in the same deleted critter location
		grid[randomRow][randomColumn] = new Ant;


	}

	 //place DoodleBugs on array
	for (int counter = 0; counter < numDoodle; counter++)
	{
		do {
			//generate a random number between 0 to 19
			randomRow = randRoll.intGen(1, 20);
			randomColumn = randRoll.intGen(1, 20);
			//keep rolling a new random number until a space occupied by a critter and not an ant is found.
		} while (grid[randomRow][randomColumn]->getType() != ' ');

		//delete the critter placed in the array
		delete grid[randomRow][randomColumn];

		//create an ant in the same deleted critter location
		grid[randomRow][randomColumn] = new Doodlebug;
	}
}
/******************************************************************************
 Name:        printGrid()
 Called by:    N/A
 Calls:        N/A
 Passed:        Critter*** &grid, int size
 Returns:    void
 Description:
 Prints out the entire grid.  
 ******************************************************************************/
void printGrid(Critter*** &grid, int size)
{
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
}

