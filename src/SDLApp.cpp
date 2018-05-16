#include "SDLApp.h"

SDLApp::SDLApp()
{
	this->mExit = false;

	this->mScreen = NULL;
}

SDLGraphics* SDLApp::getGraphics()
{
	return this->mGraphics;
}

void SDLApp::setScreen(SDLScreen* screen)
{
	this->mScreen = screen;
	this->mScreen->initialize();
}

void SDLApp::run(int resolutionX, int resolutionY, float scale)
{
	SDL_Event event;

	this->mGraphics = new SDLGraphics();
	this->mGraphics->init(scale, resolutionX, resolutionY);

	this->setScreen(this->getInitialScreen());

	while (!this->mExit)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				this->quit();
			}

			this->mScreen->update(event);
		}
		this->mScreen->draw();
	}
}

void SDLApp::quit()
{
	this->mExit = true;
}

SDLApp::~SDLApp()
{
}
