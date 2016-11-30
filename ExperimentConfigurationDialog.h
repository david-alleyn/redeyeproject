#pragma once
#include "ConfigurationData.h"
#include "ExperimentConfigurationDialogView.h"
class ExperimentConfigurationDialog :
	public ExperimentConfigurationDialogView
{
public:
	ConfigurationData* configData;

	ExperimentConfigurationDialog(wxFrame* parent, ConfigurationData* configData = 0);
	~ExperimentConfigurationDialog();

	
	virtual void OnExit(wxCloseEvent& event);
	virtual void OnTimeSelectHandler(wxCommandEvent& event);
	virtual void OnOk(wxCommandEvent& event);
	virtual void OnExit(wxCommandEvent& event);
};

