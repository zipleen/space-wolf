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

int main(int argc, char *argv[]){

//descomentar a linha para ir ao menu
	Menu *m;
	Rendering *r;
	Console::printf("Built release %s at %s" , __DATE__ , __TIME__ );
	
	r = Rendering::GetInstance();
	r->initVideo();
	
	m = new Menu();
	m->GameLoop();
	
	// Cleanup
	SDL_Quit();
	
	return 0;
}

