/*
 *  items_chave.cpp
 *  proj
 *
 *  Created by zipleen on 1/12/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "items_chave.h"

Items_Chave::Items_Chave(GLfloat x,GLfloat y,int tipo,int mapa_x, int mapa_y) : Items()
{
#ifdef WIN32
	this->som_apanhar_item = this->s->loadSound("data\\sounds\\items\\use_nothing.wav");
#else
	this->som_apanhar_item = this->s->loadSound("data/sounds/items/use_nothing.wav");
#endif
	this->mapa_x = mapa_x;
	this->mapa_y = mapa_y;
	if(tipo==1){
		// amarela
	#ifdef WIN32
		this->item_path="data\\models\\items\\key\\key.md3";
		this->item_skin_path="data\\models\\items\\key\\gold.tga";
	#else
		this->item_path="data/models/items/key/key.md3";
		this->item_skin_path="data/models/items/key/gold.tga";
	#endif
		this->item_code = 4008;
	}else{
		//vermelha
	#ifdef WIN32
		this->item_path="data\\models\\items\\key\\key.md3";
		this->item_skin_path="data\\models\\items\\key\\red.tga";
	#else
		this->item_path="data/models/items/key/key.md3";
		this->item_skin_path="data/models/items/key/red.tga";
	#endif
		this->item_code = 4009;	
	}
	this->mesh_name = "key";
	this->loadModel();
	this->z = x;
	this->x = y;
	this->tipo = tipo;
}

bool Items_Chave::consume(Player *p)
{
	if(!this->used){
		this->used = true;
		p->giveChave(this->tipo);
		this->s->playSoundDirect(this->som_apanhar_item);
		return true;
	}
	return false;
}

