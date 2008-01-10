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
	this->keyGoBackPressed = false;
	this->keyGoFrontPressed = false;
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
			this->keyGoFrontPressed = value;
			break;
		case SDLK_DOWN:
			this->keyGoBackPressed = value;
			break;
		case SDLK_w:
			// frente
			this->keyGoFrontPressed = value;
			break;
		case SDLK_s:
			// tras
			this->keyGoBackPressed = value;
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
			
		case SDLK_r:
			this->keyUpPressed = value;
			break;
		case SDLK_f:
			this->keyDownPressed = value;
			break;
			
		case SDLK_q:
			this->render->useWireframe = value;
			break;
	}
}

void Input::mouseMove (Uint16 MouseX, Uint16 MouseY)
{
/*	GLfloat DeltaMouse;
	
    if(MouseX < this->render->CenterX)
    {
		DeltaMouse = GLfloat(this->render->CenterX - MouseX);
		this->render->Cam->ChangeHeading(-0.1f * DeltaMouse);
		
    }
    else if(MouseX > this->render->CenterX)
    {
		DeltaMouse = GLfloat(MouseX - this->render->CenterX);
		this->render->Cam->ChangeHeading(0.1f * DeltaMouse);
    }
    if(MouseY < this->render->CenterY)
    {
		DeltaMouse = GLfloat(this->render->CenterY - MouseY);
		this->render->Cam->ChangePitch(-0.1f * DeltaMouse);
    }
    else if(MouseY > this->render->CenterY)
    {
		DeltaMouse = GLfloat(MouseY - this->render->CenterY);
		this->render->Cam->ChangePitch(0.1f * DeltaMouse);
    }
	
    SDL_WarpMouse(this->render->CenterX, this->render->CenterY);
	*/
}

void Input::processKeyInput(Player *p)
{
	if(this->keyLeftPressed){
		//this->render->Cam->ChangeHeading(-5.0f);
		p->GoTurnLeft();
	}
	if(this->keyRightPressed){
		p->GoTurnRight();
		//this->render->Cam->ChangeHeading(5.0f);
	}
	if(this->keyUpPressed){
		p->y--;
		//this->render->Cam->ChangePitch(5.0f);
	}
	if(this->keyDownPressed){
		p->y++;
		//this->render->Cam->ChangePitch(-5.0f);
	}
	
	if(this->keyGoBackPressed){
		// tenho de pegar no vector e andar para a frente com o vector... e nao apenas somar lol
		p->GoBack();
	}
	if(this->keyGoFrontPressed){
		p->GoFront();
	}
	if(this->keyStraffLeftPressed){
		p->GoStraffLeft();
	}
	if(this->keyStraffRightPressed){
		p->GoStraffRight();
	}
	
}
