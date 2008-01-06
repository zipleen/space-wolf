/*
 *  porta.cpp
 *  proj
 *
 *  Created by Zipleen on 1/6/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "porta.h"

Porta::Porta(int x, int y, int direction,int tipo_porta)
{
	this->open=false;
	this->x = x;
	this->y = y;
	this->direction = direction;
	this->tipo_porta = tipo_porta;
}

/*
 * Este metodo nao testa se eh possivel o jogado abrir a porta ou nao, abre-a apenas
 */
void Porta::opendoor()
{
	this->open=true;
	
	// codigo para actualizar a porta a "abrir" em opengl?! tempo?!

}

void Porta::draw()
{
	// desenhar a porta em opengl......
	
}

void Porta::animate(const double dt)
{
	// actualizar o tempo?!
	
}