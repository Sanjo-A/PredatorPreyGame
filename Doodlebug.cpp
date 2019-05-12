/******************************************************************************
 * Program Name: Group Project
 * Author: Sae Hyoung Oh
 * Date: 5/6/2019
 * Description:
 * This is the implement file for the Doodlebug class. It details the methods.
 *****************************************************************************/
#include "Doodlebug.hpp"

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
Doodlebug& Doodlebug::operator=(const Doodlebug &rhs)
{
	type = rhs.type;
	breedCount = rhs.breedCount;
	starveCount = rhs.starveCount;

	return *this;
}

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
Doodlebug::Doodlebug()
{
	type = 'X';
	breedCount = 8;
	starveCount = 3;
}

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
Doodlebug::Doodlebug(const Doodlebug &rhs)
{
	type = rhs.type;
	breedCount = rhs.breedCount;
	starveCount = rhs.starveCount;
}

//get-function for starveCount
int Doodlebug::getStarveCount()
{
	return starveCount;
}

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
char Doodlebug::move()
{
	char direction;

	if (up == 'O' || right == 'O' ||
		down == 'O' || left == 'O')
	{
		starveCount = 3;
	}

	if (up == 'O' && right == 'O' &&
		down == 'O' && left == 'O')
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
	else if (up != 'O' && right == 'O' &&
		down == 'O' && left == 'O')
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
	else if (up == 'O' && right != 'O' &&
		down == 'O' && left == 'O')
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
	else if (up == 'O' && right == 'O' &&
		down != 'O' && left == 'O')
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
	else if (up == 'O' && right == 'O' &&
		down == 'O' && left != 'O')
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
	else if (up != 'O' && right != 'O' &&
		down == 'O' && left == 'O')
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
	else if (up != 'O' && right == 'O' &&
		down != 'O' && left == 'O')
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
	else if (up != 'O' && right == 'O' &&
		down == 'O' && left != 'O')
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
	else if (up == 'O' && right != 'O' &&
		down != 'O' && left == 'O')
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
	else if (up == 'O' && right != 'O' &&
		down == 'O' && left != 'O')
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
	else if (up == 'O' && right == 'O' &&
		down != 'O' && left != 'O')
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
	else if (up != 'O' && right != 'O' &&
		down != 'O' && left == 'O')
	{
		direction = 'L';
	}
	else if (up != 'O' && right != 'O' &&
		down == 'O' && left != 'O')
	{
		direction = 'D';
	}
	else if (up != 'O' && right == 'O' &&
		down != 'O' && left != 'O')
	{
		direction = 'R';
	}
	else if (up == 'O' && right != 'O' &&
		down != 'O' && left != 'O')
	{
		direction = 'U';
	}

	else
	{
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
	}

	return direction;
}

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
char Doodlebug::breed()
{
	char direction = 'N';

	if (starveCount != 0 && breedCount == 0)
	{
		breedCount = 8;

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
This calls decreases the starveCount and breedCount by one.
******************************************************************************/
void Doodlebug::age()
{
	starveCount--;
	breedCount--;
}
