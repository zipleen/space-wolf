/*
 *  guarda_dificil.h
 *  proj
 *
 *  Created by zipleen on 1/14/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef GUARD_DIFICIL_H
#define GUARD_DIFICIL_H

#include "guard.h"

class Guard_Dificil : public Guard
	{
	protected:
		
	public:
		Guard_Dificil(); 
		virtual ~Guard_Dificil(){};
		Guard_Dificil(int z, int x, bool em_movimento, GLfloat angulo);
	};

#endif
