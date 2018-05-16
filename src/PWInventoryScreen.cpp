#include "PWInventoryScreen.h"

PWInventoryScreen::PWInventoryScreen(SDLApp* app, PWCharacter* character) : SDLScreen(app)
{
	this->mCharacter = character;
	this->mCharacter->setPosition(0, 0);
}

void PWInventoryScreen::initialize()
{
}

void PWInventoryScreen::update(SDL_Event event)
{
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			this->mApp->quit();
			break;
		}
	}
}

void PWInventoryScreen::draw()
{
	this->mApp->getGraphics()->clear();

	this->mCharacter->draw();

	this->mApp->getGraphics()->render();
}

PWInventoryScreen::~PWInventoryScreen()
{
}
