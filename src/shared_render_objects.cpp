/*
 *  items_models.cpp
 *  proj
 *
 *  Created by zipleen on 1/12/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "shared_render_objects.h"

Shared_render_objects::modelos_objectos Shared_render_objects::obj;

Shared_render_objects::Md3ModelPtr Shared_render_objects::find_or_insert(int item, std::string item_path, std::string item_skin_path, std::string mesh_name)
{
	modelos_objectos::iterator m;
	m=Shared_render_objects::obj.find(item);
	if(m==Shared_render_objects::obj.end()){
		// ler o modelo
		Md3ModelPtr new_model = Shared_render_objects::loadModel(item_path, item_skin_path, mesh_name);
		Shared_render_objects::obj.insert(modelos_objectos::value_type(item,new_model));
		m=Shared_render_objects::obj.find(item);
	}
	return m->second;
}

Texture2D* Shared_render_objects::loadTexture(std::string path)
{
	Texture2DManager *texMgr = Texture2DManager::getInstance ();
	Texture2D *tex_new = texMgr->load (path);
	return tex_new;
}

Shared_render_objects::Md3ModelPtr Shared_render_objects::loadModel(std::string item_path, std::string item_skin_path, std::string mesh_name)
{
	Texture2D *textura_item;
	Md3ModelPtr item;
	if(item_path.size()==0)
	{
		Console::addLine("erro: o item nao tem modelo?!");
		exit(-1);
	}
	
	
	// ler o md3
	try
    {
		item = Md3ModelPtr (new Md3Model (item_path));
		item->setScale (0.1f);
		// se nao tivermos meshname entao vamos ler os shaders
		if(mesh_name==""){
			item->loadShaders();

			std::ifstream ftest (item_skin_path.c_str (), std::ios::in);
			if (!ftest.fail ())
			{
				Md3Model *_barrel;
				// The barrel model exists, load it
				ftest.close ();
					
					
				_barrel = new Md3Model (item_skin_path);
				_barrel->loadShaders ();
				_barrel->setScale(0.1f);

				// Create links between weapon and barrel
				// isto vai dar leaks de memoria horriveis!!!
				// todas as vezes que aparecer a minigun, isto vai deixar lixo na memoria. mas como o shared object tem sempre as coisas lah
				// nao vai haver "2 miniguns". nao sei eh se o C++ pode escrever por cima deste apontador.... suponho que nao pq nunca foi free'd
				item->link ("tag_barrel", _barrel);
			}

		}else{
			//atribuir a textura ao modelo, atraves do mesh_name
			// ler a textura
			textura_item = Shared_render_objects::loadTexture(item_skin_path);
			item->setTexture(mesh_name, textura_item);
		}
    }
	catch (std::runtime_error &err)
    {
		Console::printf("Error: failed to load %s",item_path.c_str() );
		Console::printf("Reason: %s",err.what ());
		exit (-1);
    }
	return item;
}
