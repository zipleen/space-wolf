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

#include "guard.h"
#include "soldado.h"
#include "items.h"
#include "md3/TextureManager.h"
#include "console.h"

class Map
{
protected:
	std::vector< std::vector<int> > map; // vector de vector....
	std::vector<Guard*> guardas;
	std::vector<Items*> items;
	Texture2DManager *texMgr;
	
	int dificuldade;
	
	bool desenharTudo;
public:
	Map(); 
	virtual ~Map(){};
	
	void updateGuardAnimation(double dt);
	
	// ler mapas
	bool loadMap(std::string file);
	void setDificuldade(int dif);
	void addGuard(int x, int y, int type, int direction, bool movimento, int dificuldade);
	
	// desenhar mapas
	void drawGuards();
};

#endif
