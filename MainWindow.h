#pragma once
#include "MainWindowView.h"
#include "ConfigurationData.h"
class MainWindow :
	public MainWindowView
{
	wxLogTextCtrl* logtextctrl;

	ConfigurationData* configData;

public:
	MainWindow();
	~MainWindow();
	void OnExit(wxCommandEvent& event);

	void OnLoadConfiguration(wxCommandEvent& event) override;
	void OnSaveConfiguration(wxCommandEvent& event) override;
	void OnDisplayConfiguration(wxCommandEvent& event) override;
	void OnExperimentConfiguration(wxCommandEvent& event) override;
	void OnRunExperiment(wxCommandEvent& event) override;
};

