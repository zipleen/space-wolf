/*
 *  mapa.cpp
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "map.h"

Map::Map()
{
	texMgr = Texture2DManager::getInstance ();
	this->guardas.clear();
	this->items.clear();
	
	this->desenharTudo = true;
}

void Map::updateGuardAnimation(double dt)
{
	for(int i=0;i<(signed)this->guardas.size();i++)
	{
		this->guardas[i]->animate(dt);
	}
}

void Map::drawGuards()
{
	if(desenharTudo)
	{
		for(int i=0;i<this->guardas.size();i++)
		{
			this->guardas[i]->draw();
		}
	}else{
		// codigo optimizado para nao desenhar tudo...
	}
}

void Map::setDificuldade(int dif)
{
	this->dificuldade = dif;
}

void Map::addGuard(int x, int y, int type, int direction, bool movimento, int dificuldade)
{
	GLfloat angulo;
	
	if(this->dificuldade<=dificuldade)
		return;
	
	switch(direction)
	{
		case 1:
			angulo = 0;
			break;
		case 2:
			angulo = 90;
			break;
		case 3:
			angulo = 180;
			break;
		case 4:
			angulo = 280;
			break;
		default:
			angulo = 0;
			break;
	}
	
	switch(type){
		case 1: // soldados mais faceis
			Soldado *s = new Soldado(x,y,angulo, movimento);
			this->guardas.push_back(s);
			Console::addLine("Adicionado guarda soldado");
			break;
	}
}

bool Map::loadMap(std::string file)
{
	this->addGuard(1, 1, 1 , 90, true, 3);
	return true;
	/*std::ifstream ifs (filename.c_str(), std::ios::in);
	if (ifs.fail ())
		return false;
	
	// ler tamanho
	int tamanho;
	ifs >> tamanho;
	
	// ler textura do tecto
	int tex_tecto;
	ifs >> tex_tecto;
	
	// ler textura do chao
	int tex_chao;
	ifs >> tex_chao;
	
	/*while (!ifs.eof ())
    {
		string meshname, texname, buffer;
		
		// Read mesh name and texture name
		std::getline (ifs, meshname, ',');
		ifs >> texname;
		
		
	}*/
}