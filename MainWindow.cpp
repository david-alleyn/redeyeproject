#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "MainWindow.h"
#include "DisplayConfigurationDialog.h"
#include "ExperimentConfigurationDialog.h"
#include "DisplayEngine.h"


MainWindow::MainWindow() : MainWindowView(0)
{
	Bind(wxEVT_COMMAND_MENU_SELECTED, &MainWindow::OnExit, this, wxID_EXIT);
	m_fileMenu->AppendSeparator();
	m_fileMenu->Append(wxID_EXIT);
	
    logtextctrl = new wxLogTextCtrl(m_logTextControl);
	wxLog::SetActiveTarget(logtextctrl);

	DisplayEngine::getInstance();
}


MainWindow::~MainWindow()
{
	DisplayEngine::resetInstance();
	/*if (logtextctrl != NULL) {
		delete logtextctrl;
		logtextctrl = NULL;
	}*/
}

void MainWindow::OnExit(wxCommandEvent& event)
{
	Destroy();
}

void MainWindow::OnLoadConfiguration(wxCommandEvent& event)
{
	event.Skip();
}

void MainWindow::OnSaveConfiguration(wxCommandEvent& event)
{
	event.Skip();
}

void MainWindow::OnDisplayConfiguration(wxCommandEvent& event)
{
	DisplayConfigurationDialog* displayConfDialog = new DisplayConfigurationDialog(this);
	if (displayConfDialog->ShowModal() == wxID_OK) {
		//gather values and save into ConfigurationData
	}
	displayConfDialog->Destroy();
	delete displayConfDialog;
}

void MainWindow::OnExperimentConfiguration(wxCommandEvent& event)
{
	ExperimentConfigurationDialog* experimentConfDialog = new ExperimentConfigurationDialog(this);
	if (experimentConfDialog->ShowModal() == wxID_OK) {
		//gather values and save into ConfigurationData
	}
	experimentConfDialog->Destroy();
	delete experimentConfDialog;
}

void MainWindow::OnRunExperiment(wxCommandEvent& event)
{
	DisplayEngine::getInstance()->StartEngine();
}
