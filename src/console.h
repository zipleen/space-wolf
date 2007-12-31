/*
 *  console.h
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>
#include <vector>
#include <iostream>

#ifdef WIN32
#include<windows.h>
#include <stdio.h>
#include <wchar.h>
#include <wtypes.h>
#include <stdarg.h>
#endif

class Console
{
private:
	static std::vector<std::string> log;
	
public:
	Console(){}; 
	virtual ~Console(){};
	
	static void addLine(char *s);
	static void addLine(std::string s);
	static void Console::printf(char *fmt, ...);
	//friend std::istream& operator>>( std::istream& is, const Console& c );
};

#endif