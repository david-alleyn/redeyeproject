#include "wx/wxprec.h"
#include "MainWindow.h"
#include "DisplayConfigurationDialogView.h"


MainWindow::MainWindow() : MainWindowView(0)
{
	Bind(wxEVT_COMMAND_MENU_SELECTED, &MainWindow::OnExit, this, wxID_EXIT);
	m_fileMenu->AppendSeparator();
	m_fileMenu->Append(wxID_EXIT);
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
	DisplayConfigurationDialogView* displayConfDialog = new DisplayConfigurationDialogView(0);
	displayConfDialog->Show(true);
}

void MainWindow::OnExperimentConfiguration(wxCommandEvent& event)
{
	event.Skip();
}

void MainWindow::OnRunExperiment(wxCommandEvent& event)
{
	event.Skip();
}
