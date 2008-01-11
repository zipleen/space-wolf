/*
 *  soldado.cpp
 *  proj
 *
 *  Created by zipleen on 12/30/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "soldado.h"

Soldado::Soldado(int z, int x, bool em_movimento, GLfloat angulo)
{
	Guard();
#ifdef WIN32
	this->model_path="data\\models\\players\\razor\\";
	this->weaponpath="data\\models\\weapons2\\smg\\";
#else
	this->model_path="data/models/players/razor/";
	this->weaponpath="data/models/weapons2/smg/";
#endif
	this->loadModel();
	
	this->vida=50;
	this->velocidade_disparo=10;
	this->velocidade_correr=5;
	
	this->set_xy(z,x);
	this->em_movimento = em_movimento;
	this->modificou_movimento = true;
	this->angulo = angulo;
}

