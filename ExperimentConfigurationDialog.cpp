#include "wx/wxprec.h"
#include "ExperimentConfigurationDialog.h"


ExperimentConfigurationDialog::ExperimentConfigurationDialog(wxFrame* parent, ConfigurationData* configData) : ExperimentConfigurationDialogView(parent)
{

	/*double leftMargin = 0.02;
	double rightMargin = 0.02;
	double topMargin = 0.02;
	double bottomMargin = 0.02;
	double horizontalSep = 0.01;
	double verticalSep = 0.01;

	int numberOfDots = 100;
	double sizeOfDots = 30.0;
	glm::vec4 colorOfDots = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
	double speedOfDots = 0.1;
	vector<MovingCircle*> dots;*/

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

	timeInSeconds->SetValue("60");

	movingObjectType->Append("Dot / Circle");
	movingObjectType->SetSelection(0);

	numberOfObjects->SetValue("5");

	sizeOfObjects->SetValue("20.0");

	selectedColour = wxColour("RED");
	currentColourAsAButton->SetBackgroundColour(selectedColour);

	behavioralModel->Append("Random Movement");
	behavioralModel->SetSelection(0);

	// Set grid display parameters

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

inline void ExperimentConfigurationDialog::OnIntegerInputHandler(wxCommandEvent & event) {
	event.Skip();
}

inline void ExperimentConfigurationDialog::OnDecimalInputHandler(wxCommandEvent & event) {
	event.Skip();
}

inline void ExperimentConfigurationDialog::OnExit(wxCloseEvent & event) {
	Close(true);
}

inline void ExperimentConfigurationDialog::OnTimeSelectHandler(wxCommandEvent & event) {
	event.Skip();
}

inline void ExperimentConfigurationDialog::OnDurationTextHandler(wxCommandEvent & event) {
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
