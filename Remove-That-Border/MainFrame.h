#pragma once

#include "wx/wx.h"

class MainFrame : public wxFrame
{
public:
	MainFrame();
	~MainFrame();

private:
	void OnAboutPressed(wxCommandEvent& evt);
	
	wxDECLARE_EVENT_TABLE();
};

