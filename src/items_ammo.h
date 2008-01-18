/*
 *  items_ammo.h
 *  proj
 *
 *  Created by zipleen on 1/12/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef ITEMS_AMMO_H
#define ITEMS_AMMO_H

#include "items.h"

class Items_Ammo : public Items
	{
		int valor;
		
	public:
		Items_Ammo(){};
		Items_Ammo(GLfloat x,GLfloat y, int valor,int mapa_x, int mapa_y, bool clip);
		virtual ~Items_Ammo(){};
		virtual bool consume(Player *p);
	};

#endif
