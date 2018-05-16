#pragma once

#include "SDLEngine.h"
#include "PWCore.h"

class PWScreenPlay : public SDLScreen
{
private:
	//PWCharacter* mCharacter;

	PWMap* mMap;
	PWCompass* mCompass;

	int mDirection;
	int mPosX;
	int mPosY;
public:
	PWScreenPlay(SDLApp* app/*, PWCharacter* character*/);
	~PWScreenPlay();

	virtual void initialize();
	virtual void update(SDL_Event event);
	virtual void draw();
};
