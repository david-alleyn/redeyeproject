#pragma once
#include "DisplayConfigurationDialogView.h"
class DisplayConfigurationDialog :
	public DisplayConfigurationDialogView
{
public:
	DisplayConfigurationDialog(wxFrame* parent);
	~DisplayConfigurationDialog();

	virtual void OnExit(wxCloseEvent& event);
	virtual void OnUnlock(wxCommandEvent& event);
	virtual void OnOk(wxCommandEvent& event);
};

