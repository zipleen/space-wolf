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

#include <SDL.h>

#include <GL/glew.h>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
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
protected:
	static Rendering *m_renderingSingleton;
	
	bool useTexturing;
	bool useCulling;
	bool useWireframe;
	bool useSmooth;
	bool useLigth;
	bool drawFPS;
	
	int windowWidth;
	int windowHeight;
	int windowDepth;
	int videoFlags;
	int fps;
	std::string windowTitle;
	SDL_Surface *surface;
	
	
public:
	Timer timer;
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
	
	
	void draw3D(Map *m);
	bool initOpenGL();
	
	bool initVideo();
	void reshape (GLsizei width, GLsizei height);
	bool resizeWindow(int w,int h);
	void gameCycle (Map *m);
	void gameLogic ();
	
	
	// 2d
	void begin2D();
	void end2D();
	int glPrintf (const char *format, ...);
	void draw2D();
};



#endif
