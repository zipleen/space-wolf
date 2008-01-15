/*
 *  items_chave.h
 *  proj
 *
 *  Created by zipleen on 1/12/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef ITEMS_CHAVE_H
#define ITEMS_CHAVE_H

#include "items.h"

class Items_Chave : public Items
	{
		int tipo;
		
	public:
		Items_Chave(){};
		Items_Chave(GLfloat x,GLfloat y, int valor, int mapa_x, int mapa_y);
		virtual ~Items_Chave(){};
		virtual bool consume(Player *p);
	};

#endif
