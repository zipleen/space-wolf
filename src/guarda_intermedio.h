/*
 *  guarda_intermedio.h
 *  proj
 *
 *  Created by zipleen on 1/14/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef GUARD_INTERMEDIO_H
#define GUARD_INTERMEDIO_H

#include "guard.h"

class Guard_Intermedio : public Guard
	{
	protected:
		
	public:
		Guard_Intermedio(); 
		virtual ~Guard_Intermedio(){};
		Guard_Intermedio(int z, int x, bool em_movimento, GLfloat angulo);
	};

#endif
