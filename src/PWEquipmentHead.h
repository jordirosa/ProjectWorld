#pragma once

#include <iostream>
#include <fstream>
#include <string.h>

#include "SDLEngine.h"

#include "PWEquipmentArmor.h"
#include "PWCharacter.h"

class PWEquipmentHead : public PWEquipmentArmor
{
protected:
	virtual void buildAssetPath(char* path);
public:
	PWEquipmentHead(SDLGraphics* graphics, const char* name);
	~PWEquipmentHead();
};

