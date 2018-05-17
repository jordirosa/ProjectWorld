#pragma once
namespace PWConstants
{
	static const int NUM_CLASSES = 3;

	static const int CLASS_ENEMY_ID = -1;
	static const int CLASS_WARRIOR_ID = 0;
	static const int CLASS_ROGUE_ID = 1;
	static const int CLASS_WIZARD_ID = 2;

	static const char* CLASS_ENEMY_NAME = "Enemy";
	static const char* CLASS_WARRIOR_NAME = "Warrior";
	static const char* CLASS_ROGUE_NAME = "Rogue";
	static const char* CLASS_WIZARD_NAME = "Wizard";

	static const char* CHARACTER_ASSET_GOBLIN = "Goblin";

	static const int BACKDROP_FLOOR = 0;
	static const int BACKDROP_CEIL = 1;

	static const int ORIENTATION_NORTH = 0;
	static const int ORIENTATION_EAST = 1;
	static const int ORIENTATION_SOUTH = 2;
	static const int ORIENTATION_WEST = 3;

	static const int DISTANCE_NONE = 0;
	static const int DISTANCE_NEAR = 1;
	static const int DISTANCE_MID = 2;
	static const int DISTANCE_FAR = 3;
	static const int DISTANCE_END = 4;

	static const int POSITION_CENTER = 0;
	static const int POSITION_L1 = 1;
	static const int POSITION_R1 = 2;
	static const int POSITION_L2 = 3;
	static const int POSITION_R2 = 4;
}