/*
 *  guarda_dificil.cpp
 *  proj
 *
 *  Created by zipleen on 1/14/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "guarda_dificil.h"

Guard_Dificil::Guard_Dificil(int z, int x, bool em_movimento, GLfloat angulo) : Guard()
{
#ifdef WIN32
	this->model_path="data\\models\\players\\keel\\";
	this->weaponpath="data\\models\\weapons2\\minigun\\";
#else
	this->model_path="data/models/players/keel/";
	this->weaponpath="data/models/weapons2/minigun/";
#endif
	this->loadModel();
	
	this->vida=150;
	this->velocidade_disparo=0.35;
	this->potencia_arma=4;
	this->velocidade_correr=9;
	this->tempo_reaccao = 1.0;
	
	this->setInitial(z,x);
	this->setWalk(em_movimento);
	this->angulo = angulo;
#ifdef WIN32
	this->som_morrer[1] = this->s->loadSound("data\\models\\sounds\\keel\\death1.wav");
	this->som_morrer[2] = this->s->loadSound("data\\models\\sounds\\keel\\death2.wav");
	this->som_morrer[3] = this->s->loadSound("data\\models\\sounds\\keel\\death3.wav");
	this->som_arma = this->s->loadSound("data\\models\\sounds\\minigun\\minigun_fire.wav");
#else
	this->som_morrer[1] = this->s->loadSound("data/models/sounds/keel/death1.wav");
	this->som_morrer[2] = this->s->loadSound("data/models/sounds/keel/death2.wav");
	this->som_morrer[3] = this->s->loadSound("data/models/sounds/keel/death3.wav");
	this->som_arma = this->s->loadSound("data/models/sounds/minigun/minigun_fire.wav");
#endif	
	this->codigo_arma_que_guarda_tem = 4;
}

