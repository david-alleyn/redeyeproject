#include "wx/wxprec.h"
#include "ConfigurationData.h"


ConfigurationData::ConfigurationData() {

	displayConfigInitialized = false;
	experimentConfigInitialized = false;
}

ConfigurationData::ConfigurationData(wxString fileName) {
	//initialize with file data

	displayConfigInitialized = true;
	experimentConfigInitialized = true;
}

bool ConfigurationData::isFullyInitialized() {
	if (displayConfigInitialized && experimentConfigInitialized) {
		return true;
	}
	else {
		return false;
	}
}

bool ConfigurationData::writeToFile(wxString fileName) {
	if (isFullyInitialized()) {
		//write to file
		return true;
	}
	else {
		//error message in wxLog and return false
		return false;
	}
}

ConfigurationData::~ConfigurationData()
{
}
