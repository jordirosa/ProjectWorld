#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "SDLEngine.h"

#include "PWEquipmentArmor.h"
#include "PWCharacter.h"

class PWEquipmentLegs : public PWEquipmentArmor
{
protected:
	virtual void buildAssetPath(char* path);
public:
	PWEquipmentLegs(SDLGraphics* graphics, const char* name);
	~PWEquipmentLegs();
};

