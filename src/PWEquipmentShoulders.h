#pragma once

#include <iostream>
#include <fstream>
#include <string.h>

#include "SDLEngine.h"

#include "PWEquipmentArmor.h"
#include "PWCharacter.h"

class PWEquipmentShoulders : public PWEquipmentArmor
{
protected:
	virtual void buildAssetPath(char* path);
public:
	PWEquipmentShoulders(SDLGraphics* graphics, const char* name);
	~PWEquipmentShoulders();
};

