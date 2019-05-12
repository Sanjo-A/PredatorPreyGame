/******************************************************
*May 9th, 2019
*Group 24
*Header file for Game class
*******************************************************/
#include "Critter.hpp"
#include "Doodlebug.hpp"
#include <iostream>
#ifndef GAME_HPP
#define GAME_HPP

class Game
{
private: 
	int moveCounter; //keeps track of the move
public:
	void gameflow(Critter*** &grid, int steps, int size);
	void setGrid(Critter*** &grid, int size);
};

#endif // GAME_HPP
