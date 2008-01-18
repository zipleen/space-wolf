/*
 *  guarda_intermedio.cpp
 *  proj
 *
 *  Created by zipleen on 1/14/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "guarda_intermedio.h"

Guard_Intermedio::Guard_Intermedio(int z, int x, bool em_movimento, GLfloat angulo) : Guard()
{
#ifdef WIN32
	this->model_path="data\\models\\players\\doom\\";
	this->weaponpath="data\\models\\weapons2\\assault\\";
#else
	this->model_path="data/models/players/doom/";
	this->weaponpath="data/models/weapons2/assault/";
#endif
	this->loadModel();
	
	this->vida=75;
	this->velocidade_disparo=0.25;
	this->velocidade_correr=1;
	
	this->set_xy(z,x);
	this->em_movimento = em_movimento;
	this->modificou_movimento = true;
	this->angulo = angulo;
#ifdef WIN32
	this->som_morrer[1] = this->s->loadSound("data\\models\\sounds\\doom\\death1.wav");
	this->som_morrer[2] = this->s->loadSound("data\\models\\sounds\\doom\\death2.wav");
	this->som_morrer[3] = this->s->loadSound("data\\models\\sounds\\doom\\death3.wav");
	this->som_arma = this->s->loadSound("data\\models\\sounds\\assault\\assault_fire.wav");
#else
	this->som_morrer[1] = this->s->loadSound("data/models/sounds/doom/death1.wav");
	this->som_morrer[2] = this->s->loadSound("data/models/sounds/doom/death2.wav");
	this->som_morrer[3] = this->s->loadSound("data/models/sounds/doom/death3.wav");
	this->som_arma = this->s->loadSound("data/models/sounds/assault/assault_fire.wav");
#endif	
}

