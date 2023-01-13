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
	std::vector<std::wstring> windows;
	wxListBox* windowList;

	void RefreshWindowList();

	void OnAboutPressed(wxCommandEvent& evt);
	void OnUpdateListPressed(wxCommandEvent& evt);
	void OnRemoveBorderPressed(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

