/*
 *  guard.cpp
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "guard.h"
#define VELOCIDADE_ANDAR_GUARDA 5

Guard::Guard()
{
	this->morto = false;
	this->em_movimento = false;
	this->em_disparo = false;
	this->alerta = false;
	//this->movimento_contar_vezes = 0;
	this->som_disparo_arma = 0;
	this->ultimo_disparo = 0;
	this->ultimo_andar = 0;
	this->velocidade = VELOCIDADE_ANDAR_GUARDA;
	this->tempo_reaccao = 1.6;
	this->go_to_x = 0;
	this->go_to_z = 0;
	this->old_go_to_x = 0;
	this->old_go_to_z = 0;
	this->z=this->x=this->old_x=this->old_z=0;
	this->y=this->old_y=2.6f;
	this->vai_para_alerta = false;
	this->s = Sound::GetInstance();
	// ler passos
#ifdef WIN32
	this->som_passos[1] = this->s->loadSound("data\\sounds\\footsteps\\boot1.wav");
	this->som_passos[2] = this->s->loadSound("data\\sounds\\footsteps\\boot2.wav");
	this->som_passos[3] = this->s->loadSound("data\\sounds\\footsteps\\boot3.wav");
	this->som_passos[4] = this->s->loadSound("data\\sounds\\footsteps\\boot4.wav");
	this->som_alerta = this->s->loadSound("data\\sounds\\teste.wav");
#else
	this->som_passos[1] = this->s->loadSound("data/sounds/footsteps/boot1.wav");
	this->som_passos[2] = this->s->loadSound("data/sounds/footsteps/boot2.wav");
	this->som_passos[3] = this->s->loadSound("data/sounds/footsteps/boot3.wav");
	this->som_passos[4] = this->s->loadSound("data/sounds/footsteps/boot4.wav");
	this->som_alerta = this->s->loadSound("data/sounds/teste.wav");
#endif
	this->som_passo_corrente=1;
	this->canal_som_passos[0]=0;
	this->canal_som_passos[1]=0;
	this->canal_som_passos[2]=0;
	this->canal_som_passos[3]=0;
	this->canal_som_passos[4]=0;
	this->canal_som_levar_na_tromba=0;
}

void Guard::loadModel()
{
	if(this->model_path.size()==0)
	{
		Console::addLine("erro: o guarda nao tem modelo");
		exit(-1);
	}
	
	// ler o modelo md3
	try
    {
		// Load MD3 player
		this->guard = new Md3Player (this->model_path);
		this->guard->setScale (0.1f);
		this->guard->setAnimation (kTorsoStand);
		this->guard->setAnimation (kLegsIdle);
    }
	catch (std::runtime_error &err)
    {
		Console::printf("Error: failed to load %s",this->model_path.c_str() );
		Console::printf("Reason: %s",err.what ());
		exit (-1);
    }	
	
	try
    {
		// Load weapon if a path is given
		if (!this->weaponpath.empty ())
		{
			this->weapon = new Md3Weapon (this->weaponpath);
			this->weapon->setScale (0.1f);
			this->guard->linkWeapon (this->weapon);
		}
    }
	catch (std::runtime_error &err)
    {
		Console::printf( "Error: failed to load %s" , this->weaponpath.c_str() );
		Console::printf( "Reason: %s" , err.what () );
    }
}

void Guard::draw()
{
	glPushMatrix();
		glTranslatef(this->x,this->y,this->z);
		glRotatef(this->angulo,0,1,0);
		this->guard->draw();
	glPopMatrix();
}

// isto nao eh chamado mais
void Guard::setWalk(bool v){
	if(v){
		this->guard->setAnimation (kLegsWalk);
		this->guardar_em_movimento=true;
		this->em_movimento=true;
	}else{
		this->guard->setAnimation (kLegsIdle);
		this->guardar_em_movimento=false;
		this->em_movimento=false;
	}
}

void Guard::nextMove(float p_z, float p_x)
{
	if(this->alerta){
		// olhar para o jogador

		this->angulo=Fisica::Angle(this->x*-1,this->z*-1 ,p_x ,p_z);
		//std::cout << "eu: Z: " << this->z << " X:" << this->x << " p: Z:" << p_z << " X:" << p_x << " ang:" << this->angulo<<std::endl;
		
		//this->GoFront();
		switch(rand()%4+1){
			case 1:
				this->GoStraffLeft();
				break;
			case 2:
				this->GoStraffRight();
				break;
			case 3:
				this->GoFront();
				break;
			case 4:
				this->GoBack();
				break;
		}
	   this->shootGun();
	}
}

void Guard::shootGun()
{
	// primeiro temos de ver se podemos disparar, se podemos entao metemos o disparar a true
	//std::cout << "ult disp"<< this->ultimo_disparo << " velocidade: " << this->velocidade_disparo << " dt_cir: " << this->dt_cur << std::endl;
	if(this->ultimo_disparo+this->velocidade_disparo < this->dt_cur){
		// podemos disparar
		this->disparar = true;
		this->em_disparo = true;
		this->ultimo_disparo = this->dt_cur;
		if(Mix_Playing(this->som_disparo_arma)!=0)
			Mix_HaltChannel(this->som_disparo_arma);
		this->som_disparo_arma = this->s->playSound(this->som_arma,this->z,this->x, this->angulo);
		this->guard->setAnimation (kTorsoAttack);
	}
}


void Guard::playSomPassos()
{
	// verificar se o som está a tocar
	if(this->canal_som_passos[this->som_passo_corrente]==0 || Mix_Playing(this->canal_som_passos[this->som_passo_corrente])==0){
		//std::cout << "som corrente "<< this->z << " " << this->x << ": " << this->som_passo_corrente << std::endl;
		// ja nao toca
		this->canal_som_passos[this->som_passo_corrente] = this->s->playSound(this->som_passos[this->som_passo_corrente], this->z, this->x, this->angulo);
		if(this->som_passo_corrente==4)
			this->som_passo_corrente=1;
		else this->som_passo_corrente++;
		
	}
}

void Guard::takeHealth(int valor)
{
	//std::cout << "vida que vai ser tirada do guarda: " << valor << std::endl;
	this->vida-=valor;
	if(this->vida<=0){
		this->vida=0;
		this->morto=true;
		int orig_x = (int)(((this->z)/(Fisica::cube_size*2.0f))+0.5);
		int orig_y = (int)(((this->x)/(Fisica::cube_size*2.0f))+0.5);
		Fisica::guardas[orig_x][orig_y] = false;
	}else{
		if(this->canal_som_levar_na_tromba==0 || Mix_Playing(this->canal_som_levar_na_tromba)==0){
			this->canal_som_levar_na_tromba=this->s->playSound(this->som_levar_na_boca, this->z, this->x,this->angulo);
		}
	}
}

void Guard::takeHealth(GLfloat z, GLfloat x, int valor_arma)
{
	float z1 = this->z - (z*-1);
	float x1 = this->x - (x*-1);
	int dist = (int)sqrt(z1*z1 + x1*x1);
	if(dist!=0){
		this->takeHealth( (100-(dist/valor_arma))/2 );
	}else this->takeHealth(100);
}

void Guard::normaliza(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat *nx, GLfloat *ny)
{
	float vx = x2-x1;
	float vy = y2-y1;
	float dist = sqrt(vx*vx + vy*vy);
	*nx = vx/dist;
	*ny = vy/dist;
	
	std::cout << "norm_x:" << *nx << " norm_y:" << *ny << std::endl;
}

void Guard::setInitial(float z, float x)
{
	this->z=this->old_z=this->go_to_z=this->old_go_to_z=z;
	this->x=this->old_x=this->go_to_x=this->old_go_to_x=x;
	this->y = -2.6f;
}

void Guard::animate(const double dt, double dt_cur)
{
	this->dt_cur = dt_cur;
	if(!this->morto){
		// temos de primeiro "mexe-lo"
		// a ideia do mexer eh que eles tem uma posicao para a qual QUEREM ir,
		// mas para irem para ela, temos de passar por todas as outras anteriores
		/*std::cout << "touZ:" << this->z << " touX:" << this->x << "|"  ;
		std::cout << "OLDgoZ:" << this->old_go_to_z << " OLDgoX:" << this->old_go_to_x << "|"  ;
		std::cout << "goZ:" << this->go_to_z << " goX:" << this->go_to_x << std::endl;*/
		if( (this->go_to_z!=this->z) || (this->go_to_x!=this->x) )
		{
			GLfloat nz, nx;
			//std::cout << "ur:" <<  this->ultima_reaccao << " treacao:" << this->tempo_reaccao << "dt: " << this->dt_cur;
			
			float t = this->dt_cur-this->ultima_reaccao;//std::cout << " t: " << t << std::endl;
			if(t<=this->tempo_reaccao){

				nz = (this->go_to_z - this->old_go_to_z )*( t/this->tempo_reaccao ) ;
				nx = (this->go_to_x - this->old_go_to_x )*( t/this->tempo_reaccao ) ;
				this->set_xy(this->old_go_to_z+nz,this->old_go_to_x+nx);
			}
			
		}
		
		// precisamos de ver se ele tem de fazer coisas ou nao..
		// estamos em alerta?! se nao, vamos seguir os percursos
		if(!this->alerta){
			if(this->vai_para_alerta){
				this->vai_para_alerta=false;
				this->alerta=true;
				this->s->playSound(this->som_alerta, this->z, this->x,this->angulo);
				this->velocidade = this->velocidade_correr;
			}else if(this->guardar_em_movimento){ // se nao tamos em alerta temos de ver se tamos em movimento, se tamos, temos de o mover
				//std::cout << "vamos andar: " << this->z << " " << this->x << std::endl;
				this->GoFront();
			}
		}else{
			// o AI ja vai fazer coisas la em cima
			
		}
		
		// se ja passou tempo suficiente para interpolarmos as animacoes...
		if(this->dt_cur+0.01>this->ultimo_andar){
			if(this->old_x!=this->x || this->old_z!=this->z){
				// esta a andar
				if(!this->em_movimento){
					this->guard->setAnimation (kLegsWalk);
					this->em_movimento=true;
				}
			}else{
				// esta parado
				if(this->em_movimento){
					this->guard->setAnimation (kLegsIdle);
					this->em_movimento=false;
				}
			}
		}
		
		if(this->modificou_upper_movimento){
			if(this->em_disparo){
				//this->guard->setAnimation (kTorsoAttack);
				if(this->ultimo_disparo+this->velocidade_disparo < this->dt_cur)
					this->em_disparo=false;
			}else{
				this->guard->setAnimation (kTorsoStand);
			}
			this->modificou_upper_movimento = false;
		}
		this->guard->animate(dt);
		
		// som
		if(this->em_movimento)
			this->playSomPassos();
	}else{
		// estamos mortos ou vamos morrer
		if(!this->a_morrer){
			this->guard->unlinkWeapon();
			this->guard->_lowerAnim.executar_anim = false;
			this->guard->_upperAnim.executar_anim = false;
			if(Mix_Playing(this->canal_som_levar_na_tromba)!=0)
				Mix_HaltChannel(this->canal_som_levar_na_tromba);
			switch(rand()%4+1){
				case 1:
					this->guard->setAnimation(kBothDeath1);
					this->s->playSound(this->som_morrer[1],this->z, this->x,this->angulo);
					break;
				case 2:
					this->guard->setAnimation(kBothDeath2);
					this->s->playSound(this->som_morrer[2],this->z, this->x,this->angulo);
					break;
				default:
				case 3:
					this->guard->setAnimation(kBothDeath3);
					this->s->playSound(this->som_morrer[3],this->z, this->x,this->angulo);
					break;
			}
			
			this->a_morrer=true;
		}
		this->guard->animate(dt);
	}
}

void Guard::IwannaGoTo(float z,float x)
{
	//std::cout << "ur: " << this->ultima_reaccao << " tr:" << this->tempo_reaccao << " dt_cur:" << this->dt_cur << std::endl;
	if(this->ultima_reaccao+this->tempo_reaccao < this->dt_cur ) // se ja passou o tempo de reaccao, podemos mudar de direccao
	{
		std::cout << "vou para novo sitio:" << z << " " <<x << std::endl;
		this->old_go_to_x = this->x;
		this->old_go_to_z = this->z;
		
		this->go_to_z = z;
		this->go_to_x = x;
		this->ultima_reaccao=this->dt_cur;
		
		// tu nao te podes virar, tu queres sempre que o angulo esteja virado para o player!!!
		//float an = Fisica::Angle(this->go_to_x, this->go_to_z, this->old_go_to_x, this->old_go_to_z);
		//if(an!=-1)
		//	this->angulo=an;
	}
	
}

void Guard::set_xy(float z, float x)
{
	// temos de ir ah fisica retirar o nosso valor para 0
	int orig_x = (int)(((this->z)/(Fisica::cube_size*2.0f))+0.5);
	int orig_y = (int)(((this->x)/(Fisica::cube_size*2.0f))+0.5);
	Fisica::guardas[orig_x][orig_y] = false;

	this->old_x = this->x;
	this->old_y = this->y;
	this->old_z = this->z;
	
	this->x = x;
	this->y = -2.6f;
	this->z = z;
	//std::cout << "desenhar em:" << this->z << " " << this->x << std::endl;
	
	// actualizar para novo valor
	orig_x = (int)(((this->z)/(Fisica::cube_size*2.0f))+0.5);
	orig_y = (int)(((this->x)/(Fisica::cube_size*2.0f))+0.5);
	Fisica::guardas[orig_x][orig_y] = true;
}
void Guard::setAngulo(GLfloat angulo)
{
	this->angulo = angulo;
}

/* movimento */

float Guard::MoveTest()
{
	   return 1;
}

/* na realidade ele nao vai fazer straff, ele vai andar pra frente e virar pra esquerda */
void Guard::GoStraffLeft()
{
	GLfloat nx,nz;
	float move;
	move = this->MoveTest();
	if(move==0)
		return;
	nx=(this->x*-1)+sin(RAD(-this->angulo+315))*this->velocidade/this->tempo_reaccao;
	nz=(this->z)+cos(RAD(this->angulo+315))*this->velocidade/this->tempo_reaccao;
	
	if( Fisica::canIgoThere(this->z*-1, this->x*-1, nz*-1, nx, true) ){
		this->IwannaGoTo(nz, nx*-1);
	}
}

void Guard::GoStraffRight()
{
	GLfloat nx,nz;
	float move;
	move = this->MoveTest();
	if(move==0)
		return;
	nx=(this->x*-1)+sin(RAD(-this->angulo+45))*this->velocidade/this->tempo_reaccao;
	nz=(this->z)+cos(RAD(this->angulo+45))*this->velocidade/this->tempo_reaccao;

	if( Fisica::canIgoThere(this->z*-1, this->x*-1, nz*-1, nx, true) ){
		this->IwannaGoTo(nz, nx*-1);
	}
	
}

void Guard::GoFront()
{
	GLfloat nx,nz;
	float move;
	move = this->MoveTest();
	if(move==0)
		return;
	nx=(this->x*-1)+sin(RAD(-this->angulo))*this->velocidade/this->tempo_reaccao;
	nz=(this->z)+cos(RAD(this->angulo))*this->velocidade/this->tempo_reaccao;
	
	/*std::cout << " npc angulo:" << this->angulo << std::endl;
	std::cout << "-> nz: " << ((this->z)+cos(RAD(this->angulo))*this->velocidade*move) << " nx: " << ((this->x)+sin(-RAD(this->angulo))*this->velocidade*move) << std::endl;
	std::cout << " nz: " << ((this->z*-1)+cos(RAD(this->angulo))*this->velocidade*move) << " nx: " << (this->x*-1)+sin(-RAD(this->angulo))*this->velocidade*move << std::endl;
	std::cout << "+90 nz: " << ((this->z*-1)+cos(RAD(this->angulo))*this->velocidade*move) << " nx: " << (this->x*-1)+sin(-RAD(this->angulo+90))*this->velocidade*move << std::endl;
	std::cout << " nz: " << ((this->z)+cos(RAD(this->angulo))*this->velocidade*move) << " Inv nx: " << (this->x*-1)+sin(-RAD(this->angulo))*this->velocidade*move << std::endl;
	*/
	
	if( Fisica::canIgoThere(this->z*-1, this->x*-1, nz*-1, nx,true) ){
		this->IwannaGoTo(nz, nx*-1);
	}
}

void Guard::GoBack()
{
	GLfloat nx,nz;
	float move;
	move = this->MoveTest();
	if(move==0)
		return;
	nx=(this->x*-1)-sin(RAD(-this->angulo))*this->velocidade/this->tempo_reaccao;
	nz=(this->z)-cos(RAD(this->angulo))*this->velocidade/this->tempo_reaccao;
	
	if( Fisica::canIgoThere(this->z*-1, this->x*-1, nz*-1, nx,true) ){
		this->IwannaGoTo(nz, nx*-1);
	}
}

void Guard::GoTurnRight()
{
	float move;
	move = this->MoveTest();
	if(move==0)
		return;
	this->angulo+=3;
}

void Guard::GoTurnLeft()
{
	float move;
	move = this->MoveTest();
	if(move==0)
		return;
	this->angulo-=3;
}

