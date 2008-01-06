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

class Porta
	{
	protected:
		int x;
		int y;
		int direction; // 0 -> norte 1-> oeste 
		int open;
		int tipo_porta; // 0 - normal 1- chave amarela 2-chave vermelha
		
		int time_open;
		// tempo para abertura das portas?
		
	public:
		Porta(int x, int y, int direction,int tipo_porta); 
		virtual ~Porta(){};
		
		void opendoor();
		void draw();
		void animate(const double dt);
	};

#endif