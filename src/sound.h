/*
 *  sound.h
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SOUND_H
#define SOUND_H

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <cmath>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "fisica.h"

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif
#define RAD(x)          (M_PI*(x)/180)
#define GRAUS(x)        (180*(x)/M_PI)

class Sound
{
protected:
	
public:
	static Sound *m_soundSingleton;
	std::map<std::string, Mix_Chunk *> sons;
	
	int audio_rate;
	Uint16 audio_format; 
	int audio_channels;
	int audio_buffers;
	
	float player_x, player_z, player_ang;
	
	Sound(); 
	virtual ~Sound(){};
	static Sound *GetInstance( void )
	{
		if( m_soundSingleton == 0 )
			m_soundSingleton = new Sound;
		
		return ((Sound *)m_soundSingleton);
	}
	
	static void Kill( void )
	{
		if( m_soundSingleton != 0 )
		{
			delete m_soundSingleton;
			m_soundSingleton = 0;
		}
	}

	void shutdown();
	Mix_Chunk* loadSound(std::string path);
	int playSoundDirect(Mix_Chunk *s);
	int playSound(Mix_Chunk *s, float obj_x, float obj_y, float ang);
};

#endif
