#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class ConfigurationData
{
	//display config data
	unsigned int firstMonitorIndex;
	unsigned int lastMonitorIndex;

	//experiment config data
	unsigned int timeInSeconds;
	unsigned int movingObjectType;
	unsigned int numberOfObjects;
	double sizeOfObjects;
	wxColour selectedColour;



public:
	ConfigurationData();
	~ConfigurationData();
};

