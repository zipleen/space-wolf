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
}

void Player::draw()
{
	this->player->draw();
}

void setPosition(int x, int y)
{
	
}