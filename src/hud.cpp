/*
 *  hud.cpp
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "hud.h"

Shared_render_objects::Md3ModelPtr Hud::arma2;

void Hud::drawHud(Player *p, TTFont *font)
{
	std::string chaves;
	if(p->chave_amarela && p->chave_vermelha)
		chaves = "Amarela & Vermelha";
	else if(p->chave_amarela && !p->chave_vermelha)
		chaves = "Amarela";
	else if(!p->chave_amarela && p->chave_vermelha)
		chaves = "Vermelha";
	else chaves = "Nenhuma";
	font->printText (10, 40, "Vida: %d | Armadura: %d | Arma: %d | Balas: %d | Chaves: %s", p->vida, p->armadura, p->arma_em_uso, p->balas, chaves.c_str());
	/* descomenta para veres q ele imprime estes dados, sao os dados necessario a usar.
		para converteres numeros int para strings podes usar Str(p->balas)
	std::cout << "balas : " << p->balas << std::endl;
	std::cout << "vida: " << p->vida<< std::endl;
	std::cout << "armadura: " << p->armadura << std::endl;
	std::cout << "chave amarela: " << p->chave_amarela << std::endl;
	std::cout << "chave vermelha: " << p->chave_vermelha << std::endl;
	std::cout << "arma em uso:" << p->arma_em_uso << std::endl;*/
	
	// esta funcao eh chamada em void Rendering::draw2D(Player *p) no rendering.cpp
	// (neste momento na linha 384). muda o Hud::drawHud(p); de sitio nessa funcao se for necessario por causa das inicializacoes
	// que aquilo faz as matrizes
	
	//GLint viewport[4];
	//glGetIntegerv (GL_VIEWPORT, viewport);
	
	/*
	glPushMatrix();
	glLoadIdentity();
	//glOrtho (0, viewport[2], 0, viewport[3], -1, 1);
	
	glTranslatef(200,200,0);
	 
	 // ele nao me ta a imprimir isto, era suposto desenhar o objecto... mas eh preciso arranjar maneira 
	 // de dizer ao opengl que queremos que ele desenhe isto mas ah frente do utilizador, ou seja, no ecra sempre ah nossa frente
	 // tem algo a haver com este glLoadidentity mas a uma das matrizes (projection ou matrix ou lá o que eh)
	Hud::arma2->draw();
	
	glBegin (GL_LINES);
    // X-axis in red
    glColor3f (1.0f, 0.0f, 0.0f);
    glVertex3fv (kZeroVectorf._v);
    glVertex3fv (kZeroVectorf + Vector3f (100.0f, 0.0f, 0.0));
	
    // Y-axis in green
    glColor3f (0.0f, 1.0f, 0.0f);
    glVertex3fv (kZeroVectorf._v);
    glVertex3fv (kZeroVectorf + Vector3f (0.0f, 100.0f, 0.0));
	
    // Z-axis in blue
    glColor3f (0.0f, 0.0f, 1.0f);
    glVertex3fv (kZeroVectorf._v);
    glVertex3fv (kZeroVectorf + Vector3f (0.0f, 0.0f, 100.0));
	glEnd ();
	

	glPopMatrix ();*/

}


void Hud::initHud()
{
	std::string item_path, item_skin_path, mesh_name;
	int item_code;
	
#ifdef WIN32
	item_path="data\\models\\weapons2\\assault\\assault_2.md3";
	item_skin_path="";
#else
	item_path="data/models/weapons2/assault/assault_2.md3";
	item_skin_path="";
#endif
	item_code = 4004;
	mesh_name = "";
	
	Hud::arma2 = Shared_render_objects::find_or_insert(item_code, item_path, item_skin_path, mesh_name);
	
}

