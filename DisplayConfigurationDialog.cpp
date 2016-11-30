#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "DisplayConfigurationDialog.h"
#include "DisplayEngine.h"


DisplayConfigurationDialog::DisplayConfigurationDialog(wxFrame* parent, ConfigurationData* configData) : DisplayConfigurationDialogView(parent)
{
	DisplayEngine* displayEngine = DisplayEngine::getInstance();

	int numDisplays = displayEngine->getNumAttachedDisplays();

	for (int i = 1; i <= numDisplays; i++) {
		wxString intToString;
		intToString << i;
		firstDisplayIndex->Append(intToString);
		lastDisplayIndex->Append(intToString);
	}

	if (numDisplays > 1) {
		firstDisplayIndex->SetSelection(1);
		lastDisplayIndex->SetSelection(numDisplays - 1);
	}
	else {
		firstDisplayIndex->SetSelection(0);
		lastDisplayIndex->SetSelection(0);
	}

	//Validate passed in ConfigurationData and set the appropriate dialog options to match

	if (configData != nullptr) {
		if (configData->displayConfigInitialized) {
			if (configData->disp_firstMonitorIndex < numDisplays &&
				configData->disp_firstMonitorIndex >= 0 &&
				configData->disp_lastMonitorIndex < numDisplays &&
				configData->disp_lastMonitorIndex >= 0) {

				if (configData->disp_firstMonitorIndex <= configData->disp_lastMonitorIndex ) {
					wxLogMessage("Existing valid Display Configuration Data detected, reusing...");

					this->configData = configData;

					firstDisplayIndex->SetSelection(configData->disp_firstMonitorIndex);
					lastDisplayIndex->SetSelection(configData->disp_lastMonitorIndex);
				}
			}
		}
	}
}


DisplayConfigurationDialog::~DisplayConfigurationDialog()
{
}

void DisplayConfigurationDialog::OnExit(wxCloseEvent& event)
{
	EndModal(wxID_CANCEL);
}

void DisplayConfigurationDialog::OnOk(wxCommandEvent& event)
{
	if (firstDisplayIndex->GetSelection() <= lastDisplayIndex->GetSelection()) {
		if (configData == nullptr) {
			configData = new ConfigurationData();
		}

		configData->disp_firstMonitorIndex = firstDisplayIndex->GetSelection();
		configData->disp_lastMonitorIndex = lastDisplayIndex->GetSelection();
		configData->displayConfigInitialized = true;

		wxLogMessage("Display Configuration Data is valid. Configuration Data updated.");

		event.Skip();
	}
	else
	{
		wxMessageDialog* selectionBadMsg = new wxMessageDialog(this, "Your first display selection must be equal to or less than the last display!", "Error", wxOK);
		selectionBadMsg->ShowModal();
	}	
}
