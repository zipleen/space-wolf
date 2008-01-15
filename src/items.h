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

#ifndef ITEMS_H
#define ITEMS_H

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
#include "player.h"
#include "md3/Mathlib.h"
#include "md3/Md3Model.h"
#include "md3/TextureManager.h"
#include "shared_render_objects.h"

class Items
	{
	protected:
		GLfloat x;
		GLfloat y;
		GLfloat z;
		GLfloat angulo;
		Shared_render_objects::Md3ModelPtr item;
		std::string item_path;
		std::string item_skin_path;
		std::string mesh_name;
		int item_code;
		
		bool used; // se estiver a true ja nao se desenha nada e nao se pode usar
		double last_dt;
		bool subir;
		int tipo_item; // 1 - ammo  | 2 - pontos | 3 - vida | 4 - chaves
		
	public:
		int mapa_x;
		int mapa_y;
		Items(); 
		virtual ~Items(){ };
		
		void loadModel();
		void animate(const double dt,const double dt_cur);
		void draw();
		virtual bool consume(Player *p) = 0;
	};

#endif
