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

// guardas
#include "guard.h"
#include "soldado.h" // guarda 1
#include "guard_medium.h" // guarda 2
#include "guarda_intermedio.h"
#include "guarda_dificil.h"
#include "guard_robo.h"
#include "boss1.h"

// items
#include "items.h"
#include "items_vida.h"
#include "items_chave.h"
#include "items_armas.h"
#include "items_ammo.h"
#include "items_armor.h"

#include "porta.h"
#include "objectos_decorativos.h"

#include "shared_render_objects.h"
#include "player.h"
#include "fisica.h"
#include "md3/TextureManager.h"
#include "console.h"
#include "StrUtils.h"

class Map
{
protected:
	typedef map<int, const Texture2D *> TexMap;
	std::vector<std::vector<int> > map; // vector de vector....
	std::vector<std::vector<int> > floormap; // vector com os floor codes, para o AI
	/*int map[MAP_SIZE][MAP_SIZE];
	int floormap[MAP_SIZE][MAP_SIZE];*/
	std::vector<Guard*> guardas;
	std::vector<Items*> items;
	std::vector<Porta*> portas;
	std::vector<Objectos_decorativos*> objectos;
	Texture2DManager *texMgr;
	TexMap map_textures;
	
	GLuint calllists[3];
	bool usecalllist;
	
	int tamanho_mapa;
	int tex_tecto;
	int tex_chao;
	
	int fim_mapa_x;
	int fim_mapa_y;
	
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
	
	// accoes
	void processTiros(Player *p);
	void processAIguards();
	
	// portas
	void openDoor(Player *p);
	void openDoor(Guard *p);
	void processItems(Player *p);
	
	// animacoes
	void updateAnimations(double dt,double dt_cur);
	void updateGuardAnimation(double dt,double dt_cur);
	void updateItemsAnimation(double dt,double dt_cur);
	void updateDoorAnimation(double dt,double dt_cur);
	
	// ler mapas
	bool loadTextures();
	bool loadMap(std::string file, Player *player);
	void addItems(int x, int y, int type);
	void addGuard(int x, int y, int type, int direction, bool movimento);
	void addPorta(int x, int y, int type, int direction);
	void addObject(int x, int y, int code, std::vector<std::vector <bool> > &a);
	
	// desenhar mapas
	void drawGuards();
	void drawDoors();
	void drawItems();
	void drawMap();
	void drawObjectos();
	void drawEverything();
	
	// desenhar opengl
	void setMaterial();
	void createCallListMap();
	void glDrawCube(const Texture2D* tex);
	void desenhaChao();
	void desenhaTecto();
	void drawAllMap();
	
	int getFloorcode(int x, int y);
	int getFloorcode(GLfloat z, GLfloat x);
	
};

#endif
