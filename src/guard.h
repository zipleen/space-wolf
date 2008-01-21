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
	Mix_Chunk *som_levar_na_boca;
	int canal_som_levar_na_tromba;
	
	Md3Player *guard;
	Md3Weapon *weapon;
	static Md3Model *flash;
	bool muzzle_gun;
	
	std::string model_path;
	std::string weaponpath;
	int animacao_morrer;
public:
	bool modificou_upper_movimento; // com esta a true temos de avaliar o novo movimento "em_disparo"
	bool em_disparo; // se estivermos em disparo vamos por a animacao do disparo ou nao
	bool disparar; // vamos disparar, esta accao depois de disparada torna a 0
	int potencia_arma;
	int vida;
	float velocidade_disparo;
	float velocidade_correr;
	float velocidade; // esta eh a velocidade que interessa, as outras sao so valores q guardam a velocidade
	int floorcode;
	
	int codigo_arma_que_guarda_tem;
	
public:
	// posicao no mapa
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat angulo;
	
	GLfloat old_x, old_y, old_z;
	GLfloat old_angulo;
	bool em_movimento;
	bool guardar_em_movimento;
	
	// batota para ver se conseguimos por as mudancas de movimentos a acontecerem "no meio" -> ja nao uso
	//int movimento_contar_vezes;
	
	double dt_cur;
	double ultimo_andar;
	double ultimo_disparo;
	
	// reaccao
	double ultima_reaccao;
	double tempo_reaccao;
	GLfloat go_to_x;
	GLfloat go_to_z;
	GLfloat old_go_to_x;
	GLfloat old_go_to_z;
	
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
	
	void setInitial(float z, float x);
	void setAngulo(GLfloat angulo);
	void set_xy(float z, float x);
	void IwannaGoTo(float z,float x);
	
	/* AI ?! */
	void nextMove(float z, float x);
	void normaliza(float x1, float y1, float x2, float y2, float *nx, float *ny);
	
	void shootGun();
	void setWalk(bool v);
	
	/* player actions */
	void takeHealth(int valor);
	void takeHealth(GLfloat x, GLfloat y, int v);
	
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
