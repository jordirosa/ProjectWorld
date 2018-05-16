#include "PWCompass.h"

void PWCompass::buildImagePath(char* path, int orientation)
{
	char orientationText[11];

	switch (orientation)
	{
		case PWConstants::ORIENTATION_NORTH:
			strcpy(orientationText, "North");
			break;
		case PWConstants::ORIENTATION_EAST:
			strcpy(orientationText, "East");
			break;
		case PWConstants::ORIENTATION_SOUTH:
			strcpy(orientationText, "South");
			break;
		case PWConstants::ORIENTATION_WEST:
			strcpy(orientationText, "West");
			break;
	}

	strcpy(path, "img/UI/Compass");
	if (orientation != -1)
	{
		strcat(path, "_");
		strcat(path, orientationText);
	}
	strcat(path, ".png");
}

PWCompass::PWCompass(SDLGraphics* graphics)
{
	char path[100];

	this->mGraphics = graphics;

	this->buildImagePath(path, -1);
	this->mCompassImage = this->mGraphics->loadImage(path);
	this->mCompassImage->setPosition(7, 44);
	this->mCompassImage->setVerticalAlignment(SDLImageVerticalAlignment::eVerticalAlignment::BOTTOM);

	this->mOrientationImages = new SDLImage*[4];

	this->buildImagePath(path, PWConstants::ORIENTATION_NORTH);
	this->mOrientationImages[PWConstants::ORIENTATION_NORTH] = this->mGraphics->loadImage(path);
	this->mOrientationImages[PWConstants::ORIENTATION_NORTH]->setPosition(7, 44);
	this->mOrientationImages[PWConstants::ORIENTATION_NORTH]->setVerticalAlignment(SDLImageVerticalAlignment::eVerticalAlignment::BOTTOM);
	this->buildImagePath(path, PWConstants::ORIENTATION_EAST);
	this->mOrientationImages[PWConstants::ORIENTATION_EAST] = this->mGraphics->loadImage(path);
	this->mOrientationImages[PWConstants::ORIENTATION_EAST]->setPosition(7, 44);
	this->mOrientationImages[PWConstants::ORIENTATION_EAST]->setVerticalAlignment(SDLImageVerticalAlignment::eVerticalAlignment::BOTTOM);
	this->buildImagePath(path, PWConstants::ORIENTATION_SOUTH);
	this->mOrientationImages[PWConstants::ORIENTATION_SOUTH] = this->mGraphics->loadImage(path);
	this->mOrientationImages[PWConstants::ORIENTATION_SOUTH]->setPosition(7, 44);
	this->mOrientationImages[PWConstants::ORIENTATION_SOUTH]->setVerticalAlignment(SDLImageVerticalAlignment::eVerticalAlignment::BOTTOM);
	this->buildImagePath(path, PWConstants::ORIENTATION_WEST);
	this->mOrientationImages[PWConstants::ORIENTATION_WEST] = this->mGraphics->loadImage(path);
	this->mOrientationImages[PWConstants::ORIENTATION_WEST]->setPosition(7, 44);
	this->mOrientationImages[PWConstants::ORIENTATION_WEST]->setVerticalAlignment(SDLImageVerticalAlignment::eVerticalAlignment::BOTTOM);

}

void PWCompass::draw(int orientation)
{
	this->mGraphics->drawImage(this->mCompassImage);
	this->mGraphics->drawImage(this->mOrientationImages[orientation]);
}

PWCompass::~PWCompass()
{
}
