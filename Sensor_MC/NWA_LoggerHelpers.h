/*
//	NWA_Logger.h
//	The NarwhAltimeter Library is used to support a helmet embedded visual skydiving altimeter.
//	Authored by: Braden Roseborough
//	License: CC BY-NC-ND 3.0 – http://creativecommons.org/licenses/by-nc-nd/3.0/
//	Copyright 2013
//
//	PINS:
//	MISO->D12
//	SCLK->D13
//	MOSI->D11
//	CS->4
The circuit:
* SD card attached to SPI bus as follows:
** UNO:  MOSI - pin 11, MISO - pin 12, CLK - pin 13, CS - pin 4 (CS pin can be changed)
and pin #10 (SS) must be an output
*/

#ifndef NWA_Logger_h
#define NWA_Logger_h

#include "Arduino.h"
#include <SD.h>

class NWA_Logger
{
	public:
		NWA_Logger();
		bool initialized;
		void logGPSData(String data);
		void logAltitudeData(String data);
	private:
		Sd2Card _card;
};

#endif