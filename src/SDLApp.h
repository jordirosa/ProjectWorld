#pragma once

#include "SDLEngine.h"

class SDLApp
{
private:
	bool mExit;

	SDLGraphics* mGraphics;

	SDLScreen* mScreen;
public:
	SDLApp();
	~SDLApp();

	SDLGraphics* getGraphics();

	virtual SDLScreen* getInitialScreen() = 0;
	void setScreen(SDLScreen* screen);

	void run(int resolutionX, int resolutionY, float scale);

	void quit();
};

