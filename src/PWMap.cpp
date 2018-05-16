#include "PWMap.h"

void PWMap::buildAssetPath(char* path)
{
	strcpy(path, "data/map/");
	strcat(path, this->mAssetName);
}

void PWMap::buildBackdropImagePath(char* path, const char* tilesetName, int backdrop)
{
	char backdropText[3];

	switch (backdrop)
	{
	case PWConstants::BACKDROP_FLOOR:
		strcpy(backdropText, "BF");
		break;
	case PWConstants::BACKDROP_CEIL:
		strcpy(backdropText, "BC");
		break;
	}
	strcpy(path, "img/map/");
	strcat(path, tilesetName);
	strcat(path, "_");
	strcat(path, backdropText);
	strcat(path, ".png");
}

void PWMap::buildImagePath(char* path, const char* tilesetName, int direction, int distance, int position)
{
	char directionText[2];
	char distanceText[2];
	char positionText[3];

	switch (direction)
	{
		case PWConstants::ORIENTATION_NORTH:
			strcpy(directionText, "N");
			break;
		case PWConstants::ORIENTATION_EAST:
			strcpy(directionText, "E");
			break;
		case PWConstants::ORIENTATION_SOUTH:
			strcpy(directionText, "S");
			break;
		case PWConstants::ORIENTATION_WEST:
			strcpy(directionText, "W");
			break;
	}

	switch (distance)
	{
		case PWConstants::DISTANCE_NONE:
			strcpy(distanceText, "X");
			break;
		case PWConstants::DISTANCE_NEAR:
			strcpy(distanceText, "N");
			break;
		case PWConstants::DISTANCE_MID:
			strcpy(distanceText, "M");
			break;
		case PWConstants::DISTANCE_FAR:
			strcpy(distanceText, "F");
			break;
		case PWConstants::DISTANCE_END:
			strcpy(distanceText, "E");
			break;
	}

	switch (position)
	{
		case PWConstants::POSITION_CENTER:
			strcpy(positionText, "C");
			break;
		case PWConstants::POSITION_L1:
			strcpy(positionText, "L1");
			break;
		case PWConstants::POSITION_R1:
			strcpy(positionText, "R1");
			break;
		case PWConstants::POSITION_L2:
			strcpy(positionText, "L2");
			break;
		case PWConstants::POSITION_R2:
			strcpy(positionText, "R2");
			break;
	}

	strcpy(path, "img/map/");
	strcat(path, tilesetName);
	strcat(path, "_");
	strcat(path, directionText);
	strcat(path, "_");
	strcat(path, distanceText);
	strcat(path, "_");
	strcat(path, positionText);
	strcat(path, ".png");
}

void PWMap::loadBackdrop(const char* tilesetName, int backdrop, int posX, int posY, SDLImageHorizontalAlignment::eHorizontalAlignment horizontalAlignment, SDLImageVerticalAlignment::eVerticalAlignment verticalAlignment)
{
	char path[100];

	this->buildBackdropImagePath(path, tilesetName, backdrop);
	this->mBackdrops[backdrop] = this->mGraphics->loadImage(path);
	this->mBackdrops[backdrop]->setPosition(posX, posY);
	this->mBackdrops[backdrop]->setHorizontalAlignment(horizontalAlignment);
	this->mBackdrops[backdrop]->setVerticalAlignment(verticalAlignment);
}

void PWMap::loadTile(const char* tilesetName, int direction, int distance, int position, int posX, int posY, SDLImageHorizontalAlignment::eHorizontalAlignment horizontalAlignment, SDLImageVerticalAlignment::eVerticalAlignment verticalAlignment)
{
	char path[100];

	this->buildImagePath(path, tilesetName, direction, distance, position);
	this->mTileset[direction][distance][position] = this->mGraphics->loadImage(path);
	this->mTileset[direction][distance][position]->setPosition(posX, posY);
	this->mTileset[direction][distance][position]->setHorizontalAlignment(horizontalAlignment);
	this->mTileset[direction][distance][position]->setVerticalAlignment(verticalAlignment);
}

void PWMap::loadTileset(const char* tilesetName)
{
	this->mBackdrops = new SDLImage*[2];

	this->mTileset = new SDLImage***[4];
	for (int s = 0; s < 4; s++)
	{
		this->mTileset[s] = new SDLImage**[5];
		for (int d = 0; d < 5; d++)
		{
			this->mTileset[s][d] = new SDLImage*[5];
			for (int p = 0; p < 5; p++)
			{
				this->mTileset[s][d][p] = NULL;
			}
		}
	}

	this->loadBackdrop(tilesetName, PWConstants::BACKDROP_FLOOR, 0, 35, SDLImageHorizontalAlignment::eHorizontalAlignment::LEFT, SDLImageVerticalAlignment::eVerticalAlignment::BOTTOM);
	this->loadBackdrop(tilesetName, PWConstants::BACKDROP_CEIL, 0, 0, SDLImageHorizontalAlignment::eHorizontalAlignment::LEFT, SDLImageVerticalAlignment::eVerticalAlignment::TOP);

	this->loadTile(tilesetName, PWConstants::ORIENTATION_EAST, PWConstants::DISTANCE_NONE, PWConstants::POSITION_L1, 0, 0, SDLImageHorizontalAlignment::eHorizontalAlignment::LEFT, SDLImageVerticalAlignment::eVerticalAlignment::TOP);
	this->loadTile(tilesetName, PWConstants::ORIENTATION_WEST, PWConstants::DISTANCE_NONE, PWConstants::POSITION_R1, 35, 0, SDLImageHorizontalAlignment::eHorizontalAlignment::RIGHT, SDLImageVerticalAlignment::eVerticalAlignment::TOP);
	
	this->loadTile(tilesetName, PWConstants::ORIENTATION_SOUTH, PWConstants::DISTANCE_NEAR, PWConstants::POSITION_CENTER, 17, 17, SDLImageHorizontalAlignment::eHorizontalAlignment::CENTER, SDLImageVerticalAlignment::eVerticalAlignment::CENTER);
	this->loadTile(tilesetName, PWConstants::ORIENTATION_SOUTH, PWConstants::DISTANCE_NEAR, PWConstants::POSITION_L1, 0, 17, SDLImageHorizontalAlignment::eHorizontalAlignment::LEFT, SDLImageVerticalAlignment::eVerticalAlignment::CENTER);
	this->loadTile(tilesetName, PWConstants::ORIENTATION_SOUTH, PWConstants::DISTANCE_NEAR, PWConstants::POSITION_R1, 35, 17, SDLImageHorizontalAlignment::eHorizontalAlignment::RIGHT, SDLImageVerticalAlignment::eVerticalAlignment::CENTER);
	this->loadTile(tilesetName, PWConstants::ORIENTATION_EAST, PWConstants::DISTANCE_NEAR, PWConstants::POSITION_L1, 4, 0, SDLImageHorizontalAlignment::eHorizontalAlignment::LEFT, SDLImageVerticalAlignment::eVerticalAlignment::TOP);
	this->loadTile(tilesetName, PWConstants::ORIENTATION_WEST, PWConstants::DISTANCE_NEAR, PWConstants::POSITION_R1, 31, 0, SDLImageHorizontalAlignment::eHorizontalAlignment::RIGHT, SDLImageVerticalAlignment::eVerticalAlignment::TOP);
	this->loadTile(tilesetName, PWConstants::ORIENTATION_EAST, PWConstants::DISTANCE_NEAR, PWConstants::POSITION_L2, 0, 0, SDLImageHorizontalAlignment::eHorizontalAlignment::LEFT, SDLImageVerticalAlignment::eVerticalAlignment::TOP);
	this->loadTile(tilesetName, PWConstants::ORIENTATION_WEST, PWConstants::DISTANCE_NEAR, PWConstants::POSITION_R2, 35, 0, SDLImageHorizontalAlignment::eHorizontalAlignment::RIGHT, SDLImageVerticalAlignment::eVerticalAlignment::TOP);

	this->loadTile(tilesetName, PWConstants::ORIENTATION_SOUTH, PWConstants::DISTANCE_MID, PWConstants::POSITION_CENTER, 17, 17, SDLImageHorizontalAlignment::eHorizontalAlignment::CENTER, SDLImageVerticalAlignment::eVerticalAlignment::CENTER);
	this->loadTile(tilesetName, PWConstants::ORIENTATION_SOUTH, PWConstants::DISTANCE_MID, PWConstants::POSITION_L1, 1, 17, SDLImageHorizontalAlignment::eHorizontalAlignment::LEFT, SDLImageVerticalAlignment::eVerticalAlignment::CENTER);
	this->loadTile(tilesetName, PWConstants::ORIENTATION_SOUTH, PWConstants::DISTANCE_MID, PWConstants::POSITION_R1, 34, 17, SDLImageHorizontalAlignment::eHorizontalAlignment::RIGHT, SDLImageVerticalAlignment::eVerticalAlignment::CENTER);
	this->loadTile(tilesetName, PWConstants::ORIENTATION_EAST, PWConstants::DISTANCE_MID, PWConstants::POSITION_L1, 12, 0, SDLImageHorizontalAlignment::eHorizontalAlignment::LEFT, SDLImageVerticalAlignment::eVerticalAlignment::TOP);
	this->loadTile(tilesetName, PWConstants::ORIENTATION_WEST, PWConstants::DISTANCE_MID, PWConstants::POSITION_R1, 23, 0, SDLImageHorizontalAlignment::eHorizontalAlignment::RIGHT, SDLImageVerticalAlignment::eVerticalAlignment::TOP);

	this->loadTile(tilesetName, PWConstants::ORIENTATION_SOUTH, PWConstants::DISTANCE_FAR, PWConstants::POSITION_CENTER, 17, 17, SDLImageHorizontalAlignment::eHorizontalAlignment::CENTER, SDLImageVerticalAlignment::eVerticalAlignment::CENTER);
}

PWMap::PWMap(SDLGraphics* graphics, const char* name)
{
	char path[100];
	std::string line;
	char tilesetName[25];

	this->mGraphics = graphics;

	strcpy(this->mAssetName, name);

	this->buildAssetPath(path);

	std::ifstream assetFile(path);
	if (assetFile.is_open())
	{
		std::getline(assetFile, line);
		strcpy(tilesetName, line.c_str());
		this->loadTileset(tilesetName);

		std::getline(assetFile, line, 'x');
		this->mWidth = atoi(line.c_str());
		std::getline(assetFile, line);
		this->mHeight = atoi(line.c_str());

		this->mMap = new int**[this->mWidth];
		for (int x = 0; x < this->mWidth; x++)
		{
			this->mMap[x] = new int*[this->mHeight];

			for (int y = 0; y < this->mHeight; y++)
			{
				this->mMap[x][y] = new int[4];
			}
		}

		for (int y = 0; y < this->mHeight; y++)
		{
			for (int x = 0; x < this->mWidth; x++)
			{
				std::getline(assetFile, line, '.');
				this->mMap[x][y][0] = atoi(line.c_str());
				std::getline(assetFile, line, '.');
				this->mMap[x][y][1] = atoi(line.c_str());
				std::getline(assetFile, line, '.');
				this->mMap[x][y][2] = atoi(line.c_str());
				if (x == this->mWidth - 1)
				{
					std::getline(assetFile, line);
				}
				else
				{
					std::getline(assetFile, line, '_');
				}
				this->mMap[x][y][3] = atoi(line.c_str());
			}
		}
	}
	assetFile.close();
}

void PWMap::draw(int x, int y, int direction)
{
	this->mGraphics->drawImage(this->mBackdrops[PWConstants::BACKDROP_FLOOR]);
	this->mGraphics->drawImage(this->mBackdrops[PWConstants::BACKDROP_CEIL]);

	this->drawTile(x, y, direction, PWConstants::DISTANCE_FAR, PWConstants::POSITION_CENTER);

	this->drawTile(x, y, direction, PWConstants::DISTANCE_MID, PWConstants::POSITION_L1);
	this->drawTile(x, y, direction, PWConstants::DISTANCE_MID, PWConstants::POSITION_R1);
	this->drawTile(x, y, direction, PWConstants::DISTANCE_MID, PWConstants::POSITION_CENTER);

	this->drawTile(x, y, direction, PWConstants::DISTANCE_NEAR, PWConstants::POSITION_L2);
	this->drawTile(x, y, direction, PWConstants::DISTANCE_NEAR, PWConstants::POSITION_R2);
	this->drawTile(x, y, direction, PWConstants::DISTANCE_NEAR, PWConstants::POSITION_L1);
	this->drawTile(x, y, direction, PWConstants::DISTANCE_NEAR, PWConstants::POSITION_R1);
	this->drawTile(x, y, direction, PWConstants::DISTANCE_NEAR, PWConstants::POSITION_CENTER);

	this->drawTile(x, y, direction, PWConstants::DISTANCE_NONE, PWConstants::POSITION_L1);
	this->drawTile(x, y, direction, PWConstants::DISTANCE_NONE, PWConstants::POSITION_R1);
}

void PWMap::drawTile(int x, int y, int direction, int distance, int position)
{
	int positionX;
	int positionY;
	int positionXtmp;
	int positionYtmp;

	int tileOrientation;
	int drawingOrientation;

	if (distance > PWConstants::DISTANCE_NONE)
	{
		positionX = x;
		positionY = y;
		tileOrientation = direction;

		PWGlobal::moveForward(direction, positionX, positionY, distance);

		PWGlobal::turnBack(tileOrientation);

		switch (position)
		{
			case PWConstants::POSITION_L1:
				PWGlobal::moveLeft(direction, positionX, positionY, 1);
				drawingOrientation = PWConstants::ORIENTATION_SOUTH;
				break;
			case PWConstants::POSITION_L2:
				PWGlobal::moveLeft(direction, positionX, positionY, 2);
				drawingOrientation = PWConstants::ORIENTATION_SOUTH;
				break;
			case PWConstants::POSITION_R1:
				PWGlobal::moveRight(direction, positionX, positionY, 1);
				drawingOrientation = PWConstants::ORIENTATION_SOUTH;
				break;
			case PWConstants::POSITION_R2:
				PWGlobal::moveRight(direction, positionX, positionY, 2);
				drawingOrientation = PWConstants::ORIENTATION_SOUTH;
				break;
			case PWConstants::POSITION_CENTER:
				drawingOrientation = PWConstants::ORIENTATION_SOUTH;
				break;
		}

		if (positionX >= 0 && positionX < this->mWidth && positionY >= 0 && positionY < this->mHeight)
		{
			if (this->mMap[positionX][positionY][tileOrientation] == 1 && this->mTileset[drawingOrientation][distance][position] != NULL)
			{
				this->mGraphics->drawImage(this->mTileset[drawingOrientation][distance][position]);
			}
		}
	}

	positionX = x;
	positionY = y;
	tileOrientation = direction;

	PWGlobal::moveForward(direction, positionX, positionY, distance);

	switch (position)
	{
		case PWConstants::POSITION_L1:
			PWGlobal::moveLeft(direction, positionX, positionY, 1);
			PWGlobal::turnRight(tileOrientation);
			drawingOrientation = PWConstants::ORIENTATION_EAST;
			break;
		case PWConstants::POSITION_L2:
			PWGlobal::moveLeft(direction, positionX, positionY, 2);
			PWGlobal::turnRight(tileOrientation);
			drawingOrientation = PWConstants::ORIENTATION_EAST;
			break;
		case PWConstants::POSITION_R1:
			PWGlobal::moveRight(direction, positionX, positionY, 1);
			PWGlobal::turnLeft(tileOrientation);
			drawingOrientation = PWConstants::ORIENTATION_WEST;
			break;
		case PWConstants::POSITION_R2:
			PWGlobal::moveRight(direction, positionX, positionY, 2);
			PWGlobal::turnLeft(tileOrientation);
			drawingOrientation = PWConstants::ORIENTATION_WEST;
			break;
	}

	if (positionX >= 0 && positionX < this->mWidth && positionY >= 0 && positionY < this->mHeight)
	{
		if (this->mMap[positionX][positionY][tileOrientation] == 1 && this->mTileset[drawingOrientation][distance][position] != NULL)
		{
			this->mGraphics->drawImage(this->mTileset[drawingOrientation][distance][position]);
		}
	}
}

bool PWMap::checkWalkable(int x, int y, int orientation)
{
	if (x < this->mWidth && x >= 0 && y < this->mHeight && y >= 0)
	{
		if (this->mMap[x][y][orientation] == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

PWMap::~PWMap()
{
}
