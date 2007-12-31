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

Rendering *r;
Game *g;
Player *p;

int main(int argc, char *argv[]){
	Console::printf("Built release %s at %s" , __DATE__ , __TIME__ );
	
	r = new Rendering();
	r->initVideo();
	
	g = new Game();
	g->MainLoop();
	
	// Cleanup
	SDL_Quit();
	
	return 0;
}
