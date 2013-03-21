/*
//	NWA_GPS.h
//	The NarwhAltimeter Library is used to support a helmet embedded visual skydiving altimeter.
//	Authored by: Braden Roseborough
//	License: CC BY-NC-ND 3.0 – http://creativecommons.org/licenses/by-nc-nd/3.0/
//	Copyright 2013
//
//	Pins:
//	TX->D3
//	RX->D$
*/
#ifndef NWA_GPS_h
#define NWA_GPS_h

#include "Arduino.h"
#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>

#define RX	2
#define TX	3

class NWA_GPS {
	public:
		NWA_GPS();
		void update();
		Adafruit_GPS *gps;
	private:
		void _useInterrupt(boolean v);
		boolean _usingInterrupt;
};

#endif