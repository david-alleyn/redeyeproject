#pragma once
#include "ConfigurationData.h"
#include "ExperimentConfigurationDialogView.h"
class ExperimentConfigurationDialog :
	public ExperimentConfigurationDialogView
{

	wxColour selectedColour;
public:
	ExperimentConfigurationDialog(wxFrame* parent, ConfigurationData* configData = 0);
	~ExperimentConfigurationDialog();

	
	virtual void OnIntegerInputHandler(wxCommandEvent& event);
	virtual void OnDecimalInputHandler(wxCommandEvent& event);
	virtual void OnExit(wxCloseEvent& event);
	virtual void OnTimeSelectHandler(wxCommandEvent& event);
	virtual void OnDurationTextHandler(wxCommandEvent& event);
	virtual void OnObjectTypeSelectHandler(wxCommandEvent& event);
	virtual void OnColourPickerHandler(wxCommandEvent& event);
	virtual void OnBehaviorModelSelectHandler(wxCommandEvent& event);
	virtual void OnOk(wxCommandEvent& event);
	virtual void OnExit(wxCommandEvent& event);
};

