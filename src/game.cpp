/*
 *  game.cpp
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "game.h"

Game::Game(const char *map_name)
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

/*
 se ele fizer exit desta funcao
 1 - acabou o jogo e passou de nivel
 2 - acabou o jogo e morreu
 3 - parou o jogo com o esq
 */
int Game::MainLoop()
{
	bool isActive = true;
	double dt;
	
	SDL_ShowCursor(SDL_DISABLE);
	
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
					if(event.key.keysym.sym == SDLK_ESCAPE)
					   return 3;
					this->input->handleKeyPress (&event.key.keysym,false);
					break;
				case SDL_KEYDOWN:
				  this->input->handleKeyPress (&event.key.keysym,true);
				  break;

				case SDL_MOUSEMOTION:
				  this->input->mouseMove (event.button.x, event.button.y, this->player);
				  break;
				
				case SDL_MOUSEBUTTONUP:
					
					if( SDL_BUTTON(SDL_GetMouseState(NULL,NULL)) != SDL_BUTTON_LEFT ){
						// disparar
						this->input->keyFireHoldPressed = false;
					}
					break;
					
					
				case SDL_MOUSEBUTTONDOWN:
					if( SDL_GetMouseState(0, 0) & SDL_BUTTON(SDL_BUTTON_LEFT) ){
						// disparar
						this->input->keyFirePressed = true;
						this->input->keyFireHoldPressed = true;
					}else if(SDL_GetMouseState(0, 0) & SDL_BUTTON(SDL_BUTTON_RIGHT))
					{
						// abrir portas
						this->map->openDoor(this->player);
					}
					break;
				case SDL_QUIT:
					SDL_Quit();
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
			
			// temos de processar os tiros, o mapa eh q tem a informacao, aqui podemos actualizar o floorcode dos guardas
			this->map->processTiros(this->player);
			
			// temos de processar o AI dos guardas aqui -> aqui os guardas mexeram-se
			this->map->processAIguards(this->player);
			
			// animacoes , dois tempos, o delta e o tempo corrente
			this->map->updateAnimations(dt,this->render->timer.current_time);
			
			// temos de ver se o player passou por cima de algum item e "apanha-lo"
			this->map->processItems(this->player);
			
			// game cycle
			this->render->gameCycle (this->map, this->player);
		}
		
		// verificar se acabamos o mapa!
		if(this->map->finished_map)
			return 1;
		if(this->player->morto){
			// desenhar qq coisa a dizer que morri
			
			return 2;
		}
	}
}

