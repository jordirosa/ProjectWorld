#pragma once

#include <SDL/SDL_ttf.h>

#include "SDLImage.h"

class SDLText : public SDLImage
{
public:
	SDLText(SDL_Texture *texture, SDL_Surface *surface);
	~SDLText();
};

