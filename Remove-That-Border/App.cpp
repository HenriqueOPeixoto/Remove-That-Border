#include "App.h"

wxIMPLEMENT_APP(App);

App::App()
{
}

App::~App()
{
}

bool App::OnInit()
{
	mainFrame = new MainFrame();
	mainFrame->Show();
	return true;
}
