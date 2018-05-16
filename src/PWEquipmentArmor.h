#pragma once

#include <string.h>

#include "SDLEngine.h"

#include "PWConstants.h"
#include "PWEquipment.h"
#include "PWCharacter.h"

class PWEquipmentArmor : public PWEquipment
{
protected:
	char mPartName[11];

	char mCharacterAssetName[11];

	virtual void buildAssetPath(char* path) = 0;
	void buildImagePath(char *path, const char* partName);
public:
	PWEquipmentArmor(SDLGraphics* graphics, const char* name);
	~PWEquipmentArmor();

	virtual void setEquipedCharacterAsset(char *characterAssetName);

	virtual void draw(PWCharacter* character);
};

