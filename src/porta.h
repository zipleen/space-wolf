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
#include <SDL_mixer.h>
#include "sound.h"

class Porta
	{
	public:
		Sound *s;
		Mix_Chunk *som_porta_abrir;
		Mix_Chunk *som_porta_fechar;
		int canal_porta_abrir;
		int canal_porta_fechar;
		
		// isto vai controlar a altura (que em 3d eh na realidade o Y)
		GLfloat altura;
		// o tamanho pelo qual temos de multiplicar o x e y (na realidade Z e X) para ficar no sitio certo
		GLfloat cube_size;
		// tem uma razao de ser por estes serem int's
		// estes sao na realidade as coordenadas "no vector bidimensional"
		// depois nos eh que metemos o cubo no sitio certo multiplicando por cube_size (e aih eh um float)
		int x;
		int y;
		int direction; // 0 -> norte 1-> oeste 
		bool open;

		int time_open;
		// tempo para abertura das portas?
		bool porta_a_abrir;
		bool porta_a_fechar;
		
		double last_dt;
		double tempo_comecou_contar;
		GLfloat subir;
		
	public:
		int tipo_porta; // 0 - normal 1- chave amarela 2-chave vermelha
		Porta(int x, int y, int direction,int tipo_porta,GLfloat cube_size); 
		virtual ~Porta(){};
		
		void startOpenDoor();
		void startCloseDoor();
		void tryToOpenDoor(bool chave1, bool chave2);
		void opendoor();
		void closedoor();
		void draw(const Texture2D *textura_porta, const Texture2D *textura_porta_lado);
		void animate(const double dt,const double dt_cur);
	};

#endif