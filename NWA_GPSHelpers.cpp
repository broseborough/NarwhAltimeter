/*
//	NWA_GPS.cpp
//	The NarwhAltimeter Library is used to support a helmet embedded visual skydiving altimeter.
//	Authored by: Braden Roseborough
//	License: CC BY-NC-ND 3.0 – http://creativecommons.org/licenses/by-nc-nd/3.0/
//	Copyright 2013
*/
#include "Arduino.h"
#include "NWA_GPSHelpers.h"

#define RX	2
#define TX	3

SIGNAL(TIMER0_COMPA_vect)
{
  //char c = GPS.read();
  //	If statement echos to console
  //if (c) UDR0 = c;
}

NWA_GPS::NWA_GPS()
{
	_mySerial = new SoftwareSerial(TX, RX);
	Adafruit_GPS GPS(_mySerial);
}

void NWA_GPS::track(bool on)
{

}

void NWA_GPS::update()
{

}

void NWA_GPS::_useInterrupt(bool v)
{
	if(v)
	{
	    // Timer0 is already used for millis() - we'll just interrupt somewhere
	    // in the middle and call the "Compare A" function above
	    OCR0A = 0xAF;
	    TIMSK0 |= _BV(OCIE0A);
	    _usingInterrupt = true;
	}
	else
	{
	    // do not call the interrupt function COMPA anymore
	    TIMSK0 &= ~_BV(OCIE0A);
	    _usingInterrupt = false;
	}
}