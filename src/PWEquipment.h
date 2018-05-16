#pragma once

class PWCharacter;

#include <string.h>

#include "SDLEngine.h"

class PWEquipment
{
protected:
	SDLGraphics* mGraphics;

	char mAssetName[11];
	char mName[51];

	SDLImage* mEquipedImage;

	virtual void buildAssetPath(char* path) = 0;
	void buildImagePath(char *path, const char *partName);
public:
	PWEquipment(SDLGraphics* graphics, const char* name);
	~PWEquipment();

	char* getName();

	virtual void draw(PWCharacter* character) = 0;
};

