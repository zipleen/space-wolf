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

#ifndef MENU_S
#define MENU_S

#include <stdlib.h>
#include <time.h>

#include <SDL.h>
#include <vector>
#include "rendering.h"
#include "font/Font.h"
#include "Md3/TextureManager.h"

class Menu_def
{
public:
	Rendering *render;
	bool keyUpPressed;
	bool keyDownPressed;
	bool keyEnterPressed;
	int num_menu;

protected:
	TTFont *font;
	int tamanho_font;
	int subir_descer[4];
	Texture2D *controlos, *background;
	std::vector<std::string> menu_definicoes;

public:
	Menu_def(); 
	virtual ~Menu_def(){};
	
	void handleKeyPress (SDL_keysym *key, bool value);
	void MainLoopMenuDef();
	void end2D();
	void start2D();
};

#endif
