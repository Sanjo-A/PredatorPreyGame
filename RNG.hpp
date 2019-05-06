/******************************************************************************
 * Program Name: Group Project
 * Author: Sae Hyoung Oh
 * Date: 5/6/2019
 * Description:
 * This is the header file for the RNG class. It uses <random> library to
 * create the random-number-generating engine, seeded by a device provided in
 * the library, then uses that engine to generate a random number in range.
 *****************************************************************************/
#ifndef RNG_HPP
#define RNG_HPP
#include <random>
class RNG
{
private:
	std::random_device device;			//random number device for seeding
	std::mt19937 engine{ device() };	//random-bit-generator engine

public:
/******************************************************************************
Name:		intGen()
Called by:	Character classes and Gameplay functor
Calls:		N/A
Passed:		int min, int max
Returns:	int
Description:
This generates a random integer within the range passed by the call.
******************************************************************************/
	int intGen(int min, int max);

/******************************************************************************
Name:		doubleGen()
Called by:	N/A
Calls:		N/A
Passed:		double min, double max
Returns:	double
Description:
This generates a random double within the range passed by the call.
******************************************************************************/
	double doubleGen(double min, double max);
};
#endif
