/*
 *  soldado.cpp
 *  proj
 *
 *  Created by zipleen on 12/30/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "soldado.h"

Soldado::Soldado()
{
	Guard();
	this->model_path="models/players/harley/";
	this->weaponpath="models/weapons2/plasma";
	this->loadModel();
	
	this->vida=50;
	this->velocidade_disparo=10;
	this->velocidade_correr=5;
}

Soldado::Soldado(int x, int y, bool em_movimento, GLfloat angulo)
{
	Guard();
	this->model_path="models/players/harley/";
	this->weaponpath="models/weapons2/plasma";
	this->loadModel();
	
	this->vida=50;
	this->velocidade_disparo=10;
	this->velocidade_correr=5;
	
	this->x = x;
	this->y = y;
	this->em_movimento = em_movimento;
	this->angulo = angulo;
}

