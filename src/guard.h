/*
 *  guard.h
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef GUARD_H
#define GUARD_H

#include "md3/Md3Player.h"
#include "console.h"

class Guard 
{
protected:
	Md3Player *guard;
	Md3Weapon *weapon;
	std::string model_path;
	std::string weaponpath;
	
	bool em_movimento;
	int vida;
	int velocidade_disparo;
	int velocidade_correr;
	int damage_arma;
	
	int ultimo_disparo; // guarda-se aqui o tick do ultimo disparo para se saber quando se pode disparar outra vez
	
	// posicao no mapa
	int x;
	int y;
	GLfloat angulo;
	
	bool morto;
public:
	Guard(); 
	virtual ~Guard(){};

	void Guard::loadModel();
	void draw();
	void animate(const double dt);
	
	void set_angulo(GLfloat angulo);
	void set_xy(int x, int y);
};

#endif