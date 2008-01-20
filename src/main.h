/*
 *  main.h
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef MAIN_H
#define MAIN_H

#ifdef WIN32
#include "Windows Project\stdafx.h"
#endif

#include "rendering.h"
//descomentar a linha para ir ao menu
//#include "menu.h"
#include "game.h"
#include "player.h"
#include "console.h"
#include <iostream>

extern Player *p;

#endif
