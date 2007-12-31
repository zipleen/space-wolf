/*
 *  items.h
 *  proj
 *
 *  Created by zipleen on 12/30/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef ITEMS_H
#define ITEMS_H

class Items
	{
	protected:
		int x;
		int y;
		int tipo_item; // 1 - ammo  | 2 - pontos | 3 - vida | 4 - chaves
		
	public:
		Items(){}; 
		virtual ~Items(){};
		
	};

#endif
