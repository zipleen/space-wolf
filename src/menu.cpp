/*
 *  game.cpp
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "menu.h"

Menu::Menu()
{
	this->keyUpPressed = false;
	this->keyDownPressed = false;
	this->tamanho_font = 30;
	this->num_menu = 1;
	this->font = new TTFont ("data/Quake.ttf", this->tamanho_font, 1);
	this->render = Rendering::GetInstance();

}


void Menu::handleKeyPress (SDL_keysym *key, bool value)
{
	switch(key->sym)
	{
		case SDLK_UP:
			/* codigo para ir pra cima */
			this->keyUpPressed = value;
			this->num_menu--;
			break;
			
			break;
		case SDLK_DOWN:
			/* codigo para ir pra baixo */
			this->keyDownPressed = value;
			this->num_menu++;
			break;
			
			break;
	}
}


void Menu::MainLoopMenu()
{
	bool isActive = true;
	//double dt;
	// Loop until the end
	while (1)
	{
		SDL_Event event;

		// Parse SDL event
		while (SDL_PollEvent (&event))
		{
			switch (event.type)
			{
				case SDL_ACTIVEEVENT:
				  // Don't draw scene if the window has been minimized
					isActive = !((event.active.gain == 0) && (event.active.state & SDL_APPACTIVE));
					break;
				
				case SDL_KEYUP:
					this->handleKeyPress (&event.key.keysym,false);
					break;

				case SDL_QUIT:
				  //shutdownApp (0);
				  exit(0);
				  break;

				default:
				  break;
			}
		}

		// Draw scene if window is active
		if (isActive){

			this->start2D();

			glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glLoadIdentity ();
			
			// aqui podia haver um QUAD qq 2D (como no hud) para meter quadrados e desenhos
			// se calhar necessitam de activar o controle de DEPTH_TEST
			
			// desenhar BRANCO
			glColor4f (1.0f, 1.0f, 1.0f, 1.0f);
					
			// CUIDADO COM AS COORDENADAS!!! USAR SEMPRE SEMPRE SEMPRE o this->render->windowHeight / this->render->windowWidth / this->tamanho_font
			
			// comecar a desenhar a meio, cuidado que isto nao desenha "no meio do ecra", desenha A PARTIR do meio, ou seja vai ficar pra direita
			//this->font->printText (this->render->windowWidth/2,this->render->windowHeight/2,  "Comecer no meio do ecra, desenha pra direita");
				
			// desenhar no fundo do ecra
			//this->font->printText (0,0,  "Comecer ah esquerda, fundo do ecra");
			
			// desenhar lá em cima, no canto esquerdo, reparem q eh necessario RETIRAR o tamanho da fonte pq o opengl desenha de baixo para cima,
			// ptt a fonte vai ser desenhada lá em cima MENOS o tamanho da fonte
			if (this->num_menu==1)
			{
				this->font->printText (this->render->windowWidth/4,this->render->windowHeight/1.2,  "1 - Novo Jogo - aqui");
				this->font->printText (this->render->windowWidth/6,this->render->windowHeight/1.7,  "2 - Seleccionar mapa");
				this->font->printText (this->render->windowWidth/4.2,this->render->windowHeight/3,  "3 - Definicoes");
				this->font->printText (this->render->windowWidth/3,this->render->windowHeight/9,  "4 - Sair");
			}
			if (this->num_menu==2)
			{
				this->font->printText (this->render->windowWidth/4,this->render->windowHeight/1.2,  "1 - Novo Jogo");
				this->font->printText (this->render->windowWidth/6,this->render->windowHeight/1.7,  "2 - Seleccionar mapa - aqui");
				this->font->printText (this->render->windowWidth/4.2,this->render->windowHeight/3,  "3 - Definicoes");
				this->font->printText (this->render->windowWidth/3,this->render->windowHeight/9,  "4 - Sair");
			}
			if (this->num_menu==3)
			{
				this->font->printText (this->render->windowWidth/4,this->render->windowHeight/1.2,  "1 - Novo Jogo");
				this->font->printText (this->render->windowWidth/6,this->render->windowHeight/1.7,  "2 - Seleccionar mapa");
				this->font->printText (this->render->windowWidth/4.2,this->render->windowHeight/3,  "3 - Definicoes - aqui");
				this->font->printText (this->render->windowWidth/3,this->render->windowHeight/9,  "4 - Sair");
			}
			if (this->num_menu==4)
			{
				this->font->printText (this->render->windowWidth/4,this->render->windowHeight/1.2,  "1 - Novo Jogo");
				this->font->printText (this->render->windowWidth/6,this->render->windowHeight/1.7,  "2 - Seleccionar mapa");
				this->font->printText (this->render->windowWidth/4.2,this->render->windowHeight/3,  "3 - Definicoes");
				this->font->printText (this->render->windowWidth/3,this->render->windowHeight/9,  "4 - Sair - aqui");
			}
			
			this->end2D();
			
			SDL_GL_SwapBuffers ();
		}
		
	}
}

void Menu::end2D()
{
	glMatrixMode (GL_PROJECTION);
	glPopMatrix ();
	glMatrixMode (GL_MODELVIEW);	
}

void Menu::start2D()
{
	//GLint viewport[4];
	//glGetIntegerv (GL_VIEWPORT, viewport);
	
	glMatrixMode (GL_PROJECTION);
	glPushMatrix ();
	
	glLoadIdentity ();
	//glOrtho (0, viewport[2], 0, viewport[3], -1, 1);
	glOrtho(0,this->render->windowWidth,0,this->render->windowHeight, -1 ,1 );
	
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
	glMatrixMode (GL_TEXTURE);
	glLoadIdentity ();
	glMatrixMode (GL_MODELVIEW);
	
	glPushAttrib (GL_ENABLE_BIT | GL_POLYGON_BIT);
	glDisable (GL_DEPTH_TEST);
	glDisable (GL_LIGHTING);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	
	glEnable(GL_TEXTURE_2D);
}