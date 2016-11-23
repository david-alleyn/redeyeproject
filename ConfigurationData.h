#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class ConfigurationData
{
public:

	//display config data -- suffixed with disp_
	int disp_firstMonitorIndex;
	int disp_lastMonitorIndex;

	//experiment config data -- suffixed with exp_
	int exp_timeInSeconds;
	int exp_movingObjectType;
	int exp_numberOfObjects;
	double exp_sizeOfObjects;
	float exp_selectedColour_red;
	float exp_selectedColour_green;
	float exp_selectedColour_blue;
	double exp_objectSpeed;

	int exp_rows;
	int exp_columns;

	double exp_gridLeftMargin;
	double exp_gridRightMargin;
	double exp_gridTopMargin;
	double exp_gridBottomMargin;
	double exp_gridHorizontalSeperation;
	double exp_gridVerticalSeperation;

	//flags

	bool displayConfigInitialized;
	bool experimentConfigInitialized;

	ConfigurationData() {

		displayConfigInitialized = false;
		experimentConfigInitialized = false;
	}

	ConfigurationData(wxString fileName) {
		//initialize with file data
	}

	bool writeToFile(wxString fileName) {
		if (displayConfigInitialized == true && experimentConfigInitialized == true) {
			return true;
		}
		else {
			return false;
		}
	}

	~ConfigurationData();
};

