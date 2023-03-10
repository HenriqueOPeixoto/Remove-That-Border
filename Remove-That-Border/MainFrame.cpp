#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_MENU(wxID_ABOUT, MainFrame::OnAboutPressed)
EVT_BUTTON(wxID_REFRESH, MainFrame::OnUpdateListPressed)
EVT_BUTTON(wxID_OK, MainFrame::OnRemoveBorderPressed)
wxEND_EVENT_TABLE()

MainFrame::MainFrame() : wxFrame(
	nullptr, //parent
	wxID_ANY,  //id
	"Remove That Border", // title
	wxDefaultPosition, //pos
	wxSize(640, 480)) //size
	//wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)) //style ( not resizable )
{
	// Window constructor method begins here! -----
		
    wxMenuBar* menu = new wxMenuBar();

    wxMenu* helpMenu = new wxMenu();
    menu->Append(helpMenu, wxString("Help"));

    wxMenuItem* aboutItem = new wxMenuItem(helpMenu, wxID_ABOUT, wxString("About..."), wxString("Display about information"));
    helpMenu->Append(aboutItem);

    this->SetMenuBar(menu);

    wxBoxSizer* topsizer = new wxBoxSizer(wxVERTICAL);
    topsizer->Add(
        new wxStaticText(this, wxID_ANY, "Choose a window to remove borders:", wxDefaultPosition, wxDefaultSize),
        0,
        wxEXPAND |
        wxALL,
        10
    );
    windowList = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxSize(100, 60));
    topsizer->Add(
        windowList,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        10);         // set border width to 10
    RefreshWindowList();
    wxBoxSizer* button_sizer = new wxBoxSizer(wxHORIZONTAL);
    button_sizer->Add(
        new wxButton(this, wxID_OK, "Remove Border"),
        0,           // make horizontally unstretchable
        wxALL,       // make border all around (implicit top alignment)
        10);        // set border width to 10
    button_sizer->Add(
        new wxButton(this, wxID_REFRESH, "Update List"),
        0,           // make horizontally unstretchable
        wxALL,       // make border all around (implicit top alignment)
        10);        // set border width to 10
    topsizer->Add(
        button_sizer,
        0,                // make vertically unstretchable
        wxALIGN_CENTER); // no border and centre horizontally
    //SetSizerAndFit(topsizer); // use the sizer for layout and size window
                              // accordingly and prevent it from being resized
                              // to smaller size
    SetSizer(topsizer);

}

MainFrame::~MainFrame()
{
}

void MainFrame::RefreshWindowList()
{
    windowList->Clear();

    windows = windowManager.GetOpenWindows();

    for (std::wstring window : windows)
    {
        windowList->Append(window);
    }
}

void MainFrame::OnAboutPressed(wxCommandEvent& evt)
{
    wxMessageBox("Remove That Border\nMade by HenriqueOPeixoto\nGithub Repo: github.com/HenriqueOPeixoto/Remove-That-Border", "About", wxICON_INFORMATION);
}

void MainFrame::OnUpdateListPressed(wxCommandEvent& evt)
{
    RefreshWindowList();
}

void MainFrame::OnRemoveBorderPressed(wxCommandEvent& evt)
{
    windowManager.RemoveBorderFromWindow(windows[windowList->GetSelection()]);
}
