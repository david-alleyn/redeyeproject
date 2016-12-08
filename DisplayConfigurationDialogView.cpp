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
	
	wxBoxSizer* line1Sizer1;
	line1Sizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText41 = new wxStaticText( this, wxID_ANY, wxT("Please specify the displays which will be used in the experiment."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText41->Wrap( -1 );
	line1Sizer1->Add( m_staticText41, 0, wxLEFT|wxRIGHT|wxTOP, 5 );
	
	
	rootSizer->Add( line1Sizer1, 0, wxEXPAND, 5 );
	
	wxBoxSizer* line1Sizer;
	line1Sizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("We recommend NOT specifying display #1."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	line1Sizer->Add( m_staticText4, 0, wxLEFT|wxRIGHT, 5 );
	
	
	rootSizer->Add( line1Sizer, 0, wxEXPAND, 5 );
	
	wxBoxSizer* line1Sizer2;
	line1Sizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText42 = new wxStaticText( this, wxID_ANY, wxT("Display #1 is generally used to control the experiment."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText42->Wrap( -1 );
	line1Sizer2->Add( m_staticText42, 0, wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	
	rootSizer->Add( line1Sizer2, 1, wxEXPAND, 5 );
	
	wxBoxSizer* line2Sizer;
	line2Sizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Specify the first display to use:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	line2Sizer->Add( m_staticText6, 0, wxALL, 5 );
	
	wxArrayString firstDisplayIndexChoices;
	firstDisplayIndex = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, firstDisplayIndexChoices, 0 );
	firstDisplayIndex->SetSelection( 0 );
	line2Sizer->Add( firstDisplayIndex, 0, wxALIGN_CENTER, 5 );
	
	
	rootSizer->Add( line2Sizer, 0, wxALIGN_RIGHT, 5 );
	
	wxBoxSizer* line2Sizer1;
	line2Sizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText61 = new wxStaticText( this, wxID_ANY, wxT("Specify the last display to use:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText61->Wrap( -1 );
	line2Sizer1->Add( m_staticText61, 0, wxALL, 5 );
	
	wxArrayString lastDisplayIndexChoices;
	lastDisplayIndex = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, lastDisplayIndexChoices, 0 );
	lastDisplayIndex->SetSelection( 0 );
	line2Sizer1->Add( lastDisplayIndex, 0, wxALIGN_CENTER, 5 );
	
	
	rootSizer->Add( line2Sizer1, 1, wxALIGN_RIGHT, 5 );
	
	wxBoxSizer* OkCancelSizer;
	OkCancelSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_okButton = new wxButton( this, wxID_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	OkCancelSizer->Add( m_okButton, 0, wxALL, 5 );
	
	m_cancelButton = new wxButton( this, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	OkCancelSizer->Add( m_cancelButton, 0, wxALL, 5 );
	
	
	rootSizer->Add( OkCancelSizer, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( rootSizer );
	this->Layout();
	rootSizer->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( DisplayConfigurationDialogView::OnExit ) );
	m_okButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DisplayConfigurationDialogView::OnOk ), NULL, this );
	m_cancelButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DisplayConfigurationDialogView::OnExit ), NULL, this );
}

DisplayConfigurationDialogView::~DisplayConfigurationDialogView()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( DisplayConfigurationDialogView::OnExit ) );
	m_okButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DisplayConfigurationDialogView::OnOk ), NULL, this );
	m_cancelButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DisplayConfigurationDialogView::OnExit ), NULL, this );
	
}
