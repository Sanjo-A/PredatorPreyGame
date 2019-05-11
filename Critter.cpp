/******************************************************************************
 * Program Name: Group Project
 * Author: Sae Hyoung Oh
 * Date: 5/6/2019
 * Description:
 * This is the implement file for the Critter class. It details the methods.
 *****************************************************************************/
#include "Critter.hpp"


/******************************************************************************
Name:		Critter()
Called by:	
Calls:		N/A
Passed:		N/A
Returns:	N/A
Description:
This is the default constructor for Critter class. The type is set for ' '.
******************************************************************************/
Critter::Critter()
{
	type = ' ';
}

/******************************************************************************
Name:		~Critter()
Called by:
Calls:		N/A
Passed:		N/A
Returns:	N/A
Description:
This is the destructor for Critter class. It deallocates pointers.
******************************************************************************/
Critter::~Critter()
{
	up = nullptr;
	right = nullptr;
	down = nullptr;
	left = nullptr;
}

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
Critter& Critter::operator=(const Critter &rhs)
{
	type = rhs.type;
	breedCount = rhs.breedCount;

	return *this;
}

// get-function for type
char Critter::getType() const
{
	return type;
}

// get-function for breedCount
int Critter::getBreedCount() const
{
	return breedCount;
}
