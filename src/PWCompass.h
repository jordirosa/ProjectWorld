#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "SDLEngine.h"

#include "PWConstants.h"

class PWCompass
{
private:
	SDLImage* mCompassImage;
	SDLImage** mOrientationImages;

	SDLGraphics* mGraphics;

	void buildImagePath(char* path, int orientation);
public:
	PWCompass(SDLGraphics* graphics);
	~PWCompass();

	void draw(int orientation);
};

