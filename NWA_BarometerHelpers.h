/*
//	NWA_BarometerHelpers.h
//	The NarwhAltimeter Library is used to support a helmet embedded visual skydiving altimeter.
//	Authored by: Braden Roseborough
//	License: CC BY-NC-ND 3.0 – http://creativecommons.org/licenses/by-nc-nd/3.0/
//	Copyright 2013
*/

#ifndef NWA_Barometer_h
#define NWA_Barometer_h

#include "Arduino.h"
#include "Wire.h"
#include "Adafruit_BMP085.h"

class NWA_Barometer
{
	public:
		NWA_Barometer();
		float altitude();
	private:
		Adafruit_BMP085 _barometer;
		int32_t _initialPressure;
};

#endif