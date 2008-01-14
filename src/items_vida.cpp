/*
 *  items_vida.cpp
 *  proj
 *
 *  Created by zipleen on 1/11/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "items_vida.h"

Items_Vida::Items_Vida(GLfloat x,GLfloat y,int valor)
{
	Items();
	switch(valor){
		case 15:
		#ifdef WIN32
			this->item_path="data\\models\\items\\life\\medikit.md3";
			this->item_skin_path="data\\models\\items\\life\\medikit3.tga";
		#else
			this->item_path="data/models/items/life/medikit.md3";
			this->item_skin_path="data/models/items/life/medikit3.tga";
		#endif
			this->item_code = 4001;
			this->mesh_name = "key";		
			break;
		case 25:
		#ifdef WIN32
			this->item_path="data\\models\\items\\life\\medikit.md3";
			this->item_skin_path="data\\models\\items\\life\\medikit2.tga";
		#else
			this->item_path="data/models/items/life/medikit.md3";
			this->item_skin_path="data/models/items/life/medikit2.tga";
		#endif
			this->item_code = 4002;
			this->mesh_name = "key";		
			break;		
			break;
		case 50:
		#ifdef WIN32
			this->item_path="data\\models\\items\\life\\medikit.md3";
			this->item_skin_path="data\\models\\items\\life\\medikit1.tga";
		#else
			this->item_path="data/models/items/life/medikit.md3";
			this->item_skin_path="data/models/items/life/medikit1.tga";
		#endif
			this->item_code = 4003;
			this->mesh_name = "key";		
			break;			
			break;
	
	
	}

	this->loadModel();
	this->z = x;
	this->x = y;
	this->valor_vida = valor;
}

void Items_Vida::consume(Player *p)
{
	if(!this->used){
		this->used = true;
		p->giveHealth(this->valor_vida);
	}
}

