/*
 *  game.cpp
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "game.h"

Game::Game()
{
	this->player = new Player();
	this->render = Rendering::GetInstance();
	this->map = new Map();
	this->map->loadMap("data/maps/mapa1.map");
	this->map->loadTextures();
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
				/*
				case SDL_KEYDOWN:
				  handleKeyPress (&event.key.keysym);
				  break;

				case SDL_MOUSEMOTION:
				  mouseMove (event.button.x, event.button.y);
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
		this->render->timer.update ();

		// Draw scene if window is active
		if (isActive){
			dt = this->render->timer.current_time - this->render->timer.last_time;
			this->map->updateAnimations(dt);
			// player anim?
			// this->player->updateAnimation(dt);
			this->render->gameCycle (this->map);
		}
	}
}

