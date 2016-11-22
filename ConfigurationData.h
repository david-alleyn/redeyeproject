#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class ConfigurationData
{
public:

	//display config data
	int firstMonitorIndex;
	int lastMonitorIndex;

	//experiment config data
	int timeInSeconds;
	int movingObjectType;
	int numberOfObjects;
	double sizeOfObjects;
	wxColour selectedColour;
	double objectSpeed;

	//grid parameters

	int rows;
	int columns;

	double gridLeftMargin;
	double gridRightMargin;
	double gridTopMargin;
	double gridBottomMargin;
	double gridHorizontalSeperation;
	double gridVerticalSeperation;

	ConfigurationData() {

		firstMonitorIndex = -1;
		lastMonitorIndex = -1;

		timeInSeconds = -1;
		movingObjectType = -1;
		numberOfObjects = -1;
		sizeOfObjects = -1.0;
		selectedColour = wxColour("BLACK");

		rows = -1;
		columns = -1;

		gridLeftMargin = -1.0;
		gridRightMargin = -1.0;
		gridTopMargin = -1.0;
		gridBottomMargin = -1.0;
		gridHorizontalSeperation = -1.0;
		gridVerticalSeperation = -1.0;
	}
	~ConfigurationData();
};

