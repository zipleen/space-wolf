/*
 *  porta.cpp
 *  proj
 *
 *  Created by Zipleen on 1/6/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "porta.h"

Porta::Porta(int x, int y, int direction,int tipo_porta,GLfloat cube_size)
{
	this->open=false;
	this->x = x;
	this->y = y;
	this->direction = direction;
	this->tipo_porta = tipo_porta;
	this->cube_size = cube_size;
	this->altura = 0;
	this->porta_a_abrir = false;
	this->porta_a_fechar = false;
	
	this->tempo_comecou_contar = 0;
	this->last_dt = 0;

}

void Porta::tryToOpenDoor(bool chave1, bool chave2)
{
	if(!this->open){
		switch(this->tipo_porta){
			case 0:
				// normal, posso abrir
				this->startOpenDoor();
				break;
				
			case 1:
				// amarela
				if(chave1)
					this->startOpenDoor();
				break;
			
			case 2:
				if(chave2)
					this->startOpenDoor();
				break;
		}
	}
}

/*
 * aqui vai comecar a iniciar a abertura da porta, isto deve definir o tempo de inicio de abrir a porta
 * e definir que esta a ser aberta a porta... penso nisto depois
 */
void Porta::startOpenDoor()
{
	if(!this->porta_a_abrir){
		this->porta_a_abrir=true;
		this->porta_a_fechar = true;
		this->last_dt=0;
		
	}
}

/*
 * Este metodo nao testa se eh possivel o jogado abrir a porta ou nao, abre-a apenas
 */
void Porta::closedoor()
{
	this->open=false;
	Fisica::updatePortas(this->y, this->x, false);
	// codigo para actualizar a porta a "abrir" em opengl?! tempo?!

}

void Porta::opendoor()
{
	this->open=true;
	Fisica::updatePortas(this->y, this->x, true);
	// codigo para actualizar a porta a "abrir" em opengl?! tempo?!

}

void Porta::draw(const Texture2D *textura_porta, const Texture2D *textura_porta_lado)
{
	// desenhar a porta em opengl......
	// uma porta nao eh bem um CUBO como as paredes... é preciso empurra-lo mais para dentro e usa texturas diferentes para os lados....
	// quer dizer temos mais problemas do que apenas os lados, é preciso fazer umas paredes "fakes" ah esquerda e direita...
	
	if (this->direction == 0)
	{
		glPushMatrix();
		glTranslatef(this->x*this->cube_size*2,0,this->y*this->cube_size*2);
		//glScalef(0.1,1,1);
		textura_porta_lado->bind();
		glBegin(GL_QUADS);			// Start Drawing Quads
			// Front Face
			glNormal3f( 0.0f, 0.0f, 1.0f);		// Normal Facing Forward
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-this->cube_size,  this->cube_size,  this->cube_size-0.01);	//*2 Top Left Of The Texture and Quad
			glTexCoord2f(1.0f, 1.0f); glVertex3f( this->cube_size,  this->cube_size,  this->cube_size-0.01);	//*2 Top Right Of The Texture and Quad
			glTexCoord2f(1.0f, 0.0f); glVertex3f( this->cube_size, -this->cube_size,  this->cube_size-0.01);	// Bottom Right Of The Texture and Quad
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-this->cube_size, -this->cube_size,  this->cube_size-0.01);	// Bottom Left Of The Texture and Quad
			// Back Face
			glNormal3f( 0.0f, 0.0f,-1.0f);		// Normal Facing Away
			glTexCoord2f(0.0f, 0.0f); glVertex3f( this->cube_size, -this->cube_size, -this->cube_size+0.01);	// Bottom Left Of The Texture and Quad
			glTexCoord2f(0.0f, 1.0f); glVertex3f( this->cube_size,  this->cube_size, -this->cube_size+0.01);	//*2 Top Left Of The Texture and Quad
			glTexCoord2f(1.0f, 1.0f); glVertex3f(-this->cube_size,  this->cube_size, -this->cube_size+0.01);	//*2 Top Right Of The Texture and Quad
			glTexCoord2f(1.0f, 0.0f); glVertex3f(-this->cube_size, -this->cube_size, -this->cube_size+0.01);	// Bottom Right Of The Texture and Quad
		glEnd();
		textura_porta->bind();
		glTranslatef(0, this->altura, 0);
		glBegin(GL_QUADS);
			// Top Face
			glNormal3f( 0.0f, 1.0f, 0.0f);		// Normal Facing Up
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-this->cube_size/10,  this->cube_size, -this->cube_size);	//*2 Top Left Of The Texture and Quad
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-this->cube_size/10,  this->cube_size,  this->cube_size);	//*2 Bottom Left Of The Texture and Quad
			glTexCoord2f(1.0f, 0.0f); glVertex3f( this->cube_size/10,  this->cube_size,  this->cube_size);	//*2 Bottom Right Of The Texture and Quad
			glTexCoord2f(1.0f, 1.0f); glVertex3f( this->cube_size/10,  this->cube_size, -this->cube_size);	//*2 Top Right Of The Texture and Quad
			// Bottom Face
			glNormal3f( 0.0f,-1.0f, 0.0f);		// Normal Facing Down
			glTexCoord2f(1.0f, 1.0f); glVertex3f(-this->cube_size/10, -this->cube_size, -this->cube_size);	// Top Right Of The Texture and Quad
			glTexCoord2f(0.0f, 1.0f); glVertex3f( this->cube_size/10, -this->cube_size, -this->cube_size);	// Top Left Of The Texture and Quad
			glTexCoord2f(0.0f, 0.0f); glVertex3f( this->cube_size/10, -this->cube_size,  this->cube_size);	// Bottom Left Of The Texture and Quad
			glTexCoord2f(1.0f, 0.0f); glVertex3f(-this->cube_size/10, -this->cube_size,  this->cube_size);	// Bottom Right Of The Texture and Quad
			// Right face
			glNormal3f( 1.0f, 0.0f, 0.0f);		// Normal Facing Right
			glTexCoord2f(1.0f, 0.0f); glVertex3f( this->cube_size/10, -this->cube_size, -this->cube_size);	// Bottom Right Of The Texture and Quad
			glTexCoord2f(1.0f, 1.0f); glVertex3f( this->cube_size/10,  this->cube_size, -this->cube_size);	//*2 Top Right Of The Texture and Quad
			glTexCoord2f(0.0f, 1.0f); glVertex3f( this->cube_size/10,  this->cube_size,  this->cube_size);	//*2 Top Left Of The Texture and Quad
			glTexCoord2f(0.0f, 0.0f); glVertex3f( this->cube_size/10, -this->cube_size,  this->cube_size);	// Bottom Left Of The Texture and Quad
			// Left Face
			glNormal3f(-1.0f, 0.0f, 0.0f);		// Normal Facing Left
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-this->cube_size/10, -this->cube_size, -this->cube_size);	// Bottom Left Of The Texture and Quad
			glTexCoord2f(1.0f, 0.0f); glVertex3f(-this->cube_size/10, -this->cube_size,  this->cube_size);	// Bottom Right Of The Texture and Quad
			glTexCoord2f(1.0f, 1.0f); glVertex3f(-this->cube_size/10,  this->cube_size,  this->cube_size);	//*2 Top Right Of The Texture and Quad
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-this->cube_size/10,  this->cube_size, -this->cube_size);	//*2 Top Left Of The Texture and Quad
		glEnd();					// Done Drawing Quads
		
		glPopMatrix();
	}
	
	if (this->direction == 1)
	{
		glPushMatrix();
		glTranslatef(this->x*this->cube_size*2,0,this->y*this->cube_size*2);
		//glScalef(1,1,0.1);
		textura_porta_lado->bind();
		glBegin(GL_QUADS);
			// Right face
			glNormal3f( 1.0f, 0.0f, 0.0f);		// Normal Facing Right
			glTexCoord2f(0.0f, 0.0f); glVertex3f( this->cube_size-0.01, -this->cube_size,  this->cube_size);	// Bottom Left Of The Texture and Quad
			glTexCoord2f(0.0f, 1.0f); glVertex3f( this->cube_size-0.01,  this->cube_size,  this->cube_size);	//*2 Top Left Of The Texture and Quad
			glTexCoord2f(1.0f, 1.0f); glVertex3f( this->cube_size-0.01,  this->cube_size, -this->cube_size);	//*2 Top Right Of The Texture and Quad
			glTexCoord2f(1.0f, 0.0f); glVertex3f( this->cube_size-0.01, -this->cube_size, -this->cube_size);	// Bottom Right Of The Texture and Quad
			// Left Face
			glNormal3f(-1.0f, 0.0f, 0.0f);		// Normal Facing Left
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-this->cube_size+0.01,  this->cube_size, -this->cube_size);	//*2 Top Left Of The Texture and Quad
			glTexCoord2f(1.0f, 1.0f); glVertex3f(-this->cube_size+0.01,  this->cube_size,  this->cube_size);	//*2 Top Right Of The Texture and Quad
			glTexCoord2f(1.0f, 0.0f); glVertex3f(-this->cube_size+0.01, -this->cube_size,  this->cube_size);	// Bottom Right Of The Texture and Quad
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-this->cube_size+0.01, -this->cube_size, -this->cube_size);	// Bottom Left Of The Texture and Quad
		glEnd();					// Done Drawing Quads
		textura_porta->bind();
		glTranslatef(0, this->altura, 0);
		glBegin(GL_QUADS);			// Start Drawing Quads
			// Front Face
			glNormal3f( 0.0f, 0.0f, 1.0f);		// Normal Facing Forward
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-this->cube_size, -this->cube_size,  this->cube_size/10);	// Bottom Left Of The Texture and Quad
			glTexCoord2f(1.0f, 0.0f); glVertex3f( this->cube_size, -this->cube_size,  this->cube_size/10);	// Bottom Right Of The Texture and Quad
			glTexCoord2f(1.0f, 1.0f); glVertex3f( this->cube_size,  this->cube_size,  this->cube_size/10);	//*2 Top Right Of The Texture and Quad
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-this->cube_size,  this->cube_size,  this->cube_size/10);	//*2 Top Left Of The Texture and Quad
			// Back Face
			glNormal3f( 0.0f, 0.0f,-1.0f);		// Normal Facing Away
			glTexCoord2f(1.0f, 0.0f); glVertex3f(-this->cube_size, -this->cube_size, -this->cube_size/10);	// Bottom Right Of The Texture and Quad
			glTexCoord2f(1.0f, 1.0f); glVertex3f(-this->cube_size,  this->cube_size, -this->cube_size/10);	//*2 Top Right Of The Texture and Quad
			glTexCoord2f(0.0f, 1.0f); glVertex3f( this->cube_size,  this->cube_size, -this->cube_size/10);	//*2 Top Left Of The Texture and Quad
			glTexCoord2f(0.0f, 0.0f); glVertex3f( this->cube_size, -this->cube_size, -this->cube_size/10);	// Bottom Left Of The Texture and Quad
			// Top Face
			glNormal3f( 0.0f, 1.0f, 0.0f);		// Normal Facing Up
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-this->cube_size,  this->cube_size, -this->cube_size/10);	//*2 Top Left Of The Texture and Quad
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-this->cube_size,  this->cube_size,  this->cube_size/10);	//*2 Bottom Left Of The Texture and Quad
			glTexCoord2f(1.0f, 0.0f); glVertex3f( this->cube_size,  this->cube_size,  this->cube_size/10);	//*2 Bottom Right Of The Texture and Quad
			glTexCoord2f(1.0f, 1.0f); glVertex3f( this->cube_size,  this->cube_size, -this->cube_size/10);	//*2 Top Right Of The Texture and Quad
			// Bottom Face
			glNormal3f( 0.0f,-1.0f, 0.0f);		// Normal Facing Down
			glTexCoord2f(1.0f, 1.0f); glVertex3f(-this->cube_size, -this->cube_size, -this->cube_size/10);	// Top Right Of The Texture and Quad
			glTexCoord2f(0.0f, 1.0f); glVertex3f( this->cube_size, -this->cube_size, -this->cube_size/10);	// Top Left Of The Texture and Quad
			glTexCoord2f(0.0f, 0.0f); glVertex3f( this->cube_size, -this->cube_size,  this->cube_size/10);	// Bottom Left Of The Texture and Quad
			glTexCoord2f(1.0f, 0.0f); glVertex3f(-this->cube_size, -this->cube_size,  this->cube_size/10);	// Bottom Right Of The Texture and Quad
		glEnd();
		
		
		glPopMatrix();
	}
	
}


void Porta::animate(const double dt,const double dt_cur)
{
	// se a porta for para "abrir" entao temos de a animar, senao nao interessa
	if(this->porta_a_abrir){
		// temos de fazer batota aki com o last_dt, pois nao podemos definir o last_dt no start... nao o recebemos...
		if(this->last_dt == 0)
			this->last_dt = dt-0.01;
		if(this->last_dt+0.01 >= dt){
			// subir um bocadinho
			this->altura+=0.45;
			// actualizar o ultimo dt
			this->last_dt = dt;
			
			// se ja subiu tudo, entao vamos abrir a porta na fisica e parar com a animacao
			if(this->altura>=this->cube_size*2){
				this->porta_a_abrir = false;
				this->opendoor();
				this->tempo_comecou_contar = dt_cur;
			}
		}
	}else if(this->open){
		if(this->porta_a_fechar){
			if (this->tempo_comecou_contar+5<=dt_cur){
				//this->open=false;
				this->altura-=0.45;
				if(this->altura<=0){
					this->porta_a_fechar = false;
					this->closedoor();
				}
			}
		}
		
		
		// temos de ver se a porta vai fechar... eh preciso controlar como as portas fecham.. eh por tempo
		// eh preciso fazer codigo aqui para ver se 
		// 1) o player nao esta no sitio (deixa isso comigo)
		// 2) contar o tempo (tipo 5 segundos passaram) para a porta e qd passar, comecar a animacao para fechar
		//		primeiro fechar a porta na fisica -> Fisica::updatePortas(this->y, this->x, false);
		//		fazer outra variavel para "porta_a_fechar"
		
	}

}
