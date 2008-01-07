/*
 *  main.cpp
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#ifdef WIN32
#include "Windows Project\stdafx.h"
#endif

#include "main.h"


Player *p;

int main(int argc, char *argv[]){
	Game *g;
	Rendering *r;
	Console::printf("Built release %s at %s" , __DATE__ , __TIME__ );
	
	r = Rendering::GetInstance();
	r->initVideo();
	
	g = new Game();
	g->MainLoop();
	
	// Cleanup
	SDL_Quit();
	
	return 0;
}

