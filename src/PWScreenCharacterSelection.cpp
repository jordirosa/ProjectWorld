#include "PWScreenCharacterSelection.h"

void PWScreenCharacterSelection::loadCharacter(int ID)
{
	char className[11];

	PWCharacter::getClassNameByID(ID, className);

	this->mCharacter = new PWCharacter(this->mApp->getGraphics(), className);
	this->mCharacter->setPosition(16, 8);
	this->mCharacter->setLegsEquipment(new PWEquipmentLegs(this->mApp->getGraphics(), "0000000001"));
	this->mCharacter->setFeetEquipment(new PWEquipmentFeet(this->mApp->getGraphics(), "0000000001"));
	this->mCharacter->setChestEquipment(new PWEquipmentChest(this->mApp->getGraphics(), "0000000001"));
	this->mCharacter->setShouldersEquipment(new PWEquipmentShoulders(this->mApp->getGraphics(), "0000000001"));
	this->mCharacter->setHeadEquipment(new PWEquipmentHead(this->mApp->getGraphics(), "0000000001"));

	this->mClassText = this->mApp->getGraphics()->loadText("font/app850.fon", 8, className, this->mClassTextColor);
	this->mClassText->setPosition(32, 41);
	this->mClassText->setHorizontalAlignment(SDLImageHorizontalAlignment::eHorizontalAlignment::CENTER);
}

void PWScreenCharacterSelection::nextCharacter()
{
	this->mClassID++;
	if (this->mClassID >= PWConstants::NUM_CLASSES)
	{
		this->mClassID = 0;
	}

	this->loadCharacter(this->mClassID);
}

void PWScreenCharacterSelection::previousCharacter()
{
	this->mClassID--;
	if (this->mClassID < 0)
	{
		this->mClassID = PWConstants::NUM_CLASSES - 1;
	}

	this->loadCharacter(this->mClassID);
}

PWScreenCharacterSelection::PWScreenCharacterSelection(SDLApp* app) : SDLScreen(app)
{
	this->mClassID = 0;

	this->mCharacter = NULL;
	this->mClassText = NULL;

	this->mClassTextColor.r = 255;
	this->mClassTextColor.g = 255;
	this->mClassTextColor.b = 255;
	this->mClassTextColor.a = 255;
}

void PWScreenCharacterSelection::initialize()
{
	this->loadCharacter(this->mClassID);
}

void PWScreenCharacterSelection::update(SDL_Event event)
{
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
			case SDLK_RIGHT:
				this->nextCharacter();
				break;
			case SDLK_LEFT:
				this->previousCharacter();
				break;
			case SDLK_d:
				this->mCharacter->toggleLeftArmEquiped();
				break;
			case SDLK_a:
				this->mCharacter->toggleRightArmEquiped();
				break;
			case SDLK_RETURN:
				//this->mApp->setScreen(new PWScreenPlay(this->mApp, this->mCharacter));
				break;
			case SDLK_ESCAPE:
				this->mApp->quit();
				break;
		}
	}
}

void PWScreenCharacterSelection::draw()
{
	this->mApp->getGraphics()->clear();

	this->mCharacter->draw();
	this->mApp->getGraphics()->drawText(this->mClassText);

	this->mApp->getGraphics()->render();
}

PWScreenCharacterSelection::~PWScreenCharacterSelection()
{
}
