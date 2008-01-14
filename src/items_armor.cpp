/*
 *  items_armor.cpp
 *  proj
 *
 *  Created by zipleen on 1/14/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "items_armor.h"

Items_Armor::Items_Armor(GLfloat x,GLfloat y,int valor)
{
	Items();
#ifdef WIN32
			this->item_path="data\\models\\powerups\\armor\\armor_red.md3";
			this->item_skin_path="";
#else
			this->item_path="data/models/powerups/armor/armor_red.md3";
			this->item_skin_path="data/models/powerups/armor/newred.tga";
#endif
			this->item_code = 4012;
			this->mesh_name = "red_energy";		
	this->loadModel();
	this->z = x;
	this->x = y;
	this->valor_vida = valor;
}

void Items_Armor::consume(Player *p)
{
	if(!this->used){
		this->used = true;
		p->giveArmadura(this->valor_vida);
	}
}
