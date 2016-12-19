///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
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
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );
	
	wxBoxSizer* rootSizer;
	rootSizer = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* displayConfSizer2;
	displayConfSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* displayConfSizerLeft;
	displayConfSizerLeft = new wxBoxSizer( wxVERTICAL );
	
	displayConfSizerLeft->SetMinSize( wxSize( 220,-1 ) ); 
	wxBoxSizer* displayConfSizer;
	displayConfSizer = new wxBoxSizer( wxHORIZONTAL );
	
	instructionLabel1 = new wxStaticText( this, wxID_ANY, wxT("Step 1:"), wxDefaultPosition, wxDefaultSize, 0 );
	instructionLabel1->Wrap( -1 );
	displayConfSizer->Add( instructionLabel1, 0, wxALIGN_CENTER|wxALL, 5 );
	
	displayConfButton = new wxButton( this, wxID_ANY, wxT("Display\nConfiguration"), wxDefaultPosition, wxDefaultSize, 0 );
	displayConfSizer->Add( displayConfButton, 0, wxALL, 5 );
	
	
	displayConfSizerLeft->Add( displayConfSizer, 0, wxALIGN_CENTER, 5 );
	
	wxBoxSizer* displayConfSizer1;
	displayConfSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	instructionLabel2 = new wxStaticText( this, wxID_ANY, wxT("Step 2:"), wxDefaultPosition, wxDefaultSize, 0 );
	instructionLabel2->Wrap( -1 );
	displayConfSizer1->Add( instructionLabel2, 0, wxALIGN_CENTER|wxALL, 5 );
	
	experimentConfButton = new wxButton( this, wxID_ANY, wxT("Experiment\nConfiguration"), wxDefaultPosition, wxDefaultSize, 0 );
	displayConfSizer1->Add( experimentConfButton, 0, wxALL, 5 );
	
	
	displayConfSizerLeft->Add( displayConfSizer1, 0, wxALIGN_CENTER, 5 );
	
	wxBoxSizer* displayConfSizer3;
	displayConfSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	instructionLabel3 = new wxStaticText( this, wxID_ANY, wxT("Step 3:"), wxDefaultPosition, wxDefaultSize, 0 );
	instructionLabel3->Wrap( -1 );
	displayConfSizer3->Add( instructionLabel3, 0, wxALIGN_CENTER|wxALL, 5 );
	
	stageExperimentButton = new wxButton( this, wxID_ANY, wxT("Stage\nExperiment"), wxDefaultPosition, wxDefaultSize, 0 );
	displayConfSizer3->Add( stageExperimentButton, 0, wxALL, 5 );
	
	
	displayConfSizerLeft->Add( displayConfSizer3, 0, wxALIGN_CENTER, 5 );
	
	wxBoxSizer* displayConfSizer4;
	displayConfSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	instructionLabel4 = new wxStaticText( this, wxID_ANY, wxT("Step 4:"), wxDefaultPosition, wxDefaultSize, 0 );
	instructionLabel4->Wrap( -1 );
	displayConfSizer4->Add( instructionLabel4, 0, wxALIGN_CENTER|wxALL, 5 );
	
	runExperimentButton = new wxButton( this, wxID_ANY, wxT("Run\nExperiment"), wxDefaultPosition, wxDefaultSize, 0 );
	displayConfSizer4->Add( runExperimentButton, 0, wxALL, 5 );
	
	
	displayConfSizerLeft->Add( displayConfSizer4, 0, wxALIGN_CENTER, 5 );
	
	wxBoxSizer* topSizer1;
	topSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	loadConfButton = new wxButton( this, wxID_ANY, wxT("Load\nConfiguration"), wxDefaultPosition, wxDefaultSize, 0 );
	topSizer1->Add( loadConfButton, 0, wxALL, 5 );
	
	saveConfButton = new wxButton( this, wxID_ANY, wxT("Save\nConfiguration"), wxDefaultPosition, wxDefaultSize, 0 );
	topSizer1->Add( saveConfButton, 0, wxALL, 5 );
	
	
	displayConfSizerLeft->Add( topSizer1, 0, wxALIGN_CENTER, 5 );
	
	
	displayConfSizer2->Add( displayConfSizerLeft, 0, wxEXPAND, 5 );
	
	wxBoxSizer* displayConfSizerRight;
	displayConfSizerRight = new wxBoxSizer( wxVERTICAL );
	
	displayConfSizerRight->SetMinSize( wxSize( 350,-1 ) ); 
	wxBoxSizer* bottomSizer;
	bottomSizer = new wxBoxSizer( wxVERTICAL );
	
	logTextTitle = new wxStaticText( this, wxID_ANY, wxT("The Program Log"), wxDefaultPosition, wxDefaultSize, 0 );
	logTextTitle->Wrap( -1 );
	bottomSizer->Add( logTextTitle, 0, wxLEFT|wxRIGHT|wxTOP, 5 );
	
	logTextControl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	bottomSizer->Add( logTextControl, 1, wxALL|wxEXPAND, 5 );
	
	
	displayConfSizerRight->Add( bottomSizer, 1, wxEXPAND, 5 );
	
	
	displayConfSizer2->Add( displayConfSizerRight, 0, wxEXPAND, 5 );
	
	
	rootSizer->Add( displayConfSizer2, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( rootSizer );
	this->Layout();
	rootSizer->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	displayConfButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnDisplayConfiguration ), NULL, this );
	experimentConfButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnExperimentConfiguration ), NULL, this );
	stageExperimentButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnStageExperiment ), NULL, this );
	runExperimentButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnRunExperiment ), NULL, this );
	loadConfButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnLoadConfiguration ), NULL, this );
	saveConfButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnSaveConfiguration ), NULL, this );
}

MainWindowView::~MainWindowView()
{
	// Disconnect Events
	displayConfButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnDisplayConfiguration ), NULL, this );
	experimentConfButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnExperimentConfiguration ), NULL, this );
	stageExperimentButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnStageExperiment ), NULL, this );
	runExperimentButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnRunExperiment ), NULL, this );
	loadConfButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnLoadConfiguration ), NULL, this );
	saveConfButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnSaveConfiguration ), NULL, this );
	
}
