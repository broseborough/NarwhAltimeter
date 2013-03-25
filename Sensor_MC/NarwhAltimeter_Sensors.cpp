/*
//	The NarwhAltimeter Library is used to support a helmet embedded visual skydiving altimeter.
//	Authored by: Braden Roseborough
//	License: CC BY-NC-ND 3.0 – http://creativecommons.org/licenses/by-nc-nd/3.0/
//	Copyright 2013
*/
#include "Arduino.h"
#include "NarwhAltimeter_Sensors.h"

NarwhAltimeter_Sensors::NarwhAltimeter_Sensors()
{
	
}

void NarwhAltimeter_Sensors::init()
{
	//	Initialize Barometer
	//	Initialize GPS
	_GPS = NWA_GPS();
	//	Initialize Logger
	_logger = NWA_Logger();
	_barometer = NWA_Barometer();
}

void NarwhAltimeter_Sensors::update()
{
	//	Update Barometer
	//	Update GPS
	_GPS.update();
}