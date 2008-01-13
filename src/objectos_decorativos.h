/*
 *  objectos_decorativos.h
 *  proj
 *
 *  Created by zipleen on 1/12/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */
/*
 *  items.h
 *  proj
 *
 *  Created by zipleen on 12/30/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 
	Items fazem "coisas" ao player. portanto se for para obter um item, passa-se o player e o item "faz algo" ao player
	e depois eh consumido. a variavel used controla se o item eh valido e se eh para ser mostrado. adicionalmente se calhar vou eh 
	eliminar o item do vector.
 */

#ifndef OBJECTOS_DECORATIVOS_H
#define OBJECTOS_DECORATIVOS_H

#include <GL/glew.h>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include <string>
#include "console.h"
#include "shared_render_objects.h"

class Objectos_decorativos
	{
	protected:
		GLfloat x;
		GLfloat y;
		GLfloat z;
		GLfloat angulo;
		Shared_render_objects::Md3ModelPtr item;
		int item_code;
		
	public:
		bool impede_passagem;
		Objectos_decorativos(Shared_render_objects::Md3ModelPtr model, GLfloat x, GLfloat y, GLfloat z, int item_code, bool impede); 
		virtual ~Objectos_decorativos(){ };

		void draw();
	};

#endif

