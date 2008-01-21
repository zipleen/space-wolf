/*
 *  game.cpp
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "menu.h"

void Menu::init()
{
	this->font = new TTFont ("data/generis.TTF", this->tamanho_font, 1);
	this->font2 = new TTFont ("data/generis.TTF", 50, 1);
	this->render = Rendering::GetInstance();
	
	// ler texturas
	this->texMgr = Texture2DManager::getInstance ();
#ifdef WIN32
	this->controlos = texMgr->load ("data\\HUD\\controlos.jpg");
	this->background = texMgr->load ("data\\HUD\\background.jpg");
	this->loading = texMgr->load ("data\\HUD\\loading.jpg");
	this->died = texMgr->load ("data\\HUD\\morreste.jpg");
	this->congrats = texMgr->load ("data\\HUD\\congrats.jpg");
#else
	this->controlos = texMgr->load ("data/HUD/controlos.jpg");
	this->background = texMgr->load ("data/HUD/background.jpg");
	this->loading = texMgr->load ("data/HUD/loading.jpg");
	this->died = texMgr->load ("data/HUD/morreste.jpg");
	this->congrats =  texMgr->load ("data/HUD/congrats.jpg");
#endif
	
}

Menu::Menu()
{
	this->tamanho_font = 30;
	this->num_menu = 1;
	this->menu_to_render = 1;
	this->numero_mapa = 1;
	this->mensagem_ja_mostrada = false;
	this->game = NULL;
	this->mapa_custom = false;
	
	this->game_is_running = false; // o jogo normalmente ta a correr
	this->new_game = false; // se tiver new game entao o ciclo vai iniciar e vai pro novo jogo
	
	// configs
	this->config_fullscreen = false;
	this->nome_res = "1024x768";
	this->numero_res = 3;
	
	this->init();
	
	this->menu_principal.push_back("Novo Jogo");
	this->menu_principal.push_back("Seleccionar mapa");
	this->menu_principal.push_back("Definicoes");
	this->menu_principal.push_back("Ver comandos");
	this->menu_principal.push_back("Voltar ao jogo");
	this->menu_principal.push_back("Sair");
	
	this->menu_definicoes.push_back("Resolucao: %s");
	this->menu_definicoes.push_back("Fullscreen: %s");
	this->menu_definicoes.push_back("Voltar atras e aplicar definicoes");
	
	this->mapas.push_back("Mapa 1");
	this->mapas.push_back("Mapa 2");
	this->mapas.push_back("Mapa 3");
	this->mapas.push_back("Mapa 4");
	this->mapas.push_back("Mapa 5");
	this->mapas.push_back("Mapa 6");
	this->mapas.push_back("Mapa 7 - Boss");
	this->mapas.push_back("Mapa Alternativo 1");
	this->mapas.push_back("Mapa Alternativo 2");
	this->mapas.push_back("Mapa Alternativo 3");
	this->mapas.push_back("Mapa Alternativo 4");
	this->mapas.push_back("Mapa Alternativo 5");
	this->mapas.push_back("Mapa Alternativo 6");
	this->mapas.push_back("Mapa Alternativo 7");
	
}

void Menu::shutdown()
{
	// n sei o q fazer nisto, tenho de verificar o q fazer
	SDL_Quit();
	exit(0);
}

void Menu::handleMenuHit()
{
	switch(this->menu_to_render){
		case 1:
			// menu principal, aki temos codigo que controla o que vai acontecer nas varias opcoes do menu 1
			switch(this->num_menu){
				case 1: // novo jogo
					if(this->game!=NULL)
						delete this->game;
					this->new_game = true;
					this->mapa_custom = false;
					this->numero_mapa = 1;
					this->game_is_running = true; // vamos quebrar o ciclo
					break;
				case 2:
					 // escolher mapa
					this->mapa_custom = true;
					this->game_is_running = true;
					break;
				case 3:
					// definicoes
					this->menu_to_render = 3;
					this->num_menu = 1;
					break;
				case 4:
					// ver comandos
					this->menu_to_render = 4;
					this->num_menu = 1;
					break;
				case 5:
					// back to game
					this->game_is_running = true;
					break;
				case 6:
					// sair
					this->shutdown();
					break;
					
			}
			break;
		
		// menu 3
		case 3:
			// menu principal, aki temos codigo que controla o que vai acontecer nas varias opcoes do menu 1
			switch(this->num_menu){
				case 1: // resolucao mexer


				case 2:
					// fullscreen
					
					break;
				case 3:
					// back to main menu
					this->menu_to_render = 1;
					// aplicar novas definicoes
					switch(this->numero_res){
						case 1:
							this->render->windowWidth=640;
							this->render->windowHeight=480;
							break;
						case 2:
							this->render->windowWidth=800;
							this->render->windowHeight=600;
							break;	
						case 3:
							this->render->windowWidth=1024;
							this->render->windowHeight=768;
							break;	
						case 4:
							this->render->windowWidth=1280;
							this->render->windowHeight=1024;
							break;	
						case 5:
							this->render->windowWidth=1280;
							this->render->windowHeight=800;
							break;
					}
					
					this->render->useFullScreen=this->config_fullscreen;
					//this->render->resizeWindow(this->render->windowWidth,this->render->windowHeight);
					this->render->initVideo();
					this->texMgr->kill();
					this->init();
					break;
					
			}
			break;
		
		// menu 4 -> ver controlos
		case 4:
			// se alguem carregou em qq tecla, voltar ao menu inicial
			this->menu_to_render = 1;
			
			break;
	}
}

// tecla == 1 : esquerda | tecla == 2: direita
void Menu::handleLeftRight(int tecla)
{
	// se tivermos no menu 3
	if(this->menu_to_render==3){
		switch(this->num_menu){
			case 1:
				if(tecla)
					this->numero_res++;
				else this->numero_res--;
				if(this->numero_res==6)
					this->numero_res=1;
				if(this->numero_res==0)
					this->numero_res=5;
				switch(this->numero_res){
					case 1:
						this->nome_res="640x480";
						break;
					case 2:
						this->nome_res="800x600";
						break;
					case 3:
						this->nome_res="1024x768";
						break;
					case 4:
						this->nome_res="1280x1024";
						break;	
					case 5:
						this->nome_res="1280x800";
						break;	
				}
				break;
			case 2:
				if(this->config_fullscreen){
					this->config_fullscreen=false;
				}else this->config_fullscreen = true;
				break;
		}
	}
}

void Menu::handleKeyPress (SDL_keysym *key, bool value)
{
	switch(key->sym)
	{
		case SDLK_UP:
			/* codigo para ir pra cima */
			this->num_menu--;
			break;
			
			break;
		case SDLK_DOWN:
			/* codigo para ir pra baixo */
			this->num_menu++;
			break;
		case SDLK_KP_ENTER:
		case SDLK_RETURN:
			this->handleMenuHit();
			break;
		
		case SDLK_LEFT:
			this->handleLeftRight(1);
			
			break;
		case SDLK_RIGHT:
			this->handleLeftRight(2);
			
			break;
		default:
			this->handleMenuHit();
			break;
	}
}

void Menu::desenharMapas()
{
	glColor4f (0.5f, 0.6f, 0.8f, 1.0f);
	this->font2->printText (this->render->windowWidth/2-150, this->render->windowHeight-50, "Space Wolf");
	if (this->num_menu < 1)
		this->num_menu = 6;
	if (this->num_menu > 6)
		this->num_menu = 1;
	
	for(int i = 1; i<=this->menu_principal.size(); i++)
	{
		if(i==this->num_menu)
		{
			glColor4f (0.0f, 0.0f, 1.0f, 1.0f);
		}
		else
		{
			glColor4f (1.0f, 1.0f, 1.0f, 1.0f);
		}
		this->font->printText (10,this->render->windowHeight - (this->tamanho_font + 7) * i - (this->render->windowHeight/4) , this->menu_principal[i-1].c_str());
	}
	glColor4f (1.0f, 1.0f, 1.0f, 1.0f);
}

void Menu::desenharDefinicoes()
{
	
	
	// esta mexe com o vector menu_definicoes
	// eh preciso meter codigo para cada linha por causa da resolucao e fullscreen
	if (this->num_menu < 1)
		this->num_menu = 3;
	if (this->num_menu > 3)
		this->num_menu = 1;
	
	for(int i = 1; i<=this->menu_definicoes.size(); i++)
	{
		if(i==this->num_menu)
		{
			glColor4f (0.0f, 0.0f, 1.0f, 1.0f);
		}
		else
		{
			glColor4f (1.0f, 1.0f, 1.0f, 1.0f);
		}
		if(i==1)
			this->font->printText (10,this->render->windowHeight - (this->tamanho_font + 7) * i - (this->render->windowHeight/4) , this->menu_definicoes[i-1].c_str() , this->nome_res.c_str());
		if(i==2)
			this->font->printText (10,this->render->windowHeight - (this->tamanho_font + 7) * i - (this->render->windowHeight/4) , this->menu_definicoes[i-1].c_str() , this->config_fullscreen?" ON":" OFF");
		else 
			this->font->printText (10,this->render->windowHeight - (this->tamanho_font + 7) * i - (this->render->windowHeight/4) , this->menu_definicoes[i-1].c_str());

	}
	glColor4f (1.0f, 1.0f, 1.0f, 1.0f);
}

void Menu::desenharMainMenu()
{
	glColor4f (0.5f, 0.6f, 0.8f, 1.0f);
	this->font2->printText (this->render->windowWidth/2-150, this->render->windowHeight-50, "Space Wolf");
	if (this->num_menu < 1)
		this->num_menu = 6;
	if (this->num_menu > 6)
		this->num_menu = 1;
	
	for(int i = 1; i<=this->menu_principal.size(); i++)
	{
		if(i==this->num_menu)
		{
			glColor4f (0.0f, 0.0f, 1.0f, 1.0f);
		}
		else
		{
			glColor4f (1.0f, 1.0f, 1.0f, 1.0f);
		}
		this->font->printText (10,this->render->windowHeight - (this->tamanho_font + 7) * i - (this->render->windowHeight/4) , this->menu_principal[i-1].c_str());
	}
	glColor4f (1.0f, 1.0f, 1.0f, 1.0f);
}

void Menu::mostrar_imagem_controlos()
{
	// faz aki o desenho para mostrar em fullscreen a imagem dos controlos
	// this->controlos->bind()
	glDisable(GL_LIGHTING);
	
	glPushMatrix();
	glTranslatef(this->render->windowWidth/2,this->render->windowHeight/2,0);
	this->controlos->bind();
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(-this->render->windowWidth/2,-this->render->windowHeight/2);	
	glTexCoord2f(1.0, 0.0);	glVertex2f(this->render->windowWidth/2,-this->render->windowHeight/2);
	glTexCoord2f(1.0, 1.0); glVertex2f(this->render->windowWidth/2,this->render->windowHeight/2);
	glTexCoord2f(0.0, 1.0); glVertex2f(-this->render->windowWidth/2,this->render->windowHeight/2);	
	glEnd();
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

std::string Menu::getMapa()
{
	if(this->mapa_custom){
		
		this->game_is_running = false;
	}else{
		std::string n = Str(this->numero_mapa);
		return "data/maps/mapa"+n+".map";
	}
	return "data/maps/mapa1.map";
}
void Menu::displayImage(Texture2D *i)
{
	// serve para mostrar uma imagem in between things
	this->start2D();
	
	glDisable(GL_LIGHTING);
	
	glPushMatrix();
	glTranslatef(this->render->windowWidth/2,this->render->windowHeight/2,0);
	i->bind();
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(-this->render->windowWidth/2,-this->render->windowHeight/2);	
	glTexCoord2f(1.0, 0.0);	glVertex2f(this->render->windowWidth/2,-this->render->windowHeight/2);
	glTexCoord2f(1.0, 1.0); glVertex2f(this->render->windowWidth/2,this->render->windowHeight/2);
	glTexCoord2f(0.0, 1.0); glVertex2f(-this->render->windowWidth/2,this->render->windowHeight/2);	
	glEnd();
	glPopMatrix();
	glEnable(GL_LIGHTING);

	this->end2D();
	SDL_GL_SwapBuffers ();
}

void Menu::GameLoop()
{

	for(;;)
	{
		this->MainLoopMenu();
		if(this->new_game){
			// novo jogo, vamos cria-lo
			// mostrar ecra de loading
			this->new_game = false;
			this->game_is_running = true; // batotazita, se o mapa for custom este game is running fica false
			
			if(!this->mensagem_ja_mostrada)
				this->displayImage(this->loading);
			else this->mensagem_ja_mostrada = false;
			
			this->game = new Game(this->getMapa().c_str());
			switch(this->game->MainLoop()){
				case 1:
					// o mapa acabou, mapa seguinte por favor
					this->numero_mapa++;
					if(this->numero_mapa>8){
						this->numero_mapa = 1;
						this->new_game = false;
						this->displayImage(this->congrats);
						getchar(); // era isto q se usava para parar o input ?!?!?!?! lol
					}else
						this->new_game = true;
					break;
				case 2:
					// player morreu, vamos continuar no mm mapa
					this->new_game = true;
					this->displayImage(this->died);
					this->mensagem_ja_mostrada = true;
					break;
				case 3:
					// pausa
					this->game_is_running = false;
					break;
					
			}
			
		}else{
			// queremos entao continuar o jogo
			if(this->game==NULL)
				this->game_is_running = false;
			else {
				switch(this->game->MainLoop()){
					case 1:
						// o mapa acabou, mapa seguinte por favor
						this->numero_mapa++;
						this->game_is_running = true;
						break;
					case 2:
						// player morreu, vamos continuar no mm mapa
						this->game_is_running = true;
						this->new_game = true;
						break;
					case 3:
						// pausa
						this->game_is_running = false;
						break;
						
				}	
			}
		}
	}
	
}

void Menu::MainLoopMenu()
{
	bool isActive = true;
	//double dt;
	// Loop until the end
	for(;;)
	{
		if(this->game_is_running) return; // sair fora do mainmenu se for para correr o jogo
		
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
				  this->shutdown();
				  break;

				default:
				  break;
			}
		}

		// Draw scene if window is active
		if (isActive){

			this->start2D();

			glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glPushMatrix();
			glTranslatef(this->render->windowWidth/2,this->render->windowHeight/2,0);
			this->background->bind();
			glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex2f(-this->render->windowWidth/2,-this->render->windowHeight/2);	
				glTexCoord2f(1.0, 0.0);	glVertex2f(this->render->windowWidth/2,-this->render->windowHeight/2);
				glTexCoord2f(1.0, 1.0); glVertex2f(this->render->windowWidth/2,this->render->windowHeight/2);
				glTexCoord2f(0.0, 1.0); glVertex2f(-this->render->windowWidth/2,this->render->windowHeight/2);	
			glEnd();
			glPopMatrix();


			glLoadIdentity ();
			glEnable(GL_LIGHTING);
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
			switch(this->menu_to_render){
				case 1:
					this->desenharMainMenu();
					break;
				case 2:
					// mapas
					break;
				case 3:
					// definicoes
					this->desenharDefinicoes();
					break;
				case 4:
					// mostrar imagem
					this->mostrar_imagem_controlos();
					break;
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