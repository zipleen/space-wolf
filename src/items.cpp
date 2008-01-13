/*
 *  items.cpp
 *  proj
 *
 *  Created by zipleen on 12/30/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "items.h"
#include <iostream>
Items::Items()
{
	this->angulo=0;
	this->last_dt = 0;
	this->subir = true;
	this->y=-3;
	this->used = false;
}

void Items::loadModel()
{
	this->item = Shared_render_objects::find_or_insert(this->item_code, this->item_path, this->item_skin_path, this->mesh_name);
}

void Items::animate(const double delta, const double dt)
{
	if(this->last_dt+0.01 < dt){
		double dif = (dt-this->last_dt)*100;
		if(this->subir){
			if(this->y>-2.7)
				this->y+=0.01*dif;
			else
				this->y+=0.04*dif;
			if(this->y>-2.5){
				this->subir=false;
				this->y=-2.5;
			}
		}else{
			if(this->y<-3.8)
				this->y-=0.01*dif;
			else
				this->y-=0.04*dif;
			if(this->y<-3.5){
				this->subir=true;
				this->y=-3.5;
			}
		}
		this->angulo+=2*dif;
		if(this->angulo>360)
			this->angulo=-360;
		this->last_dt = dt;
	}
	
}

void Items::draw()
{
	if(!this->used){
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
}

void Items::consume(Player *p)
{
	// !??! era suposto isto ser virtual

}
