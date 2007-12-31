/*
 *  player.h
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "md3/Md3Player.h"

class Player
{
protected:
	int vida;
	int pontos;
	int chave_amarela;
	int chave_vermelha;
	int chave_azul;
	Md3Player *player;
	
public:
	Player(){}; 
	virtual ~Player(){};

	void draw();
};

#endif
