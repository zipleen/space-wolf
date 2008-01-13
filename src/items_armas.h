/*
 *  items_armas.h
 *  proj
 *
 *  Created by zipleen on 1/12/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef ITEMS_ARMAS_H
#define ITEMS_ARMAS_H

#include "items.h"

class Items_Armas : public Items
	{
		int valor;
		
	public:
		Items_Armas(){};
		Items_Armas(GLfloat x,GLfloat y, int valor);
		virtual ~Items_Armas(){};
		void consume(Player *p);
	};

#endif
