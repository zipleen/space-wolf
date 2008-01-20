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
#include <cmath>

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif
#define RAD(x)          (M_PI*(x)/180)
#define GRAUS(x)        (180*(x)/M_PI)

class Fisica
{
public:
	static std::vector<std::vector <bool> > mapa;
	static std::vector<std::vector <bool> > portas;
	static std::vector<std::vector <bool> > guardas;
	
public:
	
	static float cube_size;
	Fisica(){}; 
	virtual ~Fisica(){};
	static bool clip_mode;
	
	static float AngleBetween2Vect(float x1, float y1,float ang1, float x2, float y2, float ang2);
	static float Angle(float x1, float y1, float x2, float y2);
	static void setGuardas(std::vector<std::vector <bool> > map){Fisica::guardas = map;};
	static void setMap(std::vector<std::vector <bool> > map, float cube_size){Fisica::mapa = map;Fisica::cube_size = cube_size;};
	static void setPortas(std::vector<std::vector<bool> > p){ Fisica::portas=p;};
	static void updatePortas(int x, int y, bool value){ Fisica::portas[x][y]=value; };
	static bool canIgoThere(float from_z, float from_x, float to_z,float to_x,bool guarda=false);
	static bool canIgoThereIn(float from_z, float from_x, float to_z,float to_x,bool guarda=false);
	
};

#endif

