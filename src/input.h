/*
 *  intput.h
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INPUT_H
#define INPUT_G

#include <SDL.h>
#include "rendering.h"
#include "console.h"

class Input
{
public:
	static Input *m_inputSingleton;
	
	Rendering *render;
	
	bool keyUpPressed;
	bool keyDownPressed;
	bool keyLeftPressed;
	bool keyRightPressed;
	bool keyStraffLeftPressed;
	bool keyStraffRightPressed;
	bool keyGoFrontPressed;
	bool keyGoBackPressed;
	bool keyFirePressed;
	bool keyFireHoldPressed;
	bool keyOpenDoorPressed;
	bool keyRunPressed;
	bool keyArmaMudar;
	int ArmaMudarPara;
	
public:
	Input(); 
	virtual ~Input(){};
	
	static Input *GetInstance( void )
	{
		if( m_inputSingleton == 0 )
			m_inputSingleton = new Input;
		
		return ((Input *)m_inputSingleton);
	}
	
	static void Kill( void )
	{
		if( m_inputSingleton != 0 )
		{
			delete m_inputSingleton;
			m_inputSingleton = 0;
		}
	}
	
	void handleKeyPress (SDL_keysym *key, bool value);
	void mouseMove (Uint16 x, Uint16 y, Player *p);
	void processKeyInput(Player *p, Map *m);
};

#endif
