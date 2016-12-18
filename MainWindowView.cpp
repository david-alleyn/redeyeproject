///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 14 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "MainWindowView.h"

///////////////////////////////////////////////////////////////////////////

MainWindowView::MainWindowView( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 500,300 ), wxDefaultSize );
	
	wxBoxSizer* rootSizer;
	rootSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* topSizer;
	topSizer = new wxBoxSizer( wxHORIZONTAL );
	
	displayConfButton = new wxButton( this, wxID_ANY, wxT("Display\nConfiguration"), wxDefaultPosition, wxDefaultSize, 0 );
	topSizer->Add( displayConfButton, 0, wxALL, 5 );
	
	experimentConfButton = new wxButton( this, wxID_ANY, wxT("Experiment\nConfiguration"), wxDefaultPosition, wxDefaultSize, 0 );
	topSizer->Add( experimentConfButton, 0, wxALL, 5 );
	
	runExperimentButton = new wxButton( this, wxID_ANY, wxT("Run\nExperiment"), wxDefaultPosition, wxDefaultSize, 0 );
	topSizer->Add( runExperimentButton, 0, wxALL, 5 );
	
	
	rootSizer->Add( topSizer, 0, wxALIGN_CENTER, 5 );
	
	wxBoxSizer* topSizer1;
	topSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	loadConfButton = new wxButton( this, wxID_ANY, wxT("Load\nConfiguration"), wxDefaultPosition, wxDefaultSize, 0 );
	topSizer1->Add( loadConfButton, 0, wxALL, 5 );
	
	saveConfButton = new wxButton( this, wxID_ANY, wxT("Save\nConfiguration"), wxDefaultPosition, wxDefaultSize, 0 );
	topSizer1->Add( saveConfButton, 0, wxALL, 5 );
	
	stageExperimentButton = new wxButton( this, wxID_ANY, wxT("Stage\nExperiment"), wxDefaultPosition, wxDefaultSize, 0 );
	topSizer1->Add( stageExperimentButton, 0, wxALL, 5 );
	
	
	rootSizer->Add( topSizer1, 0, wxALIGN_CENTER, 5 );
	
	wxBoxSizer* bottomSizer;
	bottomSizer = new wxBoxSizer( wxVERTICAL );
	
	logTextTitle = new wxStaticText( this, wxID_ANY, wxT("The Program Log"), wxDefaultPosition, wxDefaultSize, 0 );
	logTextTitle->Wrap( -1 );
	bottomSizer->Add( logTextTitle, 0, wxLEFT|wxRIGHT|wxTOP, 5 );
	
	logTextControl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	bottomSizer->Add( logTextControl, 1, wxALL|wxEXPAND, 5 );
	
	
	rootSizer->Add( bottomSizer, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( rootSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	displayConfButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnDisplayConfiguration ), NULL, this );
	experimentConfButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnExperimentConfiguration ), NULL, this );
	runExperimentButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnRunExperiment ), NULL, this );
	loadConfButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnLoadConfiguration ), NULL, this );
	saveConfButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnSaveConfiguration ), NULL, this );
	stageExperimentButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnStageExperiment ), NULL, this );
}

MainWindowView::~MainWindowView()
{
	// Disconnect Events
	displayConfButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnDisplayConfiguration ), NULL, this );
	experimentConfButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnExperimentConfiguration ), NULL, this );
	runExperimentButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnRunExperiment ), NULL, this );
	loadConfButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnLoadConfiguration ), NULL, this );
	saveConfButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnSaveConfiguration ), NULL, this );
	stageExperimentButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnStageExperiment ), NULL, this );
	
}
