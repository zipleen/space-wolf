/*
 *  hud.h
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef HUD_H
#define HUD_H

#include <GL/glew.h>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include "player.h"
#include "StrUtils.h"
#include "shared_render_objects.h"

class Hud
{
protected:
	static Shared_render_objects::Md3ModelPtr arma2;
	
public:
	Hud(){}; 
	virtual ~Hud(){};
	
	static void drawHud(Player *p);
	static void initHud();
};

#endif
