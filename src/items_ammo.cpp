/*
 *  items_ammo.cpp
 *  proj
 *
 *  Created by zipleen on 1/12/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "items_ammo.h"

Items_Ammo::Items_Ammo(GLfloat x,GLfloat y,int valor,int mapa_x, int mapa_y, bool clip) : Items()
{
#ifdef WIN32
	this->som_apanhar_item = this->s->loadSound("data\\sounds\\items\\am_pkup.wav");
#else
	this->som_apanhar_item = this->s->loadSound("data/sounds/items/am_pkup.wav");
#endif
	this->mapa_x = mapa_x;
	this->mapa_y = mapa_y;
	
	if(!clip){
#ifdef WIN32
		this->item_path="data\\models\\items\\ammo\\ammo.md3";
		this->item_skin_path="data\\models\\items\\ammo\\ammo.tga";
#else
		this->item_path="data/models/items/ammo/ammo.md3";
		this->item_skin_path="data/models/items/ammo/ammo.tga";
#endif
		this->item_code = 4007;
	}else{
#ifdef WIN32
		this->item_path="data\\models\\items\\clip\\clip.md3";
		this->item_skin_path="data\\models\\items\\clip\\clip.tga";
#else
		this->item_path="data/models/items/clip/clip.md3";
		this->item_skin_path="data/models/items/clip/clip.tga";
#endif
		this->item_code = 4107;
	}
	
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
			this->s->playSoundDirect(this->som_apanhar_item);
			this->used = true;
			return true;
		}else return false;
	}
	return false;
}

