/*
//	NWA_Display.cpp
//	The NarwhAltimeter Library is used to support a helmet embedded visual skydiving altimeter.
//	Authored by: Braden Roseborough
//	License: CC BY-NC-ND 3.0 – http://creativecommons.org/licenses/by-nc-nd/3.0/
//	Copyright 2013
*/
#include "Arduino.h"
#include "NWA_DisplayHelpers.h"

//	PINS
//	Display requires sclk connection and MOSI connection
#define DISPLAY_CS   10
#define DISPLAY_DC   9
#define DISPLAY_RST  8 // you can also connect this to the Arduino reset

//	COLORS
#define BLACK    0x0000
#define RED     0x001F
#define BLUE      0xF800
#define GREEN    0x07E0
#define YELLOW     0x07FF
#define MAGENTA  0xF81F
#define CYAN   0xFFE0 
#define WHITE    0xFFFF
#define BACKGROUND_COLOR 0x0000


NWA_Display::NWA_Display()
{
	_tft = new Adafruit_ST7735(DISPLAY_CS, DISPLAY_DC, DISPLAY_RST);
	_tft->initR(INITR_REDTAB);   
	_tft->setRotation(3);
	_tft->setTextWrap(false);
	_tft->fillScreen(BACKGROUND_COLOR);
}

void NWA_Display::startUpImage(bool on)
{
	if(on)
	{
		_tft->fillScreen(RED);
	}
	else
	{
		_tft->fillScreen(BLACK);
	}
}

void NWA_Display::setIndicationColorByAltitude(float altitude)
{
	if(altitude > 5){ _indicationColor = WHITE; }
	else if(4 < altitude && altitude <= 5){ _indicationColor = YELLOW; }
	else{ _indicationColor = RED; }
}

void NWA_Display::updateAltitude(float altitude)
{
	setIndicationColorByAltitude(5.0);
	_tft->setCursor(64,20);
	_tft->setTextSize(4);
	_tft->setTextColor(_indicationColor, BACKGROUND_COLOR);
	_tft->print(altitude);
}

void NWA_Display::updatePullIndicator()
{
	_tft->fillRect(148, 7, 4, 5, _indicationColor);
	_tft->fillTriangle(152, 13, 152, 5, 156, 9, _indicationColor);
}

void NWA_Display::updateSpeed(int horizontal, int vertical)
{
	_tft->setCursor(62, 52);
	_tft->setTextSize(2);
	_tft->setTextColor(_indicationColor, BACKGROUND_COLOR);
	_tft->print((String)horizontal + "h/v" + (String)vertical);
}

void NWA_Display::updateHeading()
{

}