/*
 *  soldado.h
 *  proj
 *
 *  Created by zipleen on 12/30/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 
  SOLDADO mais fraco
 */

#ifndef SOLDADO_H
#define SOLDADO_H

#include "guard.h"

class Soldado : public Guard
{
	protected:
		
	public:
		Soldado(); 
		virtual ~Soldado(){};
		Soldado(int x, int y, bool em_movimento, GLfloat angulo);
};

#endif
