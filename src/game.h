/*
 *  game.h
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 *	Este game como soh tem 1 mapa significa que o main vai ter de controlar quais episodios ha para ir e todas as vezes que ha um nivel novo,
 *	deleta o objecto game e cria um novo game
 
	E o player? eh preciso guardar as estatisticas do player... sera q o player pode estar ca fora? se calhar o player tem de estar ca fora
     pq eh o unico que vai andar sempre a mexer-se... exacto... 
 */

#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <time.h>

#include <SDL.h>
#include "map.h"
#include "player.h"
#include "rendering.h"
#include "input.h"

class Game
{
public:
	Map *map; // o nosso mapa actual
	Player *player;
	Rendering *render;
	Input *input;
	
public:
	Game(const char *map_name); 
	virtual ~Game(){};
	
	/*
	 se ele fizer exit desta funcao
	 1 - acabou o jogo e passou de nivel
	 2 - acabou o jogo e morreu
	 3 - parou o jogo com o esq
	 */
	int MainLoop();
};

#endif
