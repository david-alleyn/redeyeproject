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
	this->SetSizeHints( wxSize( 500,300 ), wxDefaultSize );
	
	wxBoxSizer* rootSizer;
	rootSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* topSizer;
	topSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_displayConfButton = new wxButton( this, wxID_ANY, wxT("Display\nConfiguration"), wxDefaultPosition, wxDefaultSize, 0 );
	topSizer->Add( m_displayConfButton, 0, wxALL, 5 );
	
	m_experimentConfButton = new wxButton( this, wxID_ANY, wxT("Experiment\nConfiguration"), wxDefaultPosition, wxDefaultSize, 0 );
	topSizer->Add( m_experimentConfButton, 0, wxALL, 5 );
	
	m_runExperimentButton = new wxButton( this, wxID_ANY, wxT("Run\nExperiment"), wxDefaultPosition, wxDefaultSize, 0 );
	topSizer->Add( m_runExperimentButton, 0, wxALL, 5 );
	
	
	rootSizer->Add( topSizer, 0, wxALIGN_CENTER, 5 );
	
	wxBoxSizer* topSizer1;
	topSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	m_loadConfButton = new wxButton( this, wxID_ANY, wxT("Load\nConfiguration"), wxDefaultPosition, wxDefaultSize, 0 );
	topSizer1->Add( m_loadConfButton, 0, wxALL, 5 );
	
	m_saveConfButton = new wxButton( this, wxID_ANY, wxT("Save\nConfiguration"), wxDefaultPosition, wxDefaultSize, 0 );
	topSizer1->Add( m_saveConfButton, 0, wxALL, 5 );
	
	m_stageExperimentButton = new wxButton( this, wxID_ANY, wxT("Stage\nExperiment"), wxDefaultPosition, wxDefaultSize, 0 );
	topSizer1->Add( m_stageExperimentButton, 0, wxALL, 5 );
	
	
	rootSizer->Add( topSizer1, 0, wxALIGN_CENTER, 5 );
	
	wxBoxSizer* bottomSizer;
	bottomSizer = new wxBoxSizer( wxVERTICAL );
	
	m_logTextTitle = new wxStaticText( this, wxID_ANY, wxT("The Program Log"), wxDefaultPosition, wxDefaultSize, 0 );
	m_logTextTitle->Wrap( -1 );
	bottomSizer->Add( m_logTextTitle, 0, wxLEFT|wxRIGHT|wxTOP, 5 );
	
	m_logTextControl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	bottomSizer->Add( m_logTextControl, 1, wxALL|wxEXPAND, 5 );
	
	
	rootSizer->Add( bottomSizer, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( rootSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_displayConfButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnDisplayConfiguration ), NULL, this );
	m_experimentConfButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnExperimentConfiguration ), NULL, this );
	m_runExperimentButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnRunExperiment ), NULL, this );
	m_loadConfButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnLoadConfiguration ), NULL, this );
	m_saveConfButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnSaveConfiguration ), NULL, this );
	m_stageExperimentButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnStageExperiment ), NULL, this );
}

MainWindowView::~MainWindowView()
{
	// Disconnect Events
	m_displayConfButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnDisplayConfiguration ), NULL, this );
	m_experimentConfButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnExperimentConfiguration ), NULL, this );
	m_runExperimentButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnRunExperiment ), NULL, this );
	m_loadConfButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnLoadConfiguration ), NULL, this );
	m_saveConfButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnSaveConfiguration ), NULL, this );
	m_stageExperimentButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnStageExperiment ), NULL, this );
	
}
