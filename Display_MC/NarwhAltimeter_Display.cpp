/*
//	The NarwhAltimeter Library is used to support a helmet embedded visual skydiving altimeter.
//	Authored by: Braden Roseborough
//	License: CC BY-NC-ND 3.0 – http://creativecommons.org/licenses/by-nc-nd/3.0/
//	Copyright 2013
*/
#include "Arduino.h"
#include "NarwhAltimeter_Display.h"

NarwhAltimeter_Display::NarwhAltimeter_Display()
{
	
}

void NarwhAltimeter_Display::init()
{
	//	Initialize Display
	_display = NWA_Display();
	_display.startUpImage(true);
	_display.startUpImage(false);
}

void NarwhAltimeter_Display::update()
{
	_display.updateGPSSatellites(0);
	_display.updateGPSQuality(0);
	_display.updateAltitude(0);
	_display.updatePullIndicator();
	_display.updateSpeed(0, 0);
	_display.updateHeading(0);
	_display.updateSDAvailability(0);
}