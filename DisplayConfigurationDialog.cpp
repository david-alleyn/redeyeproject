#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "DisplayConfigurationDialog.h"


DisplayConfigurationDialog::DisplayConfigurationDialog(wxFrame* parent, ConfigurationData* configData) : DisplayConfigurationDialogView(parent)
{
	
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
	event.Skip();
}
