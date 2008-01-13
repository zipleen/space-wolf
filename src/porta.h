/*
 *  porta.h
 *  proj
 *
 *  Created by Zipleen on 1/6/08.
 *  Cada porta / item vai ter o codigo opengl para se fazer draw dela?
 *
 */

#ifndef PORTA_H
#define PORTA_H

#include "md3/TextureManager.h"
#include "console.h"
#include "fisica.h"

class Porta
	{
	public:
		
		GLfloat cube_size;
		int x;
		int y;
		int direction; // 0 -> norte 1-> oeste 
		bool open;

		int time_open;
		// tempo para abertura das portas?
		
	public:
		int tipo_porta; // 0 - normal 1- chave amarela 2-chave vermelha
		Porta(int x, int y, int direction,int tipo_porta,GLfloat cube_size); 
		virtual ~Porta(){};
		
		void startOpenDoor();
		void tryToOpenDoor(bool chave1, bool chave2);
		void opendoor();
		void draw(const Texture2D *textura_porta, const Texture2D *textura_porta_lado);
		void animate(const double dt,const double dt_cur);
	};

#endif