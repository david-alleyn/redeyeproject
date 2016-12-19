#include "wx/wxprec.h"
#include "ConfigurationData.h"


ConfigurationData::ConfigurationData() {

	displayConfigInitialized = false;
	experimentConfigInitialized = false;
}

ConfigurationData::ConfigurationData(wxTextFile* openedTextFile) {
	//initialize with file data

	if (openedTextFile->IsOpened()) {
		if (openedTextFile->GetLineCount() == CONFIGDATAVARIABLECOUNT)
		{

			disp_firstMonitorIndex = std::stoi(openedTextFile->GetFirstLine().ToStdString());
			disp_lastMonitorIndex = std::stoi(openedTextFile->GetNextLine().ToStdString());

			//experiment config data -- suffixed with exp_
			exp_timeInSeconds = std::stoi(openedTextFile->GetNextLine().ToStdString());
			exp_movingObjectType = std::stoi(openedTextFile->GetNextLine().ToStdString());
			exp_numberOfObjects = std::stoi(openedTextFile->GetNextLine().ToStdString());
			exp_sizeOfObjects = std::stod(openedTextFile->GetNextLine().ToStdString());
			exp_selectedColour_red = std::stoi(openedTextFile->GetNextLine().ToStdString());
			exp_selectedColour_green = std::stoi(openedTextFile->GetNextLine().ToStdString());
			exp_selectedColour_blue = std::stoi(openedTextFile->GetNextLine().ToStdString());
			exp_objectSpeed = std::stod(openedTextFile->GetNextLine().ToStdString());
			exp_behavioralModel = std::stoi(openedTextFile->GetNextLine().ToStdString());

			exp_rows = std::stoi(openedTextFile->GetNextLine().ToStdString());
			exp_columns = std::stoi(openedTextFile->GetNextLine().ToStdString());

			exp_gridLeftMargin = std::stod(openedTextFile->GetNextLine().ToStdString());
			exp_gridRightMargin = std::stod(openedTextFile->GetNextLine().ToStdString());
			exp_gridTopMargin = std::stod(openedTextFile->GetNextLine().ToStdString());
			exp_gridBottomMargin = std::stod(openedTextFile->GetNextLine().ToStdString());
			exp_gridHorizontalSeperation = std::stod(openedTextFile->GetNextLine().ToStdString());
			exp_gridVerticalSeperation = std::stod(openedTextFile->GetNextLine().ToStdString());

			displayConfigInitialized = true;
			experimentConfigInitialized = true;
		}
	}



}

bool ConfigurationData::isFullyInitialized() {
	if (displayConfigInitialized && experimentConfigInitialized) {
		return true;
	}
	else {
		return false;
	}
}

bool ConfigurationData::writeToFile(wxTextFile* openedOutputFile) {
	if (isFullyInitialized()) {
		//write to file
		if (openedOutputFile->IsOpened()) {
			if (openedOutputFile->GetLineCount() == 0)
			{
				openedOutputFile->AddLine(wxString::Format(wxT("%i"), disp_firstMonitorIndex));
				openedOutputFile->AddLine(wxString::Format(wxT("%i"), disp_lastMonitorIndex));

				//experiment config data -- suffixed with exp_
				openedOutputFile->AddLine(wxString::Format(wxT("%i"), exp_timeInSeconds));
				openedOutputFile->AddLine(wxString::Format(wxT("%i"), exp_movingObjectType));
				openedOutputFile->AddLine(wxString::Format(wxT("%i"), exp_numberOfObjects));
				openedOutputFile->AddLine(wxString::Format(wxT("%f"), exp_sizeOfObjects));
				openedOutputFile->AddLine(wxString::Format(wxT("%i"), exp_selectedColour_red));
				openedOutputFile->AddLine(wxString::Format(wxT("%i"), exp_selectedColour_green));
				openedOutputFile->AddLine(wxString::Format(wxT("%i"), exp_selectedColour_blue));
				openedOutputFile->AddLine(wxString::Format(wxT("%f"), exp_objectSpeed));
				openedOutputFile->AddLine(wxString::Format(wxT("%i"), exp_behavioralModel));

				openedOutputFile->AddLine(wxString::Format(wxT("%i"), exp_rows));
				openedOutputFile->AddLine(wxString::Format(wxT("%i"), exp_columns));

				openedOutputFile->AddLine(wxString::Format(wxT("%f"), exp_gridLeftMargin));
				openedOutputFile->AddLine(wxString::Format(wxT("%f"), exp_gridRightMargin));
				openedOutputFile->AddLine(wxString::Format(wxT("%f"), exp_gridTopMargin));
				openedOutputFile->AddLine(wxString::Format(wxT("%f"), exp_gridBottomMargin));
				openedOutputFile->AddLine(wxString::Format(wxT("%f"), exp_gridHorizontalSeperation));
				openedOutputFile->AddLine(wxString::Format(wxT("%f"), exp_gridVerticalSeperation));
				return true;
			}
			else {
				return false;
			}
			return false;
		}
	}
	return false;
}

ConfigurationData::~ConfigurationData()
{
}
