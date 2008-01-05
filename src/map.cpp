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
	//this->map = std::vector<std::vector<int> >(64,std::vector<int>(64,0));
	this->floormap = std::vector<std::vector<int> >(64,std::vector<int>(64,0));
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


void Map::addGuard(int x, int y, int type, int direction, bool movimento)
{
	GLfloat angulo;
	
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
	string aa; // temp
	//this->addGuard(1, 1, 1 , 90, true, 3);
	//return true;
	
	std::ifstream ifs (file.c_str(), std::ios::in);
	if (ifs.fail ())
		return false;
	
	// ler tamanho
	ifs >> this->tamanho_mapa;
	
	// ler textura do tecto
	int tex_tecto;
	ifs >> tex_tecto;
	
	// ler textura do chao
	int tex_chao;
	ifs >> tex_chao;
	std::getline (ifs, aa);
    for(int i=0; i<this->tamanho_mapa; ++i)
	{
		std::vector<int> aaa(this->tamanho_mapa-1);
		std::getline (ifs, aa);
		Tokenize(aa, aaa ,',');
		this->map.push_back(aaa);
	}
	// enter a separar
	std::getline (ifs, aa);
    for(int i=0; i<this->tamanho_mapa; ++i)
	{
		std::vector<int> aaa(this->tamanho_mapa-1);
		std::getline (ifs, aa);
		Tokenize(aa, aaa ,',');
		this->floormap.push_back(aaa);		
	}
	
	for(int i = 0; i <this->map.size(); i++){
		std::cout << i << ": " ;
		for(int e=0; e<this->map[i].size(); e++){
			std::cout << this->map[i][e] << " ";
		}
		std::cout << std::endl;
	}
}