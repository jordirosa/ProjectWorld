#pragma once

#include "SDLEngine.h"

class SDLGraphics
{
private:
	float mScale;

	int mWidth;
	int mHeight;

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;

	//SDL_GLContext mGLContext;
public:
	SDLGraphics();

	bool init(int width, int height);
	bool init(float scale, int width, int height);

	void clear();
	void render();

	SDLImage* loadImage(const char* path);
	SDLText* loadText(const char* path, int size, const char* text, SDL_Color color);

	void drawImage(SDLImage* image);
	void drawText(SDLText* text);

	~SDLGraphics();
};

