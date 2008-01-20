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

//descomentar a linha para ir ao menu
	Menu *m;
	Rendering *r;
	Console::printf("Built release %s at %s" , __DATE__ , __TIME__ );
	
	r = Rendering::GetInstance();
	r->initVideo();
	/*
	for(;;){
		if(argc>1)
			g=new Game(argv[1]);
		else
			g = new Game("data/maps/v1.map");
		
		
		
		
		g->MainLoop();
		delete g;
	}*/
	//descomentar as duas linhas seguintes para ir ao menu	
	m = new Menu();
	m->MainLoopMenu();
	
	// Cleanup
	SDL_Quit();
	
	return 0;
}

