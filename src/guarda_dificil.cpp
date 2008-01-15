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
	
	this->vida=75;
	this->velocidade_disparo=10;
	this->velocidade_correr=1;
	
	this->set_xy(z,x);
	this->em_movimento = em_movimento;
	this->modificou_movimento = true;
	this->angulo = angulo;
}

