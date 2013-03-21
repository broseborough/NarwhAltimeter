/*
//	The NarwhAltimeter Library is used to support a helmet embedded visual skydiving altimeter.
//	Authored by: Braden Roseborough
//	License: CC BY-NC-ND 3.0 – http://creativecommons.org/licenses/by-nc-nd/3.0/
//	Copyright 2013
*/
#ifndef NarwhAltimeter_Display_h
#define NarwhAltimeter_Display_h

#include "Arduino.h"
#include "NWA_DisplayHelpers.h"

class NarwhAltimeter_Display
{
	public:
		NarwhAltimeter_Display();
		void init();
		void update();
	private:
		NWA_Display _display;
};

#endif