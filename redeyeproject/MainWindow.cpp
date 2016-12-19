#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/textfile.h>

#include "MainWindow.h"
#include "DisplayConfigurationDialog.h"
#include "ExperimentConfigurationDialog.h"
#include "DisplayEngine.h"
#include "MRTExperiment.h"


MainWindow::MainWindow() : MainWindowView(0)
{
	logtextctrl = new wxLogTextCtrl(logTextControl);
	wxLog::SetActiveTarget(logtextctrl);

	configData = nullptr;
	experimentRunning = false;
	saveConfButton->Disable();
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
	wxFileDialog openFileDialog(this, _("Open Configuration file"), "", "",
			"Experiment files (*.exp)|*.exp", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if (openFileDialog.ShowModal() == wxID_CANCEL)
		return;     // the user changed idea...

					// proceed loading the file chosen by the user;
					// this can be done with e.g. wxWidgets input streams:
	wxTextFile* inputFile = new wxTextFile(openFileDialog.GetPath());
	if (!inputFile->Open())
	{
		wxLogError("Cannot open file '%s'.", openFileDialog.GetPath());
		return;
	}

	this->configData = new ConfigurationData(inputFile);

	if (configData != nullptr){
		if (configData->isFullyInitialized()) {
			saveConfButton->Enable();
		}
	}

	delete inputFile;
}

void MainWindow::OnSaveConfiguration(wxCommandEvent& event)
{
	if (configData != nullptr) {
		if (configData->isFullyInitialized()) {


			wxFileDialog
				saveFileDialog(this, _("Save Configuration file"), "", "experimentConfiguration",
					"Configuration files (*.exp)|*.exp", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
			if (saveFileDialog.ShowModal() == wxID_CANCEL)
				return;     // the user changed idea...

							// save the current contents in the file;
							// this can be done with e.g. wxWidgets output streams:
			wxTextFile* outputFile = new wxTextFile(saveFileDialog.GetPath());
			
			if (!outputFile->Create()) {
				wxLogMessage("File '%s' already exists. Overwriting.", saveFileDialog.GetPath());
			} 

			if (!outputFile->Open())
			{
				wxLogError("File coult not be opened. Cancelling.", saveFileDialog.GetPath());
				return;
			}

			outputFile->Clear();

			if (!configData->writeToFile(outputFile)) {
				wxLogError("Cannot successfully write to file '%s'.", saveFileDialog.GetPath());
				return;
			}
			else {
				outputFile->Write();
				outputFile->Close();
			}

			

		}
	}

	

}

void MainWindow::OnDisplayConfiguration(wxCommandEvent& event)
{
	DisplayConfigurationDialog* displayConfDialog = new DisplayConfigurationDialog(this, configData);

	if (displayConfDialog->ShowModal() == wxID_OK) {
		//gather configuration data pointer.
		if (displayConfDialog->configData != nullptr) {
			this->configData = displayConfDialog->configData;

			if (this->configData->isFullyInitialized())
			{
				saveConfButton->Enable();
			}
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
		if (experimentConfDialog->configData != nullptr) {
			this->configData = experimentConfDialog->configData;

			if (this->configData->isFullyInitialized())
			{
				saveConfButton->Enable();
			}
		}
	}
	experimentConfDialog->Destroy();
	delete experimentConfDialog;
}

void MainWindow::OnRunExperiment(wxCommandEvent& event)
{
	if (!experimentRunning) {
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
		else {
			//early gl calls require call to glewInit();
			glewInit();

			//since the experiment window was already running (stage experiment was used), we need to set input focus on the existing window.
			displayEngine->setActiveWindow(0);
			displayEngine->lockMouseToActiveWindow();
		}



		//Prepare MRTExperiment (using config or otherwise)
		MRTExperiment* experiment = new MRTExperiment();
		experiment->initialize(configData);

		experimentRunning = true;
		runExperimentButton->Disable();
		stageExperimentButton->Disable();

		//Start Experiment (will run until time is complete and then rest at a black screen or terminate when ESCAPE is pressed)
		experiment->run();

		//Experiment cleanup
		delete experiment;
		experiment = nullptr;

		//Stop DisplayEngine
		displayEngine->stopEngine();

		//Reset DisplayEngine
		displayEngine->resetInstance();

		experimentRunning = false;
		runExperimentButton->Enable();
		stageExperimentButton->Enable();
	}
}

void MainWindow::OnStageExperiment(wxCommandEvent & event)
{
	DisplayEngine* displayEngine = DisplayEngine::getInstance();
	
	if (!experimentRunning && displayEngine->getNumPhysicalDisplays() > 1) {
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

		if (!displayEngine->isRunning()) {
			stageExperimentButton->Disable();

			//Prepare DisplayEngine (using config or otherwise)
			displayEngine->setUsingConfigData(configData);

			//Start DisplayEngine (this will open black borderless windows on all the configured displays)
			displayEngine->startEngine();

			//early use of gl functions requires glewInit();

			glewInit();
			displayEngine->paintWindowsBlack();
		}
	}
}
