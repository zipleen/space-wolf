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

class Input
{
protected:
	static Input *m_inputSingleton;
	
public:
	Input(){}; 
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
	
};

#endif
