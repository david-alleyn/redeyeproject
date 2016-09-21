#pragma once
#include "MainWindowView.h"
class MainWindow :
	public MainWindowView
{
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

