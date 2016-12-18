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
	
	experimentParametersLabel = new wxStaticText( this, wxID_ANY, wxT("Experiment Parameters"), wxDefaultPosition, wxDefaultSize, 0 );
	experimentParametersLabel->Wrap( -1 );
	experimentParametersLabel->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );
	
	editorParametersSizer->Add( experimentParametersLabel, 0, wxALL, 5 );
	
	wxBoxSizer* durationSizer;
	durationSizer = new wxBoxSizer( wxHORIZONTAL );
	
	experimentDurationLabel = new wxStaticText( this, wxID_ANY, wxT("Experiment Duration:"), wxDefaultPosition, wxDefaultSize, 0 );
	experimentDurationLabel->Wrap( -1 );
	durationSizer->Add( experimentDurationLabel, 0, wxALL, 5 );
	
	wxArrayString experimentDurationChoices;
	experimentDuration = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, experimentDurationChoices, 0 );
	experimentDuration->SetSelection( 0 );
	experimentDuration->SetMinSize( wxSize( 200,-1 ) );
	
	durationSizer->Add( experimentDuration, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	timeInSecondsLabel = new wxStaticText( this, wxID_ANY, wxT("Time in Seconds:"), wxDefaultPosition, wxDefaultSize, 0 );
	timeInSecondsLabel->Wrap( -1 );
	durationSizer->Add( timeInSecondsLabel, 0, wxALL, 5 );
	
	timeInSeconds = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	timeInSeconds->Enable( false );
	timeInSeconds->SetMinSize( wxSize( 60,-1 ) );
	
	durationSizer->Add( timeInSeconds, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorParametersSizer->Add( durationSizer, 0, wxEXPAND, 5 );
	
	wxBoxSizer* movingObjectionSizer;
	movingObjectionSizer = new wxBoxSizer( wxHORIZONTAL );
	
	movingObjectTypeLabel = new wxStaticText( this, wxID_ANY, wxT("Moving Object Type:"), wxDefaultPosition, wxDefaultSize, 0 );
	movingObjectTypeLabel->Wrap( -1 );
	movingObjectionSizer->Add( movingObjectTypeLabel, 0, wxALL, 5 );
	
	wxArrayString movingObjectTypeChoices;
	movingObjectType = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, movingObjectTypeChoices, 0 );
	movingObjectType->SetSelection( 0 );
	movingObjectType->SetMinSize( wxSize( 200,-1 ) );
	
	movingObjectionSizer->Add( movingObjectType, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorParametersSizer->Add( movingObjectionSizer, 0, wxEXPAND, 5 );
	
	wxBoxSizer* numberOfObjectsSizer;
	numberOfObjectsSizer = new wxBoxSizer( wxHORIZONTAL );
	
	numberOfObjectsLabel = new wxStaticText( this, wxID_ANY, wxT("Number of Objects:"), wxDefaultPosition, wxDefaultSize, 0 );
	numberOfObjectsLabel->Wrap( -1 );
	numberOfObjectsSizer->Add( numberOfObjectsLabel, 0, wxALL, 5 );
	
	numberOfObjects = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	numberOfObjectsSizer->Add( numberOfObjects, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorParametersSizer->Add( numberOfObjectsSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* sizeOfObjectsSizer;
	sizeOfObjectsSizer = new wxBoxSizer( wxHORIZONTAL );
	
	sizeOfObjectsLabel = new wxStaticText( this, wxID_ANY, wxT("Size of Objects:"), wxDefaultPosition, wxDefaultSize, 0 );
	sizeOfObjectsLabel->Wrap( -1 );
	sizeOfObjectsSizer->Add( sizeOfObjectsLabel, 0, wxALL, 5 );
	
	sizeOfObjects = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sizeOfObjectsSizer->Add( sizeOfObjects, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorParametersSizer->Add( sizeOfObjectsSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* objectColourSizer;
	objectColourSizer = new wxBoxSizer( wxHORIZONTAL );
	
	objectColorLabel = new wxStaticText( this, wxID_ANY, wxT("Object Colour:"), wxDefaultPosition, wxDefaultSize, 0 );
	objectColorLabel->Wrap( -1 );
	objectColourSizer->Add( objectColorLabel, 0, wxALIGN_CENTER|wxALL, 5 );
	
	selectedColour = new wxColourPickerCtrl( this, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	selectedColour->SetMinSize( wxSize( 100,30 ) );
	
	objectColourSizer->Add( selectedColour, 0, wxALIGN_CENTER, 5 );
	
	
	editorParametersSizer->Add( objectColourSizer, 0, wxEXPAND, 5 );
	
	wxBoxSizer* behavioralModelSizer;
	behavioralModelSizer = new wxBoxSizer( wxHORIZONTAL );
	
	behavioralModelLabel = new wxStaticText( this, wxID_ANY, wxT("Behavioral Model:"), wxDefaultPosition, wxDefaultSize, 0 );
	behavioralModelLabel->Wrap( -1 );
	behavioralModelSizer->Add( behavioralModelLabel, 0, wxALL, 5 );
	
	wxArrayString behavioralModelChoices;
	behavioralModel = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, behavioralModelChoices, 0 );
	behavioralModel->SetSelection( 0 );
	behavioralModel->SetMinSize( wxSize( 200,-1 ) );
	
	behavioralModelSizer->Add( behavioralModel, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorParametersSizer->Add( behavioralModelSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* objectSpeedSizer;
	objectSpeedSizer = new wxBoxSizer( wxHORIZONTAL );
	
	objectSpeedLabel = new wxStaticText( this, wxID_ANY, wxT("Object Speed:"), wxDefaultPosition, wxDefaultSize, 0 );
	objectSpeedLabel->Wrap( -1 );
	objectSpeedSizer->Add( objectSpeedLabel, 0, wxALL, 5 );
	
	objectSpeed = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	objectSpeedSizer->Add( objectSpeed, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorParametersSizer->Add( objectSpeedSizer, 1, wxEXPAND, 5 );
	
	parametersLineSeperator = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	editorParametersSizer->Add( parametersLineSeperator, 0, wxEXPAND | wxALL, 5 );
	
	gridParametersLabel = new wxStaticText( this, wxID_ANY, wxT("Grid Parameters"), wxDefaultPosition, wxDefaultSize, 0 );
	gridParametersLabel->Wrap( -1 );
	gridParametersLabel->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );
	
	editorParametersSizer->Add( gridParametersLabel, 0, wxALL, 5 );
	
	wxBoxSizer* rowsSizer;
	rowsSizer = new wxBoxSizer( wxHORIZONTAL );
	
	rowsLabel = new wxStaticText( this, wxID_ANY, wxT("Rows:"), wxDefaultPosition, wxDefaultSize, 0 );
	rowsLabel->Wrap( -1 );
	rowsSizer->Add( rowsLabel, 0, wxALL, 5 );
	
	gridRows = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	rowsSizer->Add( gridRows, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorParametersSizer->Add( rowsSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* columnsSizer;
	columnsSizer = new wxBoxSizer( wxHORIZONTAL );
	
	columnsLabel = new wxStaticText( this, wxID_ANY, wxT("Columns:"), wxDefaultPosition, wxDefaultSize, 0 );
	columnsLabel->Wrap( -1 );
	columnsSizer->Add( columnsLabel, 0, wxALL, 5 );
	
	gridColumns = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	columnsSizer->Add( gridColumns, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorParametersSizer->Add( columnsSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* leftMarginSizer;
	leftMarginSizer = new wxBoxSizer( wxHORIZONTAL );
	
	leftMarginLabel = new wxStaticText( this, wxID_ANY, wxT("Left Margin (% of Screen):"), wxDefaultPosition, wxDefaultSize, 0 );
	leftMarginLabel->Wrap( -1 );
	leftMarginSizer->Add( leftMarginLabel, 0, wxALL, 5 );
	
	gridLeftMargin = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	leftMarginSizer->Add( gridLeftMargin, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorParametersSizer->Add( leftMarginSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* rightMarginSizer;
	rightMarginSizer = new wxBoxSizer( wxHORIZONTAL );
	
	rightMarginLabel = new wxStaticText( this, wxID_ANY, wxT("Right Margin (% of Screen):"), wxDefaultPosition, wxDefaultSize, 0 );
	rightMarginLabel->Wrap( -1 );
	rightMarginSizer->Add( rightMarginLabel, 0, wxALL, 5 );
	
	gridRightMargin = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	rightMarginSizer->Add( gridRightMargin, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorParametersSizer->Add( rightMarginSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* topMarginSizer;
	topMarginSizer = new wxBoxSizer( wxHORIZONTAL );
	
	topMarginLabel = new wxStaticText( this, wxID_ANY, wxT("Top Margin (% of Screen):"), wxDefaultPosition, wxDefaultSize, 0 );
	topMarginLabel->Wrap( -1 );
	topMarginSizer->Add( topMarginLabel, 0, wxALL, 5 );
	
	gridTopMargin = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	topMarginSizer->Add( gridTopMargin, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorParametersSizer->Add( topMarginSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bottomMarginSizer;
	bottomMarginSizer = new wxBoxSizer( wxHORIZONTAL );
	
	bottomMarginLabel = new wxStaticText( this, wxID_ANY, wxT("Bottom Margin (% of Screen):"), wxDefaultPosition, wxDefaultSize, 0 );
	bottomMarginLabel->Wrap( -1 );
	bottomMarginSizer->Add( bottomMarginLabel, 0, wxALL, 5 );
	
	gridBottomMargin = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bottomMarginSizer->Add( gridBottomMargin, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorParametersSizer->Add( bottomMarginSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* verticalCellSeperationSizer;
	verticalCellSeperationSizer = new wxBoxSizer( wxHORIZONTAL );
	
	verticalSeperationLabel = new wxStaticText( this, wxID_ANY, wxT("Vertical Cell Seperation (% of Screen):"), wxDefaultPosition, wxDefaultSize, 0 );
	verticalSeperationLabel->Wrap( -1 );
	verticalCellSeperationSizer->Add( verticalSeperationLabel, 0, wxALL, 5 );
	
	gridVerticalSeperation = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	verticalCellSeperationSizer->Add( gridVerticalSeperation, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorParametersSizer->Add( verticalCellSeperationSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* horizontalCellSeperationSizer;
	horizontalCellSeperationSizer = new wxBoxSizer( wxHORIZONTAL );
	
	horizontalSeperationLabel = new wxStaticText( this, wxID_ANY, wxT("Horizontal Cell Seperation (% of Screen):"), wxDefaultPosition, wxDefaultSize, 0 );
	horizontalSeperationLabel->Wrap( -1 );
	horizontalCellSeperationSizer->Add( horizontalSeperationLabel, 0, wxALL, 5 );
	
	gridHorizontalSeperation = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	horizontalCellSeperationSizer->Add( gridHorizontalSeperation, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	
	editorParametersSizer->Add( horizontalCellSeperationSizer, 1, wxEXPAND, 5 );
	
	
	editorColumnsSizer->Add( editorParametersSizer, 0, wxEXPAND, 5 );
	
	
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
	okButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnOk ), NULL, this );
	cancelButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnExit ), NULL, this );
}

ExperimentConfigurationDialogView::~ExperimentConfigurationDialogView()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( ExperimentConfigurationDialogView::OnExit ) );
	experimentDuration->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnTimeSelectHandler ), NULL, this );
	okButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnOk ), NULL, this );
	cancelButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ExperimentConfigurationDialogView::OnExit ), NULL, this );
	
}
