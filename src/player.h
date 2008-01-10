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
	float velocidade;
	
	Md3Player *player;
	
public:
	GLfloat x,y,z;
	GLfloat angulo;
	
	Player(); 
	virtual ~Player(){};

	void draw();
	void setPosition(int x, int y); // posicao do mapa inicial
	
	void SetAndar();
	void SetCorrer();
	
	// controlos direccao
	void GoBack();
	void GoFront();
	void GoStraffLeft();
	void GoStraffRight();
	void GoTurnRight();
	void GoTurnLeft();
};


#endif
