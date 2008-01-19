/*
 *  guard_robo.cpp
 *  proj
 *
 *  Created by zipleen on 1/14/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "guard_robo.h"

Guard_Robo::Guard_Robo(int z, int x, bool em_movimento, GLfloat angulo) : Guard()
{
#ifdef WIN32
	this->model_path="data\\models\\players\\robot\\";
	this->weaponpath="";
#else
	this->model_path="data/models/players/robot/";
	this->weaponpath="";
#endif
	this->loadModel();
	
	this->vida=75;
	this->velocidade_disparo=0.25;
	this->potencia_arma=6;
	this->velocidade_correr=8;
	
	this->set_xy(z,x);
	this->setWalk(em_movimento);
	this->angulo = angulo;
#ifdef WIN32
	this->som_morrer[1] = this->s->loadSound("data\\models\\sounds\\robot\\death1.wav");
	this->som_morrer[2] = this->s->loadSound("data\\models\\sounds\\robot\\death2.wav");
	this->som_morrer[3] = this->s->loadSound("data\\models\\sounds\\robot\\death3.wav");
	this->som_arma = this->s->loadSound("data\\models\\sounds\\minigun\\minigun_fire.wav");
#else
	this->som_morrer[1] = this->s->loadSound("data/models/sounds/robot/death1.wav");
	this->som_morrer[2] = this->s->loadSound("data/models/sounds/robot/death2.wav");
	this->som_morrer[3] = this->s->loadSound("data/models/sounds/robot/death3.wav");
	this->som_arma = this->s->loadSound("data/models/sounds/minigun/minigun_fire.wav");
#endif	
	this->codigo_arma_que_guarda_tem = 3;
}

