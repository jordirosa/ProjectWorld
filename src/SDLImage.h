#pragma once

#include <SDL/SDL_image.h>
#include <SDL/SDL_opengl.h>

namespace SDLImageHorizontalAlignment
{
	enum eHorizontalAlignment
	{
		LEFT,
		CENTER,
		RIGHT
	};
}

namespace SDLImageVerticalAlignment
{
	enum eVerticalAlignment
	{
		TOP,
		CENTER,
		BOTTOM
	};
}

class SDLImage
{
private:
	SDL_Texture* mTexture;

	int mX;
	int mY;
	int mWidth;
	int mHeight;

	float mScale;

	SDLImageHorizontalAlignment::eHorizontalAlignment mHorizontalAlignment;
	SDLImageVerticalAlignment::eVerticalAlignment mVerticalAlignment;
public:
	SDLImage(SDL_Texture *texture, SDL_Surface *surface);

	SDL_Texture* getTexture();
	int getPositionX();
	int getPositionY();
	int getWidth();
	int getHeight();
	float getScale();
	SDLImageHorizontalAlignment::eHorizontalAlignment getHorizontalAlignment();
	SDLImageVerticalAlignment::eVerticalAlignment getVerticalAlignment();

	void setPositionX(int x);
	void setPositionY(int y);
	void setPosition(int x, int y);
	void move(int x, int y);
	void setScale(float scale);
	void setHorizontalAlignment(SDLImageHorizontalAlignment::eHorizontalAlignment alignment);
	void setVerticalAlignment(SDLImageVerticalAlignment::eVerticalAlignment alignment);

	~SDLImage();
};

