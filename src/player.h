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
#include "sound.h"

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
	int potencia_arma;
	bool disparar;
	bool muzzle_flash;
	float velocidade_disparo;
	float velocidade;
	int floorcode;
	
	Md3Player *player;
	GLfloat x_inicial, z_inicial;
	Sound *s;
	Mix_Chunk *som_passos[5];
	int canal_som_passos[5];
	int som_passo_corrente;
	Mix_Chunk *som_armas[5];
	Mix_Chunk *som_sem_balas;
	int som_disparo_corrente;
	Mix_Chunk *som_mudar_arma;
	
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
	void updateAnimation(double dt, int floorcode);
	void setInitialPosition(int x, int y); // posicao do mapa inicial
	bool tenhoArma(int a);
	
	// accoes feitas pelo jogador
	void SetAndar();
	void SetCorrer();
	void setGun(int tipo);
	bool shootGun();
	
	// accoes causadas por outros actores
	void takeHealth(int valor);
	void takeHealth(GLfloat x, GLfloat y,int v);
	
	// accoes efectuadas pelos items
	bool giveHealth(int valor);
	bool giveArmadura(int valor);
	bool giveBullets(int valor);
	bool giveChave(int tipo);
	bool giveArmas(int tipo);
	
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
