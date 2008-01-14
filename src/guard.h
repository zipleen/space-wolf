/*
 *  guard.h
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef GUARD_H
#define GUARD_H

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

#include "md3/Md3Player.h"
#include "console.h"
#include "fisica.h"

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif
#define RAD(x)          (M_PI*(x)/180)
#define GRAUS(x)        (180*(x)/M_PI)

class Guard 
{

protected:	
	Md3Player *guard;
	Md3Weapon *weapon;
	std::string model_path;
	std::string weaponpath;
public:
	bool modificou_movimento;
	bool modificou_upper_movimento;
	bool em_disparo;
	int vida;
	int velocidade_disparo;
	int velocidade_correr;
	int damage_arma;
	float velocidade;
	
	int ultimo_disparo; // guarda-se aqui o tick do ultimo disparo para se saber quando se pode disparar outra vez
	
public:
	// posicao no mapa
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat angulo;
	bool em_movimento;
	
	double dt_cur;
	double ultimo_andar;
	
	bool morto;
	bool alerta;
public:
	Guard(); 
	virtual ~Guard(){};

	void loadModel();
	void draw();
	void animate(const double dt);
	
	void setAngulo(GLfloat angulo);
	void set_xy(int z, int x);
	void set_walking_front();
	
	/* movimento */
	float MoveTest();
	void GoBack();
	void GoFront();
	void GoStraffLeft();
	void GoStraffRight();
	void GoTurnRight();
	void GoTurnLeft();
};

#endif
