/*
 *  guard_medium.h
 *  proj
 *
 *  Created by zipleen on 1/11/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef GUARD_MEDIUM_H
#define GUARD_MEDIUM_H

#include "guard.h"

class Guard_Medium : public Guard
{
	protected:
		
	public:
		Guard_Medium(); 
		virtual ~Guard_Medium(){};
		Guard_Medium(int z, int x, bool em_movimento, GLfloat angulo);
};

#endif
