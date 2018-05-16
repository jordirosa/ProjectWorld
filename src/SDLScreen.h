#pragma once

#include "SDLEngine.h"

class SDLScreen
{
protected:
	SDLApp* mApp;
public:
	SDLScreen(SDLApp* app);
	~SDLScreen();

	virtual void initialize() = 0;
	virtual void update(SDL_Event event) = 0;
	virtual void draw() = 0;
};

