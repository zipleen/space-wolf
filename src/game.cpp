/*
 *  game.cpp
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "game.h"

Game::Game(char *map_name)
{
	this->player = new Player();
	this->render = Rendering::GetInstance();
	this->input = Input::GetInstance();
	this->map = new Map();
	this->map->loadMap(map_name, this->player);
	if(this->render->useTextures())
		this->map->loadTextures();
	Hud::initHud();
	srand((unsigned)time(0));
}

void Game::MainLoop()
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

				case SDL_VIDEORESIZE:
					// Resize Window
					this->render->resizeWindow(event.resize.w, event.resize.h);
				  
				  break;
				
				case SDL_KEYUP:
					this->input->handleKeyPress (&event.key.keysym,false);
					break;
				case SDL_KEYDOWN:
				  this->input->handleKeyPress (&event.key.keysym,true);
				  break;

				case SDL_MOUSEMOTION:
				  this->input->mouseMove (event.button.x, event.button.y);
				  break;
				
				case SDL_QUIT:
				  //shutdownApp (0);
				  exit(0);
				  break;

				default:
				  break;
			}
		}
		
		// Update the timer
		this->render->timer.update ();

		// Draw scene if window is active
		if (isActive){
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
		}
	}
}

