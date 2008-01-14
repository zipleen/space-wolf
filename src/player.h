/*
 *  player.h
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "md3/Md3Player.h"
#include "fisica.h"
#include "md3/Mathlib.h"

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif
#define RAD(x)          (M_PI*(x)/180)
#define GRAUS(x)        (180*(x)/M_PI)

class Player
{
public:
	int pontos;

	bool morto;
	int vida;
	int balas;
	int armadura;
	bool chave_amarela;
	bool chave_vermelha;
	bool arma2;
	bool arma3;
	bool arma4;
	int arma_em_uso;
	float velocidade;
	
	Md3Player *player;
	GLfloat x_inicial, z_inicial;
	
	double dt_cur;
	double ultimo_andar;
	double old_ultimo_andar;
	double ultimo_disparo;
	
public:
	GLfloat x,y,z;
	GLfloat angulo;
	GLfloat old_x, old_y, old_z;
	GLfloat old_angulo;
	
	Player(); 
	virtual ~Player(){};
	void resetPlayer();

	void draw();
	void updateAnimation(double dt);
	void setInitialPosition(int x, int y); // posicao do mapa inicial
	
	void SetAndar();
	void SetCorrer();
	
	// accoes causadas por outros actores
	void takeHealth(int valor);
	
	// accoes efectuadas pelos items
	void giveHealth(int valor);
	void giveArmadura(int valor);
	void giveBullets(int valor);
	void giveChave(int tipo);
	void giveArmas(int tipo);
	
	// controlos direccao
	void saveValues();
	void calculateSpeed();
	float MoveTest();
	void GoBack();
	void GoFront();
	void GoStraffLeft();
	void GoStraffRight();
	void GoTurnRight();
	void GoTurnLeft();
};


#endif
