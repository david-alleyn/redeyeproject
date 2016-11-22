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

#include "ExperimentConfigurationDialogView.h"

///////////////////////////////////////////////////////////////////////////

ExperimentConfigurationDialogView::ExperimentConfigurationDialogView( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* rootSizer;
	rootSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* editorColumnsSizer;
	editorColumnsSizer = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* editorParametersSizer;
	editorParametersSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* editorColumnsSizer1;
	editorColumnsSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText23 = new wxStaticText( this, wxID_ANY, wxT("Experiment Parameters"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	editorColumnsSizer1->Add( m_staticText23, 0, wxALL, 5 );
	
	wxBoxSizer* durationSizer;
	durationSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Experiment Duration:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	durationSizer->Add( m_staticText2, 0, wxALL, 5 );
	
	wxArrayString experimentDurationChoices;
	experimentDuration = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, experimentDurationChoices, 0 );
	experimentDuration->SetSelection( 0 );
	experimentDuration->SetMinSize( wxSize( 200,-1 ) );
	
	durationSizer->Add( experimentDuration, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Time in Seconds:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	durationSizer->Add( m_staticText3, 0, wxALL, 5 );
	
	timeInSeconds = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	timeInSeconds->Enable( false );
	timeInSeconds->SetMinSize( wxSize( 60,-1 ) );
	
	durationSizer->Add( timeInSeconds, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorColumnsSizer1->Add( durationSizer, 0, wxEXPAND, 5 );
	
	wxBoxSizer* movingObjectionSizer;
	movingObjectionSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText22 = new wxStaticText( this, wxID_ANY, wxT("Moving Object Type:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	movingObjectionSizer->Add( m_staticText22, 0, wxALL, 5 );
	
	wxArrayString movingObjectTypeChoices;
	movingObjectType = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, movingObjectTypeChoices, 0 );
	movingObjectType->SetSelection( 0 );
	movingObjectType->SetMinSize( wxSize( 200,-1 ) );
	
	movingObjectionSizer->Add( movingObjectType, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorColumnsSizer1->Add( movingObjectionSizer, 0, wxEXPAND, 5 );
	
	wxBoxSizer* numberOfObjectsSizer;
	numberOfObjectsSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText22221 = new wxStaticText( this, wxID_ANY, wxT("Number of Objects:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22221->Wrap( -1 );
	numberOfObjectsSizer->Add( m_staticText22221, 0, wxALL, 5 );
	
	numberOfObjects = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	numberOfObjectsSizer->Add( numberOfObjects, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorColumnsSizer1->Add( numberOfObjectsSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* sizeOfObjectsSizer;
	sizeOfObjectsSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText222211 = new wxStaticText( this, wxID_ANY, wxT("Size of Objects:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText222211->Wrap( -1 );
	sizeOfObjectsSizer->Add( m_staticText222211, 0, wxALL, 5 );
	
	sizeOfObjects = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sizeOfObjectsSizer->Add( sizeOfObjects, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorColumnsSizer1->Add( sizeOfObjectsSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* objectColourSizer;
	objectColourSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText221 = new wxStaticText( this, wxID_ANY, wxT("Object Colour:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText221->Wrap( -1 );
	objectColourSizer->Add( m_staticText221, 0, wxALL, 5 );
	
	colourPickerButton = new wxButton( this, wxID_ANY, wxT("Colour Picker"), wxDefaultPosition, wxDefaultSize, 0 );
	objectColourSizer->Add( colourPickerButton, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	m_staticText20 = new wxStaticText( this, wxID_ANY, wxT("Current Colour:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	objectColourSizer->Add( m_staticText20, 0, wxALL, 5 );
	
	currentColourAsAButton = new wxButton( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	currentColourAsAButton->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	currentColourAsAButton->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNHIGHLIGHT ) );
	currentColourAsAButton->Enable( false );
	currentColourAsAButton->SetMinSize( wxSize( 75,-1 ) );
	
	objectColourSizer->Add( currentColourAsAButton, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorColumnsSizer1->Add( objectColourSizer, 0, wxEXPAND, 5 );
	
	wxBoxSizer* behavioralModelSizer;
	behavioralModelSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText222 = new wxStaticText( this, wxID_ANY, wxT("Behavioral Model:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText222->Wrap( -1 );
	behavioralModelSizer->Add( m_staticText222, 0, wxALL, 5 );
	
	wxArrayString behavioralModelChoices;
	behavioralModel = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, behavioralModelChoices, 0 );
	behavioralModel->SetSelection( 0 );
	behavioralModel->SetMinSize( wxSize( 200,-1 ) );
	
	behavioralModelSizer->Add( behavioralModel, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorColumnsSizer1->Add( behavioralModelSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* objectSpeedSizer;
	objectSpeedSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2222 = new wxStaticText( this, wxID_ANY, wxT("Object Speed:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2222->Wrap( -1 );
	objectSpeedSizer->Add( m_staticText2222, 0, wxALL, 5 );
	
	objectSpeed = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	objectSpeedSizer->Add( objectSpeed, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorColumnsSizer1->Add( objectSpeedSizer, 1, wxEXPAND, 5 );
	
	m_staticline5 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	editorColumnsSizer1->Add( m_staticline5, 0, wxEXPAND | wxALL, 5 );
	
	m_staticText22215 = new wxStaticText( this, wxID_ANY, wxT("Grid Parameters"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22215->Wrap( -1 );
	editorColumnsSizer1->Add( m_staticText22215, 0, wxALL, 5 );
	
	wxBoxSizer* rowsSizer;
	rowsSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2221 = new wxStaticText( this, wxID_ANY, wxT("Rows:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2221->Wrap( -1 );
	rowsSizer->Add( m_staticText2221, 0, wxALL, 5 );
	
	gridRows = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	rowsSizer->Add( gridRows, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorColumnsSizer1->Add( rowsSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* columnsSizer;
	columnsSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText22211 = new wxStaticText( this, wxID_ANY, wxT("Columns:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22211->Wrap( -1 );
	columnsSizer->Add( m_staticText22211, 0, wxALL, 5 );
	
	gridColumns = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	columnsSizer->Add( gridColumns, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorColumnsSizer1->Add( columnsSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* leftMarginSizer;
	leftMarginSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText22212 = new wxStaticText( this, wxID_ANY, wxT("Left Margin (% of Screen):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22212->Wrap( -1 );
	leftMarginSizer->Add( m_staticText22212, 0, wxALL, 5 );
	
	gridLeftMargin = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	leftMarginSizer->Add( gridLeftMargin, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorColumnsSizer1->Add( leftMarginSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* rightMarginSizer;
	rightMarginSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText22213 = new wxStaticText( this, wxID_ANY, wxT("Right Margin (% of Screen):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22213->Wrap( -1 );
	rightMarginSizer->Add( m_staticText22213, 0, wxALL, 5 );
	
	gridRightMargin = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	rightMarginSizer->Add( gridRightMargin, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorColumnsSizer1->Add( rightMarginSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* topMarginSizer;
	topMarginSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText22214 = new wxStaticText( this, wxID_ANY, wxT("Top Margin (% of Screen):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22214->Wrap( -1 );
	topMarginSizer->Add( m_staticText22214, 0, wxALL, 5 );
	
	gridTopMargin = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	topMarginSizer->Add( gridTopMargin, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorColumnsSizer1->Add( topMarginSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bottomMarginSizer;
	bottomMarginSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText222141 = new wxStaticText( this, wxID_ANY, wxT("Bottom Margin (% of Screen):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText222141->Wrap( -1 );
	bottomMarginSizer->Add( m_staticText222141, 0, wxALL, 5 );
	
	gridBottomMargin = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bottomMarginSizer->Add( gridBottomMargin, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorColumnsSizer1->Add( bottomMarginSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* verticalCellSeperationSizer;
	verticalCellSeperationSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText222142 = new wxStaticText( this, wxID_ANY, wxT("Vertical Cell Seperation (% of Screen):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText222142->Wrap( -1 );
	verticalCellSeperationSizer->Add( m_staticText222142, 0, wxALL, 5 );
	
	gridVerticalSeperation = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	verticalCellSeperationSizer->Add( gridVerticalSeperation, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorColumnsSizer1->Add( verticalCellSeperationSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* horizontalCellSeperationSizer;
	horizontalCellSeperationSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2221421 = new wxStaticText( this, wxID_ANY, wxT("Horizontal Cell Seperation (% of Screen):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2221421->Wrap( -1 );
	horizontalCellSeperationSizer->Add( m_staticText2221421, 0, wxALL, 5 );
	
	gridHorizontalSeperation = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	horizontalCellSeperationSizer->Add( gridHorizontalSeperation, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorColumnsSizer1->Add( horizontalCellSeperationSizer, 1, wxEXPAND, 5 );
	
	
	editorParametersSizer->Add( editorColumnsSizer1, 0, wxEXPAND, 5 );
	
	
	editorColumnsSizer->Add( editorParametersSizer, 0, wxEXPAND, 5 );
	
	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	editorColumnsSizer->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* editorInformationSizer;
	editorInformationSizer = new wxBoxSizer( wxVERTICAL );
	
	editorInformationSizer->SetMinSize( wxSize( 150,-1 ) ); 
	wxBoxSizer* editorColumnsSizer11;
	editorColumnsSizer11 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* durationSizer1;
	durationSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText21 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	durationSizer1->Add( m_staticText21, 0, wxALL, 5 );
	
	
	editorColumnsSizer11->Add( durationSizer1, 0, wxEXPAND, 5 );
	
	wxBoxSizer* durationSizer11;
	durationSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText211 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText211->Wrap( -1 );
	durationSizer11->Add( m_staticText211, 0, wxALL, 5 );
	
	
	editorColumnsSizer11->Add( durationSizer11, 0, wxEXPAND, 5 );
	
	
	editorInformationSizer->Add( editorColumnsSizer11, 0, wxEXPAND, 5 );
	
	
	editorColumnsSizer->Add( editorInformationSizer, 0, wxEXPAND, 5 );
	
	
	rootSizer->Add( editorColumnsSizer, 0, wxEXPAND, 5 );
	
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
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( ExperimentConfigurationDialogView::OnExit ) );
	experimentDuration->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnTimeSelectHandler ), NULL, this );
	timeInSeconds->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnDurationTextHandler ), NULL, this );
	movingObjectType->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnObjectTypeSelectHandler ), NULL, this );
	numberOfObjects->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnIntegerInputHandler ), NULL, this );
	sizeOfObjects->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnDecimalInputHandler ), NULL, this );
	colourPickerButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnColourPickerHandler ), NULL, this );
	behavioralModel->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnBehaviorModelSelectHandler ), NULL, this );
	objectSpeed->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnDecimalInputHandler ), NULL, this );
	gridRows->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnIntegerInputHandler ), NULL, this );
	gridColumns->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnIntegerInputHandler ), NULL, this );
	gridLeftMargin->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnDecimalInputHandler ), NULL, this );
	gridRightMargin->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnDecimalInputHandler ), NULL, this );
	gridTopMargin->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnDecimalInputHandler ), NULL, this );
	gridBottomMargin->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnDecimalInputHandler ), NULL, this );
	gridVerticalSeperation->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnDecimalInputHandler ), NULL, this );
	gridHorizontalSeperation->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnDecimalInputHandler ), NULL, this );
	okButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnOk ), NULL, this );
	cancelButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnExit ), NULL, this );
}

ExperimentConfigurationDialogView::~ExperimentConfigurationDialogView()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( ExperimentConfigurationDialogView::OnExit ) );
	experimentDuration->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnTimeSelectHandler ), NULL, this );
	timeInSeconds->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnDurationTextHandler ), NULL, this );
	movingObjectType->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnObjectTypeSelectHandler ), NULL, this );
	numberOfObjects->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnIntegerInputHandler ), NULL, this );
	sizeOfObjects->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnDecimalInputHandler ), NULL, this );
	colourPickerButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnColourPickerHandler ), NULL, this );
	behavioralModel->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnBehaviorModelSelectHandler ), NULL, this );
	objectSpeed->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnDecimalInputHandler ), NULL, this );
	gridRows->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnIntegerInputHandler ), NULL, this );
	gridColumns->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnIntegerInputHandler ), NULL, this );
	gridLeftMargin->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnDecimalInputHandler ), NULL, this );
	gridRightMargin->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnDecimalInputHandler ), NULL, this );
	gridTopMargin->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnDecimalInputHandler ), NULL, this );
	gridBottomMargin->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnDecimalInputHandler ), NULL, this );
	gridVerticalSeperation->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnDecimalInputHandler ), NULL, this );
	gridHorizontalSeperation->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnDecimalInputHandler ), NULL, this );
	okButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnOk ), NULL, this );
	cancelButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnExit ), NULL, this );
	
}
