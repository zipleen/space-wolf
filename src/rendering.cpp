/*
 *  rendering.cpp
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "rendering.h"
#include "md3/Md3Player.h"

Rendering *Rendering::m_renderingSingleton = NULL;

GLenum
checkOpenGLErrors (const char *file, int line)
{
  GLenum errCode = glGetError ();

  if (errCode != GL_NO_ERROR)
    std::cerr << "(GL) " << file << " (" << line << "): "
	 << gluErrorString (errCode) << std::endl;

  return errCode;
}

Rendering::Rendering()
{
	this->windowWidth = 648;
	this->windowHeight = 480;
	this->windowDepth = 24;
	this->useTexturing = true;
	this->useCulling = true;
	this->useWireframe = false;
	this->useSmooth = true;
	this->useLigth = true;
	this->windowTitle = "Wolf3d look-a-like";
	this->drawFPS = true;

}

bool Rendering::initVideo()
{
  const SDL_VideoInfo *videoInfo;

	// Initialize SDL - debugging de sdl no windows necessita deste parametro
#ifdef WIN32 && DEBUG
	if (SDL_Init (SDL_INIT_EVERYTHING|SDL_INIT_NOPARACHUTE ) < 0)
#else
	if (SDL_Init (SDL_INIT_EVERYTHING) < 0)
#endif
	{
		std::cerr << "Video initialization failed: "
			<< SDL_GetError () << std::endl;
		return false;
	}

  atexit (SDL_Quit);

  videoInfo = SDL_GetVideoInfo ();
  if (!videoInfo)
    {
      std::cerr << "Video query failed: " << SDL_GetError () << std::endl;
      return false;
    }

  // Initialize flags to pass to SDL_SetVideoMode
  this->videoFlags  = SDL_OPENGL;             // Uses OpenGL
  this->videoFlags |= SDL_GL_DOUBLEBUFFER;    // Uses double buffering
  this->videoFlags |= SDL_HWPALETTE;
  this->videoFlags |= SDL_RESIZABLE;          // App. window is resizable

  // Check if we can allocate memory in hardware for the window
  if (videoInfo->hw_available)
    this->videoFlags |= SDL_HWSURFACE;
  else
    this->videoFlags |= SDL_SWSURFACE;

  // Check if hardware blit is possible
  if (videoInfo->blit_hw)
   this->videoFlags |= SDL_HWACCEL;

  // Set double buffering for OpenGL
  SDL_GL_SetAttribute (SDL_GL_DOUBLEBUFFER, 1);

  // Initialize video mode
  this->surface = SDL_SetVideoMode (this->windowWidth, this->windowHeight, this->windowDepth, videoFlags);
  if (!this->surface)
    {
      std::cerr << "Video mode set failed: " << SDL_GetError () << std::endl;
      return false;
    }

  SDL_WM_SetCaption (this->windowTitle.c_str(), this->windowTitle.c_str());

  // Enable keypress repetition
  if (SDL_EnableKeyRepeat (100, SDL_DEFAULT_REPEAT_INTERVAL))
    {
      std::cerr << "Setting keyboard repeat failed: "
	   << SDL_GetError () << std::endl;
      return false;
	}

  // Initialize OpenGL
  this->initOpenGL ();

  // Resize OpenGL window
  this->reshape (this->windowWidth, this->windowHeight);
	Console::printf("Video Initialized");
  return true;
}

void
Rendering::reshape (GLsizei width, GLsizei height)
{
  if (height == 0)
    height = 1;

  glViewport (0, 0, width, height);

  // Reinit projection matrix
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective (45.0, width/static_cast<GLfloat>(height), 0.1f, 10000.0f);

  // Reinit model-view matrix
  glMatrixMode (GL_MODELVIEW);
  glLoadIdentity ();
}

bool Rendering::initOpenGL()
{
	glClearColor (0.5f, 0.5f, 0.5f, 1.0f);
	glShadeModel (GL_SMOOTH);
	
	glEnable (GL_DEPTH_TEST);
	glEnable (GL_TEXTURE_2D);
	glEnable (GL_CULL_FACE);
	glEnable (GL_LIGHTING);
	glEnable (GL_LIGHT0);
	
	glCullFace (GL_BACK);

	// Initialize GLEW
	GLenum err = glewInit ();
	if (GLEW_OK != err)
	{
		// Problem: glewInit failed, something is seriously wrong.
		std::cerr << "Error: " << glewGetErrorString (err) << std::endl;
		return false;
	}

	// Print some infos about user's OpenGL implementation
	Console::printf("OpenGL Version String: %s",glGetString (GL_VERSION));
	Console::printf("GLU Version String: %s",gluGetString (GLU_VERSION));
	Console::printf("GLEW Version String: %s",glewGetString (GLEW_VERSION));
 
	
	
	checkOpenGLErrors (__FILE__, __LINE__);
	Console::printf("OpenGL initialized");
	return true;
}

bool Rendering::resizeWindow(int w,int h)
{
	this->surface = SDL_SetVideoMode (w, h, this->windowDepth, this->videoFlags);
	if (!surface)
	{
		std::cerr << "Could not get a surface after resize: "<< SDL_GetError () << std::endl;
		return false;
	}
	
	this->reshape (w, h);
	this->initOpenGL ();
	return true;
}

void Rendering::gameLogic()
{
	// Calculate frame per seconds
	static double current_time = 0;
	static double last_time = 0;
	static int n = 0;
	
	n++;
	current_time = this->timer.current_time;
	
	if ((current_time - last_time) >= 1.0)
    {
		this->fps = n;
		n = 0;
		last_time = current_time;
    }
	
	// Animate todos os guardas
	//double dt = this->timer.current_time - this->timer.last_time;
	
	//player->animate (dt);
	
}

void Rendering::gameCycle (Map *m)
{
	this->gameLogic ();
	
	this->draw3D (m);
	
	this->draw2D ();
	
	SDL_GL_SwapBuffers ();
}

void Rendering::draw3D(Map *m)
{
	// Clear window
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity ();
	
	// Perform camera transformations
	glTranslated (-0.0f, -0.0f, -8.0f);
	glRotated (0.0f, 1.0f, 0.0f, 0.0f);
	glRotated (0.0f, 0.0f, 1.0f, 0.0f);
	glRotated (0.0f, 0.0f, 0.0f, 1.0f);
	
	glEnable (GL_DEPTH_TEST);
	
	if (this->useLigth){
		glEnable (GL_LIGHTING);
	}
	if (this->useTexturing)
		glEnable (GL_TEXTURE_2D);
	
	// desenhar o mapa (o mapa trata de desenhar texturas + items + guardas + portas)
	m->drawEverything();
	// desenhar o hud do player (inclui hud e arma do player)
	
	glDisable (GL_LIGHTING);
	glDisable (GL_TEXTURE_2D);
	glDisable (GL_DEPTH_TEST);
	
}

void Rendering::draw2D()
{
		
	begin2D ();
	
	// Reset texture matrix
	//glActiveTexture (GL_TEXTURE0);
	glMatrixMode (GL_TEXTURE);
	glLoadIdentity ();
	glMatrixMode (GL_MODELVIEW);
	
	glPushAttrib (GL_ENABLE_BIT | GL_POLYGON_BIT);
	glDisable (GL_DEPTH_TEST);
	glDisable (GL_LIGHTING);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	
	// White text
	glColor4f (1.0f, 1.0f, 1.0f, 1.0f);
	
	if(this->drawFPS)
	{
		// Print frame rate int the bottom-left corner
		//this->font->printText (10, 10, "%i fps", this->fps);
	}
	
	glPopAttrib ();
	
	end2D ();
	
}

void Rendering::begin2D ()
{
	GLint viewport[4];
	glGetIntegerv (GL_VIEWPORT, viewport);
	
	glMatrixMode (GL_PROJECTION);
	glPushMatrix ();
	
	glLoadIdentity ();
	glOrtho (0, viewport[2], 0, viewport[3], -1, 1);
	
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
	
}

void Rendering::end2D ()
{
	glMatrixMode (GL_PROJECTION);
	glPopMatrix ();
	glMatrixMode (GL_MODELVIEW);
}

