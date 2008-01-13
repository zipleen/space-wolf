/*
 *  fisica.h
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef FISICA_H
#define FISICA_H

#include <vector>
#include <iostream>
class Fisica
{
protected:
	static std::vector<std::vector <bool> > mapa;
	static std::vector<std::vector <bool> > portas;
	static float cube_size;
	
public:
	Fisica(){}; 
	virtual ~Fisica(){};
	
	static void setMap(std::vector<std::vector <bool> > map, float cube_size){Fisica::mapa = map;Fisica::cube_size = cube_size;};
	static void setPortas(std::vector<std::vector<bool> > p){ Fisica::portas=p;};
	static void updatePortas(int x, int y, bool value){ Fisica::portas[x][y]=value; };
	static bool canIgoThere(float from_z, float from_x, float to_z,float to_x);
	
};

#endif

