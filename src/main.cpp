#include "PWCore.h"

#include "PWApp.h";

const float GAME_SCALE = 16.0f;

int main(int argc, char* args[])
{
	PWApp* app = new PWApp();

	app->run(64, 48, GAME_SCALE);

	return 0;
}