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

#include "DisplayConfigurationDialogView.h"

///////////////////////////////////////////////////////////////////////////

DisplayConfigurationDialogView::DisplayConfigurationDialogView( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* rootSizer;
	rootSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* line1Sizer;
	line1Sizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("There are"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	line1Sizer->Add( m_staticText2, 0, wxALL, 5 );
	
	m_numDisplays = new wxStaticText( this, wxID_ANY, wxT("NUMBER"), wxDefaultPosition, wxDefaultSize, 0 );
	m_numDisplays->Wrap( -1 );
	line1Sizer->Add( m_numDisplays, 0, wxBOTTOM|wxTOP, 5 );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("displays. ID's begin at 0 and continue to"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	line1Sizer->Add( m_staticText4, 0, wxALL, 5 );
	
	m_maxDisplayIndex = new wxStaticText( this, wxID_ANY, wxT("NUMBER"), wxDefaultPosition, wxDefaultSize, 0 );
	m_maxDisplayIndex->Wrap( -1 );
	line1Sizer->Add( m_maxDisplayIndex, 0, wxBOTTOM|wxRIGHT|wxTOP, 5 );
	
	
	rootSizer->Add( line1Sizer, 0, wxEXPAND, 5 );
	
	wxBoxSizer* line2Sizer;
	line2Sizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Specify which displays to use:   First Display ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	line2Sizer->Add( m_staticText6, 0, wxALL, 5 );
	
	m_firstDisplayIndex = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_firstDisplayIndex->SetMaxSize( wxSize( 30,-1 ) );
	
	line2Sizer->Add( m_firstDisplayIndex, 0, wxALIGN_CENTER, 5 );
	
	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT(", Last Display ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	line2Sizer->Add( m_staticText7, 0, wxALL, 5 );
	
	m_lastDisplayIndex = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_lastDisplayIndex->SetMaxSize( wxSize( 30,-1 ) );
	
	line2Sizer->Add( m_lastDisplayIndex, 0, wxALIGN_CENTER, 5 );
	
	
	rootSizer->Add( line2Sizer, 0, wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	rootSizer->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* line3Sizer;
	line3Sizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("It is recommended that you use the suggested defaults."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	line3Sizer->Add( m_staticText9, 0, wxALL, 5 );
	
	
	rootSizer->Add( line3Sizer, 0, wxEXPAND, 5 );
	
	wxBoxSizer* line4Sizer;
	line4Sizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("To make resolution changes. Press Unlock --->"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	line4Sizer->Add( m_staticText10, 0, wxALL, 5 );
	
	m_unlockModificationButton = new wxButton( this, wxID_ANY, wxT("Unlock"), wxDefaultPosition, wxDefaultSize, 0 );
	line4Sizer->Add( m_unlockModificationButton, 0, wxALIGN_CENTER, 5 );
	
	
	rootSizer->Add( line4Sizer, 0, wxEXPAND, 5 );
	
	wxGridSizer* confButtonGridSizer;
	confButtonGridSizer = new wxGridSizer( 3, 3, 0, 0 );
	
	
	rootSizer->Add( confButtonGridSizer, 0, wxALL, 1 );
	
	wxBoxSizer* OkCancelSizer;
	OkCancelSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_okButton = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	OkCancelSizer->Add( m_okButton, 0, wxALL, 5 );
	
	m_cancelButton = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	OkCancelSizer->Add( m_cancelButton, 0, wxALL, 5 );
	
	
	rootSizer->Add( OkCancelSizer, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( rootSizer );
	this->Layout();
	rootSizer->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(DisplayConfigurationDialogView::OnExit));
	m_unlockModificationButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DisplayConfigurationDialogView::OnUnlock ), NULL, this );
	m_okButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DisplayConfigurationDialogView::OnOk ), NULL, this );
	m_cancelButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DisplayConfigurationDialogView::OnExit ), NULL, this );
}

DisplayConfigurationDialogView::~DisplayConfigurationDialogView()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( DisplayConfigurationDialogView::OnExit ) );
	m_unlockModificationButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DisplayConfigurationDialogView::OnUnlock ), NULL, this );
	m_okButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DisplayConfigurationDialogView::OnOk ), NULL, this );
	m_cancelButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DisplayConfigurationDialogView::OnExit ), NULL, this );
	
}
