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

#include "DisplayConfigurationDialogView.h"

///////////////////////////////////////////////////////////////////////////

DisplayConfigurationDialogView::DisplayConfigurationDialogView( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* rootSizer;
	rootSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* labelSizer1;
	labelSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	instructionLabel1 = new wxStaticText( this, wxID_ANY, wxT("Please specify the displays which will be used in the experiment."), wxDefaultPosition, wxDefaultSize, 0 );
	instructionLabel1->Wrap( -1 );
	labelSizer1->Add( instructionLabel1, 0, wxLEFT|wxRIGHT|wxTOP, 5 );
	
	
	rootSizer->Add( labelSizer1, 0, wxEXPAND, 5 );
	
	wxBoxSizer* labelSizer2;
	labelSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	instructionLabel2 = new wxStaticText( this, wxID_ANY, wxT("We recommend NOT specifying display #1."), wxDefaultPosition, wxDefaultSize, 0 );
	instructionLabel2->Wrap( -1 );
	labelSizer2->Add( instructionLabel2, 0, wxLEFT|wxRIGHT, 5 );
	
	
	rootSizer->Add( labelSizer2, 0, wxEXPAND, 5 );
	
	wxBoxSizer* labelSizer3;
	labelSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	instructionLabel3 = new wxStaticText( this, wxID_ANY, wxT("Display #1 is generally used to control the experiment."), wxDefaultPosition, wxDefaultSize, 0 );
	instructionLabel3->Wrap( -1 );
	labelSizer3->Add( instructionLabel3, 0, wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	
	rootSizer->Add( labelSizer3, 1, wxEXPAND, 5 );
	
	wxBoxSizer* labelSizer4;
	labelSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	firstDisplayIndexLabel = new wxStaticText( this, wxID_ANY, wxT("Specify the first display to use:"), wxDefaultPosition, wxDefaultSize, 0 );
	firstDisplayIndexLabel->Wrap( -1 );
	labelSizer4->Add( firstDisplayIndexLabel, 0, wxALL, 5 );
	
	wxArrayString firstDisplayIndexChoices;
	firstDisplayIndex = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, firstDisplayIndexChoices, 0 );
	firstDisplayIndex->SetSelection( 0 );
	labelSizer4->Add( firstDisplayIndex, 0, wxALIGN_CENTER, 5 );
	
	
	rootSizer->Add( labelSizer4, 0, wxALIGN_RIGHT, 5 );
	
	wxBoxSizer* labelSizer5;
	labelSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	lastDisplayIndexLabel = new wxStaticText( this, wxID_ANY, wxT("Specify the last display to use:"), wxDefaultPosition, wxDefaultSize, 0 );
	lastDisplayIndexLabel->Wrap( -1 );
	labelSizer5->Add( lastDisplayIndexLabel, 0, wxALL, 5 );
	
	wxArrayString lastDisplayIndexChoices;
	lastDisplayIndex = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, lastDisplayIndexChoices, 0 );
	lastDisplayIndex->SetSelection( 0 );
	labelSizer5->Add( lastDisplayIndex, 0, wxALIGN_CENTER, 5 );
	
	
	rootSizer->Add( labelSizer5, 1, wxALIGN_RIGHT, 5 );
	
	wxBoxSizer* OkCancelSizer;
	OkCancelSizer = new wxBoxSizer( wxHORIZONTAL );
	
	okButton = new wxButton( this, wxID_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	OkCancelSizer->Add( okButton, 0, wxALL, 5 );
	
	cancelButton = new wxButton( this, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	OkCancelSizer->Add( cancelButton, 0, wxALL, 5 );
	
	
	rootSizer->Add( OkCancelSizer, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( rootSizer );
	this->Layout();
	rootSizer->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( DisplayConfigurationDialogView::OnExit ) );
	okButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DisplayConfigurationDialogView::OnOk ), NULL, this );
	cancelButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DisplayConfigurationDialogView::OnExit ), NULL, this );
}

DisplayConfigurationDialogView::~DisplayConfigurationDialogView()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( DisplayConfigurationDialogView::OnExit ) );
	okButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DisplayConfigurationDialogView::OnOk ), NULL, this );
	cancelButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DisplayConfigurationDialogView::OnExit ), NULL, this );
	
}
