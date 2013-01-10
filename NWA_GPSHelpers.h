/*
//	NWA_GPS.h
//	The NarwhAltimeter Library is used to support a helmet embedded visual skydiving altimeter.
//	Authored by: Braden Roseborough
//	License: CC BY-NC-ND 3.0 – http://creativecommons.org/licenses/by-nc-nd/3.0/
//	Copyright 2013
*/
#ifndef NWA_GPS_h
#define NWA_GPS_h

#include "Arduino.h"
#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>

class NWA_GPS
{
	public:
		NWA_GPS();
		Adafruit_GPS* GPS;
		void track(bool on);
		void update();
	private:
		SoftwareSerial* _mySerial;
		bool _usingInterrupt;
		void _useInterrupt(bool v);
};

#endif