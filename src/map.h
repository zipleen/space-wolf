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

#include <iostream>
#include <iomanip>
#include<boost/tokenizer.hpp>
#include<string>
#include <fstream>

#include "guard.h"
#include "soldado.h"
#include "items.h"
#include "md3/TextureManager.h"
#include "console.h"
#include <StrUtils.h>


class Map
{
protected:
	std::vector<std::vector<int> > map; // vector de vector....
	std::vector<std::vector<int> > floormap; // vector com os floor codes, para o AI
	std::vector<Guard*> guardas;
	std::vector<Items*> items;
	Texture2DManager *texMgr;
	int tamanho_mapa;
	
	bool desenharTudo;
public:
	Map(); 
	virtual ~Map(){};
	
	void updateGuardAnimation(double dt);
	
	// ler mapas
	bool loadMap(std::string file);
	void addGuard(int x, int y, int type, int direction, bool movimento);
	
	// desenhar mapas
	void drawGuards();
};

#endif
