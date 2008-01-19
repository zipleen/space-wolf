/*
 *  soldado.cpp
 *  proj
 *
 *  Created by zipleen on 12/30/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "soldado.h"

Soldado::Soldado(int z, int x, bool em_movimento, GLfloat angulo) : Guard()
{
#ifdef WIN32
	this->model_path="data\\models\\players\\bitterman\\";
	this->weaponpath="data\\models\\weapons2\\smg\\";
#else
	this->model_path="data/models/players/bitterman/";
	this->weaponpath="data/models/weapons2/smg/";
#endif
	this->loadModel();
	
	this->vida=25;
	this->velocidade_disparo=0.75;
	this->potencia_arma=2;
	this->velocidade_correr=8;
	
	this->setInitial(z,x);
	this->setWalk(em_movimento);
	this->angulo = angulo;
	
#ifdef WIN32
	this->som_morrer[1] = this->s->loadSound("data\\models\\sounds\\bitterman\\death1.wav");
	this->som_morrer[2] = this->s->loadSound("data\\models\\sounds\\bitterman\\death2.wav");
	this->som_morrer[3] = this->s->loadSound("data\\models\\sounds\\bitterman\\death3.wav");
	this->som_arma = this->s->loadSound("data\\models\\sounds\\smg\\smg_fire.wav");
	//this->som_alerta = this->s->loadSound();
#else
	this->som_morrer[1] = this->s->loadSound("data/models/sounds/bitterman/death1.wav");
	this->som_morrer[2] = this->s->loadSound("data/models/sounds/bitterman/death2.wav");
	this->som_morrer[3] = this->s->loadSound("data/models/sounds/bitterman/death3.wav");
	this->som_arma = this->s->loadSound("data/models/sounds/smg/smg_fire.wav");
	//this->som_alerta = this->s->loadSound();
#endif	
	this->codigo_arma_que_guarda_tem = 2;
}

