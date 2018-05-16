#include "PWApp.h"

PWApp::PWApp()
{
}

SDLScreen* PWApp::getInitialScreen()
{
	return new PWScreenPlay(this);
}

PWApp::~PWApp()
{
}
