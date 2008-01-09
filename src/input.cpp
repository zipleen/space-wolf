/*
 *  intput.cpp
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "input.h"

Input *Input::m_inputSingleton = NULL;

Input::Input()
{
	this->keyUpPressed = false;
	this->keyDownPressed = false;
	this->keyLeftPressed = false;
	this->keyRightPressed = false;
	this->keyStraffLeftPressed = false;
	this->keyStraffRightPressed = false;
	this->keyFirePressed = false;
	this->keyOpenDoorPressed = false;
	this->keyRunPressed = false;
	
	this->render = Rendering::GetInstance();
}

void Input::handleKeyPress (SDL_keysym *key, bool value)
{
	switch(key->sym)
	{
		case SDLK_LEFT:
			this->keyLeftPressed = value;
			break;
		
		case SDLK_RIGHT:
			this->keyRightPressed = value;
			break;
		case SDLK_UP:
			this->keyUpPressed = value;
			break;
		case SDLK_DOWN:
			this->keyDownPressed = value;
			break;
		case SDLK_w:
			// frente
			this->keyUpPressed = value;
			break;
		case SDLK_s:
			// tras
			this->keyDownPressed = value;
			break;
		case SDLK_a:
			// straff esquerda
			this->keyStraffLeftPressed = value;
			break;
		case SDLK_d:
			// straff direita
			this->keyStraffRightPressed = value;
			break;
		case SDLK_SPACE:
			// abrir portas
			this->keyOpenDoorPressed = value;
			break;

	}
}

void Input::mouseMove (Uint16 x, Uint16 y)
{
	
}

void Input::processKeyInput()
{
	if(this->keyLeftPressed){
		this->render->Cam->ChangeHeading(-1.0f);
		Console::addLine("virando pra esquerda");
	}
	if(this->keyRightPressed){
		this->render->Cam->ChangeHeading(1.0f);
		Console::addLine("virando pra direita");
	}
	if(this->keyUpPressed){
		this->render->Cam->ChangePitch(1.0f);
		Console::addLine("virando pra cima");
	}
	if(this->keyDownPressed){
		this->render->Cam->ChangePitch(-1.0f);
		Console::addLine("virando pra baixo");
	}
}
