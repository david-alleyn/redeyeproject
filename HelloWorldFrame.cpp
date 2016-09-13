// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "HelloWorldFrame.h"

//EVT_MENU(ID_Hello, MyFrame::OnHello)
//EVT_MENU(wxID_EXIT, MyFrame::OnExit)
//EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, pos, size)
{
	Bind(wxEVT_COMMAND_MENU_SELECTED, &MyFrame::OnHello, this, ID_Hello);
	Bind(wxEVT_COMMAND_MENU_SELECTED, &MyFrame::OnExit, this, wxID_EXIT);
	Bind(wxEVT_COMMAND_MENU_SELECTED, &MyFrame::OnAbout, this, wxID_ABOUT);

	wxMenu *menuFile = new wxMenu;
	menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",	"Help string shown in status bar for this menu item");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);
	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);
	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuHelp, "&Help");
	SetMenuBar(menuBar);
	CreateStatusBar();
	SetStatusText("Welcome to wxWidgets!");

	wxBoxSizer *verticalSizer = new wxBoxSizer(wxVERTICAL);
	
	wxBoxSizer *verticalSizerTop = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer *verticalSizerBottom = new wxBoxSizer(wxVERTICAL);

	verticalSizer->Add(verticalSizerTop, 1, wxEXPAND, 5);
	verticalSizer->Add(verticalSizerBottom, 1, wxEXPAND, 5);

	this->SetSizer(verticalSizer);
	this->Layout();
	this->Center();

	verticalSizerTop->Add(new wxButton(this, wxID_ANY, "newButton"), 0, wxALIGN_CENTER | wxALL, 5);
	verticalSizerBottom->Add(new wxButton(this, wxID_ANY, "newButton"), 0, wxALIGN_CENTER | wxALL, 5);
}
void MyFrame::OnExit(wxCommandEvent& event)
{
	Close(true);
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox("This is a wxWidgets' Hello world sample",
		"About Hello World", wxOK | wxICON_INFORMATION);
}
void MyFrame::OnHello(wxCommandEvent& event)
{
	wxLogMessage("Hello world from wxWidgets! AAAAAAAAAAA");
}