/*
 *  items.cpp
 *  proj
 *
 *  Created by zipleen on 12/30/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "items.h"

Items::Items()
{
	this->angulo=0;
	this->last_dt = 0;
	this->subir = true;
	this->y=-3;
}

void Items::animate(const double delta, const double dt)
{
	if(last_dt+0.01 < dt){
		if(this->subir){
			if(this->y>-1.7)
				this->y+=-1*(this->y)/(1050*delta);
			else
				this->y+=-1*(this->y)/(400*delta);
			if(this->y>-1.5){
				this->subir=false;
				this->y=-1.5;
			}
		}else{
			if(this->y<-3.8)
				this->y-=-1*(this->y)/(1050*delta);
			else
				this->y-=-1*(this->y)/(400*delta);
			if(this->y<-3.5){
				this->subir=true;
				this->y=-3.5;
			}
		}
		this->angulo+=4;
		if(this->angulo>360)
			this->angulo=-360;
		this->last_dt = dt;
	}
	
	
}

void Items::draw()
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

void Items::loadModel()
{
	this->item = Md3ModelPtr (new Md3Model (this->item_path));
	if(this->item_path.size()==0)
	{
		Console::addLine("erro: o item nao tem modelo?!");
		exit(-1);
	}
	
	// ler o modelo md3
	try
    {
		this->item = Md3ModelPtr (new Md3Model (this->item_path));
		this->item->setScale (0.1f);
    }
	catch (std::runtime_error &err)
    {
		Console::printf("Error: failed to load %s",this->item_path.c_str() );
		Console::printf("Reason: %s",err.what ());
		exit (-1);
    }	

}
