#pragma once

#include "wx/wx.h"

#include "WindowManager.h"

class MainFrame : public wxFrame
{
public:
	MainFrame();
	~MainFrame();

private:
	WindowManager windowManager;
	wxListBox* windowList;

	void RefreshWindowList();

	void OnAboutPressed(wxCommandEvent& evt);
	void OnUpdateListPressed(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

