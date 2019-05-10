/*/******************************************************************************
 * Program Name: Group Project
 * Author: Sae Hyoung Oh
 * Date: 5/6/2019
 * Description:
 * This is the header file for the Doodlebug class. It is a derived class of
 * Critter class. It overrides the virtual classes. It also adds a special
 * variable starveCount.
 *****************************************************************************/
#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP
#include "Critter.hpp"

class Doodlebug : public Critter
{
private:
	int starveCount;		//steps until it starves to death

public:
/******************************************************************************
Name:		virtual Doodlebug& operator=()
Called by:	
Calls:		N/A
Passed:		const Doodlebug &rhs
Returns:	Doodlebug&
Description:
This is the assignment operator overloading. It allows copying the type,
breedCount, and starveCount of the right-hand-side Critter object to this one.
It overrides the one in the base class.
******************************************************************************/
	Doodlebug& operator=(const Doodlebug &rhs);

/******************************************************************************
Name:		Doodlebug()
Called by:	
Calls:		N/A
Passed:		N/A
Returns:	N/A
Description:
This is the default constructor for Ant class. The type is set for 'X',
breedCount for 8, starveCount for 3.
******************************************************************************/
	Doodlebug();

/******************************************************************************
Name:		Doodlebug()
Called by:
Calls:		N/A
Passed:		const Doodlebug &rhs
Returns:	N/A
Description:
This is the copy constructor for Doodlebug class. The copies the type,
breedCount, and starveCount from the right-hand-side Critter to instantiate a
Doodlebug object.
******************************************************************************/
	Doodlebug(const Doodlebug &rhs);

//get-function for starveCount
	int getStarveCount(); //changed from char to int

/******************************************************************************
Name:		move()
Called by:	
Calls:		getType() from Critter class, intGen() from RNG class
Passed:		N/A
Returns:	char
Description:
This moves the Doodlebug in a random direction, as specified in the assignment.
It returns the character for the direction it moves.
******************************************************************************/
	virtual char move();

/******************************************************************************
Name:		breed()
Called by:	
Calls:		getType() from Critter class, intGen() from RNG class
Passed:		N/A
Returns:	char
Description:
This breeds the Doodlebug in a random direction, as specified in the
assignment. It returns the character for the direction it breeds.
******************************************************************************/
	virtual char breed();

/******************************************************************************
Name:		age()
Called by:	
Calls:		breed(), move() from Ant class
Passed:		N/A
Returns:	void
Description:
This calls decreases the starveCount and breedCount by one.
******************************************************************************/
	virtual void age();
};
#endif
