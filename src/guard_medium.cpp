/*
 *  guard_medium.cpp
 *  proj
 *
 *  Created by zipleen on 1/11/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "guard_medium.h"

Guard_Medium::Guard_Medium(int z, int x, bool em_movimento, GLfloat angulo)
{
	Guard();
#ifdef WIN32
	this->model_path="data\\models\\players\\doom\\";
	this->weaponpath="data\\models\\weapons2\\assault\\";
#else
	this->model_path="data/models/players/doom/";
	this->weaponpath="data/models/weapons2/assault/";
#endif
	this->loadModel();
	
	this->vida=75;
	this->velocidade_disparo=10;
	this->velocidade_correr=5;
	
	this->set_xy(z,x);
	this->em_movimento = em_movimento;
	this->modificou_movimento = true;
	this->angulo = angulo;
}

