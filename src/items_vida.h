/*
 *  items_vida.h
 *  proj
 *
 *  Created by zipleen on 1/11/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef ITEMS_VIDA_H
#define ITEMS_VIDA_H

#include "items.h"

class Items_Vida : public Items
	{
		int valor_vida;
		
	public:
		Items_Vida(){};
		Items_Vida(GLfloat x,GLfloat y, int valor, int mapa_x, int mapa_y);
		virtual ~Items_Vida(){};
		virtual bool consume(Player *p);
	};

#endif
