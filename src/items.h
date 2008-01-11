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

#include "md3/Mathlib.h"
#include <GL/glew.h>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

class Items
	{
	protected:
		GLfloat x;
		GLfloat y;
		GLfloat z;
		
		int tipo_item; // 1 - ammo  | 2 - pontos | 3 - vida | 4 - chaves
		
	public:
		Items(){}; 
		virtual ~Items(){};
		
		void animate(const double dt);
		void draw();
	};

#endif
