#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "SDLEngine.h"

#include "PWEquipmentWeapon.h"
#include "PWCharacter.h"

class PWEquipment1HSword : public PWEquipmentWeapon
{
protected:
	virtual void buildAssetPath(char* path);
	void buildImagePath(char* path, const char* name, const char* characterClass, const char* hand);
public:
	PWEquipment1HSword(SDLGraphics* graphics, const char* name);
	~PWEquipment1HSword();

	virtual void draw(PWCharacter* character);
};

