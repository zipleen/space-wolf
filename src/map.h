/*
 *  mapa.h
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef MAP_H
#define MAP_H

#define MAP_SIZE 64

#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <boost/tokenizer.hpp>
#include <string>
#include <fstream>

#include "guard.h"
#include "soldado.h"
#include "items.h"
#include "items_vida.h"
#include "porta.h"
#include "player.h"
#include "md3/TextureManager.h"
#include "console.h"
#include "StrUtils.h"

typedef map<int, const Texture2D *> TexMap;

class Map
{
protected:
	std::vector<std::vector<int> > map; // vector de vector....
	std::vector<std::vector<int> > floormap; // vector com os floor codes, para o AI
	/*int map[MAP_SIZE][MAP_SIZE];
	int floormap[MAP_SIZE][MAP_SIZE];*/
	std::vector<Guard*> guardas;
	std::vector<Items*> items;
	std::vector<Porta*> portas;
	Texture2DManager *texMgr;
	TexMap map_textures;
	
	GLuint calllists[3];
	bool usecalllist;
	
	int tamanho_mapa;
	int tex_tecto;
	int tex_chao;
	
	// porta normal
	int tex_porta; // textura da porta
	const Texture2D *textura_porta;
	int tex_porta_lado; // parede da direita e esquerda ah beira de uma porta
	const Texture2D *textura_porta_lado;
	// porta chave 1
	int tex_porta_chave1; // textura da porta
	const Texture2D *textura_porta_chave1;
	int tex_porta_lado_chave1; // parede da direita e esquerda ah beira de uma porta
	const Texture2D *textura_porta_lado_chave1;
	// porta chave 2
	int tex_porta_chave2; // textura da porta
	const Texture2D *textura_porta_chave2;
	int tex_porta_lado_chave2; // parede da direita e esquerda ah beira de uma porta
	const Texture2D *textura_porta_lado_chave2;
	
	bool desenharTudo;
	GLfloat cube_size;
	
public:
	
	Map(); 
	virtual ~Map(){};
	
	// animacoes
	void updateAnimations(double dt,double dt_cur);
	void updateGuardAnimation(double dt);
	void updateItemsAnimation(double dt,double dt_cur);
	void updateDoorAnimation(double dt,double dt_cur);
	
	// ler mapas
	bool loadTextures();
	bool loadMap(std::string file, Player *player);
	void addItems(int x, int y, int type);
	void addGuard(int x, int y, int type, int direction, bool movimento);
	void addPorta(int x, int y, int type, int direction);
	
	// desenhar mapas
	void drawGuards();
	void drawDoors();
	void drawItems();
	void drawMap();
	void drawEverything();
	
	// desenhar opengl
	void setMaterial();
	void createCallListMap();
	void glDrawCube(const Texture2D* tex);
	void desenhaChao();
	void desenhaTecto();
	void drawAllMap();
};

#endif
