/******************************************************************************
 * Program Name: Group Project
 * Author: Sae Hyoung Oh
 * Date: 5/6/2019
 * Description:
 * This is the implement file for the RNG class. It details the methods.
 *****************************************************************************/
#include "RNG.hpp"

/******************************************************************************
Name:		intGen()
Called by:	Character classes and Gameplay functor
Calls:		N/A
Passed:		int min, int max
Returns:	int
Description:
This generates a random integer within the range passed by the call.
******************************************************************************/
int RNG::intGen(int min, int max)
{
	std::uniform_int_distribution<int> generator{ min, max };
	return generator(engine);
}

/******************************************************************************
Name:		doubleGen()
Called by:	N/A
Calls:		N/A
Passed:		double min, double max
Returns:	double
Description:
This generates a random double within the range passed by the call.
******************************************************************************/
double RNG::doubleGen(double min, double max)
{
	std::uniform_real_distribution<double> generator{ min, max };
	return generator(engine);
}
