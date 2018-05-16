#include "PWEquipment.h"

PWEquipment::PWEquipment(SDLGraphics* graphics, const char* assetName)
{
	this->mGraphics = graphics;

	strcpy(this->mAssetName, assetName);
}

char* PWEquipment::getName()
{
	char name[50];

	strcpy(this->mName, name);

	return name;
}

PWEquipment::~PWEquipment()
{
}
