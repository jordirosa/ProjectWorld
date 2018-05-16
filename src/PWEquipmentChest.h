#pragma once

#include <iostream>
#include <fstream>
#include <string.h>

#include "SDLEngine.h"

#include "PWEquipmentArmor.h"
#include "PWCharacter.h"

class PWEquipmentChest : public PWEquipmentArmor
{
protected:
	virtual void buildAssetPath(char* path);
public:
	PWEquipmentChest(SDLGraphics* graphics, const char* name);
	~PWEquipmentChest();
};

