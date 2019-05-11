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
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

//function prototypes
char read(Critter *obj);
void setGrid(Critter*** grid, int size);

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

//assign derived classes to different elements in the array to imitate move()
	delete grid[1][1];
	delete grid[1][2];
	delete grid[5][5];
	delete grid[10][10];
	grid[1][1] = new Ant;
	grid[1][2] = new Doodlebug;
	grid[5][5] = new Ant;
	grid[10][10] = new Doodlebug;

//define linked-classes-relationship before and/or after each move()
	setGrid(grid, size);
	
	menu menu;
	int choice = 1;
	do 
	{
		int steps = menu.getSteps();
		game.gameflow(Critter*** grid, steps);
		choice = menu.playAgain();
	} while (choice == 1)

//print the grid
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

//check if reading worked, using read(). Pass the linked object.
	//should be 'L'
	cout << "grid[1][1]: " << read(grid[1][1]) << endl;
	//should be '*'
	cout << "grid[0][1]: " << read(grid[1][1]->left) << endl;
	//should be '*'
	cout << "grid[1][0]: " << read(grid[1][1]->up) << endl;
	//should be 'X'
	cout << "grid[1][2]: " << read(grid[1][1]->right) << endl;
	//should be ' '
	cout << "grid[2][1]: " << read(grid[1][1]->down) << endl;
	//should be 'L'
	cout << "grid[1][2]->move(): " << grid[1][2]->move() << endl;
	//should be 'D'
	cout << "grid[1][1]->move(): " << grid[1][1]->move() << endl;
	//should be random
	cout << "grid[5][5]->move(): " << grid[5][5]->move() << endl;
	//should be random
	cout << "grid[10][10]->move(): " << grid[10][10]->move() << endl;

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
	return obj->getType();
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
void setGrid(Critter*** grid, int size)
{
	for (int i = 0; i < size + 2; i++)
	{
		for (int j = 0; j < size + 1; j++)
		{
			//set all the "right" relationships, except the rightmost ones
			grid[i][j]->right = grid[i][j + 1];
		}
		for (int j = 1; j < size + 2; j++)
		{
			//set all the "left" relationships, except the leftmost ones
			grid[i][j]->left = grid[i][j - 1];
		}
		//set the leftmost relationship
		grid[i][0]->left = nullptr;
		//set the rightmost relationship
		grid[i][size + 1]->right = nullptr;
	}
	for (int j = 0; j < size + 2; j++)
	{
		for (int i = 0; i < size + 1; i++)
		{
			//set all the "down" relationships, except the downmost ones
			grid[i][j]->down = grid[i + 1][j];
		}
		for (int i = 1; i < size + 2; i++)
		{
			//set all the "up" relationships, except the upmost ones
			grid[i][j]->up = grid[i - 1][j];
		}
		//set the upmost relationship
		grid[0][j]->up = nullptr;
		//set the downmost relationship
		grid[size + 1][j]->down = nullptr;
	}
}
