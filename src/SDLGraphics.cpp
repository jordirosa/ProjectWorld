#include "SDLGraphics.h"

SDLGraphics::SDLGraphics()
{
	this->mScale = 1.0f;

	this->mWidth = 0;
	this->mHeight = 0;

	this->mWindow = NULL;
	this->mRenderer = NULL;
}

bool SDLGraphics::init(int width, int height)
{
	this->mWidth = width;
	this->mHeight = height;

	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();

	this->mWindow = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width * this->mScale, height * this->mScale, SDL_WINDOW_BORDERLESS );
	this->mRenderer = SDL_CreateRenderer(this->mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_SetRenderDrawColor(this->mRenderer, 0, 0, 0, 255);

	return true;
}

bool SDLGraphics::init(float scale, int width, int height)
{
	this->mScale = scale;

	return this->init(width, height);
}

void SDLGraphics::clear()
{
	SDL_RenderClear(this->mRenderer);
}

void SDLGraphics::render()
{
	SDL_RenderPresent(this->mRenderer);
}

SDLImage* SDLGraphics::loadImage(const char* path)
{
	SDLImage* image = NULL;
	SDL_Texture* texture = NULL;
	SDL_Surface* surface = NULL;

	texture = IMG_LoadTexture(this->mRenderer, path);
	surface = IMG_Load(path);

	if (surface != NULL)
	{
		image = new SDLImage(texture, surface);
	}

	return image;
}

SDLText* SDLGraphics::loadText(const char* path, int size, const char* text, SDL_Color color)
{
	SDLText* textObject = NULL;
	SDL_Texture* texture = NULL;
	SDL_Surface* textSurface;

	TTF_Font * font = TTF_OpenFont(path, size);
	//textSurface = TTF_RenderText_Solid(font, text, color);
	textSurface = TTF_RenderText_Blended(font, text, color);
	texture = SDL_CreateTextureFromSurface(this->mRenderer, textSurface);
	SDL_FreeSurface(textSurface);
	TTF_CloseFont(font);

	if (texture != NULL)
	{
		textObject = new SDLText(texture, textSurface);
	}

	return textObject;
}

void SDLGraphics::drawImage(SDLImage* image)
{
	SDL_Rect destRect;

	float x;
	float y;

	x = image->getPositionX();
	switch (image->getHorizontalAlignment())
	{
		case SDLImageHorizontalAlignment::eHorizontalAlignment::CENTER:
			x -= image->getWidth() / 2;
			break;
		case SDLImageHorizontalAlignment::eHorizontalAlignment::RIGHT:
			x -= image->getWidth();
			break;
	}
	destRect.x = x * this->mScale;

	y = image->getPositionY();
	switch (image->getVerticalAlignment())
	{
		case SDLImageVerticalAlignment::eVerticalAlignment::CENTER:
			y -= image->getHeight() / 2;
			break;
		case SDLImageVerticalAlignment::eVerticalAlignment::BOTTOM:
			y -= image->getHeight();
			break;
	}
	destRect.y = y * this->mScale;

	destRect.w = image->getWidth() * this->mScale;
	destRect.h = image->getHeight() * this->mScale;

	SDL_RenderCopy(this->mRenderer, image->getTexture(), NULL, &destRect);
}

void SDLGraphics::drawText(SDLText* text)
{
	SDL_Rect destRect;

	destRect.x = text->getPositionX() * this->mScale;
	switch (text->getHorizontalAlignment())
	{
	case SDLImageHorizontalAlignment::eHorizontalAlignment::CENTER:
		destRect.x -= ((text->getWidth() * this->mScale) / 2);
		break;
	case SDLImageHorizontalAlignment::eHorizontalAlignment::RIGHT:
		destRect.x -= (text->getWidth() * this->mScale);
		break;
	}
	destRect.y = text->getPositionY() * this->mScale;
	switch (text->getVerticalAlignment())
	{
	case SDLImageVerticalAlignment::eVerticalAlignment::CENTER:
		destRect.y -= ((text->getHeight() * this->mScale) / 2);
		break;
	case SDLImageVerticalAlignment::eVerticalAlignment::BOTTOM:
		destRect.y -= (text->getHeight() * this->mScale);
		break;
	}
	destRect.w = text->getWidth() * this->mScale;
	destRect.h = text->getHeight() * this->mScale;

	SDL_RenderCopy(this->mRenderer, text->getTexture(), NULL, &destRect);
}

SDLGraphics::~SDLGraphics()
{
}
