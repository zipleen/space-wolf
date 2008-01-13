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
	// por agora abre logo
	this->opendoor();
}

/*
 * Este metodo nao testa se eh possivel o jogado abrir a porta ou nao, abre-a apenas
 */
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
		glScalef(0.1,1,1);
		textura_porta->bind();
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
		
		glPopMatrix();
	}

	if (this->direction == 1)
	{
		glPushMatrix();
		glTranslatef(this->x*this->cube_size*2,0,this->y*this->cube_size*2);
		glScalef(1,1,0.1);
		textura_porta->bind();
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
		
		glPopMatrix();
	}
	
}


void Porta::animate(const double dt,const double dt_cur)
{
	// actualizar o tempo?!
	
}