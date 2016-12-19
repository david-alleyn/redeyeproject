#pragma once

#include <vector>
#include <SDL.h>

#include "ConfigurationData.h"

using namespace std;

class DisplayEngine
{
	//Singleton Instance - We can only ever have a single manager of window creation and control
	static DisplayEngine* s_instance;

	struct Window {
		SDL_Window* window;
		SDL_GLContext glContext;

		Window(SDL_Window* window, SDL_GLContext glContext);
	};

	vector<Window> windows;

	int currentlyActiveWindow;

	//State
	bool running;

	//Display Configuration Variables
	int firstDisplay;
	int lastDisplay;
	
	DisplayEngine();
	~DisplayEngine();

public:
	static DisplayEngine* getInstance();
	static void resetInstance();

	bool setUsingConfigData(ConfigurationData* configData);
	
	//Returns the number of available displays. Starts at value 1
	int getNumPhysicalDisplays();

	//Returns the current index of the first display
	int getFirstPhysicalDisplay();

	//Used to set the first display. Must be equal to or lower than getLastDisplay() otherwise it will return false.
	bool setFirstPhysicalDisplay(int displayIndex);

	//Returns the current index of the last display
	int getLastPhysicalDisplay();

	//Used to set the last display. Must be equal to or greater than getFirstDisplay() otherwise it will return false.
	bool setLastPhysicalDisplay(int displayIndex);

	//REQUIRED TO SET THE DisplayEngine to "Running state"
	//Creates the rendering windows to be used by the application
	//By default they appear as a black and borderless window, occupying the full screen.
	bool startEngine();

	//Used to check and see if the DisplayEngine is running
	//Returns false if startEngine() did not run successfully or when stopEngine() has executed.
	bool isRunning();

	//NOT REQUIRED BUT HIGHLY SUGGESTED before the reuse of the created windows for any purposes.
	//This will close any open windows and cleanup any resources that they were using.
	bool stopEngine();

	//Returns the index of the currently active window
	//REQUIRES isRunning() to return true
	int getCurrentActiveWindow();

	//Returns the number of windows
	//REQUIRES isRunning() to return true
	int getNumWindows();

	//Used to set the active window
	//REQUIRES isRunning() to return true, also returns false when displayIndex is out of bounds
	bool setActiveWindow(int displayIndex);

	//Draws the graphics buffer for the active window, to the active window.
	//REQUIRES isRunning() to return true
	bool swapActiveWindowBuffer();

	//Returns the index of the currently active window
	//REQUIRES isRunning() to return true
	bool paintWindowsBlack();

	//Returns the drawable area size of the currently active window
	//REQUIRES isRunning() to return true
	bool getActiveWindowSize(int& width, int& height);

	//Focuses the currently active window
	//REQUIRES isRunning() to return true
	bool lockMouseToActiveWindow();
};