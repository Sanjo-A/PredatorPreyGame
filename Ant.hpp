/******************************************************************************
 * Program Name: Group Project
 * Author: Sae Hyoung Oh
 * Date: 5/6/2019
 * Description:
 * This is the header file for the Ant class. It is a derived class of Critter
 * class. It overrides the virtual classes.
 *****************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP
#include "Critter.hpp"

class Ant : public Critter
{
public:
/******************************************************************************
Name:		Ant()
Called by:	
Calls:		N/A
Passed:		N/A
Returns:	N/A
Description:
This is the default constructor for Ant class. The type is set for 'O', and
breedCount for 3.
******************************************************************************/
	Ant();

/******************************************************************************
Name:		Ant()
Called by:	
Calls:		N/A
Passed:		const Ant &rhs
Returns:	N/A
Description:
This is the copy constructor for Ant class. The copies the type and breedCount
from the right-hand-side Critter to instantiate an Ant object.
******************************************************************************/
	Ant(const Ant &rhs);

/******************************************************************************
Name:		move()
Called by:	
Calls:		getType() from Critter class, intGen() from RNG class
Passed:		N/A
Returns:	char
Description:
This moves the Ant in a random direction, as specified in the assignment.
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
This breeds the Ant in a random direction, as specified in the assignment.
It returns the character for the direction it breeds.
******************************************************************************/
	virtual char breed();

/******************************************************************************
Name:		step()
Called by:	
Calls:		breed(), move() from Ant class
Passed:		N/A
Returns:	void
Description:
This calls breed(), decreases the breedCount by one, and calls move().
******************************************************************************/
	virtual void step();
};
#endif
