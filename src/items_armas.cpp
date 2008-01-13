/*
 *  items_armas.cpp
 *  proj
 *
 *  Created by zipleen on 1/12/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "items_armas.h"

Items_Armas::Items_Armas(GLfloat x,GLfloat y,int valor)
{
	Items();
	switch(valor){
		case 2:
		#ifdef WIN32
			this->item_path="data\\models\\weapons2\\assault\\assault_2.md3";
			this->item_skin_path="";
		#else
			this->item_path="data/models/weapons2/assault/assault_2.md3";
			this->item_skin_path="";
		#endif
			this->item_code = 4004;
			this->mesh_name = "";
			break;
		case 3:
		#ifdef WIN32
			this->item_path="data\\models\\weapons2\\minigun\\minigun_2.md3";
			this->item_skin_path="data\\models\\weapons2\\minigun\\minigun_barrel_2.md3";
		#else
			this->item_path="data/models/weapons2/minigun/minigun_2.md3";
			this->item_skin_path="data/models/weapons2/minigun/minigun_barrel_2.md3";
		#endif
			this->item_code = 4005;
			this->mesh_name = "";			
			break;
			
		case 4:
		#ifdef WIN32
			this->item_path="data\\models\\weapons2\\standardgun\\standardgun_2.md3";
			this->item_skin_path="";
		#else
			this->item_path="data/models/weapons2/standardgun/standardgun_2.md3";
			this->item_skin_path="";
		#endif
			this->item_code = 4006;
			this->mesh_name = "";			
			break;
	}
	
	this->loadModel();
	this->z = x;
	this->x = y;
	this->valor = valor;
}

void Items_Armas::consume(Player *p)
{
	if(!this->used){
		this->used = true;
		p->giveArmas(this->valor);
		p->giveBullets(8);
	}
}

