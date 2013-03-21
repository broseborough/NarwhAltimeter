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
	//	Initialize Display
	//_display = NWA_Display();
	//_display.startUpImage(true);
	//	Initialize Barometer
	//	Initialize GPS
	_GPS = NWA_GPS();
	//	Initialize Logger
	_logger = NWA_Logger();
	_barometer = NWA_Barometer();
	//_display.startUpImage(false);
}

void NarwhAltimeter_Sensors::update()
{
	//	Update Barometer
	//	Update GPS
	_GPS.update();
	//	Update Display
	//_display.updateGPSSatellites(_GPS.gps->satellites);
	//_display.updateGPSQuality(_GPS.gps->fixquality);
	//_display.updateAltitude(_barometer.altitude());
	//_display.updatePullIndicator();
	//_display.updateSpeed(_GPS.gps->speed, 000);
	//_display.updateHeading(_GPS.gps->angle);
	//	Update Logger
	//_display.updateSDAvailability(_logger.initialized);
}