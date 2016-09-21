#include "wx/wxprec.h"
#include "DisplayConfigurationDialog.h"


DisplayConfigurationDialog::DisplayConfigurationDialog(wxFrame* parent) : DisplayConfigurationDialogView(parent)
{
	
}


DisplayConfigurationDialog::~DisplayConfigurationDialog()
{
}

void DisplayConfigurationDialog::OnExit(wxCloseEvent& event)
{
	Close(true);
}

void DisplayConfigurationDialog::OnUnlock(wxCommandEvent& event)
{
	event.Skip();
}

void DisplayConfigurationDialog::OnOk(wxCommandEvent& event)
{
	event.Skip();
}
