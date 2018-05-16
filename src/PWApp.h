#pragma once

#include "SDLEngine.h"

#include "PWScreenCharacterSelection.h"

class PWApp : public SDLApp
{
public:
	PWApp();
	~PWApp();

	virtual SDLScreen* getInitialScreen();
};

