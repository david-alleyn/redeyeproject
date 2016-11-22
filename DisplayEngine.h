#pragma once

#include <vector>
#include <SDL.h>

using namespace std;

class Display
{
public:
	
	int displayId;
	int maxWidth;
	int maxHeight;
	int maxRefreshRate;	
	
	Display(int displayId, int maxWidth, int maxHeight, int maxRefreshRate)
	{
		this->displayId = displayId;
		this->maxWidth = maxWidth;
		this->maxHeight = maxHeight;
		this->maxRefreshRate = maxRefreshRate;
	}
};

class DisplayEngine
{
	//Singleton Instance
	static DisplayEngine* s_instance;

	int numDisplays;
	vector<SDL_Window*> windows;
	vector<SDL_GLContext> glContexts;

	//State
	bool running;

	//Display Configuration Variables
	int firstDisplay = -1; // Default = -1 (secondary display is first). First display will be used if there is only one display.
	int lastDisplay = -1; // Default = -1 (the Nth display is last). First display will be used if there is only one display

	//Experiment Configuration
	// Experiment object (or a subclass thereof) implementing a series of "init", "run", "terminate" functions to run the experiment
	
	DisplayEngine();
	~DisplayEngine();

public:
	static DisplayEngine* getInstance();
	static void resetInstance();
	vector<Display> enumerateAllDisplays();
	
	int getFirstDisplay();
	void setFirstDisplay(int displayIndex);

	int getLastDisplay();
	void setLastDisplay(int displayIndex);

	// Controls
	void StartEngine();
	void StopEngine();
	

};