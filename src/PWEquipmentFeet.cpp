#include "PWEquipmentFeet.h"

void PWEquipmentFeet::buildAssetPath(char* path)
{
	strcpy(path, "data/equip/Feet_");
	strcat(path, this->mAssetName);
}

PWEquipmentFeet::PWEquipmentFeet(SDLGraphics* graphics, const char* name) : PWEquipmentArmor(graphics, name)
{
	char path[100];
	std::string line;

	strcpy(this->mPartName, "Feet");

	this->buildAssetPath(path);

	/*std::ifstream assetFile(path);
	if (assetFile.is_open())
	{
		std::getline(assetFile, line);
		strcpy(this->mName, line.c_str());

		for (int i = 0; i < PWConstants::NUM_CLASSES; i++)
		{
			std::getline(assetFile, line);
			this->buildImagePath(this->mImagesPath[i], line.c_str());

			std::getline(assetFile, line);
			this->mPosX[i] = atoi(line.c_str());
			std::getline(assetFile, line);
			this->mPosY[i] = atoi(line.c_str());
		}

		this->mEquipedImage = this->mGraphics->loadImage(this->mImagesPath[0]);
		this->mEquipedImage->setHorizontalAlignment(SDLImageHorizontalAlignment::eHorizontalAlignment::CENTER);
		this->mEquipedImage->setVerticalAlignment(SDLImageVerticalAlignment::eVerticalAlignment::BOTTOM);
	}
	assetFile.close();*/
}

PWEquipmentFeet::~PWEquipmentFeet()
{
}
