/*
 *  player.cpp
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "player.h"

Player::Player()
{
	this->vida = 100;
	this->armadura = 0;
	this->pontos = 0;
	this->x = this->y = this->z = this->x_inicial = this->z_inicial = 0;
	this->resetPlayer();
	this->SetAndar();
}

void Player::draw()
{
	this->player->draw();
}

void Player::setInitialPosition(int x, int y)
{
	// em 3d, o X = Y e Z = X , 
	// Y é altura
	this->x_inicial = y;
	this->z_inicial = x;
	this->x = y;
	this->z = x;
	this->y = 0;
	this->old_x = this->x;
	this->old_y = this->y;
	this->old_z = this->z;
}

void Player::SetCorrer()
{
	this->velocidade = 1.7;
}

void Player::SetAndar()
{
	this->velocidade = 1.3;
}

void Player::resetPlayer()
{
	this->vida = 100;
	this->arma2 = false;
	this->arma3 = false;
	this->arma4 = false;
	this->armadura = 0;
	this->chave_amarela = false;
	this->chave_vermelha = false;
	this->balas = 8;
	this->setInitialPosition(this->z_inicial, this->x_inicial);
	this->morto = false;
	this->angulo = 0;
	this->arma_em_uso = 1; // ha 3 armas, cada uma dispensa balas mais rapido que a outra e tem mais "forca"
}

void Player::setGun(int tipo){
	switch(tipo)
	{
		case 1:
			this->arma_em_uso = 1;
			break;
		case 2:
			if(this->arma2)
				this->arma_em_uso = 2;
			break;
		case 3:
			if(this->arma3)
				this->arma_em_uso = 3;
			break;
		
		case 4:
			if(this->arma4)
				this->arma_em_uso = 4;
			break;
	}
	// animacao para se mudou a arma?!?!? por agora muda logo a arma..
	
}

// accoes provocadas por outros actores
void Player::takeHealth(int valor)
{
	if(this->armadura>0){
		// vamos tirar armadura
		if(this->armadura<valor){
			this->armadura=0;
			this->vida-=(valor-this->armadura);
		}else
			this->armadura-=valor;
	}else
		this->vida-=valor;
	if(this->vida<=0){
		this->vida=0;
		this->morto=true;
	}
}

// items accoes
bool Player::giveHealth(int valor)
{
	if(this->vida==100)
		return false; // nao necessitamos de mais vida
	this->vida+=valor;
	if(this->vida>100)
		this->vida=100;
	return true;
}

bool Player::giveArmadura(int valor)
{
	if(this->armadura==100)
		return false;
	this->armadura+=valor;
	if(this->armadura>100)
		this->armadura=100;
	return true;
}

bool Player::giveBullets(int valor)
{
	// so ha 1 tipo de balas HEHE mas mais tipos de balas nao era dificil anyway
	this->balas+=valor;
	if(this->balas>200)
		this->balas = 200;
	return true;
}

bool Player::giveChave(int tipo)
{
	if(tipo==1)
		this->chave_amarela = true;
	else 
		this->chave_vermelha = true;
	return true;
}

bool Player::giveArmas(int tipo)
{
	switch(tipo){
		case 2:
			this->arma2 = true;
			break;
		case 3:
			this->arma3 = true;
			break;
		case 4:
			this->arma4 = true;
			break;
	
	}
	return true;
}


/* movimentos */

void Player::updateAnimation(double dt_cur)
{
	this->dt_cur = dt_cur;
}

float Player::MoveTest()
{
	if(this->dt_cur+0.01>this->ultimo_andar){
		// temos de ver se ele ja andou mais do que devia
		double dt_menos = this->dt_cur-this->ultimo_andar;
		this->old_ultimo_andar = this->ultimo_andar;
		this->ultimo_andar = this->dt_cur;
		if(dt_menos>0.1)
			return 1+dt_menos;
		else return 1;
	 }else return 0;
}

void Player::saveValues()
{
	this->old_z = this->z;
	this->old_y = this->y;
	this->old_x = this->x;
	this->old_angulo = this->angulo;
}

void Player::calculateSpeed()
{
	if((this->dt_cur-this->old_ultimo_andar)==0)
		return;
	double dist = sqrt( pow((this->x - this->old_x),2)+pow((this->y-this->old_y),2)+pow((this->z-this->old_z),2) );
	std::cout << dist / (this->dt_cur-this->old_ultimo_andar) << std::endl;
}

void Player::GoStraffLeft()
{
	GLfloat nx,nz;
	float move;
	move = this->MoveTest();
	if(move==0)
		return;
	nx=this->x+sin(-RAD(this->angulo+270))*(this->velocidade*2/3)*move;
	nz=this->z+cos(RAD(this->angulo+270))*(this->velocidade*2/3)*move;

	if( Fisica::canIgoThere(this->z, this->x, nz, nx) ){
		
		this->saveValues();
		this->z = nz;
		this->x = nx;
		Player::calculateSpeed();
	}
}

void Player::GoStraffRight()
{
	GLfloat nx,nz;
	float move;
	move = this->MoveTest();
	if(move==0)
		return;
	nx=this->x+sin(-RAD(this->angulo+90))*(this->velocidade*2/3)*move;
	nz=this->z+cos(RAD(this->angulo+90))*(this->velocidade*2/3)*move;
	
	if( Fisica::canIgoThere(this->z, this->x, nz, nx) ){
		
		this->saveValues();
		this->z = nz;
		this->x = nx;
		Player::calculateSpeed();
	}
}

void Player::GoFront()
{
	GLfloat nx,nz;
	float move;
	move = this->MoveTest();
	if(move==0)
		return;
	nx=this->x+sin(-RAD(this->angulo))*this->velocidade*move;
	nz=this->z+cos(RAD(this->angulo))*this->velocidade*move;
	
	if( Fisica::canIgoThere(this->z, this->x, nz, nx) ){
		
		this->saveValues();
		this->z = nz;
		this->x = nx;
		Player::calculateSpeed();
	}
}

void Player::GoBack()
{
	GLfloat nx,nz;
	float move;
	move = this->MoveTest();
	if(move==0)
		return;
	nx=this->x-sin(-RAD(this->angulo))*this->velocidade*move;
	nz=this->z-cos(RAD(this->angulo))*this->velocidade*move;
	
	if( Fisica::canIgoThere(this->z, this->x, nz, nx) ){
		
		this->saveValues();
		this->z = nz;
		this->x = nx;
		Player::calculateSpeed();
	}
}

void Player::GoTurnRight()
{
	float move;
	move = this->MoveTest();
	if(move==0)
		return;
	this->angulo+=3;
}

void Player::GoTurnLeft()
{
	float move;
	move = this->MoveTest();
	if(move==0)
		return;
	this->angulo-=3;
}

