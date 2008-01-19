/*
 *  boss1.cpp
 *  proj
 *
 *  Created by zipleen on 1/14/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "boss1.h"

Guard_Boss1::Guard_Boss1(int z, int x, bool em_movimento, GLfloat angulo) : Guard()
{
#ifdef WIN32
	this->model_path="data\\models\\players\\SpaceMarine40k\\";
	this->weaponpath="data\\models\\weapons2\\minigun\\";
#else
	this->model_path="data/models/players/SpaceMarine40k/";
	this->weaponpath="data/models/weapons2/minigun/";
#endif
	this->loadModel();
	
	this->vida=3000;
	this->velocidade_disparo=0.05;
	this->potencia_arma=3;
	this->velocidade_correr=1;
	
	this->set_xy(z,x);
	this->setWalk(em_movimento);
	this->angulo = angulo;
#ifdef WIN32
	this->som_morrer[1] = this->s->loadSound("data\\models\\sounds\\boss\\death1.wav");
	this->som_morrer[2] = this->s->loadSound("data\\models\\sounds\\boss\\death2.wav");
	this->som_morrer[3] = this->s->loadSound("data\\models\\sounds\\boss\\death3.wav");
	this->som_arma = this->s->loadSound("data\\models\\sounds\\minigun\\minigun_fire.wav");
#else
	this->som_morrer[1] = this->s->loadSound("data/models/sounds/boss/death1.wav");
	this->som_morrer[2] = this->s->loadSound("data/models/sounds/boss/death2.wav");
	this->som_morrer[3] = this->s->loadSound("data/models/sounds/boss/death3.wav");
	this->som_arma = this->s->loadSound("data/models/sounds/minigun/minigun_fire.wav");
#endif	
	this->codigo_arma_que_guarda_tem = 4;
}

