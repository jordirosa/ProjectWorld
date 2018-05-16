#pragma once

#include <iostream>
#include <fstream>
#include <string.h>

#include "SDLEngine.h"

#include "PWEquipmentArmor.h"
#include "PWCharacter.h"

class PWEquipmentFeet : public PWEquipmentArmor
{
protected:
	virtual void buildAssetPath(char* path);
public:
	PWEquipmentFeet(SDLGraphics* graphics, const char* name);
	~PWEquipmentFeet();
};

