/*
 *  objectos_decorativos.cpp
 *  proj
 *
 *  Created by zipleen on 1/12/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "objectos_decorativos.h"


Objectos_decorativos::Objectos_decorativos(Shared_render_objects::Md3ModelPtr model, GLfloat x, GLfloat y, GLfloat z, int item_code, bool impede)
{
	this->item = model;
	this->x = x;
	this->y = y;
	this->z = z;
	this->item_code = item_code;
	this->angulo = 0;
	this->impede_passagem = impede;
}

void Objectos_decorativos::draw()
{
	glPushMatrix ();
		// mover para o sitio certo, Y eh da animacao
		glTranslatef(this->x,this->y,this->z);
		// animacao
		glRotatef(this->angulo,0,1,0);
	
		glRotatef (-90.0, 1.0, 0.0, 0.0);
		glRotatef (-90.0, 0.0, 0.0, 1.0);
		
		this->item->draw ();
	glPopMatrix ();
}
