/*
//	The NarwhAltimeter Library is used to support a helmet embedded visual skydiving altimeter.
//	Authored by: Braden Roseborough
//	License: CC BY-NC-ND 3.0 – http://creativecommons.org/licenses/by-nc-nd/3.0/
//	Copyright 2013
*/
#ifndef NarwhAltimeter_h
#define NarwhAltimeter_h

#include "Arduino.h"
#include "NWA_DisplayHelpers.h"
#include "NWA_GPSHelpers.h"
#include "NWA_LoggerHelpers.h"
#include "NWA_BarometerHelpers.h"

class NarwhAltimeter
{
	public:
		NarwhAltimeter();
		void init();
		void update();
	private:
		NWA_Display _display;
		NWA_GPS _GPS;
		NWA_Logger _logger;
		NWA_Barometer _barometer;
};

#endif