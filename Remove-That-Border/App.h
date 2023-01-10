#pragma once

#include "wx/wx.h"

#include "MainFrame.h"

class App : public wxApp
{
public:
	App();
	~App();
	virtual bool OnInit();

private:
	MainFrame* mainFrame;
};

