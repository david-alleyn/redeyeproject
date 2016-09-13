#pragma once

//#include <SDL.h>

class DisplayEngine
{
	//Singleton Instance
	static DisplayEngine *s_instance;

	
	DisplayEngine();
	~DisplayEngine();
public:
	static DisplayEngine *getInstance();
	

};