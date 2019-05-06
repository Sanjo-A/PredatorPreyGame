/******************************************************************************
 * Program Name: Group Project
 * Author: Sae Hyoung Oh
 * Date: 5/6/2019
 * Description:
 * This is the header file for the Critter class. It is the base class for
 * Ant class and Doodlebug class. The instance of this class also serves as an
 * empty tile in the grid.
 * It is a linked class, with pointers to Critter objects, each direction of
 * this object.
 * It has virtual functions which are defined in the drived classes.
 *****************************************************************************/
#ifndef CRITTER_HPP
#define CRITTER_HPP
#include "RNG.hpp"
class Critter
{
protected:
	char type;			//type of the critter. Base Critter is ' ' (empty).
	int breedCount;		//steps until it breeds

	RNG rng;			//random number generator class object

public:
	Critter *up,		//Critter to the 'up' of this one (row - 1)
		*right,			//Critter to the 'right' of this one (column + 1)
		*down,			//Critter to the 'down' of this one (row + 1)
		*left;			//Critter to the 'left' of this one (column - 1)

/******************************************************************************
Name:		Critter()
Called by:	
Calls:		N/A
Passed:		N/A
Returns:	N/A
Description:
This is the default constructor for Critter class. The type is set for ' '.
******************************************************************************/
	Critter();

/******************************************************************************
Name:		virtual Critter& operator=()
Called by:	
Calls:		N/A
Passed:		const Critter &rhs
Returns:	Critter&
Description:
This is the assignment operator overloading. It allows copying the type and
breedCount of the right-hand-side Critter object to this one.
Override in Doodlebug.
******************************************************************************/
	virtual Critter& operator=(const Critter &rhs);
	
// get-function for type
	char getType() const;

// get-function for breedCount
	int getBreedCount() const;

/******************************************************************************
Name:		move()
Called by:	
Calls:		N/A
Passed:		N/A
Returns:	char
Description:
This is the virtual move function for derived classes, to be defined there.
******************************************************************************/
	virtual char move() { return '?'; };

/******************************************************************************
Name:		breed()
Called by:	
Calls:		N/A
Passed:		N/A
Returns:	char
Description:
This is the virtual breed function for derived classes, to be defined there.
******************************************************************************/
	virtual char breed() { return '?'; };

/******************************************************************************
Name:		age()
Called by:	
Calls:		N/A
Passed:		N/A
Returns:	char
Description:
This is the virtual step function for derived classes, to be defined there.
******************************************************************************/
	virtual void age() {};
};
#endif
