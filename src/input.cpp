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
	this->keyFireHoldPressed = true;
	this->keyGodModePressed = false;
	
	this->render = Rendering::GetInstance();
}

void Input::handleKeyPress (SDL_keysym *key, bool value)
{
	switch(key->sym)
	{
		case SDLK_LALT:
		case SDLK_RALT:
			this->keyRunPressed = value;
			break;
		case SDLK_LCTRL:
		case SDLK_RCTRL:
			this->keyFirePressed = value;
			if(!value)
				this->keyFireHoldPressed = true;
			break;
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
			if(value==false)
				this->keyOpenDoorPressed = true;
			break;
		case SDLK_1:
			this->keyArmaMudar = true;
			this->ArmaMudarPara = 1;
			break;
		case SDLK_2:
			this->keyArmaMudar = true;
			this->ArmaMudarPara = 2;
			break;
		case SDLK_3:
			this->keyArmaMudar = true;
			this->ArmaMudarPara = 3;
			break;
		case SDLK_4:
			this->keyArmaMudar = true;
			this->ArmaMudarPara = 4;
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
		case SDLK_g:
			if(value){
				this->keyGodModePressed = true;
			}
			break;
		case SDLK_i:
			if(value){
				if(Fisica::clip_mode)
					Fisica::clip_mode=false;
				else Fisica::clip_mode=true;
			}
			break;
	}
}

void Input::mouseMove (Uint16 MouseX, Uint16 MouseY, Player *p)
{
	GLfloat DeltaMouse;
	
	if(MouseX < this->render->CenterX)
    {
		DeltaMouse = GLfloat(this->render->CenterX - MouseX);
		p->GoTurnLeft(true,0.15f *DeltaMouse);
    }
    else if(MouseX > this->render->CenterX)
    {
		DeltaMouse = GLfloat(MouseX - this->render->CenterX);
		p->GoTurnRight(true,0.15f *DeltaMouse);
    }
	
    SDL_WarpMouse(this->render->CenterX, this->render->CenterY);
	
}

void Input::processKeyInput(Player *p, Map *m)
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
		p->y-=1;
		//this->render->Cam->ChangePitch(5.0f);
	}
	if(this->keyDownPressed){
		p->y+=1;
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
	if(this->keyOpenDoorPressed){
		m->openDoor(p);
		this->keyOpenDoorPressed=false;
	}
	if(this->keyArmaMudar){
		p->setGun(this->ArmaMudarPara);
		this->keyArmaMudar = false;
		this->ArmaMudarPara = false;
	}
	if(this->keyFirePressed){
		if(this->keyFireHoldPressed)
			if(!p->shootGun())
				this->keyFireHoldPressed=false;
	}
	if(this->keyRunPressed){
		p->SetCorrer(true);
	}else p->SetCorrer(false);
	
	if(this->keyGodModePressed){
		if(p->god_mode)
			p->god_mode=false;
		else p->god_mode=true;
		this->keyGodModePressed=false;
	}
}
