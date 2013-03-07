/*
//	NWA_LoggerHelpers.cpp
//	The NarwhAltimeter Library is used to support a helmet embedded visual skydiving altimeter.
//	Authored by: Braden Roseborough
//	License: CC BY-NC-ND 3.0 – http://creativecommons.org/licenses/by-nc-nd/3.0/
//	Copyright 2013
*/
#include "Arduino.h"
#include "NWA_LoggerHelpers.h"

#define CHIPSELECT 4

NWA_Logger::NWA_Logger()
{
	pinMode(SS, OUTPUT);
	initialized = !initialized && SD.begin(CHIPSELECT) ? true : false;
}

void NWA_Logger::logGPSData(String data)
{
	File file = SD.open("gps.log", FILE_WRITE);
	file.println(data);
	file.close();
}

void NWA_Logger::logAltitudeData(String data)
{
	File file = SD.open("altitude.log", FILE_WRITE);
	file.println(data);
	file.close();
}