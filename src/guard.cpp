/*
 *  guard.cpp
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "guard.h"

Guard::Guard()
{
	this->morto = false;
	this->em_movimento = false;
	this->modificou_movimento = false;
	this->em_disparo = false;
}

void Guard::loadModel()
{
	if(this->model_path.size()==0)
	{
		Console::addLine("erro: o guarda nao tem modelo");
		exit(-1);
	}
	
	// ler o modelo md3
	try
    {
		// Load MD3 player
		this->guard = new Md3Player (this->model_path);
		this->guard->setScale (0.1f);
		this->guard->setAnimation (kTorsoStand);
		this->guard->setAnimation (kLegsIdle);
    }
	catch (std::runtime_error &err)
    {
		Console::printf("Error: failed to load %s",this->model_path.c_str() );
		Console::printf("Reason: %s",err.what ());
		exit (-1);
    }	
	
	try
    {
		// Load weapon if a path is given
		if (!this->weaponpath.empty ())
		{
			this->weapon = new Md3Weapon (this->weaponpath);
			this->weapon->setScale (0.1f);
			this->guard->linkWeapon (this->weapon);
		}
    }
	catch (std::runtime_error &err)
    {
		Console::printf( "Error: failed to load %s" , this->weaponpath.c_str() );
		Console::printf( "Reason: %s" , err.what () );
    }
}

void Guard::draw()
{
	glPushMatrix();
		glTranslatef(this->x,-2.6f,this->y);
		glRotatef(this->angulo,0,1,0);
		this->guard->draw();
	glPopMatrix();
}

void Guard::animate(const double dt)
{
	if(!this->morto){
		if(this->modificou_movimento){
			if(this->em_movimento){
				this->guard->setAnimation (kLegsWalk);
			}else{
				this->guard->setAnimation (kLegsIdle);
			}
			this->modificou_movimento = false;
		}
		if(this->modificou_upper_movimento){
			if(this->em_disparo){
				this->guard->setAnimation (kTorsoAttack);
			}else{
				this->guard->setAnimation (kTorsoStand);
			}
			this->modificou_upper_movimento = false;
		}
		this->guard->animate(dt);
	}
}

void Guard::set_xy(int x, int y)
{
	this->x = x;
	this->y = y;
}
void Guard::set_angulo(GLfloat angulo)
{
	this->angulo = angulo;
}

void Guard::set_walking_front()
{
	this->em_movimento = false;
	this->modificou_movimento = true;
}

