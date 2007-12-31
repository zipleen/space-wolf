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
#include "game.h"
#include "player.h"
#include "console.h"
#include <iostream>

extern Rendering *r;
extern Game *g;
extern Player *p;

#endif
