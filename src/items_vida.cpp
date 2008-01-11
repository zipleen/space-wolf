/*
 *  items_vida.cpp
 *  proj
 *
 *  Created by zipleen on 1/11/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "items_vida.h"

Items_Vida::Items_Vida(int x,int y)
{
	Items();
#ifdef WIN32
	this->item_path="data\\models\\players\\razor\\";
	this->item_skin_path="data\\models\\weapons2\\smg\\";
#else
	this->item_path="data/models/items/key/key.md3";
	this->item_skin_path="data/models/items/key/gold.tga";
#endif
	this->loadModel();
	this->z = x;
	this->x = y;
}
