/*
 *  guard.cpp
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "guard.h"
#define VELOCIDADE_ANDAR_GUARDA 0.15

Guard::Guard()
{
	this->morto = false;
	this->em_movimento = false;
	this->modificou_movimento = false;
	this->em_disparo = false;
	this->alerta = false;
	this->movimento_contar_vezes = 0;
	this->velocidade = VELOCIDADE_ANDAR_GUARDA;
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
		glTranslatef(this->x,this->y,this->z);
		glRotatef(this->angulo,0,1,0);
		this->guard->draw();
	glPopMatrix();
}

void Guard::animate(const double dt)
{
	if(!this->morto){
		// precisamos de ver se ele tem de fazer coisas ou nao..
		// estamos em alerta?! se nao, vamos seguir os percursos
		if(!this->alerta){
			// se nao tamos em alerta temos de ver se tamos em movimento, se tamos, temos de o mover
			if(this->em_movimento){
				//std::cout << "vamos andar: " << this->z << " " << this->x << std::endl;
				this->GoFront();
			}
		}else{
			// temos de pedir ao AI para saber o que fazer
			
		}
		
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

void Guard::set_xy(float z, float x)
{
	this->x = x;
	this->y = -2.6f;
	this->z = z;
}
void Guard::setAngulo(GLfloat angulo)
{
	this->angulo = angulo;
}

void Guard::set_walking_front()
{
	this->em_movimento = false;
	this->modificou_movimento = true;
}


/* movimento */

float Guard::MoveTest()
{
	if(this->dt_cur+0.01>this->ultimo_andar){
		// temos de ver se ele ja andou mais do que devia
		double dt_menos = this->dt_cur-this->ultimo_andar;
		this->ultimo_andar = this->dt_cur;
		if(dt_menos>0.1)
			return 1+dt_menos;
		else return 1;
	}else return 0;
}

void Guard::GoStraffLeft()
{
	GLfloat nx,nz;
	float move;
	move = this->MoveTest();
	if(move==0)
		return;
	nx=(this->x*-1)+sin(RAD(-this->angulo+270))*this->velocidade*move;
	nz=(this->z)+cos(RAD(this->angulo+270))*this->velocidade*move;
	
	if( Fisica::canIgoThere(this->z*-1, this->x*-1, nz*-1, nx, true) ){
		this->set_xy(nz, nx*-1);
	}
}

void Guard::GoStraffRight()
{
	GLfloat nx,nz;
	float move;
	move = this->MoveTest();
	if(move==0)
		return;
	nx=(this->x*-1)+sin(RAD(-this->angulo+90))*this->velocidade*move;
	nz=(this->z)+cos(RAD(this->angulo+90))*this->velocidade*move;

	if( Fisica::canIgoThere(this->z*-1, this->x*-1, nz*-1, nx, true) ){
		this->set_xy(nz, nx*-1);
	}
	
}

void Guard::GoFront()
{
	GLfloat nx,nz;
	float move;
	move = this->MoveTest();
	if(move==0)
		return;
	nx=(this->x*-1)+sin(RAD(-this->angulo))*this->velocidade*move;
	nz=(this->z)+cos(RAD(this->angulo))*this->velocidade*move;
	
	/*std::cout << " npc angulo:" << this->angulo << std::endl;
	std::cout << "-> nz: " << ((this->z)+cos(RAD(this->angulo))*this->velocidade*move) << " nx: " << ((this->x)+sin(-RAD(this->angulo))*this->velocidade*move) << std::endl;
	std::cout << " nz: " << ((this->z*-1)+cos(RAD(this->angulo))*this->velocidade*move) << " nx: " << (this->x*-1)+sin(-RAD(this->angulo))*this->velocidade*move << std::endl;
	std::cout << "+90 nz: " << ((this->z*-1)+cos(RAD(this->angulo))*this->velocidade*move) << " nx: " << (this->x*-1)+sin(-RAD(this->angulo+90))*this->velocidade*move << std::endl;
	std::cout << " nz: " << ((this->z)+cos(RAD(this->angulo))*this->velocidade*move) << " Inv nx: " << (this->x*-1)+sin(-RAD(this->angulo))*this->velocidade*move << std::endl;
	*/
	
	if( Fisica::canIgoThere(this->z*-1, this->x*-1, nz*-1, nx,true) ){
		this->set_xy(nz, nx*-1);
	}
}

void Guard::GoBack()
{
	GLfloat nx,nz;
	float move;
	move = this->MoveTest();
	if(move==0)
		return;
	nx=(this->x*-1)-sin(RAD(-this->angulo))*this->velocidade*move;
	nz=(this->z)-cos(RAD(this->angulo))*this->velocidade*move;
	
	if( Fisica::canIgoThere(this->z*-1, this->x*-1, nz*-1, nx,true) ){
		this->set_xy(nz, nx*-1);
	}
}

void Guard::GoTurnRight()
{
	float move;
	move = this->MoveTest();
	if(move==0)
		return;
	this->angulo+=3;
}

void Guard::GoTurnLeft()
{
	float move;
	move = this->MoveTest();
	if(move==0)
		return;
	this->angulo-=3;
}

