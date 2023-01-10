#include "MainFrame.h"

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

    wxMenuItem* aboutItem = new wxMenuItem(helpMenu, wxID_ANY, wxString("About..."), wxString("Display about information"));
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
    topsizer->Add(
        new wxListBox(this, wxID_ANY, wxDefaultPosition, wxSize(100, 60)),
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        10);         // set border width to 10
    wxBoxSizer* button_sizer = new wxBoxSizer(wxHORIZONTAL);
    button_sizer->Add(
        new wxButton(this, wxID_OK, "Remove Border"),
        0,           // make horizontally unstretchable
        wxALL,       // make border all around (implicit top alignment)
        10);        // set border width to 10
    button_sizer->Add(
        new wxButton(this, wxID_CANCEL, "Cancel"),
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
