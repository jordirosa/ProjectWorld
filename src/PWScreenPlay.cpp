#include "PWScreenPlay.h"

PWScreenPlay::PWScreenPlay(SDLApp* app/*, PWCharacter* character*/) : SDLScreen(app)
{
	//this->mCharacter = character;

	this->mDirection = PWConstants::ORIENTATION_NORTH;
	this->mPosX = 1;
	this->mPosY = 7;
}

void PWScreenPlay::initialize()
{
	this->mMap = new PWMap(this->mApp->getGraphics(), "testmap");
	this->mCompass = new PWCompass(this->mApp->getGraphics());
}

void PWScreenPlay::update(SDL_Event event)
{
	int posX = this->mPosX;
	int posY = this->mPosY;
	int orientation = this->mDirection;

	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
			case SDLK_UP:
				PWGlobal::moveForward(this->mDirection, posX, posY, 1);
				PWGlobal::turnBack(orientation);
				if (this->mMap->checkWalkable(posX, posY, orientation))
				{
					this->mPosX = posX;
					this->mPosY = posY;
				}
				break;
			case SDLK_DOWN:
				PWGlobal::moveBack(this->mDirection, posX, posY, 1);
				if (this->mMap->checkWalkable(posX, posY, orientation))
				{
					this->mPosX = posX;
					this->mPosY = posY;
				}
				break;
			case SDLK_LEFT:
				PWGlobal::turnLeft(this->mDirection);
				break;
			case SDLK_RIGHT:
				PWGlobal::turnRight(this->mDirection);
				break;
			case SDLK_ESCAPE:
				this->mApp->quit();
				break;
		}
	}
}

void PWScreenPlay::draw()
{
	this->mApp->getGraphics()->clear();

	this->mMap->draw(this->mPosX, this->mPosY, this->mDirection);
//*******************************************************************
	PWCharacter *character = new PWCharacter(this->mApp->getGraphics(), PWConstants::CHARACTER_ASSET_GOBLIN);
	character->setPosition(4, 8);
	character->setScale(0.5f);
	character->setLegsEquipment(new PWEquipmentLegs(this->mApp->getGraphics(), "0000000001"));
	character->setFeetEquipment(new PWEquipmentFeet(this->mApp->getGraphics(), "0000000001"));
	character->setChestEquipment(new PWEquipmentChest(this->mApp->getGraphics(), "0000000001"));
	character->setShouldersEquipment(new PWEquipmentShoulders(this->mApp->getGraphics(), "0000000001"));
	character->setHeadEquipment(new PWEquipmentHead(this->mApp->getGraphics(), "0000000001"));
	character->draw();
//*******************************************************************
	this->mCompass->draw(this->mDirection);

	this->mApp->getGraphics()->render();
}

PWScreenPlay::~PWScreenPlay()
{
}
