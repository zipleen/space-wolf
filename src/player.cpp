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
	this->chave_amarela = false;
	this->chave_vermelha = false;
	this->x = this->y = this->z = 0;
	this->SetAndar();
}

void Player::draw()
{
	this->player->draw();
}

void Player::setPosition(int x, int y)
{
	this->x = x;
	this->z = y;
	this->y = 1;
}

void Player::SetCorrer()
{
	this->velocidade = 0.3;
}

void Player::SetAndar()
{
	this->velocidade = 3;
}

void Player::GoStraffLeft()
{
	this->x++;
}

void Player::GoStraffRight()
{
	this->x--;
}

void Player::GoFront()
{
	// nao esquecer que estes valores tem de ir pelo objecto de fisica
	
	// isto nao bate certo lol
	GLfloat nx,nz;
	nx=this->x-cos(this->angulo)*this->velocidade;
	nz=this->z-sin(-this->angulo)*this->velocidade;
	
	this->z = nz;
	this->x = nx;
	//this->z++;
}

void Player::GoBack()
{
	GLfloat nx,nz;
	nx=this->x+cos(this->angulo)*this->velocidade;
	nz=this->z+sin(-this->angulo)*this->velocidade;
	
	this->z = nz;
	this->x = nx;
	//this->z--;
}

void Player::GoTurnRight()
{
	this->angulo++;
}

void Player::GoTurnLeft()
{
	this->angulo--;
}

