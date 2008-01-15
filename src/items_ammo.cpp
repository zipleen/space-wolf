/*
 *  items_ammo.cpp
 *  proj
 *
 *  Created by zipleen on 1/12/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "items_ammo.h"

Items_Ammo::Items_Ammo(GLfloat x,GLfloat y,int valor,int mapa_x, int mapa_y) : Items()
{
	this->mapa_x = mapa_x;
	this->mapa_y = mapa_y;
#ifdef WIN32
	this->item_path="data\\models\\items\\ammo\\ammo.md3";
	this->item_skin_path="data\\models\\items\\ammo\\ammo.tga";
#else
	this->item_path="data/models/items/ammo/ammo.md3";
	this->item_skin_path="data/models/items/ammo/ammo.tga";
#endif
	this->item_code = 4007;
	this->mesh_name = "key";
	this->loadModel();
	this->z = x;
	this->x = y;
	this->valor = valor;
}

bool Items_Ammo::consume(Player *p)
{
	if(!this->used){
		if(p->giveBullets(this->valor)){
			this->used = true;
			return true;
		}else return false;
	}
	return false;
}

