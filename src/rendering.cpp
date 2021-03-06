/*
 *  rendering.cpp
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "rendering.h"

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
	this->windowWidth = 1024;
	this->windowHeight = 768;
	this->windowDepth = 24;
	this->useFullScreen = false;
	this->useTexturing = true;
	this->useCulling = true;
	this->useWireframe = false;
	this->useSmooth = true;
	this->useLigth = true;
	this->windowTitle = "Space Wolf";
	this->drawFPS = true;
	this->bCullFace = true;

}

bool Rendering::initVideo()
{

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

	this->setSDLflags();

  // Set double buffering for OpenGL
  SDL_GL_SetAttribute (SDL_GL_DOUBLEBUFFER, 1);

  // Initialize video mode
  this->surface = SDL_SetVideoMode (this->windowWidth, this->windowHeight, this->windowDepth, this->videoFlags);
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
	this->CenterX = this->windowWidth/2;
	this->CenterY = this->windowHeight/2;
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
  gluPerspective (45.0f, width/static_cast<GLfloat>(height), 0.1f, 450.0f); // meter aki 100000 para ver tudo 450.0f

  // Reinit model-view matrix
  glMatrixMode (GL_MODELVIEW);
  glLoadIdentity ();
}

bool Rendering::initOpenGL()
{
	GLfloat amb[] = { 0.3f, 0.3f, 0.3f, 1.0f };
	
	glClearColor (0.5f, 0.5f, 0.5f, 1.0f);
	glShadeModel (GL_SMOOTH);
	
	glEnable (GL_DEPTH_TEST);
	glEnable (GL_CULL_FACE);
	glEnable (GL_LIGHTING);

	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);
	
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_NORMALIZE);
	
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,amb);

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
 
 	
	try
	{
      this->font = new TTFont ("data/Vera.ttf", 12, 1);
    }
	catch (std::runtime_error &err)
    {
      cerr << "Failed to create truetype font" << endl;
      cerr << "Reason: " << err.what () << endl;
    }
 
	checkOpenGLErrors (__FILE__, __LINE__);
	Console::printf("OpenGL initialized");
	return true;
}

void Rendering::setSDLflags()
{
	const SDL_VideoInfo *videoInfo;
	
	videoInfo = SDL_GetVideoInfo ();
	if (!videoInfo)
    {
		std::cerr << "Video query failed: " << SDL_GetError () << std::endl;
		return;
    }
	
	// Initialize flags to pass to SDL_SetVideoMode
	this->videoFlags  = SDL_OPENGL;             // Uses OpenGL
	this->videoFlags |= SDL_GL_DOUBLEBUFFER;    // Uses double buffering
	this->videoFlags |= SDL_HWPALETTE;
	if(this->useFullScreen){
		this->videoFlags |= SDL_FULLSCREEN;
	}
	
	//this->videoFlags |= SDL_RESIZABLE;          // App. window is resizable
	
	// Check if we can allocate memory in hardware for the window
	if (videoInfo->hw_available)
		this->videoFlags |= SDL_HWSURFACE;
	else
		this->videoFlags |= SDL_SWSURFACE;
	
	// Check if hardware blit is possible
	if (videoInfo->blit_hw)
		this->videoFlags |= SDL_HWACCEL;
}

bool Rendering::resizeWindow(int w,int h)
{
	this->surface = SDL_SetVideoMode (w, h, this->windowDepth, this->videoFlags);
	if (!surface)
	{
		std::cerr << "Could not get a surface after resize: "<< SDL_GetError () << std::endl;
		return false;
	}
	this->windowWidth = w;
	this->windowHeight = h;
	this->CenterX = w/2;
	this->CenterY = h/2;
	
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

void Rendering::changeMode()
{
	if(this->useWireframe){
          glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
          glDisable(GL_TEXTURE_2D);
	}else{
		glEnable(GL_TEXTURE_2D);
		glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	}

}

void Rendering::gameCycle (Map *m, Player *p)
{
	this->gameLogic ();
	
	this->draw3D (m,p);
	
	this->draw2D (p);
	
	SDL_GL_SwapBuffers ();
}

void Rendering::setLight()
{	
	GLfloat light_pos[4] =	{-5.0, 20.0, -5.0, 0.0};
	GLfloat light_ambient[4] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat light_diffuse[4] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat light_specular[4]=	{ 0.5f, 0.5f, 0.5f, 1.0f };
	
	// isto eh definido ali atras
	//glEnable(GL_LIGHTING);
	// ligar e definir fonte de light 0
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,1);
	
	/*glEnable(GL_LIGHT1); 
	GLfloat light_pos1[4] =	{250, 4, 519, 1.0};
	GLfloat direction[] = { 0.0, -4.0, 0.0 };
    glLightfv( GL_LIGHT1, GL_POSITION, light_pos1 );
    glLightfv( GL_LIGHT1, GL_SPOT_DIRECTION, direction);
    glLightf ( GL_LIGHT1, GL_SPOT_EXPONENT , 1);
    glLightf ( GL_LIGHT1, GL_SPOT_CUTOFF, 180);*/
	
}


void Rendering::draw3D(Map *m, Player *p)
{
	// Clear window
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity ();
	
	// Perform camera transformations
	//gluLookAt(p->x,p->y,p->z, 0, 50,20 ,0,0,-1);
	// deve-se fazer sempre translate e depois rotate
	glRotatef(p->angulo, 0.0, 1.0, 0.0);
	glTranslatef(p->x,p->y,p->z);
	glEnable (GL_DEPTH_TEST);
	
	if (this->useLigth){
		glEnable (GL_LIGHTING);
		this->setLight();
	}
	
	if (this->useTexturing)
		glEnable (GL_TEXTURE_2D);
	if (this->bCullFace)
		glEnable (GL_CULL_FACE);
	else
		glDisable (GL_CULL_FACE);
	
	// Setup polygon mode and shade model
	glPolygonMode (GL_FRONT_AND_BACK, this->useWireframe ? GL_LINE : GL_FILL);
	glShadeModel (this->useSmooth ? GL_SMOOTH : GL_FLAT);
	
	m->setMaterial();
	
	// desenhar o hud do player ( arma do player)
	Hud::drawGun(p);
	
	// desenhar o mapa (o mapa trata de desenhar texturas + items + guardas + portas)
	m->drawEverything();
	
	glDisable (GL_LIGHTING);
	glDisable (GL_TEXTURE_2D);
	glDisable (GL_DEPTH_TEST);
	
	
}

void Rendering::drawAxes ()
{
  glPushMatrix();
  // Setup world model view matrix
  glLoadIdentity ();

  // Draw the three axes
  glBegin (GL_LINES);
    // X-axis in red
    glColor3f (1.0f, 0.0f, 0.0f);
    glVertex3fv (kZeroVectorf._v);
    glVertex3fv (kZeroVectorf + Vector3f (10.0f, 0.0f, 0.0));

    // Y-axis in green
    glColor3f (0.0f, 1.0f, 0.0f);
    glVertex3fv (kZeroVectorf._v);
    glVertex3fv (kZeroVectorf + Vector3f (0.0f, 10.0f, 0.0));

    // Z-axis in blue
    glColor3f (0.0f, 0.0f, 1.0f);
    glVertex3fv (kZeroVectorf._v);
    glVertex3fv (kZeroVectorf + Vector3f (0.0f, 0.0f, 10.0));
  glEnd ();
  glPopMatrix();
}

void Rendering::draw2D(Player *p)
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
	
	// desenhar o hud do player ( vida, balas, etc do player)

	Hud::drawHud(p);
	
	// White text
	glColor4f (1.0f, 1.0f, 1.0f, 1.0f);
	
	if(this->drawFPS)
	{
		// Print frame rate int the bottom-left corner
		this->font->printText (10, 10, "%i fps", this->fps);
	}
#ifdef DEBUG
	this->font->printText(10,22,"Player x:%f y:%f z:%f angulo:%f floorcode:%d",p->x, p->y, p->z, p->angulo,p->floorcode);
#endif
	
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

