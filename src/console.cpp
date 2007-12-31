/*
 *  console.cpp
 *  wolf
 *
 *  Created by zipleen on 12/29/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "console.h"

std::vector<std::string> Console::log;

void Console::addLine(char *s)
{
	Console::log.push_back(s);
#if DEBUG
	std::cout << s << std::endl;
#endif
}

void Console::addLine(std::string s)
{
	Console::log.push_back(s);
#if DEBUG
	std::cout << s << std::endl;
#endif
}

void Console::printf(char *fmt, ...)
{
	va_list argptr;
	char msg[1000];
		
	va_start(argptr,fmt);
	vsprintf(msg, fmt, argptr);
	va_end(argptr);
	
	Console::addLine(msg);
}

/*std::istream& operator>>( std::istream& is, const Console& c )
{
	Console::log.push_back(is.str());
	return is;
}*/
