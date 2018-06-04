/*
 *  items_models.h
 *  proj
 *
 *  Created by zipleen on 1/12/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef SHARD_RENDER_OBJECTS_H
#define SHARD_RENDER_OBJECTS_H

#include <GL/glew.h>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include <string>
#include <map>
#include "console.h"
#include "md3/Md3Model.h"
#include "md3/TextureManager.h"

class Shared_render_objects
{
	public:
		typedef boost::shared_ptr<Md3Model> Md3ModelPtr;
		typedef map<int, Md3ModelPtr> modelos_objectos;
		
	protected: 
		static Shared_render_objects::modelos_objectos obj;
	
	public:
		Shared_render_objects(){}; 
		virtual ~Shared_render_objects(){ };
		
		static Texture2D* loadTexture(std::string path);
		static Shared_render_objects::Md3ModelPtr loadModel(std::string item_path, std::string item_skin_path, std::string mesh_name);
		static Shared_render_objects::Md3ModelPtr find_or_insert(int item, std::string item_path, std::string item_skin_path, std::string mesh_name);
	};

#endif
