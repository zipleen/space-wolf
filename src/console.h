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