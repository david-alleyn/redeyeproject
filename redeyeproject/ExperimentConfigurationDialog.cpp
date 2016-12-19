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

	wxFloatingPointValidator<double> sizeOfObjectsValidator = wxFloatingPointValidator<double>(0, wxNUM_VAL_NO_TRAILING_ZEROES);
	sizeOfObjectsValidator.SetRange(0.0001, 100);
	sizeOfObjectsValidator.SetPrecision(6);
	sizeOfObjects->SetValidator(sizeOfObjectsValidator);

	wxFloatingPointValidator<double> objectSpeedValidator = wxFloatingPointValidator<double>(0, wxNUM_VAL_NO_TRAILING_ZEROES);
	objectSpeedValidator.SetRange(0.0001, 100);
	objectSpeedValidator.SetPrecision(6);
	objectSpeed->SetValidator(objectSpeedValidator);

	wxIntegerValidator<int> gridRowsValidator = wxIntegerValidator<int>();
	gridRowsValidator.SetRange(1, 10);
	gridRows->SetValidator(gridRowsValidator);

	wxIntegerValidator<int> gridColumnsValidator = wxIntegerValidator<int>();
	gridColumnsValidator.SetRange(1, 10);
	gridColumns->SetValidator(gridColumnsValidator);

	wxFloatingPointValidator<double> gridLeftMarginValidator = wxFloatingPointValidator<double>(0, wxNUM_VAL_NO_TRAILING_ZEROES);
	gridLeftMarginValidator.SetRange(0, 1);
	gridLeftMarginValidator.SetPrecision(6);
	gridLeftMargin->SetValidator(gridLeftMarginValidator);

	wxFloatingPointValidator<double> gridRightMarginValidator = wxFloatingPointValidator<double>(0, wxNUM_VAL_NO_TRAILING_ZEROES);
	gridRightMarginValidator.SetRange(0, 1);
	gridRightMarginValidator.SetPrecision(6);
	gridRightMargin->SetValidator(gridRightMarginValidator);

	wxFloatingPointValidator<double> gridTopMarginValidator = wxFloatingPointValidator<double>(0, wxNUM_VAL_NO_TRAILING_ZEROES);
	gridTopMarginValidator.SetRange(0, 1);
	gridTopMarginValidator.SetPrecision(6);
	gridTopMargin->SetValidator(gridTopMarginValidator);

	wxFloatingPointValidator<double> gridBottomMarginValidator = wxFloatingPointValidator<double>(0, wxNUM_VAL_NO_TRAILING_ZEROES);
	gridBottomMarginValidator.SetRange(0, 1);
	gridBottomMarginValidator.SetPrecision(6);
	gridBottomMargin->SetValidator(gridBottomMarginValidator);

	wxFloatingPointValidator<double> gridHorizontalSeperationValidator = wxFloatingPointValidator<double>(0, wxNUM_VAL_NO_TRAILING_ZEROES);
	gridHorizontalSeperationValidator.SetRange(0, 1);
	gridHorizontalSeperationValidator.SetPrecision(6);
	gridHorizontalSeperation->SetValidator(gridHorizontalSeperationValidator);

	wxFloatingPointValidator<double> gridVerticalSeperationValidator = wxFloatingPointValidator<double>(0, wxNUM_VAL_NO_TRAILING_ZEROES);
	gridVerticalSeperationValidator.SetRange(0, 1);
	gridVerticalSeperationValidator.SetPrecision(6);
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

	//when more than one object type comes along... dynamically generate options for this menu item
	movingObjectType->Append("Dot / Circle");
	movingObjectType->SetSelection(0);

	numberOfObjects->SetValue("5");

	sizeOfObjects->SetValue("20.0");

	selectedColour->SetColour(wxColour("RED"));

	behavioralModel->Append("Random Movement");
	behavioralModel->SetSelection(0);

	objectSpeed->SetValue("0.1");

	// Set grid display parameters

	gridRows->SetValue("3");
	gridColumns->SetValue("5");

	gridLeftMargin->SetValue("0.02");
	gridRightMargin->SetValue("0.02");
	gridTopMargin->SetValue("0.02");
	gridBottomMargin->SetValue("0.02");
	gridHorizontalSeperation->SetValue("0.01");
	gridVerticalSeperation->SetValue("0.01");

	//Validate passed in ConfigurationData and set the appropriate dialog options to match

	if (configData != nullptr) {
		if (configData->displayConfigInitialized) {
			this->configData = configData;
		}
	}

	if (configData != nullptr) {
		if (configData->experimentConfigInitialized) {
			this->configData = configData;

			//Calls to SetValue() result in validation of the data being set. If the data is valid, it will be set, otherwise the old values will remain.
			wxString timeToString;
			timeToString << configData->exp_timeInSeconds;
			timeInSeconds->SetValue(timeToString);

			wxString numObjectsToString;
			numObjectsToString << configData->exp_numberOfObjects;
			numberOfObjects->SetValue(numObjectsToString);

			wxString sizeObjectsToString;
			sizeObjectsToString << configData->exp_sizeOfObjects;
			sizeOfObjects->SetValue(sizeObjectsToString);

			wxString speedObjectsToString;
			speedObjectsToString << configData->exp_objectSpeed;
			objectSpeed->SetValue(speedObjectsToString);

			wxString gridRowsToString;
			gridRowsToString << configData->exp_rows;
			gridRows->SetValue(gridRowsToString);

			wxString gridColumnsToString;
			gridColumnsToString << configData->exp_columns;
			gridColumns->SetValue(gridColumnsToString);

			wxString gridLeftMarginToString;
			gridLeftMarginToString << configData->exp_gridLeftMargin;
			gridLeftMargin->SetValue(gridLeftMarginToString);

			wxString gridRightMarginToString;
			gridRightMarginToString << configData->exp_gridRightMargin;
			gridRightMargin->SetValue(gridRightMarginToString);

			wxString gridTopMarginToString;
			gridTopMarginToString << configData->exp_gridTopMargin;
			gridTopMargin->SetValue(gridTopMarginToString);

			wxString gridBottomMarginToString;
			gridBottomMarginToString << configData->exp_gridBottomMargin;
			gridBottomMargin->SetValue(gridBottomMarginToString);

			wxString gridHorizontalSeperationToString;
			gridHorizontalSeperationToString << configData->exp_gridHorizontalSeperation;
			gridHorizontalSeperation->SetValue(gridHorizontalSeperationToString);

			wxString gridVerticalSeperationToString;
			gridVerticalSeperationToString << configData->exp_gridVerticalSeperation;
			gridVerticalSeperation->SetValue(gridVerticalSeperationToString);

			if (configData->exp_movingObjectType < (int)movingObjectType->GetCount()) {
				movingObjectType->SetSelection(configData->exp_movingObjectType);
			}

			wxColour savedColour = wxColour(configData->exp_selectedColour_red, configData->exp_selectedColour_green, configData->exp_selectedColour_blue, 255);
			selectedColour->SetColour(savedColour);

			if (configData->exp_behavioralModel < (int)behavioralModel->GetCount()) {
				behavioralModel->SetSelection(configData->exp_behavioralModel);
			}
			
			wxLogMessage("Existing valid Experiment Configuration Data detected, reusing...");
		}
	}

}


ExperimentConfigurationDialog::~ExperimentConfigurationDialog()
{
}

void ExperimentConfigurationDialog::OnExit(wxCloseEvent & event) {
	EndModal(wxID_CANCEL);
}

void ExperimentConfigurationDialog::OnTimeSelectHandler(wxCommandEvent & event) {
	wxChoice* timeChosen = static_cast<wxChoice*> (event.GetEventObject());

	//based on these values determined in the constructor of ExperimentConfigurationDialog
	/*experimentDuration->Append("Specify Your Own -->");
	experimentDuration->Append("1 Minute");
	experimentDuration->Append("5 Minutes");
	experimentDuration->Append("10 Minutes");
	experimentDuration->Append("15 Minutes");
	experimentDuration->Append("30 Minutes");
	experimentDuration->Append("45 Minutes");
	experimentDuration->Append("1 Hour");*/

	if (timeChosen->GetSelection() == 0) {
		timeInSeconds->Enable();
	}
	else {
		timeInSeconds->Disable();
	}

	switch (timeChosen->GetSelection()) {
		case 0:
			break;
		case 1:
			timeInSeconds->SetValue("60");
			break;
		case 2:
			timeInSeconds->SetValue("300");
			break;
		case 3:
			timeInSeconds->SetValue("600");
			break;
		case 4:
			timeInSeconds->SetValue("900");
			break;
		case 5:
			timeInSeconds->SetValue("1800");
			break;
		case 6:
			timeInSeconds->SetValue("2700");
			break;
		case 7:
			timeInSeconds->SetValue("3600");
			break;
	}
}

void ExperimentConfigurationDialog::OnOk(wxCommandEvent & event) {
	if (this->configData == nullptr) {
		this->configData = new ConfigurationData();
	}

	//All input was validated successfully before reaching this point

	unsigned long exp_timeInSeconds;
	timeInSeconds->GetValue().ToCULong(&exp_timeInSeconds);
	configData->exp_timeInSeconds = exp_timeInSeconds & INT_MAX;

	configData->exp_movingObjectType = movingObjectType->GetSelection();

	unsigned long exp_numberOfObjects;
	numberOfObjects->GetValue().ToCULong(&exp_numberOfObjects);
	configData->exp_numberOfObjects = exp_numberOfObjects & INT_MAX;

	double exp_sizeOfObjects;
	sizeOfObjects->GetValue().ToDouble(&exp_sizeOfObjects);
	configData->exp_sizeOfObjects = exp_sizeOfObjects;

	double exp_objectSpeed;
	objectSpeed->GetValue().ToDouble(&exp_objectSpeed);
	configData->exp_objectSpeed = exp_objectSpeed;

	configData->exp_selectedColour_red = selectedColour->GetColour().Red();
	configData->exp_selectedColour_green = selectedColour->GetColour().Green();
	configData->exp_selectedColour_blue = selectedColour->GetColour().Blue();

	configData->exp_behavioralModel = behavioralModel->GetSelection();

	double exp_rows;
	gridRows->GetValue().ToDouble(&exp_rows);
	configData->exp_rows = exp_rows;

	double exp_columns;
	gridColumns->GetValue().ToDouble(&exp_columns);
	configData->exp_columns = exp_columns;

	double exp_gridLeftMargin;
	gridLeftMargin->GetValue().ToDouble(&exp_gridLeftMargin);
	configData->exp_gridLeftMargin = exp_gridLeftMargin;

	double exp_gridRightMargin;
	gridRightMargin->GetValue().ToDouble(&exp_gridRightMargin);
	configData->exp_gridRightMargin = exp_gridRightMargin;

	double exp_gridTopMargin;
	gridTopMargin->GetValue().ToDouble(&exp_gridTopMargin);
	configData->exp_gridTopMargin = exp_gridTopMargin;

	double exp_gridBottomMargin;
	gridBottomMargin->GetValue().ToDouble(&exp_gridBottomMargin);
	configData->exp_gridBottomMargin = exp_gridBottomMargin;

	double exp_gridVerticalSeperation;
	gridVerticalSeperation->GetValue().ToDouble(&exp_gridVerticalSeperation);
	configData->exp_gridVerticalSeperation = exp_gridVerticalSeperation;

	double exp_gridHorizontalSeperation;
	gridHorizontalSeperation->GetValue().ToDouble(&exp_gridHorizontalSeperation);
	configData->exp_gridHorizontalSeperation = exp_gridHorizontalSeperation;

	configData->experimentConfigInitialized = true;

	/*configData->disp_firstMonitorIndex = firstDisplayIndex->GetSelection();
	configData->disp_lastMonitorIndex = lastDisplayIndex->GetSelection();
	configData->displayConfigInitialized = true;*/

	wxLogMessage("Experiment Configuration Data is valid. Configuration Data updated.");

	event.Skip();
}

void ExperimentConfigurationDialog::OnExit(wxCommandEvent & event) {
	event.Skip();
}
