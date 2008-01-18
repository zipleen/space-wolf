/*
 *  fisica.cpp
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "fisica.h"

std::vector<std::vector <bool> > Fisica::mapa;
std::vector<std::vector <bool> > Fisica::portas;
std::vector<std::vector <bool> > Fisica::guardas;
float Fisica::cube_size;
bool Fisica::clip_mode;

bool Fisica::canIgoThere(float from_z, float from_x, float to_z,float to_x,bool guarda)
{
	int map_orig_x, map_orig_y;
	int map_x_a1, map_x_a2, map_y_a1, map_y_a2;
	bool pode_ir_paredes, pode_ir_portas;
	
	// cheat mode de passar pelas paredes
	if(Fisica::clip_mode && !guarda)
		return true;
	
	map_orig_x = (int)(((to_z*-1)/(Fisica::cube_size*2.0f))+0.5);
	map_orig_y = (int)(((to_x*-1)/(Fisica::cube_size*2.0f))+0.5);
	
	// para o X -> calcular com os Z
	map_x_a1 = (int)(((to_z*-1+(Fisica::cube_size/2))/(Fisica::cube_size*2.0f))+0.5);
	map_x_a2 = (int)(((to_z*-1-(Fisica::cube_size/2))/(Fisica::cube_size*2.0f))+0.5);
				
	// para o Y -> calcular com os X
	map_y_a1 = (int)(((to_x*-1+(Fisica::cube_size/2))/(Fisica::cube_size*2.0f))+0.5);
	map_y_a2 = (int)(((to_x*-1-(Fisica::cube_size/2))/(Fisica::cube_size*2.0f))+0.5);
	
	pode_ir_paredes = (!Fisica::mapa[map_x_a1][map_y_a1] && !Fisica::mapa[map_x_a1][map_y_a2] && !Fisica::mapa[map_x_a2][map_y_a1] && !Fisica::mapa[map_x_a2][map_y_a2]);
	
	if(pode_ir_paredes){
		// eh preciso verificar nas portas se estao abertas
		pode_ir_portas = (Fisica::portas[map_x_a1][map_y_a1] && Fisica::portas[map_x_a1][map_y_a2] && Fisica::portas[map_x_a2][map_y_a1] && Fisica::portas[map_x_a2][map_y_a2]);
		if(pode_ir_portas){
			if(guarda)
				return true;
			else{
				// verificar guardas
				if((!Fisica::guardas[map_x_a1][map_y_a1] && !Fisica::guardas[map_x_a1][map_y_a2] && !Fisica::guardas[map_x_a2][map_y_a1] && !Fisica::guardas[map_x_a2][map_y_a2]))
					return true;
				else return false;
			}
			return true;
		}
	}
	return false;
}

