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
	
	m_menubar = new wxMenuBar( 0 );
	m_fileMenu = new wxMenu();
	wxMenuItem* m_loadConfItem;
	m_loadConfItem = new wxMenuItem( m_fileMenu, wxID_ANY, wxString( wxT("Load Configuration") ) , wxEmptyString, wxITEM_NORMAL );
	m_fileMenu->Append( m_loadConfItem );
	
	wxMenuItem* m_saveConfItem;
	m_saveConfItem = new wxMenuItem( m_fileMenu, wxID_ANY, wxString( wxT("Save Configuration") ) , wxEmptyString, wxITEM_NORMAL );
	m_fileMenu->Append( m_saveConfItem );
	
	m_menubar->Append( m_fileMenu, wxT("File") ); 
	
	this->SetMenuBar( m_menubar );
	
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
	
	wxBoxSizer* bottomSizer;
	bottomSizer = new wxBoxSizer( wxVERTICAL );
	
	m_logTextTitle = new wxStaticText( this, wxID_ANY, wxT("The Output Window"), wxDefaultPosition, wxDefaultSize, 0 );
	m_logTextTitle->Wrap( -1 );
	bottomSizer->Add( m_logTextTitle, 0, wxLEFT|wxRIGHT|wxTOP, 5 );
	
	m_logTextControl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bottomSizer->Add( m_logTextControl, 1, wxALL|wxEXPAND, 5 );
	
	
	rootSizer->Add( bottomSizer, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( rootSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( m_loadConfItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindowView::OnLoadConfiguration ) );
	this->Connect( m_saveConfItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindowView::OnSaveConfiguration ) );
	m_displayConfButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnDisplayConfiguration ), NULL, this );
	m_experimentConfButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnExperimentConfiguration ), NULL, this );
	m_runExperimentButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnRunExperiment ), NULL, this );
}

MainWindowView::~MainWindowView()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindowView::OnLoadConfiguration ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindowView::OnSaveConfiguration ) );
	m_displayConfButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnDisplayConfiguration ), NULL, this );
	m_experimentConfButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnExperimentConfiguration ), NULL, this );
	m_runExperimentButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindowView::OnRunExperiment ), NULL, this );
	
}
