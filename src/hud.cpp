/*
 *  hud.cpp
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "hud.h"

Hud::Md3ModelPtr Hud::arma1, Hud::arma2, Hud::arma3, Hud::arma4 ;
Md3Model *Hud::arma1_f, *Hud::arma2_f, *Hud::arma3_f, *Hud::arma4_f, *Hud::arma4_1;
float Hud::yaw, Hud::yaw_walk;
bool Hud::yaw_up, Hud::yaw_up_walk;
TTFont *Hud::font;

void Hud::drawHud(Player *p)
{
	std::string chaves;
	if(p->chave_amarela && p->chave_vermelha)
		chaves = "Amarela & Vermelha";
	else if(p->chave_amarela && !p->chave_vermelha)
		chaves = "Amarela";
	else if(!p->chave_amarela && p->chave_vermelha)
		chaves = "Vermelha";
	else chaves = "Nenhuma";
	Hud::font->printText (45, 40, "%d", p->vida);
	Hud::font->printText (135, 40, "%d", p->armadura);	
	Hud::font->printText (225, 40, "%d", p->arma_em_uso);	
	Hud::font->printText (290, 40, "%d", p->balas);	
	Hud::font->printText (380, 40, "%s", chaves.c_str());	
	

	/*glTranslatef(80,35,0);
	glBegin(GL_QUADS);
		glVertex2f(-15,-15);
		glVertex2f(15,-15);
		glVertex2f(15,15);
		glVertex2f(-15,15);
	glEnd();*/
	/* descomenta para veres q ele imprime estes dados, sao os dados necessario a usar.
		para converteres numeros int para strings podes usar Str(p->balas)
	std::cout << "balas : " << p->balas << std::endl;
	std::cout << "vida: " << p->vida<< std::endl;
	std::cout << "armadura: " << p->armadura << std::endl;
	std::cout << "chave amarela: " << p->chave_amarela << std::endl;
	std::cout << "chave vermelha: " << p->chave_vermelha << std::endl;
	std::cout << "arma em uso:" << p->arma_em_uso << std::endl;*/
	
	// esta funcao eh chamada em void Rendering::draw2D(Player *p) no rendering.cpp
	// (neste momento na linha 377). muda o Hud::drawHud(p); de sitio nessa funcao se for necessario por causa das inicializacoes
	// que aquilo faz as matrizes
	
}

void Hud::drawGun(Player *p)
{
	glPushMatrix();
	//glLoadIdentity();
	
	if(yaw>=1.0){
		yaw_up=false;
	}else if(yaw<=0.90)
		yaw_up=true;
	if(yaw_up)
		yaw+=0.001;
	else yaw-=0.001;

	glTranslatef((p->x+(sin(-RAD(p->angulo))*yaw*yaw))*-1, 0 , (p->z+(cos(RAD(p->angulo))*yaw))*-1 );
	//glTranslatef((p->x*-1)+0.8,p->y,(p->z*-1)+0.8);
	//glTranslatef(130,0,600);
	glRotatef(90,0, 1 ,0);
	glRotatef(-90,1,0,0);
	glRotatef(-p->angulo, 0.0, 0.0,1.0);
	
	switch(p->arma_em_uso)
	{
		case 1:
			if(p->muzzle_flash){
				Hud::arma1->link("tag_flash", Hud::arma1_f);
				p->muzzle_flash=false;
			}else Hud::arma1->unlink("tag_flash");
			Hud::arma1->draw();
			break;
		case 2:
			if(p->muzzle_flash){
				Hud::arma2->link("tag_flash", Hud::arma2_f);
				p->muzzle_flash=false;
			}else Hud::arma2->unlink("tag_flash");
			Hud::arma2->draw();
			break;
		case 3:
			if(p->muzzle_flash){
				Hud::arma3->link("tag_flash", Hud::arma3_f);
				p->muzzle_flash=false;
			}else Hud::arma3->unlink("tag_flash");
			Hud::arma3->draw();
			break;
		case 4:
			if(p->muzzle_flash){
				Hud::arma4->link("tag_flash", Hud::arma4_f);
				p->muzzle_flash=false;
			}else Hud::arma4->unlink("tag_flash");
			Hud::arma4->draw();
			break;
	}
	glPopMatrix();
	
}

void Hud::initHud()
{	
#ifdef WIN32
#define ARMA1_PATH "data\\models\\weapons2\\standardgun\\standardgun_hand.md3"
#define ARMA1_F_PATH "data\\models\\weapons2\\standardgun\\standardgun_flash.md3"
	
#define ARMA2_PATH "data\\models\\weapons2\\smg\\smg_hand.md3"
#define ARMA2_F_PATH "data\\models\\weapons2\\smg\\smg_flash.md3"
	
#define ARMA3_PATH "data\\models\\weapons2\\assault\\assault_hand.md3"
#define ARMA3_F_PATH "data\\models\\weapons2\\assault\\assault_flash.md3"
	
#define ARMA4_PATH "data\\models\\weapons2\\minigun\\minigun_hand.md3"
#define ARMA4_1_PATH "data\\models\\weapons2\\minigun\\minigun_barrel.md3"
#define ARMA4_F_PATH "data\\models\\weapons2\\minigun\\minigun_flash.md3"
#else
#define ARMA1_PATH "data/models/weapons2/standardgun/standardgun_hand.md3"
#define ARMA1_F_PATH "data/models/weapons2/standardgun/standardgun_flash.md3"
	
#define ARMA2_PATH "data/models/weapons2/smg/smg_hand.md3"
#define ARMA2_F_PATH "data/models/weapons2/smg/smg_flash.md3"
	
#define ARMA3_PATH "data/models/weapons2/assault/assault_hand.md3"
#define ARMA3_F_PATH "data/models/weapons2/assault/assault_flash.md3"
	
#define ARMA4_PATH "data/models/weapons2/minigun/minigun_hand.md3"
#define ARMA4_1_PATH "data/models/weapons2/minigun/minigun_barrel.md3"
#define ARMA4_F_PATH "data/models/weapons2/minigun/minigun_flash.md3"	
#endif
	
	Hud::arma1 = Md3ModelPtr (new Md3Model (ARMA1_PATH));
	Hud::arma1_f = new Md3Model (ARMA1_F_PATH);
	Hud::arma1->setScale (0.05f);
	Hud::arma1->loadShaders();
	Hud::arma1_f->setScale (0.1f);
	Hud::arma1_f->loadShaders();
	
	Hud::arma2 = Md3ModelPtr (new Md3Model (ARMA2_PATH));
	Hud::arma2_f = new Md3Model (ARMA2_F_PATH);
	Hud::arma2->setScale (0.1f);
	Hud::arma2->loadShaders();
	Hud::arma2_f->setScale (0.1f);
	Hud::arma2_f->loadShaders();
	
	Hud::arma3 = Md3ModelPtr (new Md3Model (ARMA3_PATH));
	Hud::arma3_f = new Md3Model (ARMA3_F_PATH);
	Hud::arma3->setScale (0.1f);
	Hud::arma3->loadShaders();
	Hud::arma3_f->setScale (0.1f);
	Hud::arma3_f->loadShaders();
	
	Hud::arma4 = Md3ModelPtr (new Md3Model (ARMA4_PATH));
	Hud::arma4_1 = new Md3Model (ARMA4_1_PATH);
	Hud::arma4_f = new Md3Model (ARMA4_F_PATH);
	Hud::arma4->setScale (0.1f);
	Hud::arma4->loadShaders();
	Hud::arma4_1->setScale (0.13f);
	Hud::arma4_1->loadShaders();
	Hud::arma4_f->setScale (0.1f);
	Hud::arma4_f->loadShaders();
	Hud::arma4->link("tag_barrel", Hud::arma4_1);

	Hud::yaw = 1;
	Hud::yaw_up = false;
	Hud::yaw_walk = 1;
	Hud::yaw_up_walk = false;
	
	try
	{
		Hud::font = new TTFont ("data/Quake.ttf", 18, 1);
    }
	catch (std::runtime_error &err)
    {
		std::cerr << "Failed to create truetype font" << endl;
		std::cerr << "Reason: " << err.what () << endl;
    }
}

