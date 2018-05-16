#pragma once

#include <string.h>

#include "SDLEngine.h"

#include "PWEquipment.h"
#include "PWCharacter.h"

namespace Weapon
{
	enum eWeaponEquipedHand
	{
		RIGHT_HAND,
		LEFT_HAND
	};
}

class PWEquipmentWeapon : public PWEquipment
{
protected:
	char mImagesPath[2][100];

	int mPosX[2];
	int mPosY[2];
	SDLImageHorizontalAlignment::eHorizontalAlignment mHorizontalAlignment[2];
	SDLImageVerticalAlignment::eVerticalAlignment mVerticalAlignment[2];

	Weapon::eWeaponEquipedHand mHand;

	virtual void buildAssetPath(char* path) = 0;
public:
	PWEquipmentWeapon(SDLGraphics* graphics, const char* name);
	~PWEquipmentWeapon();

	void setHand(Weapon::eWeaponEquipedHand hand);

	virtual void draw(PWCharacter* character) = 0;
};

