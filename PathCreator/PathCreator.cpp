// PathCreator.cpp : main project file.

#include "stdafx.h"
#include "global.h"
#include "HomeWindow.h"

using namespace PathCreator;

#pragma warning(disable:4075)
#pragma warning(disable:4996)
#pragma warning(disable:4018)
#pragma warning(disable:4049)

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Load resource images
	LoadResourceImages();

	// Set-up GraphicsMagick++
	Magick::InitializeMagick(nullptr);

	// Load ProgramSettings
	String^ msg = nullptr;

	if (File::Exists("settings"))
	{
		global::Settings = gcnew ProgramSettings();
		global::Settings->Open(msg);
	}
	else
	{
		global::Settings = ProgramSettings::CreateDefault(msg);
	}

	global::PreInitMessage = msg;

	global::IsDarkHorizons = false;

	// Create the main window and run it
	Application::Run(gcnew HomeWindow());

	if (global::Settings->SaveOnExit)
		global::Settings->Save();

	return 0;
}
