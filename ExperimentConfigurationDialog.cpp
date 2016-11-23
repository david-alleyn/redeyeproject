#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/valnum.h>

#include "ExperimentConfigurationDialog.h"


ExperimentConfigurationDialog::ExperimentConfigurationDialog(wxFrame* parent, ConfigurationData* configData) : ExperimentConfigurationDialogView(parent)
{
	//Setup input field validation for text boxes

	wxIntegerValidator<int> timeInSecondsValidator = wxIntegerValidator<int>();
	timeInSecondsValidator.SetRange(1, 31536000);
	timeInSeconds->SetValidator(timeInSecondsValidator);

	wxIntegerValidator<int> numberOfObjectsValidator = wxIntegerValidator<int>();
	numberOfObjectsValidator.SetRange(1, 10000);
	numberOfObjects->SetValidator(numberOfObjectsValidator);

	wxFloatingPointValidator<double> sizeOfObjectsValidator = wxFloatingPointValidator<double>();
	sizeOfObjectsValidator.SetRange(0.01, 100);
	sizeOfObjects->SetValidator(sizeOfObjectsValidator);

	wxFloatingPointValidator<double> objectSpeedValidator = wxFloatingPointValidator<double>();
	objectSpeedValidator.SetRange(0.01, 100);
	objectSpeed->SetValidator(objectSpeedValidator);

	wxIntegerValidator<int> gridRowsValidator = wxIntegerValidator<int>();
	gridRowsValidator.SetRange(1, 10);
	gridRows->SetValidator(gridRowsValidator);

	wxIntegerValidator<int> gridColumnsValidator = wxIntegerValidator<int>();
	gridColumnsValidator.SetRange(1, 10);
	gridColumns->SetValidator(gridColumnsValidator);

	wxFloatingPointValidator<double> gridLeftMarginValidator = wxFloatingPointValidator<double>();
	gridLeftMarginValidator.SetRange(0, 1);
	gridLeftMargin->SetValidator(gridLeftMarginValidator);

	wxFloatingPointValidator<double> gridRightMarginValidator = wxFloatingPointValidator<double>();
	gridRightMarginValidator.SetRange(0, 1);
	gridRightMargin->SetValidator(gridRightMarginValidator);

	wxFloatingPointValidator<double> gridTopMarginValidator = wxFloatingPointValidator<double>();
	gridTopMarginValidator.SetRange(0, 1);
	gridTopMargin->SetValidator(gridTopMarginValidator);

	wxFloatingPointValidator<double> gridBottomMarginValidator = wxFloatingPointValidator<double>();
	gridBottomMarginValidator.SetRange(0, 1);
	gridBottomMargin->SetValidator(gridBottomMarginValidator);

	wxFloatingPointValidator<double> gridHorizontalSeperationValidator = wxFloatingPointValidator<double>();
	gridHorizontalSeperationValidator.SetRange(0, 1);
	gridHorizontalSeperation->SetValidator(gridHorizontalSeperationValidator);

	wxFloatingPointValidator<double> gridVerticalSeperationValidator = wxFloatingPointValidator<double>();
	gridVerticalSeperationValidator.SetRange(0, 1);
	gridVerticalSeperation->SetValidator(gridVerticalSeperationValidator);

	// For when configuration data is not initialized, load hardcoded values.

	// Set experiment values

	experimentDuration->Append("Specify Your Own -->");
	experimentDuration->Append("1 Minute");
	experimentDuration->Append("5 Minutes");
	experimentDuration->Append("10 Minutes");
	experimentDuration->Append("15 Minutes");
	experimentDuration->Append("30 Minutes");
	experimentDuration->Append("45 Minutes");
	experimentDuration->Append("1 Hour");
	experimentDuration->SetSelection(0);

	timeInSeconds->Enable();
	timeInSeconds->SetValue("60");

	movingObjectType->Append("Dot / Circle");
	movingObjectType->SetSelection(0);

	numberOfObjects->SetValue("5");

	sizeOfObjects->SetValue("20.0");

	selectedColour = wxColour("RED");
	currentColourAsAButton->SetBackgroundColour(selectedColour);

	behavioralModel->Append("Random Movement");
	behavioralModel->SetSelection(0);

	objectSpeed->SetValue("0.1");

	// Set grid display parameters

	gridRows->SetValue("3");
	gridColumns->SetValue("3");

	gridLeftMargin->SetValue("0.02");
	gridRightMargin->SetValue("0.02");
	gridTopMargin->SetValue("0.02");
	gridBottomMargin->SetValue("0.02");
	gridHorizontalSeperation->SetValue("0.01");
	gridVerticalSeperation->SetValue("0.01");

}


ExperimentConfigurationDialog::~ExperimentConfigurationDialog()
{
}

inline void ExperimentConfigurationDialog::OnExit(wxCloseEvent & event) {
	EndModal(wxID_CANCEL);
}

inline void ExperimentConfigurationDialog::OnTimeSelectHandler(wxCommandEvent & event) {
	event.Skip();
}

inline void ExperimentConfigurationDialog::OnObjectTypeSelectHandler(wxCommandEvent & event) {
	event.Skip();
}

inline void ExperimentConfigurationDialog::OnColourPickerHandler(wxCommandEvent & event) {
	event.Skip();
}

inline void ExperimentConfigurationDialog::OnBehaviorModelSelectHandler(wxCommandEvent & event) {
	event.Skip();
}

inline void ExperimentConfigurationDialog::OnOk(wxCommandEvent & event) {
	event.Skip();
}

inline void ExperimentConfigurationDialog::OnExit(wxCommandEvent & event) {
	event.Skip();
}
