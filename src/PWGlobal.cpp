#include "PWGlobal.h"

void PWGlobal::turnRight(int &direction)
{
	switch (direction)
	{
	case PWConstants::ORIENTATION_NORTH:
		direction = PWConstants::ORIENTATION_EAST;
		break;
	case PWConstants::ORIENTATION_EAST:
		direction = PWConstants::ORIENTATION_SOUTH;
		break;
	case PWConstants::ORIENTATION_SOUTH:
		direction = PWConstants::ORIENTATION_WEST;
		break;
	case PWConstants::ORIENTATION_WEST:
		direction = PWConstants::ORIENTATION_NORTH;
		break;
	}
}

void PWGlobal::turnLeft(int &direction)
{
	switch (direction)
	{
	case PWConstants::ORIENTATION_NORTH:
		direction = PWConstants::ORIENTATION_WEST;
		break;
	case PWConstants::ORIENTATION_WEST:
		direction = PWConstants::ORIENTATION_SOUTH;
		break;
	case PWConstants::ORIENTATION_SOUTH:
		direction = PWConstants::ORIENTATION_EAST;
		break;
	case PWConstants::ORIENTATION_EAST:
		direction = PWConstants::ORIENTATION_NORTH;
		break;
	}
}

void PWGlobal::turnBack(int &direction)
{
	switch (direction)
	{
	case PWConstants::ORIENTATION_NORTH:
		direction = PWConstants::ORIENTATION_SOUTH;
		break;
	case PWConstants::ORIENTATION_WEST:
		direction = PWConstants::ORIENTATION_EAST;
		break;
	case PWConstants::ORIENTATION_SOUTH:
		direction = PWConstants::ORIENTATION_NORTH;
		break;
	case PWConstants::ORIENTATION_EAST:
		direction = PWConstants::ORIENTATION_WEST;
		break;
	}
}

void PWGlobal::moveForward(int direction, int &x, int &y, int distance)
{
	switch (direction)
	{
	case PWConstants::ORIENTATION_NORTH:
		y -= distance;
		break;
	case PWConstants::ORIENTATION_EAST:
		x += distance;
		break;
	case PWConstants::ORIENTATION_SOUTH:
		y += distance;
		break;
	case PWConstants::ORIENTATION_WEST:
		x -= distance;
		break;
	}
}

void PWGlobal::moveBack(int direction, int &x, int &y, int distance)
{
	switch (direction)
	{
	case PWConstants::ORIENTATION_NORTH:
		y += distance;
		break;
	case PWConstants::ORIENTATION_EAST:
		x -= distance;
		break;
	case PWConstants::ORIENTATION_SOUTH:
		y -= distance;
		break;
	case PWConstants::ORIENTATION_WEST:
		x += distance;
		break;
	}
}

void PWGlobal::moveLeft(int direction, int &x, int &y, int distance)
{
	switch (direction)
	{
	case PWConstants::ORIENTATION_NORTH:
		x -= distance;
		break;
	case PWConstants::ORIENTATION_EAST:
		y -= distance;
		break;
	case PWConstants::ORIENTATION_SOUTH:
		x += distance;
		break;
	case PWConstants::ORIENTATION_WEST:
		y += distance;
		break;
	}
}

void PWGlobal::moveRight(int direction, int &x, int &y, int distance)
{
	switch (direction)
	{
	case PWConstants::ORIENTATION_NORTH:
		x += distance;
		break;
	case PWConstants::ORIENTATION_EAST:
		y += distance;
		break;
	case PWConstants::ORIENTATION_SOUTH:
		x -= distance;
		break;
	case PWConstants::ORIENTATION_WEST:
		y -= distance;
		break;
	}
}

PWGlobal::PWGlobal()
{
}

PWGlobal::~PWGlobal()
{
}
