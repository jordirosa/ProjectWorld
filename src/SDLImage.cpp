#include "SDLImage.h"

SDLImage::SDLImage(SDL_Texture *texture, SDL_Surface *surface)
{
	int pitch;
	void* pixels;

	this->mTexture = texture;

	this->mX = 0;
	this->mY = 0;
	SDL_QueryTexture(this->mTexture, NULL, NULL, &this->mWidth, &this->mHeight);
	this->mScale = 1.0f;

	this->mHorizontalAlignment = SDLImageHorizontalAlignment::eHorizontalAlignment::LEFT;
	this->mVerticalAlignment = SDLImageVerticalAlignment::eVerticalAlignment::TOP;
}

SDL_Texture* SDLImage::getTexture()
{
	return this->mTexture;
}

int SDLImage::getPositionX()
{
	return this->mX;
}

int SDLImage::getPositionY()
{
	return this->mY;
}

int SDLImage::getWidth()
{
	return this->mWidth * this->mScale;
}

int SDLImage::getHeight()
{
	return this->mHeight * this->mScale;
}

float SDLImage::getScale()
{
	return this->mScale;
}

SDLImageHorizontalAlignment::eHorizontalAlignment SDLImage::getHorizontalAlignment()
{
	return this->mHorizontalAlignment;
}

SDLImageVerticalAlignment::eVerticalAlignment SDLImage::getVerticalAlignment()
{
	return this->mVerticalAlignment;
}

void SDLImage::setPositionX(int x)
{
	this->mX = x;
}

void SDLImage::setPositionY(int y)
{
	this->mY = y;
}

void SDLImage::setPosition(int x, int y)
{
	this->mX = x;
	this->mY = y;
}

void SDLImage::move(int x, int y)
{
	this->mX += x;
	this->mY += y;
}

void SDLImage::setScale(float scale)
{
	this->mScale = scale;
}

void SDLImage::setHorizontalAlignment(SDLImageHorizontalAlignment::eHorizontalAlignment alignment)
{
	this->mHorizontalAlignment = alignment;
}

void SDLImage::setVerticalAlignment(SDLImageVerticalAlignment::eVerticalAlignment alignment)
{
	this->mVerticalAlignment = alignment;
}

SDLImage::~SDLImage()
{
}
