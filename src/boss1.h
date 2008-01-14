/*
 *  boss1.h
 *  proj
 *
 *  Created by zipleen on 1/14/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef GUARD_BOSS1_H
#define GUARD_BOSS1_H

#include "guard.h"

class Guard_Boss1 : public Guard
	{
	protected:
		
	public:
		Guard_Boss1(); 
		virtual ~Guard_Boss1(){};
		Guard_Boss1(int z, int x, bool em_movimento, GLfloat angulo);
	};

#endif
