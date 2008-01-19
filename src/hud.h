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

#include <SDL_ttf.h>

#include "player.h"
#include "StrUtils.h"
#include "md3/Md3Model.h"
#include "font/Font.h"
#include "md3/TextureManager.h"
#include "shared_render_objects.h" 
#include "md3/TextureManager.h"
//#define Texture2D *tex_balas, *tex_armor, *tex_chave1, *tex_chave2, *tex_vida;

class Hud
{
protected:
	typedef shared_ptr<Md3Model> Md3ModelPtr;
	static Hud::Md3ModelPtr arma1,arma2,arma3,arma4 ;
	static Md3Model *arma1_f, *arma2_f, *arma3_f, *arma4_f, *arma4_1;
	static float yaw,yaw_walk;
	static bool yaw_up,yaw_up_walk;
	static TTFont *font;
	static Texture2D *tex_balas, *tex_armor, *tex_chave1, *tex_chave2, *tex_vida;
	
public:
	Hud(){}; 
	virtual ~Hud(){};

	static void drawHud(Player *p);
	static void initHud();
	static void drawGun(Player *p);
};

#endif
