#pragma once
#include "ConfigurationData.h"
#include "DisplayConfigurationDialogView.h"
class DisplayConfigurationDialog :
	public DisplayConfigurationDialogView
{
public:

	ConfigurationData* configData;

	DisplayConfigurationDialog(wxFrame* parent, ConfigurationData* configData = 0);
	~DisplayConfigurationDialog();

	virtual void OnExit(wxCloseEvent& event);
	virtual void OnOk(wxCommandEvent& event);
};

