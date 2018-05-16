#include "PWEquipment1HSword.h"

void PWEquipment1HSword::buildAssetPath(char* path)
{
	strcpy(path, "data/equip/Sword1H_");
	strcat(path, this->mAssetName);
}

void PWEquipment1HSword::buildImagePath(char* path, const char* name, const char* characterClass, const char* hand)
{
	strcpy(path, "img/equip/Sword1H_");
	strcat(path, characterClass);
	strcat(path, "_");
	strcat(path, this->mAssetName);
	strcat(path, "_");
	strcat(path, hand);
	strcat(path, ".png");
}

PWEquipment1HSword::PWEquipment1HSword(SDLGraphics* graphics, const char* name) : PWEquipmentWeapon(graphics, name)
{
	char path[100];
	std::string line;

	this->buildAssetPath(path);

	std::ifstream assetFile(path);
	if (assetFile.is_open())
	{
		std::getline(assetFile, line);
		strcpy(this->mName, line.c_str());
		
		//Warrior
		std::getline(assetFile, line);
		this->buildImagePath(this->mImagesPath[Weapon::eWeaponEquipedHand::RIGHT_HAND], line.c_str(), "Warrior", "R");
		this->buildImagePath(this->mImagesPath[Weapon::eWeaponEquipedHand::LEFT_HAND], line.c_str(), "Warrior", "L");
		this->setHand(Weapon::eWeaponEquipedHand::RIGHT_HAND);

		//Right hand
		std::getline(assetFile, line);
		this->mPosX[Weapon::eWeaponEquipedHand::RIGHT_HAND] = atoi(line.c_str());
		std::getline(assetFile, line);
		this->mPosY[Weapon::eWeaponEquipedHand::RIGHT_HAND] = atoi(line.c_str());
		std::getline(assetFile, line);
		switch (line[0])
		{
			case 'L':
				this->mHorizontalAlignment[Weapon::eWeaponEquipedHand::RIGHT_HAND] = SDLImageHorizontalAlignment::eHorizontalAlignment::LEFT;
				break;
			case 'C':
				this->mHorizontalAlignment[Weapon::eWeaponEquipedHand::RIGHT_HAND] = SDLImageHorizontalAlignment::eHorizontalAlignment::CENTER;
				break;
			case 'R':
				this->mHorizontalAlignment[Weapon::eWeaponEquipedHand::RIGHT_HAND] = SDLImageHorizontalAlignment::eHorizontalAlignment::RIGHT;
				break;
		}
		std::getline(assetFile, line);
		switch (line[0])
		{
		case 'T':
			this->mVerticalAlignment[Weapon::eWeaponEquipedHand::RIGHT_HAND] = SDLImageVerticalAlignment::eVerticalAlignment::TOP;
			break;
		case 'C':
			this->mVerticalAlignment[Weapon::eWeaponEquipedHand::RIGHT_HAND] = SDLImageVerticalAlignment::eVerticalAlignment::CENTER;
			break;
		case 'B':
			this->mVerticalAlignment[Weapon::eWeaponEquipedHand::RIGHT_HAND] = SDLImageVerticalAlignment::eVerticalAlignment::BOTTOM;
			break;
		}

		//Left hand
		std::getline(assetFile, line);
		this->mPosX[Weapon::eWeaponEquipedHand::LEFT_HAND] = atoi(line.c_str());
		std::getline(assetFile, line);
		this->mPosY[Weapon::eWeaponEquipedHand::LEFT_HAND] = atoi(line.c_str());
		std::getline(assetFile, line);
		switch (line[0])
		{
		case 'L':
			this->mHorizontalAlignment[Weapon::eWeaponEquipedHand::LEFT_HAND] = SDLImageHorizontalAlignment::eHorizontalAlignment::LEFT;
			break;
		case 'C':
			this->mHorizontalAlignment[Weapon::eWeaponEquipedHand::LEFT_HAND] = SDLImageHorizontalAlignment::eHorizontalAlignment::CENTER;
			break;
		case 'R':
			this->mHorizontalAlignment[Weapon::eWeaponEquipedHand::LEFT_HAND] = SDLImageHorizontalAlignment::eHorizontalAlignment::RIGHT;
			break;
		}
		std::getline(assetFile, line);
		switch (line[0])
		{
		case 'T':
			this->mVerticalAlignment[Weapon::eWeaponEquipedHand::LEFT_HAND] = SDLImageVerticalAlignment::eVerticalAlignment::TOP;
			break;
		case 'C':
			this->mVerticalAlignment[Weapon::eWeaponEquipedHand::LEFT_HAND] = SDLImageVerticalAlignment::eVerticalAlignment::CENTER;
			break;
		case 'B':
			this->mVerticalAlignment[Weapon::eWeaponEquipedHand::LEFT_HAND] = SDLImageVerticalAlignment::eVerticalAlignment::BOTTOM;
			break;
		}
	}
	assetFile.close();
}

PWEquipment1HSword::~PWEquipment1HSword()
{
}

void PWEquipment1HSword::draw(PWCharacter* character)
{
	this->mEquipedImage->setPosition(character->getPositionX() + this->mPosX[this->mHand], character->getPositionY() + this->mPosY[this->mHand]);
	this->mGraphics->drawImage(this->mEquipedImage);
}
