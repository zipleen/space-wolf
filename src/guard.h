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

class Guard 
{

protected:
	Md3Player *guard;
	Md3Weapon *weapon;
	std::string model_path;
	std::string weaponpath;
	
	bool em_movimento;
	bool modificou_movimento;
	bool modificou_upper_movimento;
	bool em_disparo;
	int vida;
	int velocidade_disparo;
	int velocidade_correr;
	int damage_arma;
	
	int ultimo_disparo; // guarda-se aqui o tick do ultimo disparo para se saber quando se pode disparar outra vez
	
public:
	// posicao no mapa
	GLfloat x;
	GLfloat y;
	GLfloat angulo;
	
	bool morto;
public:
	Guard(); 
	virtual ~Guard(){};

	void loadModel();
	void draw();
	void animate(const double dt);
	
	void set_angulo(GLfloat angulo);
	void set_xy(int x, int y);
	void set_walking_front();
};

#endif
