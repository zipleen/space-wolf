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
	//this->floormap = std::vector<std::vector<int> >(64,std::vector<int>(64,0));
	this->guardas.clear();
	this->items.clear();
	
	this->desenharTudo = true;
}

/* texturas */
bool Map::loadTextures()
{
	std::string line;
	boost::char_separator<char> sep(" ");
	Console::addLine("Loading textures...");
	std::ifstream ifs ("data/textures/textures.def", std::ios::in);
	if (ifs.fail ()){
		Console::addLine("Erro a ler o ficheiro de texturas");
		return false;
	}
	
	// fazer o mapa das texturas que sao necessarias
	std::set<int> needed;
	for(int i=0; i< this->map.size(); ++i)
	{
		for(int e=0; e< this->map[i].size(); ++e){
			
		if(this->map[i][e]!=0)
			needed.insert(this->map[i][e]);
		}
	}
	
	while(!ifs.eof())
	{
		std::vector<std::string> t;
		int num;
		// ler linha
		std::getline(ifs, line);
		// partir pq o primeiro eh o numero e segundo eh a path
		Tokenize(line, t, sep);
		num = StrtoInt(t[0]);
		// iterador para encontrar no needed
		set<int>::iterator it;
		it=needed.find(num);
		if(it!=needed.end()){
			Console::addLine("Loading texture "+t[0]+" in "+t[1]);
			Texture2D *tex = texMgr->load (t[1]);
			map_textures.insert (TexMap::value_type (num, tex));
		}
	}
	
	Console::addLine("Ended loading textures");
	return true;
}


void Map::updateAnimations(double dt)
{
	this->updateGuardAnimation(dt);
	/*this->updateDoorAnimation(dt);
	 this->updateItemsAnimation(dt);*/
}

void Map::updateGuardAnimation(double dt)
{
	for(int i=0;i<(signed)this->guardas.size();i++)
	{
		this->guardas[i]->animate(dt);
	}
}
/*
void Map::updateDoorAnimation(double dt)
{
	for(int i=0;i<(signed)this->guardas.size();i++)
	{
		this->guardas[i]->animate(dt);
	}
}

void Map::updateItemsAnimation(double dt)
{
	for(int i=0;i<(signed)this->guardas.size();i++)
	{
		this->guardas[i]->animate(dt);
	}
}*/

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

void Map::drawDoors()
{
	if(this->desenharTudo)
	{
		for(int i=0;i<this->portas.size();i++)
		{
			this->portas[i]->draw();
		}
	}else{
		// codigo optimizado para nao desenhar tudo...
	}
	
}
void Map::drawItems()
{
	if(this->desenharTudo)
	{
		for(int i=0;i<this->items.size();i++)
		{
			this->items[i]->draw();
		}
	}else{
		// codigo optimizado para nao desenhar tudo...
	}
	
}
void Map::drawMap()
{
	if(this->desenharTudo)
	{
		/*for(int i=0;i<this->guardas.size();i++)
		{
			this->guardas[i]->draw();
		}*/
	}else{
		// codigo optimizado para nao desenhar tudo...
	}
	
}

void Map::drawEverything()
{
	this->drawMap();
	this->drawGuards();
	this->drawDoors();
	this->drawItems();
}

void Map::addPorta(int x, int y, int type, int direction)
{
	// type = 0 , 1 , 2
	// direction = 0 ou 1 (norte ou oeste)
	Porta *s = new Porta(x,y,type,direction);
	this->portas.push_back(s);
	Console::printf("Adicionado porta em %d,%d, tipo: %d, direccao: %d",x,y,type,direction);			
}

void Map::addGuard(int x, int y, int type, int direction, bool movimento)
{
	GLfloat angulo;
	
	// 0 -> E
	// 90 -> N
	// 180 -> O
	// 270 -> S
	
	// 1 - N - 90
	// 2 - S - 270
	// 3 - E - 0
	// 4 - O - 180
	switch(direction)
	{
		case 1:
			angulo = 90;
			break;
		case 2:
			angulo = 270;
			break;
		case 3:
			angulo = 0;
			break;
		case 4:
			angulo = 180;
			break;
		default:
			angulo = 0;
			break;
	}
	
	switch(type){
		case 1: // soldados mais faceis
			//Soldado *s = new Soldado(x,y,angulo, movimento);
			//this->guardas.push_back(s);
			Console::printf("Adicionado guarda facil em %d,%d, angulo: %d, movimento: %d",x,y,angulo,movimento);
			break;
	}
}

bool Map::loadMap(std::string file)
{
	std::string linha; // temp
	//this->addGuard(1, 1, 1 , 90, true, 3);
	//return true;
	
	Console::printf("Comecar a ler o ficheiro do mapa %s",file.c_str());
	
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
		std::vector<int> codigos_mapa(this->tamanho_mapa-1);
		std::vector<int> linha_para_ir(this->tamanho_mapa-1);
		std::getline (ifs, linha);
		Tokenize(linha, codigos_mapa ,sep);
		for(int e=0; e<codigos_mapa.size(); ++e){
			// stuff pro mapa
			//	1000 - texturas
			//	2000 - guardas
			//  3000 - portas
			//  4000 - items
			bool to_go = true;
			if(codigos_mapa[e]>1000 && codigos_mapa[e]<2000){
				// paredes -> enviar para o 
				linha_para_ir.push_back(codigos_mapa[e]);
				to_go = false;
			}else
			if(codigos_mapa[e]>3000 && codigos_mapa[e]<4000){
				// portas
				switch(codigos_mapa[e]){
					case 3001:
						// porta norte-sul
						
						break;
					case 3002:
						// porta oeste-este
						break;	
					case 3003:
						// porta norte-sul chave amarela
						break;
					case 3004:
						// porta oeste-este chave amarela
						break;
					case 3005:
						// porta norte-sul chave vermelha
						break;
					case 3006:
						// porta oeste-este chave vermelha

						break;
					default:
						Console::printf("Nao entendo este codigo de mapa porta: %d",codigos_mapa[e]);
						
				}
				
			}else
			if(codigos_mapa[e]>4000 && codigos_mapa[e]<5000){
				// items
				switch(codigos_mapa[e]){
					case 4001:
						// vida 15
						break;
					case 4002:
						// vida 25
						break;	
					case 4003:
						// vida 50
						break;
					case 4004:
						// gun 1
						break;
					case 4005:
						// gun 2
						break;
					case 4006:
						// gun 3
						break;
					case 4007:
						// ammo
						
						break;
					case 4008:
						// chave 1
						
						break;
					case 4009:
						// chave 2
						break;
					case 4010:
						// start player
						
						break;
					case 4011:
						// finish map
						
						break;
					default:
						Console::printf("Nao entendo este codigo de mapa item: %d",codigos_mapa[e]);
						break;
				}
			}else
				if(codigos_mapa[e]>2000 && codigos_mapa[e]<3000){
					// guardas
					// addGuard(int x, int y, int type, int direction, bool movimento)
					switch(codigos_mapa[e]){
						// guarda 1
						case 2001:
							// Norte / parado
							this->addGuard(i, e, 1, 1, false );
							break;
						case 2002:
							// Sul / parado
							this->addGuard(i, e, 1, 2, false );
							break;
						case 2003:
							// Este / parado
							this->addGuard(i, e, 1, 3, false );
							break;
						case 2004:
							// Oeste / parado
							this->addGuard(i, e, 1, 4, false );
							break;
						case 2005:
							// Norte / mover-se
							this->addGuard(i, e, 1, 1, true );
							break;
						case 2006:
							// Sul / mover-se
							this->addGuard(i, e, 1, 2, true );
							break;
						case 2007:
							// Este / mover-se
							this->addGuard(i, e, 1, 3, true );
							break;
						case 2008:
							// Oeste / mover-se
							this->addGuard(i, e, 1, 4, true );
							break;
							
						// guarda 2
						case 2009:
							// Norte / parado
							this->addGuard(i, e, 2, 1, false );
							break;
						case 2010:
							// Sul / parado
							this->addGuard(i, e, 2, 2, false );
							break;
						case 2011:
							// Este / parado
							this->addGuard(i, e, 2, 3, false );
							break;
						case 2012:
							// Oeste / parado
							this->addGuard(i, e, 2, 4, false );
							break;
						case 2013:
							// Norte / mover-se
							this->addGuard(i, e, 2, 1, true );
							break;
						case 2014:
							// Sul / mover-se
							this->addGuard(i, e, 2, 2, true );
							break;
						case 2015:
							// Este / mover-se
							this->addGuard(i, e, 2, 3, true );
							break;
						case 2016:
							// Oeste / mover-se
							this->addGuard(i, e, 2, 4, true );
							break;	
							
						// guarda 3
						case 2017:
							// Norte / parado
							this->addGuard(i, e, 3, 1, false );
							break;
						case 2018:
							// Sul / parado
							this->addGuard(i, e, 3, 2, false );
							break;
						case 2019:
							// Este / parado
							this->addGuard(i, e, 3, 3, false );
							break;
						case 2020:
							// Oeste / parado
							this->addGuard(i, e, 3, 4, false );
							break;
						case 2021:
							// Norte / mover-se
							this->addGuard(i, e, 3, 1, true );
							break;
						case 2022:
							// Sul / mover-se
							this->addGuard(i, e, 3, 2, true );
							break;
						case 2023:
							// Este / mover-se
							this->addGuard(i, e, 3, 3, true );
							break;
						case 2024:
							// Oeste / mover-se
							this->addGuard(i, e, 3, 4, true );
							break;
							
						// guarda 4
						case 2025:
							// Norte / parado
							this->addGuard(i, e, 3, 1, false );
							break;
						case 2026:
							// Sul / parado
							this->addGuard(i, e, 3, 2, false );
							break;
						case 2027:
							// Este / parado
							this->addGuard(i, e, 3, 3, false );
							break;
						case 2028:
							// Oeste / parado
							this->addGuard(i, e, 3, 4, false );
							break;
						case 2029:
							// Norte / mover-se
							this->addGuard(i, e, 3, 1, true );
							break;
						case 2030:
							// Sul / mover-se
							this->addGuard(i, e, 3, 2, true );
							break;
						case 2031:
							// Este / mover-se
							this->addGuard(i, e, 3, 3, true );
							break;
						case 2032:
							// Oeste / mover-se
							this->addGuard(i, e, 3, 4, true );
							break;	
							
						// direccoes dos guardas -> adicionar no mapa
						case 2033:
							to_go=false;
							linha_para_ir.push_back(2033);
							break;
						case 2034:
							to_go=false;
							linha_para_ir.push_back(2034);
							break;
						case 2035:
							to_go=false;
							linha_para_ir.push_back(2035);
							break;
						case 2036:
							to_go=false;
							linha_para_ir.push_back(2036);
							break;
						case 2037:
							to_go=false;
							linha_para_ir.push_back(2037);
							break;
						case 2038:
							to_go=false;
							linha_para_ir.push_back(2038);
							break;
						case 2039:
							to_go=false;
							linha_para_ir.push_back(2039);
							break;
						case 2040:
							to_go=false;
							linha_para_ir.push_back(2040);
							break;
							
						default:
							Console::printf("Nao entendo este codigo de mapa guarda: %d",codigos_mapa[e]);
							break;
							
					}
										
				}else if(codigos_mapa[e]==0){
					// 0 -> sem nada
					linha_para_ir.push_back(codigos_mapa[e]);	
					to_go = false;
				}
				else{
					Console::printf("Nao entendo este codigo de mapa: %d",codigos_mapa[e]);
				}
			// tem de ser 0 pelo menos
			if(to_go)
				linha_para_ir.push_back(0);
		}
		this->map.push_back(linha_para_ir);
		
	}
	// enter a separar, floorcodes a seguir
	std::getline (ifs, linha);
    for(int i=0; i<this->tamanho_mapa; ++i)
	{
		std::vector<int> codigos_floor(this->tamanho_mapa-1);
		std::getline (ifs, linha);
		Tokenize(linha, codigos_floor ,sep);
		this->floormap.push_back(codigos_floor);
		std::cout << "floor " << i << " " ;
	}
	
	// we're done
	/*for(int i = 0; i <this->map.size(); i++){
		std::cout << i << ": " ;
		for(int e=0; e<this->map[i].size(); e++){
			std::cout << this->map[i][e] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "floor" << std::endl;
	for(int i = 0; i <this->floormap.size(); i++){
		std::cout << i << ": " ;
		for(int e=0; e<this->floormap[i].size(); e++){
			std::cout << this->floormap[i][e] << " ";
		}
		std::cout << std::endl;
	}*/
	Console::addLine("Mapa OK!");
	return true;
}