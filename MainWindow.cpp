#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "MainWindow.h"
#include "DisplayConfigurationDialog.h"
#include "ExperimentConfigurationDialog.h"
#include "DisplayEngine.h"
#include "MRTExperiment.h"


MainWindow::MainWindow() : MainWindowView(0)
{
	Bind(wxEVT_COMMAND_MENU_SELECTED, &MainWindow::OnExit, this, wxID_EXIT);
	m_fileMenu->AppendSeparator();
	m_fileMenu->Append(wxID_EXIT);
	
    logtextctrl = new wxLogTextCtrl(m_logTextControl);
	wxLog::SetActiveTarget(logtextctrl);

	configData = nullptr;
}


MainWindow::~MainWindow()
{
	DisplayEngine::resetInstance();
	if (configData != nullptr) {
		delete configData;
		configData = nullptr;
	}
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
	DisplayConfigurationDialog* displayConfDialog = new DisplayConfigurationDialog(this, configData);

	if (displayConfDialog->ShowModal() == wxID_OK) {
		//gather configuration data pointer.
		if (this->configData == nullptr && displayConfDialog->configData != nullptr) {
			this->configData = displayConfDialog->configData;
		}
	}
	displayConfDialog->Destroy();
	delete displayConfDialog;
}

void MainWindow::OnExperimentConfiguration(wxCommandEvent& event)
{
	//TODO: pass partially initialized configurationdata object to the config dialog

	ExperimentConfigurationDialog* experimentConfDialog = new ExperimentConfigurationDialog(this, configData);

	if (experimentConfDialog->ShowModal() == wxID_OK) {
		//gather configuration data pointer.
		if (this->configData == nullptr && experimentConfDialog->configData != nullptr) {
			this->configData = experimentConfDialog->configData;
		}
	}
	experimentConfDialog->Destroy();
	delete experimentConfDialog;
}

void MainWindow::OnRunExperiment(wxCommandEvent& event)
{
	//Check CONFIGURATIONDATA object for proper initialization of data.
	//Validation can be accomplished by using the validation built into DisplayConfigurationDialog and ExperimentConfigurationDialog
	if (configData == nullptr) {
		wxMessageDialog* warningMessage = new wxMessageDialog(this, "Before running an experiment, please \"Load Configuration\" OR \"Configure Displays\" AND \"Configure Experiment\"", "Incomplete configuration", wxOK);
		warningMessage->ShowModal();
		return;
	}
	else if (!configData->isFullyInitialized()) {
		wxMessageDialog* warningMessage = new wxMessageDialog(this, "Before running an experiment, please \"Load Configuration\" OR \"Configure Displays\" AND \"Configure Experiment\"", "Incomplete configuration", wxOK);
		warningMessage->ShowModal();
		return;
	}

	//Get DisplayEngine
	DisplayEngine* displayEngine = DisplayEngine::getInstance();

	//If DisplayEngine has already been started (experiment has been "staged"), skip starting
	if (!displayEngine->isRunning()) {
		//Prepare DisplayEngine (using config or otherwise)
		displayEngine->setUsingConfigData(configData);

		//Start DisplayEngine (this will open black borderless windows on all the configured displays)
		displayEngine->startEngine();
	}

	//Prepare MRTExperiment (using config or otherwise)
	MRTExperiment experiment;
	experiment.initialize(configData);

	//Start Experiment (will run until time is complete and then rest at a black screen or terminate when ESCAPE is pressed)
	experiment.run();

	//Experiment cleanup
	experiment.~MRTExperiment();

	//Stop DisplayEngine
	displayEngine->stopEngine();

	//Reset DisplayEngine
	displayEngine->resetInstance();
}
