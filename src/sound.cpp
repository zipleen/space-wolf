/*
 *  sound.cpp
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "sound.h"
#include "console.h"

Sound *Sound::m_soundSingleton = NULL;

Sound::Sound()
{
	this->audio_rate = 44100;
	this->audio_format = AUDIO_S16;
	this->audio_channels = 2;
	this->audio_buffers = 4096;
	
	if(Mix_OpenAudio(this->audio_rate, this->audio_format, this->audio_channels, this->audio_buffers)) {
		Console::addLine("Unable to open audio!");
		return;
	}
	
}

void Sound::shutdown()
{
	Mix_CloseAudio();	
}

Mix_Chunk* Sound::loadSound(const char *path)
{
	return Mix_LoadWAV(path);
}

/*
 * Quando nao precisamos de calcular o volume do som, pois somos nos que o estamos a fazer
 *  tipo apanhar items, nossos passos, disparar nossas balas
 */
int Sound::playSoundDirect(Mix_Chunk *s)
{
	return Mix_PlayChannel(-1, s, 0);
}

int Sound::playSound(Mix_Chunk *s, float obj_z, float obj_x)
{
	
	// eh necessario calcular o angulo e a distancia da posicao do gajo
	// distancia pode-se calcular usando
	//x1-x2=x   z1-z2=z
	//sqrt(x*x +  z*z) -> talvez nao usando o sqrt e dividindo por um numero maior
	// angulo
	//	invcos(A * B)
	
	// distancia
	float z = this->player_z - obj_z;
	float x = this->player_x - obj_x;
	int dist = sqrt(z*z + x*x)*3/2;
	std::cout << "dist: " << dist << std::endl;
	if(dist < 250){
		int canal = Mix_PlayChannel(-1, s, 0);
		Mix_SetDistance ( canal, dist );
		return canal;
	}else return 0;
	
	/* quando souber fazer o angulo com estes 2 valores, posso usar isto....
	 int angulo = GRAUS(acos(this->player_z * obj_z + this->player_x * obj_x));
	std::cout << "angulo: "<< angulo << std::endl;
	Mix_SetPosition ( canal, angulo, dist );*/
	
}