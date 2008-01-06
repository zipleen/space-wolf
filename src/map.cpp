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
	if(this->desenharTudo)
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
			Console::printf("Adicionado guarda facil em %d,%d, angulo: %d, movimento: %d",x,y,angulo,movimento);
			break;
	}
}

bool Map::loadMap(std::string file)
{
	std::string linha; // temp
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
	std::getline (ifs, linha);
	boost::char_separator<char> sep(",");
    for(int i=0; i<this->tamanho_mapa; ++i)
	{
		std::vector<int> coisas_para_por(this->tamanho_mapa-1);
		std::getline (ifs, linha);
		boost::tokenizer<boost::char_separator<char> > tok(linha,sep);
		for(boost::tokenizer<boost::char_separator<char> >::iterator beg=tok.begin(); beg!=tok.end();++beg){
			cout << *beg ;
		}
		cout << "\n";
		//Tokenize(linha, coisas_para_por ,',');
		//this->map.push_back(coisas_para_por);
	}
	// enter a separar
	std::getline (ifs, linha);
    for(int i=0; i<this->tamanho_mapa; ++i)
	{
		std::vector<int> codigos_floor(this->tamanho_mapa-1);
		std::getline (ifs, linha);
		Tokenize(linha, codigos_floor ,sep);
		this->floormap.push_back(codigos_floor);		
	}
	
	for(int i = 0; i <this->map.size(); i++){
		std::cout << i << ": " ;
		for(int e=0; e<this->map[i].size(); e++){
			std::cout << this->map[i][e] << " ";
		}
		std::cout << std::endl;
	}
	for(int i = 0; i <this->floormap.size(); i++){
		std::cout << i << ": " ;
		for(int e=0; e<this->floormap[i].size(); e++){
			std::cout << this->floormap[i][e] << " ";
		}
		std::cout << std::endl;
	}
}