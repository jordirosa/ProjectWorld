#include "PWCharacter.h"

void PWCharacter::buildAssetPath(char* path)
{
	strcpy(path, "data/character/");
	strcat(path, this->mAssetName);
}

void PWCharacter::buildImagePath(char* path, const char* partName)
{
	strcpy(path, "img/character/");
	strcat(path, this->mAssetName);
	strcat(path, "_");
	strcat(path, partName);
	strcat(path, ".png");
}

void PWCharacter::getClassNameByID(int id, char* name)
{
	switch (id)
	{
		case PWConstants::CLASS_WARRIOR_ID:
			strcpy(name, PWConstants::CLASS_WARRIOR_NAME);
			break;
		case PWConstants::CLASS_ROGUE_ID:
			strcpy(name, PWConstants::CLASS_ROGUE_NAME);
			break;
		case PWConstants::CLASS_WIZARD_ID:
			strcpy(name, PWConstants::CLASS_WIZARD_NAME);
			break;
	}
}

int PWCharacter::getClassIDByName(const char* name)
{
	if (strcmp(name, PWConstants::CLASS_WARRIOR_NAME) == 0)
	{
		return PWConstants::CLASS_WARRIOR_ID;
	}
	else if (strcmp(name, PWConstants::CLASS_ROGUE_NAME) == 0)
	{
		return PWConstants::CLASS_ROGUE_ID;
	}
	else if (strcmp(name, PWConstants::CLASS_WIZARD_NAME) == 0)
	{
		return PWConstants::CLASS_WIZARD_ID;
	}
}

PWCharacter::PWCharacter(SDLGraphics* graphics, const char* assetName)
{
	char path[100];
	std::string line;

	this->mGraphics = graphics;

	strcpy(this->mAssetName, assetName);

	this->mX = 0;
	this->mY = 0;

	this->mScale = 1.0f;

	this->buildAssetPath(path);

	std::ifstream assetFile(path);
	if (assetFile.is_open())
	{
		std::getline(assetFile, line);
		strcpy(this->mName, line.c_str());

		std::getline(assetFile, line);
		this->mXLeftArm = atoi(line.c_str());
		std::getline(assetFile, line);
		this->mYLeftArm = atoi(line.c_str());
		std::getline(assetFile, line);
		this->mXLeftArmEquiped = atoi(line.c_str());
		std::getline(assetFile, line);
		this->mYLeftArmEquiped = atoi(line.c_str());
		std::getline(assetFile, line);
		this->mXRightArm = atoi(line.c_str());
		std::getline(assetFile, line);
		this->mYRightArm = atoi(line.c_str());
		std::getline(assetFile, line);
		this->mXRightArmEquiped = atoi(line.c_str());
		std::getline(assetFile, line);
		this->mYRightArmEquiped = atoi(line.c_str());

		this->buildImagePath(path, PWCharacter::BODY_IMG);
		this->mBodyImage = this->mGraphics->loadImage(path);

		this->setLeftArmUnequiped();
		this->setRightArmUnequiped();

		this->mLegsEquipment = NULL;
		this->mFeetEquipment = NULL;
		this->mChestEquipment = NULL;
		this->mShouldersEquipment = NULL;
		this->mHeadEquipment = NULL;
		this->mWeaponEquipmentLeft = NULL;
		this->mWeaponEquipmentRight = NULL;
	}
	assetFile.close();
}

char *PWCharacter::getAssetName()
{
	return this->mAssetName;
}

int PWCharacter::getPositionX()
{
	return this->mX;
}

int PWCharacter::getPositionY()
{
	return this->mY;
}

float PWCharacter::getScale()
{
	return this->mScale;
}

void PWCharacter::setPositionX(int x)
{
	this->mX = x;

	this->mBodyImage->setPositionX(x);
	(this->mLeftArmEquiped) ? this->mLeftArmImage->setPositionX(x + this->mXLeftArmEquiped) : this->mLeftArmImage->setPositionX(x + this->mXLeftArm);
	(this->mRightArmEquiped) ? this->mRightArmImage->setPositionX(x + this->mXRightArmEquiped) : this->mRightArmImage->setPositionX(x + this->mXRightArm);
}

void PWCharacter::setPositionY(int y)
{
	this->mY = y;

	this->mBodyImage->setPositionY(y);
	(this->mLeftArmEquiped) ? this->mLeftArmImage->setPositionY(y + this->mYLeftArmEquiped) : this->mLeftArmImage->setPositionY(y + this->mYLeftArm);
	(this->mRightArmEquiped) ? this->mRightArmImage->setPositionY(y + this->mYRightArmEquiped) : this->mRightArmImage->setPositionY(y + this->mYRightArm);
}

void PWCharacter::setPosition(int x, int y)
{
	this->setPositionX(x);
	this->setPositionY(y);
}

void PWCharacter::move(int x, int y)
{
	this->setPositionX(this->mX + x);
	this->setPositionY(this->mY + y);
}

void PWCharacter::setScale(float scale)
{
	this->mScale = scale;

	this->mBodyImage->setScale(scale);
	(this->mLeftArmEquiped) ? this->mLeftArmImage->setScale(scale) : this->mLeftArmImage->setScale(scale);
	(this->mRightArmEquiped) ? this->mRightArmImage->setScale(scale) : this->mRightArmImage->setScale(scale);
}

void PWCharacter::setLeftArmEquiped()
{
	char path[80];

	this->mLeftArmEquiped = true;

	this->buildImagePath(path, PWCharacter::LEFTARM_EQUIP_IMG);
	this->mLeftArmImage = this->mGraphics->loadImage(path);

	this->mLeftArmImage->setPositionX(this->mX + this->mXLeftArmEquiped);
	this->mLeftArmImage->setPositionY(this->mY + this->mYLeftArmEquiped);
}

void PWCharacter::setLeftArmUnequiped()
{
	char path[80];

	this->mLeftArmEquiped = false;

	this->buildImagePath(path, PWCharacter::LEFTARM_IMG);
	this->mLeftArmImage = this->mGraphics->loadImage(path);

	this->mLeftArmImage->setPositionX(this->mX + this->mXLeftArm);
	this->mLeftArmImage->setPositionY(this->mY + this->mYLeftArm);
}

void PWCharacter::toggleLeftArmEquiped()
{
	this->mLeftArmEquiped = !this->mLeftArmEquiped;

	(this->mLeftArmEquiped) ? this->setLeftArmEquiped() : this->setLeftArmUnequiped();
}

void PWCharacter::setRightArmEquiped()
{
	char path[80];

	this->mRightArmEquiped = true;

	this->buildImagePath(path, PWCharacter::RIGHTARM_EQUIP_IMG);
	this->mRightArmImage = this->mGraphics->loadImage(path);

	this->mRightArmImage->setPositionX(this->mX + this->mXRightArmEquiped);
	this->mRightArmImage->setPositionY(this->mY + this->mYRightArmEquiped);
}

void PWCharacter::setRightArmUnequiped()
{
	char path[80];

	this->mRightArmEquiped = false;

	this->buildImagePath(path, PWCharacter::RIGHTARM_IMG);
	this->mRightArmImage = this->mGraphics->loadImage(path);

	this->mRightArmImage->setPositionX(this->mX + this->mXRightArm);
	this->mRightArmImage->setPositionY(this->mY + this->mYRightArm);
}

void PWCharacter::toggleRightArmEquiped()
{
	this->mRightArmEquiped = !this->mRightArmEquiped;

	(this->mRightArmEquiped) ? this->setRightArmEquiped() : this->setRightArmUnequiped();
}

void PWCharacter::setLegsEquipment(PWEquipmentLegs* legsEquipment)
{
	this->mLegsEquipment = legsEquipment;
	if (this->mLegsEquipment != NULL)
	{
		((PWEquipmentArmor*)this->mLegsEquipment)->setEquipedCharacterAsset(this->getAssetName());
	}
}

void PWCharacter::setFeetEquipment(PWEquipmentFeet* feetEquipment)
{
	this->mFeetEquipment = feetEquipment;
	if (this->mFeetEquipment != NULL)
	{
		((PWEquipmentArmor*)this->mFeetEquipment)->setEquipedCharacterAsset(this->getAssetName());
	}
}

void PWCharacter::setChestEquipment(PWEquipmentChest* chestEquipment)
{
	this->mChestEquipment = chestEquipment;
	if (this->mChestEquipment != NULL)
	{
		((PWEquipmentArmor*)this->mChestEquipment)->setEquipedCharacterAsset(this->getAssetName());
	}
}

void PWCharacter::setShouldersEquipment(PWEquipmentShoulders* shoulderEquipment)
{
	this->mShouldersEquipment = shoulderEquipment;
	if (this->mShouldersEquipment != NULL)
	{
		((PWEquipmentArmor*)this->mShouldersEquipment)->setEquipedCharacterAsset(this->getAssetName());
	}
}

void PWCharacter::setHeadEquipment(PWEquipmentHead* headEquipment)
{
	this->mHeadEquipment = headEquipment;
	if (this->mHeadEquipment != NULL)
	{
		((PWEquipmentArmor*)this->mHeadEquipment)->setEquipedCharacterAsset(this->getAssetName());
	}
}

void PWCharacter::setWeaponEquipmentLeftHand(PWEquipmentWeapon* weaponEquipment)
{
	this->mWeaponEquipmentLeft = weaponEquipment;

	if (this->mWeaponEquipmentLeft != NULL)
	{
		this->setLeftArmEquiped();
		this->mWeaponEquipmentLeft->setHand(Weapon::eWeaponEquipedHand::LEFT_HAND);
	}
}

void PWCharacter::setWeaponEquipmentRightHand(PWEquipmentWeapon* weaponEquipment)
{
	this->mWeaponEquipmentRight = weaponEquipment;

	if (this->mWeaponEquipmentRight != NULL)
	{
		this->setRightArmEquiped();
		this->mWeaponEquipmentRight->setHand(Weapon::eWeaponEquipedHand::RIGHT_HAND);
	}
}

void PWCharacter::draw()
{
	this->mGraphics->drawImage(this->mBodyImage);
	this->mGraphics->drawImage(this->mLeftArmImage);
	this->mGraphics->drawImage(this->mRightArmImage);

	if (this->mLegsEquipment != NULL)
	{
		((PWEquipment*)this->mLegsEquipment)->draw(this);
	}

	if (this->mFeetEquipment != NULL)
	{
		((PWEquipment*)this->mFeetEquipment)->draw(this);
	}

	if (this->mChestEquipment != NULL)
	{
		((PWEquipment*)this->mChestEquipment)->draw(this);
	}

	if (this->mShouldersEquipment != NULL)
	{
		((PWEquipment*)this->mShouldersEquipment)->draw(this);
	}

	if (this->mHeadEquipment != NULL)
	{
		((PWEquipment*)this->mHeadEquipment)->draw(this);
	}

	if (this->mWeaponEquipmentLeft != NULL)
	{
		((PWEquipment*)this->mWeaponEquipmentLeft)->draw(this);
	}

	if (this->mWeaponEquipmentRight != NULL)
	{
		((PWEquipment*)this->mWeaponEquipmentRight)->draw(this);
	}
}

PWCharacter::~PWCharacter()
{
}
