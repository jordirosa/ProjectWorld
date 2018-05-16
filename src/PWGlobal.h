#pragma once

#include "PWConstants.h"

class PWGlobal
{
public:
	PWGlobal();
	~PWGlobal();

	static void turnRight(int &direction);
	static void turnLeft(int &direction);
	static void turnBack(int &direction);
	static void moveForward(int direction, int &x, int &y, int distance);
	static void moveBack(int direction, int &x, int &y, int distance);
	static void moveLeft(int direction, int &x, int &y, int distance);
	static void moveRight(int direction, int &x, int &y, int distance);
};

