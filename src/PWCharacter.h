#pragma once

class PWEquipmentArmor;
class PWEquipmentLegs;
class PWEquipmentFeet;
class PWEquipmentChest;
class PWEquipmentShoulders;
class PWEquipmentHead;
class PWEquipmentWeapon;

#include <iostream>
#include <fstream>
#include <string>

#include "SDLEngine.h"

#include "PWEquipment.h"
#include "PWEquipmentArmor.h"
#include "PWEquipmentWeapon.h"

class PWCharacter
{
private:
	const char* BODY_IMG = "Body";
	const char* LEFTARM_IMG = "Arm_L";
	const char* LEFTARM_EQUIP_IMG = "Arm_LE";
	const char* RIGHTARM_IMG = "Arm_R";
	const char* RIGHTARM_EQUIP_IMG = "Arm_RE";

	SDLGraphics* mGraphics;

	char mAssetName[11];
	char mName[51];

	bool mLeftArmEquiped;
	bool mRightArmEquiped;

	SDLImage* mBodyImage;
	SDLImage* mLeftArmImage;
	SDLImage* mRightArmImage;

	int mX;
	int mY;

	int mXLeftArm;
	int mYLeftArm;
	int mXLeftArmEquiped;
	int mYLeftArmEquiped;
	int mXRightArm;
	int mYRightArm;
	int mXRightArmEquiped;
	int mYRightArmEquiped;

	float mScale;

	PWEquipmentLegs* mLegsEquipment;
	PWEquipmentFeet* mFeetEquipment;
	PWEquipmentChest* mChestEquipment;
	PWEquipmentShoulders* mShouldersEquipment;
	PWEquipmentHead* mHeadEquipment;
	PWEquipmentWeapon* mWeaponEquipmentLeft;
	PWEquipmentWeapon* mWeaponEquipmentRight;

	void buildAssetPath(char* path);
	void buildImagePath(char* path, const char* partName);
public:
	static void getClassNameByID(int id, char* name);
	static int getClassIDByName(const char *name);

	PWCharacter(SDLGraphics* graphics, const char* name);

	char *getAssetName();

	int getPositionX();
	int getPositionY();
	float getScale();

	void setPositionX(int x);
	void setPositionY(int y);
	void setPosition(int x, int y);
	void move(int x, int y);
	void setScale(float scale);

	void setLeftArmEquiped();
	void setLeftArmUnequiped();
	void toggleLeftArmEquiped();
	void setRightArmEquiped();
	void setRightArmUnequiped();
	void toggleRightArmEquiped();

	void setLegsEquipment(PWEquipmentLegs* legsEquipment);
	void setFeetEquipment(PWEquipmentFeet* feetEquipment);
	void setChestEquipment(PWEquipmentChest* chestEquipment);
	void setShouldersEquipment(PWEquipmentShoulders* shouldersEquipment);
	void setHeadEquipment(PWEquipmentHead* headEquipment);
	void setWeaponEquipmentLeftHand(PWEquipmentWeapon* weaponEquipment);
	void setWeaponEquipmentRightHand(PWEquipmentWeapon* weaponEquipment);

	void draw();

	~PWCharacter();
};

