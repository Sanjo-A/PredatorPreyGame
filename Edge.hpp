/******************************************************************************
 * Program Name: Group Project
 * Author: Sae Hyoung Oh
 * Date: 5/6/2019
 * Description:
 * This is the header file for the Edge class. It is a derived class of Critter
 * class. It only serves as the edges of the grid.
 *****************************************************************************/
#ifndef EDGE_HPP
#define EDGE_HPP
#include "Critter.hpp"
class Edge : public Critter
{
public:
/******************************************************************************
Name:		Edge()
Called by:	
Calls:		N/A
Passed:		N/A
Returns:	N/A
Description:
This is the default constructor for Ant class. The type is set for '*'.
******************************************************************************/
	Edge();
};
#endif
