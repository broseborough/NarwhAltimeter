/*
//	NWA_Display.h
//	The NarwhAltimeter Library is used to support a helmet embedded visual skydiving altimeter.
//	Authored by: Braden Roseborough
//	License: CC BY-NC-ND 3.0 – http://creativecommons.org/licenses/by-nc-nd/3.0/
//	Copyright 2013
*/
#ifndef NWA_Display_h
#define NWA_Display_h

#include "Arduino.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

class NWA_Display
{
	public:
		NWA_Display();
		void startUpImage(bool on);
		void updateAltitude(float altitude);
		void updatePullIndicator();
		void updateSpeed(int horizontal, int vertical);
		void updateHeading();
	private:
		Adafruit_ST7735* _tft;
		uint16_t _indicationColor;
		void setIndicationColorByAltitude(float altitude);
};

#endif