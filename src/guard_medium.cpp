/*
 *  guard_medium.cpp
 *  proj
 *
 *  Created by zipleen on 1/11/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "guard_medium.h"

Guard_Medium::Guard_Medium(int z, int x, bool em_movimento, GLfloat angulo) : Guard()
{
#ifdef WIN32
	this->model_path="data\\models\\players\\visor\\";
	this->weaponpath="data\\models\\weapons2\\assault\\";
#else
	this->model_path="data/models/players/visor/";
	this->weaponpath="data/models/weapons2/assault/";
#endif
	this->loadModel();
	
	this->vida=50;
	this->velocidade_disparo=0.75;
	this->potencia_arma=3;
	this->velocidade_correr=11;
	this->tempo_reaccao = 1.6;
	
	this->setInitial(z,x);
	this->setWalk(em_movimento);
	this->angulo = angulo;
#ifdef WIN32
	this->som_morrer[1] = this->s->loadSound("data\\models\\sounds\\visor\\death1.wav");
	this->som_morrer[2] = this->s->loadSound("data\\models\\sounds\\visor\\death2.wav");
	this->som_morrer[3] = this->s->loadSound("data\\models\\sounds\\visor\\death3.wav");
	this->som_arma = this->s->loadSound("data\\models\\sounds\\assault\\assault_fire.wav");
#else
	this->som_morrer[1] = this->s->loadSound("data/models/sounds/visor/death1.wav");
	this->som_morrer[2] = this->s->loadSound("data/models/sounds/visor/death2.wav");
	this->som_morrer[3] = this->s->loadSound("data/models/sounds/visor/death3.wav");
	this->som_arma = this->s->loadSound("data/models/sounds/assault/assault_fire.wav");
#endif	
	this->codigo_arma_que_guarda_tem = 3;
}

