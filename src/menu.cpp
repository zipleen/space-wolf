/*
 *  game.cpp
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "menu.h"

TTFont *Menu::font;

Menu::Menu()
{
	Menu::font = new TTFont ("data/Quake.ttf", 30, 1);
	this->keyUpPressed = false;
	this->keyDownPressed = false;
}


void Menu::handleKeyPress (SDL_keysym *key, bool value)
{
	switch(key->sym)
	{
		case SDLK_UP:
			this->keyUpPressed = value;
			break;
		case SDLK_DOWN:
			this->keyDownPressed = value;
			break;
	}
}


void Menu::MainLoopMenu()
{
	bool isActive = true;
	double dt;
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

				//case SDL_VIDEORESIZE:
					// Resize Window
				//	this->render->resizeWindow(event.resize.w, event.resize.h);
				  
				//  break;
				
				case SDL_KEYUP:
					this->handleKeyPress (&event.key.keysym,false);
					break;

				/*case SDL_MOUSEMOTION:
				  this->Menu->mouseMove (event.button.x, event.button.y);
				  break;
				*/
				case SDL_QUIT:
				  //shutdownApp (0);
				  exit(0);
				  break;

				default:
				  break;
			}
		}
		
		// Update the timer
		//this->render->timer.update ();

		// Draw scene if window is active
		if (isActive){

				GLint viewport[4];
					glGetIntegerv (GL_VIEWPORT, viewport);
					
					glMatrixMode (GL_PROJECTION);
					glPushMatrix ();
					
					glLoadIdentity ();
					glOrtho (0, viewport[2], 0, viewport[3], -1, 1);
					
					glMatrixMode (GL_MODELVIEW);
					glLoadIdentity();
				glMatrixMode (GL_TEXTURE);
					glLoadIdentity ();
					glMatrixMode (GL_MODELVIEW);
					
					glPushAttrib (GL_ENABLE_BIT | GL_POLYGON_BIT);
					glDisable (GL_DEPTH_TEST);
					glDisable (GL_LIGHTING);
					glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);

					glColor4f (1.0f, 1.0f, 1.0f, 1.0f);
					
					font->printText (10, 10, "TEXTO %F", 324234);
					glMatrixMode (GL_PROJECTION);
						glPopMatrix ();
						glMatrixMode (GL_MODELVIEW);

			/*
			dt = this->render->timer.current_time - this->render->timer.last_time;
			// controlador de teclas, aqui o player mexeu-se
			this->input->processKeyInput(this->player, this->map);

			// player anim-> actualizar tempo
			this->player->updateAnimation(this->render->timer.current_time, this->map->getFloorcode(this->player->z*-1, this->player->x*-1));
			
			// temos de processar o AI dos guardas aqui -> aqui os guardas mexeram-se
			this->map->processAIguards();
			
			// temos de processar os tiros, o mapa eh q tem a informacao, aqui podemos actualizar o floorcode dos guardas
			this->map->processTiros(this->player);
			
			// animacoes , dois tempos, o delta e o tempo corrente
			this->map->updateAnimations(dt,this->render->timer.current_time);
			
			// temos de ver se o player passou por cima de algum item e "apanha-lo"
			this->map->processItems(this->player);
			
			// game cycle
			this->render->gameCycle (this->map, this->player);
			*/
		}
		
		// verificar se acabamos o mapa!
		//if(this->map->finished_map)
		//	break;
	}
}

