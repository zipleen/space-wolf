/*
 *  items_armor.h
 *  proj
 *
 *  Created by zipleen on 1/14/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef ITEMS_ARMOR_H
#define ITEMS_ARMOR_H

#include "items.h"

class Items_Armor : public Items
	{
		int valor_vida;
		
	public:
		Items_Armor(){};
		Items_Armor(GLfloat x,GLfloat y, int valor);
		virtual ~Items_Armor(){};
		void consume(Player *p);
	};

#endif
