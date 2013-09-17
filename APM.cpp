// APM.cpp : main project file.

#include "stdafx.h"
//#include "Form1.h"
#include "ProcessIcon.h"

using namespace APM;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 


	ProcessIcon^ pi;
	try
	{
		pi = gcnew ProcessIcon();
		pi->Display();
		// Create the main window and run it
		Application::Run();
	}
	finally
	{
	  if (pi != nullptr)
		delete pi;
	}

	//ProcessIcon^ pi = gcnew ProcessIcon();
	//pi->Display();
	//// Create the main window and run it
	//Application::Run();	//Application::Run(gcnew Form1()); 
	return 0;
}
