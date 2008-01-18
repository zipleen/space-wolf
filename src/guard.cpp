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
	this->som_disparo_arma = 0;
	this->ultimo_disparo = 0;
	this->ultimo_andar = 0;
	this->velocidade = VELOCIDADE_ANDAR_GUARDA;
	this->z=this->x=0;
	this->s = Sound::GetInstance();
	// ler passos
#ifdef WIN32
	this->som_passos[1] = this->s->loadSound("data\\sounds\\footsteps\\boot1.wav");
	this->som_passos[2] = this->s->loadSound("data\\sounds\\footsteps\\boot2.wav");
	this->som_passos[3] = this->s->loadSound("data\\sounds\\footsteps\\boot3.wav");
	this->som_passos[4] = this->s->loadSound("data\\sounds\\footsteps\\boot4.wav");
#else
	this->som_passos[1] = this->s->loadSound("data/sounds/footsteps/boot1.wav");
	this->som_passos[2] = this->s->loadSound("data/sounds/footsteps/boot2.wav");
	this->som_passos[3] = this->s->loadSound("data/sounds/footsteps/boot3.wav");
	this->som_passos[4] = this->s->loadSound("data/sounds/footsteps/boot4.wav");
#endif
	this->som_passo_corrente=1;
	this->canal_som_passos[0]=0;
	this->canal_som_passos[1]=0;
	this->canal_som_passos[2]=0;
	this->canal_som_passos[3]=0;
	this->canal_som_passos[4]=0;
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

void Guard::nextMove()
{
	this->shootGun();
	
}

void Guard::shootGun()
{
	// primeiro temos de ver se podemos disparar, se podemos entao metemos o disparar a true
	//std::cout << "ult disp"<< this->ultimo_disparo << " velocidade: " << this->velocidade_disparo << " dt_cir: " << this->dt_cur << std::endl;
	if(this->ultimo_disparo+this->velocidade_disparo < this->dt_cur){
		// podemos disparar
		this->disparar = true;
		this->em_disparo = true;
		this->ultimo_disparo = this->dt_cur;
		if(Mix_Playing(this->som_disparo_arma)!=0)
			Mix_HaltChannel(this->som_disparo_arma);
		this->som_disparo_arma = this->s->playSound(this->som_arma,this->z,this->x);
		this->guard->setAnimation (kTorsoAttack);
	}
}


void Guard::playSomPassos()
{
	// verificar se o som está a tocar
	if(this->canal_som_passos[this->som_passo_corrente]==0 || Mix_Playing(this->canal_som_passos[this->som_passo_corrente])==0){
		//std::cout << "som corrente "<< this->z << " " << this->x << ": " << this->som_passo_corrente << std::endl;
		// ja nao toca
		this->canal_som_passos[this->som_passo_corrente] = this->s->playSound(this->som_passos[this->som_passo_corrente], this->z, this->x);
		if(this->som_passo_corrente==4)
			this->som_passo_corrente=1;
		else this->som_passo_corrente++;
		
	}
}

void Guard::takeHealth(GLfloat z, GLfloat x)
{
	this->morto=true;
	int orig_x = (int)(((this->z)/(Fisica::cube_size*2.0f))+0.5);
	int orig_y = (int)(((this->x)/(Fisica::cube_size*2.0f))+0.5);
	Fisica::guardas[orig_x][orig_y] = false;
	
}

void Guard::animate(const double dt, double dt_cur)
{
	this->dt_cur = dt_cur;
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
				//this->guard->setAnimation (kTorsoAttack);
				if(this->ultimo_disparo+this->velocidade_disparo < this->dt_cur)
					this->em_disparo=false;
			}else{
				this->guard->setAnimation (kTorsoStand);
			}
			this->modificou_upper_movimento = false;
		}
		this->guard->animate(dt);
		
		// som
		if(this->em_movimento)
			this->playSomPassos();
	}else{
		// estamos mortos ou vamos morrer
		if(!this->a_morrer){
			this->guard->unlinkWeapon();
			this->guard->_lowerAnim.executar_anim = false;
			this->guard->_upperAnim.executar_anim = false;
			switch(rand()%4+1){
				case 1:
					this->guard->setAnimation(kBothDeath1);
					this->s->playSound(this->som_morrer[1],this->z, this->x);
					break;
				case 2:
					this->guard->setAnimation(kBothDeath2);
					this->s->playSound(this->som_morrer[2],this->z, this->x);
					break;
				default:
				case 3:
					this->guard->setAnimation(kBothDeath3);
					this->s->playSound(this->som_morrer[3],this->z, this->x);
					break;
			}
			
			this->a_morrer=true;
		}
		this->guard->animate(dt);
	}
}

void Guard::set_xy(float z, float x)
{
	// temos de ir ah fisica retirar o nosso valor para 0
	int orig_x = (int)(((this->z)/(Fisica::cube_size*2.0f))+0.5);
	int orig_y = (int)(((this->x)/(Fisica::cube_size*2.0f))+0.5);
	Fisica::guardas[orig_x][orig_y] = false;

	this->x = x;
	this->y = -2.6f;
	this->z = z;
	
	// actualizar para novo valor
	orig_x = (int)(((this->z)/(Fisica::cube_size*2.0f))+0.5);
	orig_y = (int)(((this->x)/(Fisica::cube_size*2.0f))+0.5);
	Fisica::guardas[orig_x][orig_y] = true;
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
		if(dt_menos>0.1 && dt_menos <2)
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

