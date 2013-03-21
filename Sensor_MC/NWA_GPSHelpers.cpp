/*
//	NWA_GPS.cpp
//	The NarwhAltimeter Library is used to support a helmet embedded visual skydiving altimeter.
//	Authored by: Braden Roseborough
//	License: CC BY-NC-ND 3.0 – http://creativecommons.org/licenses/by-nc-nd/3.0/
//	Copyright 2013
*/
#include "Arduino.h"
#include "NWA_GPSHelpers.h"

SoftwareSerial GPSSerial(3, 2);
Adafruit_GPS GPS(&GPSSerial);

NWA_GPS::NWA_GPS()
{
	gps = &GPS;
	gps->begin(9600);
	gps->sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
	gps->sendCommand(PMTK_SET_NMEA_UPDATE_5HZ);
	_useInterrupt(true);
}

void NWA_GPS::update()
{
	gps->parse(GPS.lastNMEA());
}

SIGNAL(TIMER0_COMPA_vect) {
  char c = GPS.read();
  // if you want to debug, this is a good time to do it!
  if (c) UDR0 = c;  
    // writing direct to UDR0 is much much faster than Serial.print 
    // but only one character can be written at a time. 
}

void NWA_GPS::_useInterrupt(boolean v) {
  if (v) {
    // Timer0 is already used for millis() - we'll just interrupt somewhere
    // in the middle and call the "Compare A" function above
    OCR0A = 0xAF;
    TIMSK0 |= _BV(OCIE0A);
    _usingInterrupt = true;
  } else {
    // do not call the interrupt function COMPA anymore
    TIMSK0 &= ~_BV(OCIE0A);
    _usingInterrupt = false;
  }
}