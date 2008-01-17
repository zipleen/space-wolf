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
	this->objectos.clear();
	this->desenharTudo = true;
	this->cube_size = 5.0f;
	this->tex_porta = 1006;
	this->tex_porta_lado = 1009;
	this->tex_porta_chave1 = 1007;
	this->tex_porta_lado_chave1 = 1010;
	this->tex_porta_chave2 = 1008;
	this->tex_porta_lado_chave2 = 1011;
	this->usecalllist = false;
	Fisica::clip_mode = false;
	Fisica::cube_size = this->cube_size;
}

/* processar eventos */
void Map::processTiros(Player *p)
{
	if(p->disparar){
		// temos de processar o tiro do player, basicamente calcular o proximo quadrado ate encontrar qq coisa, 
		//  uma parede, um guarda, ou o fim do mapa
		GLfloat nx,ny;
		int cx, cy;
		float a_seguir = this->cube_size;
		bool acertou = false;
		for(;;){
			// primeiro vamos "uma casa" para a frente
			ny=p->x+sin(-RAD(p->angulo))*a_seguir;
			nx=p->z+cos(RAD(p->angulo))*a_seguir;
			cx = (int)(((nx*-1)/(this->cube_size*2.0f))+0.5);
			cy = (int)(((ny*-1)/(this->cube_size*2.0f))+0.5);
			//std::cout << "testar: nx: " << nx << " ny: " << ny << " cx: " << cx << " cy: " << cy << std::endl;
			
			if(cx>this->tamanho_mapa || cy>this->tamanho_mapa || cx<0 || cy<0)
				break; // nao acertaste em nada
			
			// vamos procurar os guardas todos
			for(int i=0;i<this->guardas.size();i++){
				if(!this->guardas[i]->morto){
					int guarda_x = (int)(((this->guardas[i]->z)/(this->cube_size*2.0f))+0.5);
					int guarda_y = (int)(((this->guardas[i]->x)/(this->cube_size*2.0f))+0.5);
					if(guarda_x == cx && guarda_y == cy){
						this->guardas[i]->takeHealth(p->z, p->x);
						acertou=true;
						break;
					}
				}
			}
			if(acertou)
				break;
			/*
			// mas se ja testamos os guardas todos, para q queremos testar as paredes?!
			if(this->map[cx][cy]>1000 && this->map[cx][cy]<2000)
				break; // bateste na parede
			*/
			a_seguir+=this->cube_size;
		}
		p->disparar = false;
	}
	
	// agora temos de processar os tiros dos guardas
}


/* portas */
void Map::openDoor(Player *p)
{
	// so ha um player, vamos buscar os dados la, precisamos de saber onde ele ta
	// como a porta normalmente eh "ah frente" podemos fazer a conta do player avancando "uma casa" ah frente e vendo qual casa eh essa 
	int p_z = (int)((((p->z+cos(RAD(p->angulo))*this->cube_size)*-1)/(this->cube_size*2.0f))+0.5);
	int p_x = (int)((((p->x+sin(-RAD(p->angulo))*this->cube_size)*-1)/(this->cube_size*2.0f))+0.5);
	/*Console::printf("tentando abrir a porta %d %d %f %f",p_x, p_z,
					((((p->z+cos(RAD(p->angulo))*this->cube_size)*-1)/(this->cube_size*2.0f))+0.5),
					((((p->x+sin(-RAD(p->angulo))*this->cube_size)*-1)/(this->cube_size*2.0f))+0.5)
	);
	Console::printf("tou em %f %f", ((((p->z)*-1)/(this->cube_size*2.0f))+0.5),
					((((p->x)*-1)/(this->cube_size*2.0f))+0.5));*/
	for(int i=0; i<this->portas.size(); i++){
		if(this->portas[i]->x == p_x && this->portas[i]->y == p_z)
			this->portas[i]->tryToOpenDoor(p->chave_amarela, p->chave_vermelha);

	}
}
void Map::openDoor(Guard *p)
{
	// so ha um player, vamos buscar os dados la, precisamos de saber onde ele ta
	// como a porta normalmente eh "ah frente" podemos fazer a conta do player avancando "uma casa" ah frente e vendo qual casa eh essa 
	int p_z = (int)(((((p->z)+cos(RAD(p->angulo))*this->cube_size)*-1)/(this->cube_size*2.0f))+0.5);
	int p_x = (int)(((((p->x*-1)+sin(-RAD(p->angulo))*this->cube_size)*-1)/(this->cube_size*2.0f))+0.5);
	/*Console::printf("tentando abrir a porta %d %d %f %f",p_x, p_z,
	 ((((p->z+cos(RAD(p->angulo))*this->cube_size)*-1)/(this->cube_size*2.0f))+0.5),
	 ((((p->x+sin(-RAD(p->angulo))*this->cube_size)*-1)/(this->cube_size*2.0f))+0.5)
	 );
	 Console::printf("tou em %f %f", ((((p->z)*-1)/(this->cube_size*2.0f))+0.5),
	 ((((p->x)*-1)/(this->cube_size*2.0f))+0.5));*/
	for(int i=0; i<this->portas.size(); i++){
		if(this->portas[i]->x == p_x && this->portas[i]->y == p_z*-1)
			this->portas[i]->tryToOpenDoor(true, true);
		
	}
}
void Map::processItems(Player *p)
{
	int p_x = (int)(((p->z*-1)/(this->cube_size*2.0f))+0.5);
	int p_y = (int)(((p->x*-1)/(this->cube_size*2.0f))+0.5);
	/*std::vector<Items*>::iterator cii;
	for(cii=this->items.begin(); cii!=this->items.end(); cii++)
	{
		Items *t = *cii;
		if(t->mapa_x == p_x && t->mapa_y == p_y){
			if(t->consume(p)){
				// eliminar no vector
				//this->items.erase(cii);
			}
		}
	}*/
	for(int i=0; i<this->items.size(); i++)
	{
		if(this->items[i]->mapa_x == p_x && this->items[i]->mapa_y == p_y){
			this->items[i]->consume(p);
			// era suposto depois eliminar isto do vector...
		}
	}
	
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
				Texture2D *tex = this->texMgr->load (t[1]);
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
	
	Console::addLine("Generating CallLists");
	this->createCallListMap();
	Console::addLine("Generating CallLists completed");
	return true;
}


void Map::updateAnimations(double dt,double dt_cur)
{
	this->updateGuardAnimation(dt);
	this->updateItemsAnimation(dt,dt_cur);
	this->updateDoorAnimation(dt,dt_cur);
}

void Map::updateGuardAnimation(double dt)
{
	for(int i=0;i<(signed)this->guardas.size();i++)
	{
		this->guardas[i]->animate(dt);
		if(!this->guardas[i]->alerta && this->guardas[i]->em_movimento){
			// primeiro vamos po-los a abrirem portas coitados :P
			this->openDoor(this->guardas[i]);
			// se nao tao em alerta e tao em movimento vamos ver se estao em nova posicao para nova direccao
			int orig_x = (int)(((this->guardas[i]->z)/(this->cube_size*2.0f))+0.5);
			int orig_y = (int)(((this->guardas[i]->x)/(this->cube_size*2.0f))+0.5);
			if(orig_x>0 && orig_x<=this->tamanho_mapa && orig_y>0 && orig_y<=this->tamanho_mapa && this->map[orig_x][orig_y]>=2033 && this->map[orig_x][orig_y]<=2040){
				this->guardas[i]->movimento_contar_vezes++;
				if(this->guardas[i]->movimento_contar_vezes>50)
				{
					this->guardas[i]->movimento_contar_vezes=0;
					switch(this->map[orig_x][orig_y]){
						case 2033:
							// direita, este
							this->guardas[i]->setAngulo(90);
							break;
						case 2034:
							// esquerda, oeste
							this->guardas[i]->setAngulo(270);
							break;
						case 2036:
							// cima norte
							this->guardas[i]->setAngulo(0);
							break;	
						case 2035:
							// baixo, sul
							this->guardas[i]->setAngulo(180);
							break;	
						case 2037:
							this->guardas[i]->setAngulo(135);
							break;	
						case 2038:
							this->guardas[i]->setAngulo(225);
							break;	
						case 2039:
							this->guardas[i]->setAngulo(45);
							break;	
						case 2040:
							this->guardas[i]->setAngulo(315);
							break;	
					}
				}
			}
		}
	}
}

void Map::updateDoorAnimation(double dt,double dt_cur)
{
	for(int i=0;i<(signed)this->portas.size();i++)
	{
		this->portas[i]->animate(dt,dt_cur);
	}
}

void Map::updateItemsAnimation(double dt,double dt_cur)
{
	for(int i=0;i<(signed)this->items.size();i++)
	{
		this->items[i]->animate(dt,dt_cur);
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
void Map::drawObjectos()
{
	if(this->desenharTudo)
	{
		for(int i=0;i<this->objectos.size();i++)
		{
			this->objectos[i]->draw();
		}
	}else{
		// codigo optimizado para nao desenhar tudo...
	}
	
}

void Map::drawAllMap()
{
	TexMap::iterator tex;
	int previous_tex = 0;

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
					glTranslatef(e*this->cube_size*2,0,i*this->cube_size*2);
					this->glDrawCube(tex->second);
				glPopMatrix();
			}
		}
	}
}

void Map::createCallListMap()
{
	// chao
	this->calllists[0]=glGenLists(4);
	glNewList(this->calllists[0], GL_COMPILE);
		//glPushAttrib(GL_COLOR_BUFFER_BIT | GL_CURRENT_BIT | GL_ENABLE_BIT );
		  this->desenhaChao();
		//glPopAttrib();
	glEndList();

	// tecto
	this->calllists[1]=this->calllists[0]+1;
	glNewList(this->calllists[1], GL_COMPILE);
		//glPushAttrib(GL_COLOR_BUFFER_BIT | GL_CURRENT_BIT | GL_ENABLE_BIT );
		  this->desenhaTecto();
		//glPopAttrib();
	glEndList();

	// mapa
	this->calllists[2]=this->calllists[1]+1;
	glNewList(this->calllists[2], GL_COMPILE);
		//glPushAttrib(GL_COLOR_BUFFER_BIT | GL_CURRENT_BIT | GL_ENABLE_BIT );
			this->drawAllMap();
		//glPopAttrib();
	glEndList();
	
	// objectos
	this->calllists[3]=this->calllists[2]+1;
	glNewList(this->calllists[3], GL_COMPILE);
		//glPushAttrib(GL_COLOR_BUFFER_BIT | GL_CURRENT_BIT | GL_ENABLE_BIT );
			this->drawObjectos();
		//glPopAttrib();
	glEndList();	
}

void Map::drawMap()
{

	if(this->desenharTudo)
	{
		// chao
		glPushMatrix();
			if(this->usecalllist)
				glCallList(this->calllists[0]);
			else
				this->desenhaChao();
		glPopMatrix();
		
		// tecto
		glPushMatrix();
			if(this->usecalllist)
				glCallList(this->calllists[1]);
			else
				this->desenhaTecto();
		glPopMatrix();
		
		// desenhar as paredes
		glPushMatrix();
			if(this->usecalllist)
				glCallList(this->calllists[2]);
			else
				this->drawAllMap();
		glPopMatrix();
		
		// desenhar os objectos
		glPushMatrix();
			if(this->usecalllist)
				glCallList(this->calllists[3]);
			else
				this->drawObjectos();
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

void Map::addObject(int x, int y, int code, std::vector<std::vector <bool> > &fisica){
	// isto poderia nao passar a vida a abrir e fechar o ficheiro de texto mas depois tinha de ter tudo em memoria...
	// mais rapido assim
	std::string line;
	boost::char_separator<char> sep(",");
	Console::addLine("Loading object...");
	std::ifstream ifs ("data/models/objects/objects.def", std::ios::in);
	if (ifs.fail ()){
		Console::addLine("Erro a ler o ficheiro de objectos");
		return;
	}
	
	while(!ifs.eof())
	{
		int num;
		std::vector<std::string> t;
		// ler linha
		std::getline(ifs, line);
		if(line.size()>1){
			// t[0] -> item number
			// t[1] -> md3 path
			// t[2] -> image path
			// t[3] -> mesh name, se vazio o image path eh o _barrel, se image path for vazio nao tem _barrel
			// t[4] -> y para por o objecto
			// t[5] -> impede ou nao (bool)
			// t[6] -> nome do objecto
			Tokenize(line, t, sep);
			num = StrtoInt(t[0]);
			if(num==code){
				float y_to_go;
				bool impede;
				y_to_go = StrtoFloat(t[4]);
				if(t[5][0]=='1')
					impede=true;
				else 
					impede=false;
				fisica[x][y]=impede;
				Shared_render_objects::Md3ModelPtr model_object = Shared_render_objects::find_or_insert(num, t[1], t[2], t[3]);
				Objectos_decorativos *o= new Objectos_decorativos(model_object,y*this->cube_size*2,y_to_go-this->cube_size,x*this->cube_size*2,code,impede);
				this->objectos.push_back(o);
				Console::printf("Loaded object %s %d at %d %d",t[6].c_str(),code,x,y);
				return;
			}
		}
	}
	Console::printf("Nao encontrei o objecto no ficheiro de definicoes para o objecto estatico numero %d",code);

}

void Map::addItems(int x, int y, int type)
{
	Items_Vida *v;
	Items_Armas *a;
	Items_Ammo *am;
	Items_Chave *c;
	Items_Armor *aa;
	
	switch(type){
		case 1:
			// vida 15
			v= new Items_Vida(x*this->cube_size*2,y*this->cube_size*2,15,x,y);
			this->items.push_back(v);
			break;
		case 2:
			// vida 25
			v = new Items_Vida(x*this->cube_size*2,y*this->cube_size*2,25,x,y);
			this->items.push_back(v);
			break;
		case 3:
			// vida 50
			v = new Items_Vida(x*this->cube_size*2,y*this->cube_size*2,50,x,y);
			this->items.push_back(v);
			break;
		case 4:
			// arma 2
			a = new Items_Armas(x*this->cube_size*2,y*this->cube_size*2,2,x,y);
			this->items.push_back(a);
			break;
		case 5:
			// arma 3
			a = new Items_Armas(x*this->cube_size*2,y*this->cube_size*2,3,x,y);
			this->items.push_back(a);
			break;
		case 6:
			// arma 4
			a = new Items_Armas(x*this->cube_size*2,y*this->cube_size*2,4,x,y);
			this->items.push_back(a);
			break;
		case 7:
			// ammo, default 8 balas?! vamos ser generosos, 15
			am = new Items_Ammo(x*this->cube_size*2,y*this->cube_size*2,15,x,y);
			this->items.push_back(am);
			break;
		case 8:
			// chave amarela
			c = new Items_Chave(x*this->cube_size*2,y*this->cube_size*2,1,x,y);
			this->items.push_back(c);
			break;
		case 9:
			// chave vermelha
			c = new Items_Chave(x*this->cube_size*2,y*this->cube_size*2,2,x,y);
			this->items.push_back(c);
			break;
		case 10:
			// armor
			aa = new Items_Armor(x*this->cube_size*2, y*this->cube_size*2,100,x,y);
			this->items.push_back(aa);
			break;
	}

}

void Map::addPorta(int x, int y, int type1, int direction)
{
	// type = 0 , 1 , 2
	// direction = 0 ou 1 (norte ou oeste)
	Porta *s = new Porta(y,x,direction,type1,this->cube_size);
	this->portas.push_back(s);
	Console::printf("Adicionado porta em %d,%d, tipo: %d, direccao: %d",x,y,type1,direction);			
}

void Map::addGuard(int x, int y, int type, int direction, bool movimento)
{
	GLfloat angulo;
	Soldado *s;
	Guard_Medium *s1;
	Guard_Intermedio *s2;
	Guard_Dificil *s3;
	Guard_Robo *s4;
	Guard_Boss1 *b1;
	// 0 -> E
	// 90 -> N
	// 180 -> O
	// 270 -> S
	
	// 1 - N - 90 - 270
	// 2 - S - 270 - 90
	// 3 - E - 0 - 180
	// 4 - O - 180 - 0
	switch(direction)
	{
		case 1:
			angulo = 180;
			break;
		case 2:
			angulo = 0;
			break;
		case 3:
			angulo = 90;
			break;
		case 4:
			angulo = 270;
			break;
		default:
			angulo = 0;
			break;
	}
	
	switch(type){
		case 1: // soldados mais faceis
			s = new Soldado(x*this->cube_size*2,y*this->cube_size*2,movimento,angulo);
			this->guardas.push_back(s);
			Console::printf("Adicionado guarda facil em %d,%d, mapa: %f %f, angulo: %f, movimento: %d",x,y,y*this->cube_size*2,x*this->cube_size*2,angulo,movimento);
			break;
		case 2: // guarda medio
			s1 = new Guard_Medium(x*this->cube_size*2,y*this->cube_size*2,movimento,angulo);
			this->guardas.push_back(s1);
			Console::printf("Adicionado guarda medio em %d,%d, mapa: %f %f, angulo: %f, movimento: %d",x,y,y*this->cube_size*2,x*this->cube_size*2,angulo,movimento);
			break;
		case 3: // guarda intermedio
			s2 = new Guard_Intermedio(x*this->cube_size*2,y*this->cube_size*2,movimento,angulo);
			this->guardas.push_back(s2);
			Console::printf("Adicionado guarda intermedio em %d,%d, mapa: %f %f, angulo: %f, movimento: %d",x,y,y*this->cube_size*2,x*this->cube_size*2,angulo,movimento);
			break;
		case 4: // guarda dificil
			s3 = new Guard_Dificil(x*this->cube_size*2,y*this->cube_size*2,movimento,angulo);
			this->guardas.push_back(s3);
			Console::printf("Adicionado guarda dificil em %d,%d, mapa: %f %f, angulo: %f, movimento: %d",x,y,y*this->cube_size*2,x*this->cube_size*2,angulo,movimento);
			break;
		case 5: // guarda robo
			s4 = new Guard_Robo(x*this->cube_size*2,y*this->cube_size*2,movimento,angulo);
			this->guardas.push_back(s4);
			Console::printf("Adicionado boss1 em %d,%d, mapa: %f %f, angulo: %f, movimento: %d",x,y,y*this->cube_size*2,x*this->cube_size*2,angulo,movimento);
			break;
		case 6: // guarda robo
			b1 = new Guard_Boss1(x*this->cube_size*2,y*this->cube_size*2,movimento,angulo);
			this->guardas.push_back(b1);
			Console::printf("Adicionado boss1 em %d,%d, mapa: %f %f, angulo: %f, movimento: %d",x,y,y*this->cube_size*2,x*this->cube_size*2,angulo,movimento);
			break;
			
	}
}

bool Map::loadMap(std::string file, Player *player)
{
	int i,e;
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
	
	// portas para a fisica, vamos por tudo a 0, as portas tem de falar ah fisica para actualizar o seu estado
	std::vector<std::vector <bool> > to_fisica_portas(this->tamanho_mapa,this->tamanho_mapa);
	std::vector<std::vector <bool> > to_fisica_objectos(this->tamanho_mapa,this->tamanho_mapa);
	for(int i=0; i<to_fisica_portas.size(); i++)
		for(int e=0; e<to_fisica_portas.size(); e++){
			to_fisica_portas[i][e] = true;
			to_fisica_objectos[i][e] = false;
		}
	std::getline (ifs, linha);
	boost::char_separator<char> sep(",");
    for(i=0; i<this->tamanho_mapa; i++)
	{
		std::vector<int> codigos_mapa(this->tamanho_mapa-1);
		std::vector<int> linha_para_ir(this->tamanho_mapa-1);
		std::getline (ifs, linha);
		Tokenize(linha, codigos_mapa ,sep);
		linha_para_ir.clear();
		for(e=0; e<codigos_mapa.size(); e++){
			// stuff pro mapa
			//	1000 - texturas
			//	2000 - guardas
			//  3000 - portas
			//  4000 - items
			//  5000 - objectos mapa
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
						this->addPorta(i,e,1, 0);
						break;
					case 3004:
						// porta oeste-este chave amarela
						this->addPorta(i,e,1, 1);
						break;
					case 3005:
						// porta norte-sul chave vermelha
						this->addPorta(i,e,2, 0);
						break;
					case 3006:
						// porta oeste-este chave vermelha
						this->addPorta(i,e,2, 1);
						break;
					default:
						Console::printf("Nao entendo este codigo de mapa porta: %d",codigos_mapa[e]);
						break;
				}
				if(codigos_mapa[e]>=3001 && codigos_mapa[e]<=3006){
					to_fisica_portas[i][e]=false;
				}
				
			}else
			if(codigos_mapa[e]>4000 && codigos_mapa[e]<5000){
				// items
				switch(codigos_mapa[e]){
					case 4001:
						// vida 15
						this->addItems(i,e,1);
						break;
					case 4002:
						// vida 25
						this->addItems(i,e,2);
						break;	
					case 4003:
						// vida 50
						this->addItems(i,e,3);
						break;
					case 4004:
						// gun 2
						this->addItems(i,e,4);
						break;
					case 4005:
						// gun 3
						this->addItems(i,e,5);
						break;
					case 4006:
						// gun 4
						this->addItems(i,e,6);
						break;
					case 4007:
						// ammo
						this->addItems(i,e,7);
						break;
					case 4008:
						// chave 1
						this->addItems(i,e,8);
						break;
					case 4009:
						// chave 2
						this->addItems(i,e,9);
						break;
					case 4010:
						// start player
						player->setInitialPosition(i*this->cube_size*2*-1 , e*this->cube_size*2*-1);
						Console::printf("Jogador vai começar em %f %f. No mapa tem %d %d", player->x, player->z, i, e);
						break;
					case 4011:
						// finish map
						this->fim_mapa_x = i;
						this->fim_mapa_y = e;
						break;
					case 4012:
						this->addItems(i,e,10);
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
						// guarda 1 - soldado
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
							
						// guarda 2 - medium
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
							
						// guarda 3 - intermedio
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
							
						// guarda 4 - dificil
						case 2025:
							// Norte / parado
							this->addGuard(i, e, 4, 1, false );
							break;
						case 2026:
							// Sul / parado
							this->addGuard(i, e, 4, 2, false );
							break;
						case 2027:
							// Este / parado
							this->addGuard(i, e, 4, 3, false );
							break;
						case 2028:
							// Oeste / parado
							this->addGuard(i, e, 4, 4, false );
							break;
						case 2029:
							// Norte / mover-se
							this->addGuard(i, e, 4, 1, true );
							break;
						case 2030:
							// Sul / mover-se
							this->addGuard(i, e, 4, 2, true );
							break;
						case 2031:
							// Este / mover-se
							this->addGuard(i, e, 4, 3, true );
							break;
						case 2032:
							// Oeste / mover-se
							this->addGuard(i, e, 4, 4, true );
							break;	
						
						// guarda 5 - robo
						case 2041:
							// Norte / parado
							this->addGuard(i, e, 5, 1, false );
							break;
						case 2042:
							// Sul / parado
							this->addGuard(i, e, 5, 2, false );
							break;
						case 2043:
							// Este / parado
							this->addGuard(i, e, 5, 3, false );
							break;
						case 2044:
							// Oeste / parado
							this->addGuard(i, e, 5, 4, false );
							break;
						case 2045:
							// Norte / mover-se
							this->addGuard(i, e, 5, 1, true );
							break;
						case 2046:
							// Sul / mover-se
							this->addGuard(i, e, 5, 2, true );
							break;
						case 2047:
							// Este / mover-se
							this->addGuard(i, e, 5, 3, true );
							break;
						case 2048:
							// Oeste / mover-se
							this->addGuard(i, e, 5, 4, true );
							break;	
						case 2049:
							// boss1
							this->addGuard(i, e, 6, 1, false);
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
										
			}else 
				if(codigos_mapa[e]>5000 && codigos_mapa[e]<6000){
					// objectos decorativos para o mapa
					this->addObject(i,e,codigos_mapa[e],to_fisica_objectos);
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
    for(i=0; i<this->tamanho_mapa; ++i)
	{
		std::vector<int> codigos_floor(this->tamanho_mapa-1);
		std::getline (ifs, linha);
		Tokenize(linha, codigos_floor ,sep);
		this->floormap.push_back(codigos_floor);
	}
	
	// we're done
	// necessitamos de fornecer ah fisica as posicoes onde nos nao podemos avancar ate..
	// para isso vamos criar um vector de vector de booleanos que dizem que podemos ir ou nao podemos ir
	// percorremos o mapa. objectos agora sao calculados num vector ah parte e adicionados aqui ao vector que vai pra fisica
	// os guardas and such temos de por os guardas a actualizarem o seu estado para o vector de fisica....
	std::vector<std::vector <bool> > to_fisica(this->tamanho_mapa,this->tamanho_mapa);
	for(int i=0; i<this->map.size(); i++)
	{
		//to_fisica[i] = new std::vector<std::vector<bool> >(this->tamanho_mapa);
		for(e=0; e<this->map[i].size(); e++)
		{
			if(this->map[i][e]>1000 && this->map[i][e]<2000)
				to_fisica[i][e]=true;
			else {
				if(to_fisica_objectos[i][e])
					to_fisica[i][e]=true;
				else
					to_fisica[i][e]=false;
			}
		}
	}
	Fisica::setMap(to_fisica,this->cube_size);
	Fisica::setPortas(to_fisica_portas);
	Console::addLine("Mapa OK!");
	return true;
}