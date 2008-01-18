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
#include <SDL_mixer.h>
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
#include "sound.h"

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif
#define RAD(x)          (M_PI*(x)/180)
#define GRAUS(x)        (180*(x)/M_PI)

class Guard 
{

protected:	
	Sound *s;
	Mix_Chunk *som_passos[5];
	int canal_som_passos[5];
	int som_passo_corrente;
	
	Mix_Chunk *som_morrer[4];
	Mix_Chunk *som_arma;
	Mix_Chunk *som_alerta;
	int som_disparo_arma;
	
	Md3Player *guard;
	Md3Weapon *weapon;
	std::string model_path;
	std::string weaponpath;
public:
	bool modificou_movimento;
	bool modificou_upper_movimento;
	bool em_disparo;
	bool disparar;
	int vida;
	float velocidade_disparo;
	float velocidade_correr;
	float damage_arma;
	float velocidade;
	int floorcode;
	
	int codigo_arma_que_guarda_tem;
	
public:
	// posicao no mapa
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat angulo;
	bool em_movimento;
	
	// batota para ver se conseguimos por as mudancas de movimentos a acontecerem "no meio"
	int movimento_contar_vezes;
	
	double dt_cur;
	double ultimo_andar;
	double ultimo_disparo;
	
	bool morto;
	bool a_morrer;
	bool alerta;
	bool vai_para_alerta;
public:
	Guard(); 
	virtual ~Guard(){};

	void loadModel();
	void draw();
	void animate(const double dt, double dt_cur);
	
	void setAngulo(GLfloat angulo);
	void set_xy(float z, float x);
	void set_walking_front();
	
	/* AI ?! */
	void nextMove();
	
	void shootGun();
	
	/* player actions */
	void takeHealth(GLfloat x, GLfloat y);
	
	/* movimento */
	void playSomPassos();
	float MoveTest();
	void GoBack();
	void GoFront();
	void GoStraffLeft();
	void GoStraffRight();
	void GoTurnRight();
	void GoTurnLeft();
};

#endif
