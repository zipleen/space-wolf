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
	// nao eh necessario isto...
	//this->map = std::vector<std::vector<int> >(64,std::vector<int>(64,0));
	//this->floormap = std::vector<std::vector<int> >(64,std::vector<int>(64,0));
	this->guardas.clear();
	this->items.clear();
	this->portas.clear();
	this->desenharTudo = true;
	this->cube_size = 5.0f;
	this->tex_porta = 1006;
	this->tex_porta_lado = 1009;
	this->tex_porta_chave1 = 1007;
	this->tex_porta_lado_chave1 = 1010;
	this->tex_porta_chave2 = 1008;
	this->tex_porta_lado_chave2 = 1011;
}

/* desenhar */

void Map::setMaterial()
{
	GLfloat mat_specular[]= { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat mat_shininess = 104;
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	// definir os outros par‚metros estaticamente
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess); 
}

void Map::desenhaPoligono(GLfloat a[], GLfloat b[], GLfloat c[], GLfloat  d[], GLfloat normal[],GLfloat tx,GLfloat ty)
{
  glBegin(GL_POLYGON);
    glNormal3fv(normal);
    //glTexCoord2f(tx+0,ty+0);
	glTexCoord2f(1,1);
    glVertex3fv(a);
	glTexCoord2f(0,1);
    //glTexCoord2f(tx+0,ty+0.25);
    glVertex3fv(b);
	glTexCoord2f(0,0);
    //glTexCoord2f(tx+0.25,ty+0.25);
    glVertex3fv(c);
	glTexCoord2f(1,0);
    //glTexCoord2f(tx+0.25,ty+0);
    glVertex3fv(d);
  glEnd();
}

void Map::glDrawCube(const Texture2D* tex)					// Draw A Cube
{
	tex->bind();
	glBegin(GL_QUADS);			// Start Drawing Quads
		// Front Face
		glNormal3f( 0.0f, 0.0f, 1.0f);		// Normal Facing Forward
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-this->cube_size, -this->cube_size,  this->cube_size);	// Bottom Left Of The Texture and Quad
		glTexCoord2f(1.0f, 0.0f); glVertex3f( this->cube_size, -this->cube_size,  this->cube_size);	// Bottom Right Of The Texture and Quad
		glTexCoord2f(1.0f, 1.0f); glVertex3f( this->cube_size,  this->cube_size,  this->cube_size);	//*2 Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-this->cube_size,  this->cube_size,  this->cube_size);	//*2 Top Left Of The Texture and Quad
		// Back Face
		glNormal3f( 0.0f, 0.0f,-1.0f);		// Normal Facing Away
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-this->cube_size, -this->cube_size, -this->cube_size);	// Bottom Right Of The Texture and Quad
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-this->cube_size,  this->cube_size, -this->cube_size);	//*2 Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, 1.0f); glVertex3f( this->cube_size,  this->cube_size, -this->cube_size);	//*2 Top Left Of The Texture and Quad
		glTexCoord2f(0.0f, 0.0f); glVertex3f( this->cube_size, -this->cube_size, -this->cube_size);	// Bottom Left Of The Texture and Quad
		// Top Face
		glNormal3f( 0.0f, 1.0f, 0.0f);		// Normal Facing Up
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-this->cube_size,  this->cube_size, -this->cube_size);	//*2 Top Left Of The Texture and Quad
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-this->cube_size,  this->cube_size,  this->cube_size);	//*2 Bottom Left Of The Texture and Quad
		glTexCoord2f(1.0f, 0.0f); glVertex3f( this->cube_size,  this->cube_size,  this->cube_size);	//*2 Bottom Right Of The Texture and Quad
		glTexCoord2f(1.0f, 1.0f); glVertex3f( this->cube_size,  this->cube_size, -this->cube_size);	//*2 Top Right Of The Texture and Quad
		// Bottom Face
		glNormal3f( 0.0f,-1.0f, 0.0f);		// Normal Facing Down
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-this->cube_size, -this->cube_size, -this->cube_size);	// Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, 1.0f); glVertex3f( this->cube_size, -this->cube_size, -this->cube_size);	// Top Left Of The Texture and Quad
		glTexCoord2f(0.0f, 0.0f); glVertex3f( this->cube_size, -this->cube_size,  this->cube_size);	// Bottom Left Of The Texture and Quad
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-this->cube_size, -this->cube_size,  this->cube_size);	// Bottom Right Of The Texture and Quad
		// Right face
		glNormal3f( 1.0f, 0.0f, 0.0f);		// Normal Facing Right
		glTexCoord2f(1.0f, 0.0f); glVertex3f( this->cube_size, -this->cube_size, -this->cube_size);	// Bottom Right Of The Texture and Quad
		glTexCoord2f(1.0f, 1.0f); glVertex3f( this->cube_size,  this->cube_size, -this->cube_size);	//*2 Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, 1.0f); glVertex3f( this->cube_size,  this->cube_size,  this->cube_size);	//*2 Top Left Of The Texture and Quad
		glTexCoord2f(0.0f, 0.0f); glVertex3f( this->cube_size, -this->cube_size,  this->cube_size);	// Bottom Left Of The Texture and Quad
		// Left Face
		glNormal3f(-1.0f, 0.0f, 0.0f);		// Normal Facing Left
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-this->cube_size, -this->cube_size, -this->cube_size);	// Bottom Left Of The Texture and Quad
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-this->cube_size, -this->cube_size,  this->cube_size);	// Bottom Right Of The Texture and Quad
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-this->cube_size,  this->cube_size,  this->cube_size);	//*2 Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-this->cube_size,  this->cube_size, -this->cube_size);	//*2 Top Left Of The Texture and Quad
	glEnd();					// Done Drawing Quads
}

void Map::desenhaCubo(const Texture2D* tex)
{
  GLfloat vertices[][3] = { {-this->cube_size,-this->cube_size,-this->cube_size}, 
                            {this->cube_size,-this->cube_size,-this->cube_size}, 
                            {this->cube_size,this->cube_size,-this->cube_size}, 
                            {-this->cube_size,this->cube_size,-this->cube_size}, 
                            {-this->cube_size,-this->cube_size,this->cube_size},  
                            {this->cube_size,-this->cube_size,this->cube_size}, 
                            {this->cube_size,this->cube_size,this->cube_size}, 
                            {-this->cube_size,this->cube_size,this->cube_size}};
  GLfloat normais[][3] = {  {0,0,-1}, 
                            {0,1,0}, 
                            {-1,0,0}, 
                            {1,0,0}, 
                            {0,0,1},  
                            {0,-1,0}};

  GLfloat tx,ty;
  tx=0,ty=0;
  
  tex->bind();

  desenhaPoligono(vertices[1],vertices[0],vertices[3],vertices[2],normais[0],tx,ty);
  desenhaPoligono(vertices[2],vertices[3],vertices[7],vertices[6],normais[1],tx,ty);
  desenhaPoligono(vertices[3],vertices[0],vertices[4],vertices[7],normais[2],tx,ty);
  desenhaPoligono(vertices[6],vertices[5],vertices[1],vertices[2],normais[3],tx,ty);
  desenhaPoligono(vertices[4],vertices[5],vertices[6],vertices[7],normais[4],tx,ty);
  desenhaPoligono(vertices[5],vertices[4],vertices[0],vertices[1],normais[5],tx,ty);
  glBindTexture(GL_TEXTURE_2D, NULL);
}

void Map::desenhaTecto()
{
	// esta coisa parece que esta a desenhar para baixo... portanto serve para o tecto
	GLfloat i,j;
	//textura do chao, bind it
	TexMap::iterator tecto;
	tecto = this->map_textures.find(this->tex_tecto);
	tecto->second->bind();
	
	//glPushMatrix();
	glColor3f(0.5f,0.5f,0.5f);
	glTranslatef(0,this->cube_size,0);
	for(i=-this->cube_size;i<=this->tamanho_mapa*this->cube_size*2;i+=this->cube_size)
		for(j=-this->cube_size;j<=this->tamanho_mapa*this->cube_size*2;j+=this->cube_size)
		{
		  glBegin(GL_POLYGON);
			glNormal3f(0,1,0);
			glTexCoord2f(1,1);
			glVertex3f(i+this->cube_size,0,j+this->cube_size);
			glTexCoord2f(0,1);
			glVertex3f(i,0,j+this->cube_size);
			glTexCoord2f(0,0);
			glVertex3f(i,0,j);
			glTexCoord2f(1,0);
			glVertex3f(i+this->cube_size,0,j);
			glNormal3f(0,1,0);
			glEnd();
		}
	//glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, NULL);
}

void Map::desenhaChao()
{
	GLfloat i,j;
	//textura do chao, bind it
	TexMap::iterator chao;
	chao = this->map_textures.find(this->tex_chao);
	chao->second->bind();
	
	//glPushMatrix();
	glColor3f(0.5f,0.5f,0.5f);
	glTranslatef(0,-this->cube_size,0);
	for(i=-this->cube_size;i<=this->tamanho_mapa*this->cube_size*2;i+=this->cube_size)
		for(j=-this->cube_size;j<=this->tamanho_mapa*this->cube_size*2;j+=this->cube_size)
		{
		  glBegin(GL_POLYGON);
			glNormal3f(0,1,0);
			glTexCoord2f(1,0);
			glVertex3f(i+this->cube_size,0,j);
			glTexCoord2f(0,0);
			glVertex3f(i,0,j);
			glTexCoord2f(0,1);
			glVertex3f(i,0,j+this->cube_size);
			glTexCoord2f(1,1);
			glVertex3f(i+this->cube_size,0,j+this->cube_size);
			glEnd();
		}
	//glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, NULL);
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
	needed.insert(this->tex_chao);
	needed.insert(this->tex_tecto);
	needed.insert(this->tex_porta);
	needed.insert(this->tex_porta_lado);
	needed.insert(this->tex_porta_chave1);
	needed.insert(this->tex_porta_lado_chave1);
	needed.insert(this->tex_porta_chave2);
	needed.insert(this->tex_porta_lado_chave2);
	
	while(!ifs.eof())
	{
		std::vector<std::string> t;
		int num;
		// ler linha
		std::getline(ifs, line);
		if(line.size()>1){
			// partir pq o primeiro eh o numero e segundo eh a path
			Tokenize(line, t, sep);
			num = StrtoInt(t[0]);
			// iterador para encontrar no needed
			set<int>::iterator it;
			it=needed.find(num);
			if(it!=needed.end()){
				Console::addLine("Loading texture "+t[0]+" in "+t[1]);
				Texture2D *tex = texMgr->load (t[1]);
				this->map_textures.insert (TexMap::value_type (num, tex));
			}
		}
	}
	
	// buscar texturas de portas
	this->textura_porta = this->map_textures.find(this->tex_porta)->second;
	this->textura_porta_lado = this->map_textures.find (this->tex_porta_lado)->second;
	this->textura_porta_chave1 = this->map_textures.find (this->tex_porta_chave1)->second;
	this->textura_porta_lado_chave1 = this->map_textures.find (this->tex_porta_lado_chave1)->second;
	this->textura_porta_chave2 = this->map_textures.find(this->tex_porta_chave2)->second;
	this->textura_porta_lado_chave2 = this->map_textures.find (this->tex_porta_lado_chave2)->second;
	
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
			// shortcut.. nao devia fazer isto mas pronto
			// vou buscar o tipo de porta e passo-lhe a textura consoante o tipo de porta
			// nao eh assim mt mau, podiamos depois adicionar mais uma linha no ficheiro de mapas
			// e os mapas passavam a ter as texturas de portas que queriam
			switch(this->portas[i]->tipo_porta){
				case 0:
					this->portas[i]->draw(this->textura_porta, this->textura_porta_lado);
					break;
				case 1:
					this->portas[i]->draw(this->textura_porta_chave1, this->textura_porta_lado_chave1);
					break;
				case 2:	
					this->portas[i]->draw(this->textura_porta_chave2, this->textura_porta_lado_chave2);
					break;
			}
			
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
	TexMap::iterator tex;
	int previous_tex = 0;

	if(this->desenharTudo)
	{
		glPushMatrix();
			this->desenhaChao();
		glPopMatrix();
		
		glPushMatrix();
			this->desenhaTecto();
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(0,0,-(this->tamanho_mapa*this->cube_size*2)+this->cube_size+this->cube_size);
		// desenhar as paredes
		for(int i=0;i<this->map.size();i++)
		{
			for(int e=0;e<this->map[i].size();e++)
			{
				if(this->map[i][e]>1000 && this->map[i][e]<2000)
				{
					if(previous_tex!=this->map[i][e]){
						previous_tex = this->map[i][e];
						tex = this->map_textures.find(this->map[i][e]);
					}
					glPushMatrix();
						glTranslatef(i*this->cube_size*2,0,e*this->cube_size*2);
						this->glDrawCube(tex->second);
					glPopMatrix();
				}
			}
		}
		glPopMatrix();
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
	TexMap::iterator tex1 =  this->map_textures.find(this->tex_porta);
	TexMap::iterator tex2 =  this->map_textures.find(this->tex_porta_lado);
	
	Porta *s = new Porta(x,y,type,direction,this->cube_size);
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
			Soldado *s = new Soldado(x*this->cube_size*2,y*this->cube_size*2,angulo, movimento);
			this->guardas.push_back(s);
			Console::printf("Adicionado guarda facil em %d,%d, angulo: %f, movimento: %b",x,y,angulo,movimento);
			break;
	}
}

bool Map::loadMap(std::string file, Player *player)
{
	std::string linha; // temp
	
	Console::printf("Comecar a ler o ficheiro do mapa %s",file.c_str());
	
	std::ifstream ifs (file.c_str(), std::ios::in);
	if (ifs.fail ())
		return false;
	
	// ler tamanho
	ifs >> this->tamanho_mapa;
	
	// ler textura do tecto
	ifs >> this->tex_tecto;
	
	// ler textura do chao
	ifs >> this->tex_chao;
	
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
						this->addPorta(i,e,0, 0);
						break;
					case 3002:
						// porta oeste-este
						this->addPorta(i,e,0, 1);
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
						/*player->x = i*this->cube_size;
						player->y = 2;
						player->z = e*this->cube_size;*/
						player->x = 0;
						player->y = 2;
						player->z = 0;
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