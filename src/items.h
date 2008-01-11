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

#include <string>
#include "console.h"
#include "md3/Mathlib.h"
#include "md3/Md3Model.h"

class Items
	{
	protected:
		typedef shared_ptr<Md3Model> Md3ModelPtr;
		GLfloat x;
		GLfloat y;
		GLfloat z;
		GLfloat angulo;
		Md3ModelPtr item;
		std::string item_path;
		std::string item_skin_path;
		
		double last_dt;
		bool subir;
		int tipo_item; // 1 - ammo  | 2 - pontos | 3 - vida | 4 - chaves
		
	public:
		Items(); 
		virtual ~Items(){ };
		
		void loadModel();
		void animate(const double dt,const double dt_cur);
		void draw();
	};

#endif
