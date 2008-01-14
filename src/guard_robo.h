/*
 *  guard_robo.h
 *  proj
 *
 *  Created by zipleen on 1/14/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef GUARD_ROBO_H
#define GUARD_ROBO_H

#include "guard.h"

class Guard_Robo : public Guard
	{
	protected:
		
	public:
		Guard_Robo(); 
		virtual ~Guard_Robo(){};
		Guard_Robo(int z, int x, bool em_movimento, GLfloat angulo);
	};

#endif
