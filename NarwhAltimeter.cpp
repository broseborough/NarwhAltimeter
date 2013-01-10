/*
//	The NarwhAltimeter Library is used to support a helmet embedded visual skydiving altimeter.
//	Authored by: Braden Roseborough
//	License: CC BY-NC-ND 3.0 – http://creativecommons.org/licenses/by-nc-nd/3.0/
//	Copyright 2013
*/
#include "Arduino.h"
#include "NarwhAltimeter.h"

NarwhAltimeter::NarwhAltimeter()
{
	
}

void NarwhAltimeter::init()
{
	//	Initialize Display
	_display = NWA_Display();
	_display.startUpImage(true);
	//	Initialize Barometer
	//	Initialize GPS
	//	Initialize Logger
	_display.startUpImage(false);
}

void NarwhAltimeter::update()
{
	//	Update Barometer
	//	Update GPS
	//	Update Display
	_display.updateAltitude(12.5);
	_display.updatePullIndicator();
	_display.updateSpeed(20, 120);
	_display.updateHeading();
	//	Update Logger
}