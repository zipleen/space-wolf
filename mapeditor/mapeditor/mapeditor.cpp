// mapeditor.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"

using namespace mapeditor;
int mapeditor::codemap[64][64];
int mapeditor::codefloormap[64][64];
int mapeditor::codigo_a_por;
int mapeditor::floorcodigo_a_por;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}
