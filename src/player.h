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
	bool chave_amarela;
	bool chave_vermelha;
	Md3Player *player;
	
	GLfloat x,y;
public:
	Player(); 
	virtual ~Player(){};

	void draw();
	void setPosition(int x, int y); // posicao do mapa inicial
};

#endif
