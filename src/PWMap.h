#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "SDLEngine.h"

#include "PWConstants.h"
#include "PWGlobal.h"

class PWMap
{
private:
	char mAssetName[11];

	SDLImage** mBackdrops;
	SDLImage**** mTileset;
	int mWidth;
	int mHeight;
	int*** mMap;

	SDLGraphics* mGraphics;

	void buildAssetPath(char* path);
	void buildBackdropImagePath(char* path, const char* tileSetName, int backdrop);
	void buildImagePath(char* path, const char* tilesetName, int direction, int distance, int position);
	void loadBackdrop(const char* tilesetName, int backdrop, int posX, int posY, SDLImageHorizontalAlignment::eHorizontalAlignment horizontalAlignment, SDLImageVerticalAlignment::eVerticalAlignment verticalAlignment);
	void loadTile(const char* tilesetName, int direction, int distance, int position, int posX, int posY, SDLImageHorizontalAlignment::eHorizontalAlignment horizontalAlignment, SDLImageVerticalAlignment::eVerticalAlignment verticalAlignment);
	void loadTileset(const char* tilesetName);
public:
	PWMap(SDLGraphics* graphics, const char* name);
	~PWMap();

	void draw(int x, int y, int direction);
	void drawTile(int x, int y, int direction, int distance, int position);

	bool checkWalkable(int x, int y, int orientation);
};

