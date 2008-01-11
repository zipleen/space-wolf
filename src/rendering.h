/*
 *  rendering.h
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef RENDERING_H
#define RENDERING_H

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif
#define RAD(x)          (M_PI*(x)/180)
#define GRAUS(x)        (180*(x)/M_PI)

#include <SDL.h>
#include <SDL_ttf.h>

#include <GL/glew.h>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdarg>

#ifdef WIN32
#include<windows.h>
#include <stdio.h>
#include <wchar.h>
#include <wtypes.h>
#include <stdarg.h>
#endif

#include "console.h"
#include "map.h"
#include "player.h"
#include "camera/glCamera.h"
#include "font/Font.h"

GLenum checkOpenGLErrors (const char *file, int line);

// Application's Timer
struct Timer
{
public:
	Timer ()
    : current_time (0.0), last_time (0.0) { }
	
public:
	void update () {
		last_time = current_time;
		current_time = static_cast<double>(SDL_GetTicks ()) / 1000.0;
	}
	
	double deltaTime () const {
		return (current_time - last_time);
	}
	
public:
	double current_time;
	double last_time;
	
};


class Rendering
{
//protected:
public:
	static Rendering *m_renderingSingleton;
	
	bool useTexturing;
	bool useCulling;
	bool useWireframe;
	bool useSmooth;
	bool useLigth;
	bool drawFPS;
	bool bCullFace;
	
	int windowWidth;
	int windowHeight;
	int windowDepth;
	int videoFlags;
	int fps;
	std::string windowTitle;
	SDL_Surface *surface;
	TTFont *font;
	
	bool debug_use_cam;
public:
	int CenterX;
	int CenterY;
	Timer timer;
	glCamera *Cam;
	
	Rendering(); 
	virtual ~Rendering(){};
	
	static Rendering *GetInstance( void )
	{
		if( m_renderingSingleton == 0 )
			m_renderingSingleton = new Rendering;
		
		return ((Rendering *)m_renderingSingleton);
	}
	
	static void Kill( void )
	{
		if( m_renderingSingleton != 0 )
		{
			delete m_renderingSingleton;
			m_renderingSingleton = 0;
		}
	}
	
	bool useTextures(){ return this->useTexturing; };

	bool initVideo();
	void reshape (GLsizei width, GLsizei height);
	bool resizeWindow(int w,int h);
	void gameCycle (Map *m, Player *p);
	void gameLogic ();
	
	void changeMode();
	
	// 3d
	void setLight();
	void drawAxes();
	
	void draw3D(Map *m, Player *p);
	bool initOpenGL();
	
	// 2d
	void begin2D();
	void end2D();
	void draw2D(Player *p);
};

#endif
