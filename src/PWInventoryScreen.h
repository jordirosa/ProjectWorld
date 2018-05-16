#pragma once

#include "SDLEngine.h"
#include "PWCore.h"

class PWInventoryScreen : public SDLScreen
{
private:
	PWCharacter* mCharacter;
public:
	PWInventoryScreen(SDLApp* app, PWCharacter* character);
	~PWInventoryScreen();

	virtual void initialize();
	virtual void update(SDL_Event event);
	virtual void draw();
};

