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
	
	wxLog::SetActiveTarget(new wxLogTextCtrl(m_logTextControl));

	DisplayEngine::getInstance();
}


MainWindow::~MainWindow()
{
}

void MainWindow::OnExit(wxCommandEvent& event)
{
	Close(true);
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
	DisplayConfigurationDialog* displayConfDialog = new DisplayConfigurationDialog(0);
	displayConfDialog->Show(true);
}

void MainWindow::OnExperimentConfiguration(wxCommandEvent& event)
{
	ExperimentConfigurationDialog* experimentConfDialog = new ExperimentConfigurationDialog(0);
}

void MainWindow::OnRunExperiment(wxCommandEvent& event)
{
	DisplayEngine::getInstance()->StartEngine();
}
