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

#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <time.h>

#include <SDL.h>
#include <vector>
#include "game.h"
#include "rendering.h"
#include "font/Font.h"
#include "Md3/TextureManager.h"
#include "game.h"
#include "StrUtils.h"

class Menu
{
public:
	Rendering *render;
	Game *game;
	
	int num_menu;
	int menu_to_render;
	int numero_mapa;
	bool mensagem_ja_mostrada;
	bool new_game;
	bool game_is_running;
	
	bool mapa_custom;
	std::string mapa_custom_nome;
	
	// configs
	bool config_fullscreen;

protected:
	TTFont *font;
	TTFont *font2;
	int tamanho_font;
	int subir_descer[4];
	Texture2D *controlos, *background, *loading, *died, *congrats;
	std::vector<std::string> menu_principal;
	std::vector<std::string> menu_definicoes;

public:
	Menu(); 
	virtual ~Menu(){};
	
	void handleKeyPress (SDL_keysym *key, bool value);
	void GameLoop();
	void MainLoopMenu();
	void end2D();
	void start2D();
	
	void shutdown();
	std::string getMapa();
	void displayImage(Texture2D *i);
	
	void desenharMainMenu();
	void desenharDefinicoes();
	void mostrar_imagem_controlos();
	
	void handleLeftRight(int v);
	void handleMenuHit();
};

#endif
