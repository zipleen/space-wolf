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

/* 1 VECTOR e 1 ponto, qual o angulo? NAO WORKA*/
float Fisica::AngleBetweenVectandPoint(float x1, float y1,float ang1, float x2, float y2)
{
	// achar vector do 1 ponto+angulo
	float vx1 = x1+cos(RAD(ang1));
	float vy1 = y1+sin(RAD(ang1));
	// achar segundo vector, desta vez com o primeiro ponto do primeiro 
	float vx2 = x2-x1;
	float vy2 = y2-y1;
	
	float cosine = (vx1 * vx2 + vy1 * vy1) / (sqrt( (vx1*vx1) + (vy1*vy1) ) * sqrt( (vx2*vx2) + (vy2*vy2) ));
	// rounding errors might make dotproduct out of range for cosine
	if (cosine > 1) cosine = 1;
	else if (cosine < -1) cosine = -1;
	
	if ((vx1 * vy2 - vy1 * vx2) < 0)
		return GRAUS(-acos(cosine));
	else
		return GRAUS(acos(cosine));
}


/* se tivermos dois pontos e 2 angulos (ou seja 1 ponto com um angulo pode ser um vector director), podemos achar os angulos entre eles */
float Fisica::AngleBetween2Vect(float x1, float y1,float ang1, float x2, float y2, float ang2)
{
	// achar vector 1 e 2
	float vx1 = x1*cos(RAD(ang1));
	float vy1 = y1*sin(RAD(ang1));
	float vx2 = x2*cos(RAD(ang2));
	float vy2 = y2*sin(RAD(ang2));
	
	float cosine = (vx1 * vx2 + vy1 * vy1) / (sqrt( (vx1*vx1) + (vy1*vy1) ) * sqrt( (vx2*vx2) + (vy2*vy2) ));
	// rounding errors might make dotproduct out of range for cosine
	if (cosine > 1) cosine = 1;
	else if (cosine < -1) cosine = -1;
	
	if ((vx1 * vy2 - vy1 * vx2) < 0)
		return GRAUS(-acos(cosine));
	else
		return GRAUS(acos(cosine));
}

/*
  tenho de dar credito a quem merece, apos 6 horas de andar as voltas com vectores e contas e altos filmes
 encontrei a solucao aqui: http://www.allegro.cc/forums/thread/591460 , ultimo post
 */
float Fisica::Angle(float x1, float y1, float x2, float y2)
{
	double opp;
	double adj;
	double ang1;
	
	//calculate vector differences
	opp=y1-y2;
	adj=x1-x2;
	
	if(x1==x2 && y1==y2) return(-1);
	
	//trig function to calculate angle
	if(adj==0) // to catch vertical co-ord to prevent division by 0
	{
		if(opp>=0) 
		{
			return(0);
		}
		else 
		{
			return(180);
		}
	}
	else 
	{
		ang1=(atan(opp/adj))*180/M_PI;
		//the angle calculated will range from +90 degrees to -90 degrees
		//so the angle needs to be adjusted if point x1 is less or greater then x2
		if(x1>=x2)
		{
			ang1=90-ang1;
		}
		else
		{
			ang1=270-ang1;
		}
	} 
	return(ang1);
}

/*
  ha uma confusao gigantesca de coordenadas positivas e negativas... o player ta nas negativas, mas tudo ta nas positivas
 a fisica faz sempre contas com negativas, ptt eh preciso passar tudo pras negativas
 */
bool Fisica::canIgoThere(float from_z, float from_x, float to_z,float to_x,bool guarda)
{
	// calcular se o From e To tem uma distancia maior que cube_size
	float vx = to_z-from_z;
	float vy = to_x-from_x;
	float dist = sqrt(vx*vx + vy*vy);
	if(dist>=(Fisica::cube_size*2)){
		
		int ang = Fisica::Angle(from_x*-1, from_z*-1, to_x*-1, to_z*-1);
		//std::cout << "FROM:("<<from_z << "," << from_x << ") TO("<< to_z << "," << to_x << ") ang: " << ang << " ";
		std::cout << "ang: " << ang << " ";
		float newx = to_x + (sin(-RAD(ang))*Fisica::cube_size);
		float newz = to_z + (cos(RAD(ang))*Fisica::cube_size);
		if( Fisica::canIgoThereIn(from_z, from_x, to_z,to_x,guarda) )
			return Fisica::canIgoThere(from_z, from_x, newz, newx, guarda);
		else return false;
	}else return Fisica::canIgoThereIn(from_z, from_x, to_z,to_x,guarda);
}

bool Fisica::canIgoThereIn(float from_z, float from_x, float to_z,float to_x,bool guarda)
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
			if(guarda){
				// ja tou farto do guarda andar por cima do player!!!
				Sound *s = Sound::GetInstance();
				int p_x = (int)(((s->player_z)/(Fisica::cube_size*2.0f))+0.5);
				int p_y = (int)(((s->player_x)/(Fisica::cube_size*2.0f))+0.5);
				if( (p_x == map_orig_x && p_y == map_orig_y) || (p_x == map_x_a1 && p_y == map_y_a1) ||  (p_x == map_x_a2 && p_y == map_y_a2) )
					return false;
				else return true;
			}
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

