#pragma once

#include "SDLEngine.h"
#include "PWCore.h"

#include "PWScreenPlay.h"

class PWScreenCharacterSelection : public SDLScreen
{
private:
	static const int MAX_CLASS_ID;

	int mClassID;

	PWCharacter* mCharacter;
	SDLText* mClassText;
	SDL_Color mClassTextColor;

	void loadCharacter(int ID);

	void nextCharacter();
	void previousCharacter();
public:
	PWScreenCharacterSelection(SDLApp* app);
	~PWScreenCharacterSelection();

	virtual void initialize();
	virtual void update(SDL_Event event);
	virtual void draw();
};

