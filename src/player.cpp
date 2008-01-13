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
}

void Player::SetCorrer()
{
	this->velocidade = 1.5;
}

void Player::SetAndar()
{
	this->velocidade = 1.9;
}

void Player::resetPlayer()
{
	this->vida = 100;
	this->chave_amarela = false;
	this->chave_vermelha = false;
	this->balas = 8;
	this->x = this->x_inicial;
	this->z = this->z_inicial;
	this->morto = false;
	this->angulo = 0;
	this->arma_em_uso = 1; // ha 3 armas, cada uma dispensa balas mais rapido que a outra e tem mais "forca"
}

// accoes provocadas por outros actores
void Player::takeHealth(int valor)
{
	this->vida-=valor;
	if(this->vida<=0){
		this->vida=0;
		this->morto=true;
	}
}

// items accoes
void Player::giveHealth(int valor)
{
	this->vida+=valor;
	if(this->vida>100)
		this->vida=100;
}

void Player::giveBullets(int valor)
{
	// so ha 1 tipo de balas HEHE mas mais tipos de balas nao era dificil anyway
	this->balas+=valor;
	if(this->balas>200)
		this->balas = 200;
}

void Player::giveChave(int tipo)
{
	if(tipo==1)
		this->chave_amarela = true;
	else 
		this->chave_vermelha = true;
}

void Player::giveArmas(int tipo)
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
}

void Player::GoStraffLeft()
{
	GLfloat nx,nz;
	nx=this->x+sin(-RAD(this->angulo+270))*this->velocidade;
	nz=this->z+cos(RAD(this->angulo+270))*this->velocidade;

	if( Fisica::canIgoThere(this->z, this->x, nz, nx) ){
		this->z = nz;
		this->x = nx;
	}
}

void Player::GoStraffRight()
{
	GLfloat nx,nz;
	nx=this->x+sin(-RAD(this->angulo+90))*this->velocidade;
	nz=this->z+cos(RAD(this->angulo+90))*this->velocidade;
	
	if( Fisica::canIgoThere(this->z, this->x, nz, nx) ){
		this->z = nz;
		this->x = nx;
	}
}

void Player::GoFront()
{
	// nao esquecer que estes valores tem de ir pelo objecto de fisica
	
	GLfloat nx,nz;
	nx=this->x+sin(-RAD(this->angulo))*this->velocidade;
	nz=this->z+cos(RAD(this->angulo))*this->velocidade;
	
	if( Fisica::canIgoThere(this->z, this->x, nz, nx) ){
		this->z = nz;
		this->x = nx;
	}
}

void Player::GoBack()
{
	GLfloat nx,nz;
	nx=this->x-sin(-RAD(this->angulo))*this->velocidade;
	nz=this->z-cos(RAD(this->angulo))*this->velocidade;
	
	if( Fisica::canIgoThere(this->z, this->x, nz, nx) ){
		this->z = nz;
		this->x = nx;
	}
}

void Player::GoTurnRight()
{
	this->angulo+=2;
}

void Player::GoTurnLeft()
{
	this->angulo-=2;
}

