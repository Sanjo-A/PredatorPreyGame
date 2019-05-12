/******************************************************************************
 * Program Name: Group Project
 * Author: Sae Hyoung Oh
 * Date: 5/6/2019
 * Description:
 * This is the implement file for the Ant class. It details the methods.
 *****************************************************************************/
#include "Ant.hpp"

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
Ant::Ant()
{
	type = 'O';
	breedCount = 3;
}

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
Ant::Ant(const Ant* &rhs)
{
	type = rhs->type;
	breedCount = rhs->breedCount;
}

/******************************************************************************
Name:		move()
Called by:
Calls:		getType() from Critter class, intGen() from RNG class
Passed:		N/A
Returns:	char
Description:
This moves the Ant in a random direction, as specified in the assignment.
It returns the character for the direction it moves.
It overrides the one in the base class.
******************************************************************************/
char Ant::move()
{
	if (!moved)
	{
		char direction;

		if (up == ' ' && right == ' ' &&
			down == ' ' && left == ' ')
		{
			int num = rng.intGen(1, 4);

			switch (num)
			{
			case 1: direction = 'U';
				break;
			case 2: direction = 'R';
				break;
			case 3: direction = 'D';
				break;
			case 4: direction = 'L';
				break;
			}
		}
		else if (up != ' ' && right == ' ' &&
			down == ' ' && left == ' ')
		{
			int num = rng.intGen(1, 3);

			switch (num)
			{
			case 1: direction = 'R';
				break;
			case 2: direction = 'D';
				break;
			case 3: direction = 'L';
				break;
			}
		}
		else if (up == ' ' && right != ' ' &&
			down == ' ' && left == ' ')
		{
			int num = rng.intGen(1, 3);

			switch (num)
			{
			case 1: direction = 'U';
				break;
			case 2: direction = 'D';
				break;
			case 3: direction = 'L';
				break;
			}
		}
		else if (up == ' ' && right == ' ' &&
			down != ' ' && left == ' ')
		{
			int num = rng.intGen(1, 3);

			switch (num)
			{
			case 1: direction = 'U';
				break;
			case 2: direction = 'R';
				break;
			case 3: direction = 'L';
				break;
			}
		}
		else if (up == ' ' && right == ' ' &&
			down == ' ' && left != ' ')
		{
			int num = rng.intGen(1, 3);

			switch (num)
			{
			case 1: direction = 'U';
				break;
			case 2: direction = 'R';
				break;
			case 3: direction = 'D';
				break;
			}
		}
		else if (up != ' ' && right != ' ' &&
			down == ' ' && left == ' ')
		{
			int num = rng.intGen(1, 2);

			switch (num)
			{
			case 1: direction = 'D';
				break;
			case 2: direction = 'L';
				break;
			}
		}
		else if (up != ' ' && right == ' ' &&
			down != ' ' && left == ' ')
		{
			int num = rng.intGen(1, 2);

			switch (num)
			{
			case 1: direction = 'R';
				break;
			case 2: direction = 'L';
				break;
			}
		}
		else if (up != ' ' && right == ' ' &&
			down == ' ' && left != ' ')
		{
			int num = rng.intGen(1, 2);

			switch (num)
			{
			case 1: direction = 'R';
				break;
			case 2: direction = 'D';
				break;
			}
		}
		else if (up == ' ' && right != ' ' &&
			down != ' ' && left == ' ')
		{
			int num = rng.intGen(1, 2);

			switch (num)
			{
			case 1: direction = 'U';
				break;
			case 2: direction = 'L';
				break;
			}
		}
		else if (up == ' ' && right != ' ' &&
			down == ' ' && left != ' ')
		{
			int num = rng.intGen(1, 2);

			switch (num)
			{
			case 1: direction = 'U';
				break;
			case 2: direction = 'D';
				break;
			}
		}
		else if (up == ' ' && right == ' ' &&
			down != ' ' && left != ' ')
		{
			int num = rng.intGen(1, 2);

			switch (num)
			{
			case 1: direction = 'U';
				break;
			case 2: direction = 'R';
				break;
			}
		}
		else if (up != ' ' && right != ' ' &&
			down != ' ' && left == ' ')
		{
			direction = 'L';
		}
		else if (up != ' ' && right != ' ' &&
			down == ' ' && left != ' ')
		{
			direction = 'D';
		}
		else if (up != ' ' && right == ' ' &&
			down != ' ' && left != ' ')
		{
			direction = 'R';
		}
		else if (up == ' ' && right != ' ' &&
			down != ' ' && left != ' ')
		{
			direction = 'U';
		}
		else if (up != ' ' && right != ' ' &&
			down != ' ' && left != ' ')
		{
			direction = 'N';
		}

		moved = true;
		return direction;
	}
}

/******************************************************************************
Name:		breed()
Called by:
Calls:		getType() from Critter class, intGen() from RNG class
Passed:		N/A
Returns:	char
Description:
This breeds the Ant in a random direction, as specified in the assignment.
It returns the character for the direction it breeds.
It overrides the one in the base class.
******************************************************************************/
char Ant::breed()
{
	breedCount = 3;

	char direction = 'N';

	if (up == ' ' && right == ' ' &&
		down == ' ' && left == ' ')
	{
		int num = rng.intGen(1, 4);

		switch (num)
		{
		case 1: direction = 'U';
			break;
		case 2: direction = 'R';
			break;
		case 3: direction = 'D';
			break;
		case 4: direction = 'L';
			break;
		}
	}
	else if (up != ' ' && right == ' ' &&
		down == ' ' && left == ' ')
	{
		int num = rng.intGen(1, 3);

		switch (num)
		{
		case 1: direction = 'R';
			break;
		case 2: direction = 'D';
			break;
		case 3: direction = 'L';
			break;
		}
	}
	else if (up == ' ' && right != ' ' &&
		down == ' ' && left == ' ')
	{
		int num = rng.intGen(1, 3);

		switch (num)
		{
		case 1: direction = 'U';
			break;
		case 2: direction = 'D';
			break;
		case 3: direction = 'L';
			break;
		}
	}
	else if (up == ' ' && right == ' ' &&
		down != ' ' && left == ' ')
	{
		int num = rng.intGen(1, 3);

		switch (num)
		{
		case 1: direction = 'U';
			break;
		case 2: direction = 'R';
			break;
		case 3: direction = 'L';
			break;
		}
	}
	else if (up == ' ' && right == ' ' &&
		down == ' ' && left != ' ')
	{
		int num = rng.intGen(1, 3);

		switch (num)
		{
		case 1: direction = 'U';
			break;
		case 2: direction = 'R';
			break;
		case 3: direction = 'D';
			break;
		}
	}
	else if (up != ' ' && right != ' ' &&
		down == ' ' && left == ' ')
	{
		int num = rng.intGen(1, 2);

		switch (num)
		{
		case 1: direction = 'D';
			break;
		case 2: direction = 'L';
			break;
		}
	}
	else if (up != ' ' && right == ' ' &&
		down != ' ' && left == ' ')
	{
		int num = rng.intGen(1, 2);

		switch (num)
		{
		case 1: direction = 'R';
			break;
		case 2: direction = 'L';
			break;
		}
	}
	else if (up != ' ' && right == ' ' &&
		down == ' ' && left != ' ')
	{
		int num = rng.intGen(1, 2);

		switch (num)
		{
		case 1: direction = 'R';
			break;
		case 2: direction = 'D';
			break;
		}
	}
	else if (up == ' ' && right != ' ' &&
		down != ' ' && left == ' ')
	{
		int num = rng.intGen(1, 2);

		switch (num)
		{
		case 1: direction = 'U';
			break;
		case 2: direction = 'L';
			break;
		}
	}
	else if (up == ' ' && right != ' ' &&
		down == ' ' && left != ' ')
	{
		int num = rng.intGen(1, 2);

		switch (num)
		{
		case 1: direction = 'U';
			break;
		case 2: direction = 'D';
			break;
		}
	}
	else if (up == ' ' && right == ' ' &&
		down != ' ' && left != ' ')
	{
		int num = rng.intGen(1, 2);

		switch (num)
		{
		case 1: direction = 'U';
			break;
		case 2: direction = 'R';
			break;
		}
	}
	else if (up != ' ' && right != ' ' &&
		down != ' ' && left == ' ')
	{
		direction = 'L';
	}
	else if (up != ' ' && right != ' ' &&
		down == ' ' && left != ' ')
	{
		direction = 'D';
	}
	else if (up != ' ' && right == ' ' &&
		down != ' ' && left != ' ')
	{
		direction = 'R';
	}
	else if (up == ' ' && right != ' ' &&
		down != ' ' && left != ' ')
	{
		direction = 'U';
	}
	else if (up != ' ' && right != ' ' &&
		down != ' ' && left != ' ')
	{
		direction = 'N';
	}

	return direction;
}

/******************************************************************************
Name:		age()
Called by:
Calls:		breed(), move() from Ant class
Passed:		N/A
Returns:	void
Description:
This calls decreases the breedCount by one.
******************************************************************************/
void Ant::age()
{
	breedCount--;
	moved = false;
}
