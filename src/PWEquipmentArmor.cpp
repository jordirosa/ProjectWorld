#include "PWEquipmentArmor.h"

void PWEquipmentArmor::buildImagePath(char *path, const char* partName)
{
	strcpy(path, "img/equip/");
	strcat(path, this->mCharacterAssetName);
	strcat(path, "_");
	strcat(path, partName);
	strcat(path, "_");
	strcat(path, this->mAssetName);
	strcat(path, ".png");
}
PWEquipmentArmor::PWEquipmentArmor(SDLGraphics* graphics, const char* assetName) : PWEquipment(graphics, assetName)
{
	strcpy(this->mAssetName, assetName);
}

void PWEquipmentArmor::setEquipedCharacterAsset(char *characterAssetName)
{
	char path[100];

	strcpy(this->mCharacterAssetName, characterAssetName);

	buildImagePath(path, this->mPartName);

	this->mEquipedImage = this->mGraphics->loadImage(path);
}

void PWEquipmentArmor::draw(PWCharacter* character)
{
	this->mEquipedImage->setPosition(character->getPositionX(), character->getPositionY());
	this->mEquipedImage->setScale(character->getScale());
	this->mGraphics->drawImage(this->mEquipedImage);
}

PWEquipmentArmor::~PWEquipmentArmor()
{
}
