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
#define MAGENTA    0x07E0
#define YELLOW     0x07FF
#define MAGENTA  0xF81F
#define CYAN   0xFFE0 
#define WHITE    0xFFFF
#define BACKGROUND_COLOR 0x0000
#define PCOLOR BLACK

//	https://bitbucket.org/fabienroyer/nwazet.go/src/7f5b9fd055a3/Microbuilder/drivers/lcd/tft/colors.h
// Basic Color definitions
#define COLOR_BLACK                         (uint16_t)(0x0000)
#define COLOR_BLUE                          (uint16_t)(0x001F)
#define COLOR_RED                           (uint16_t)(0xF800)
#define COLOR_GREEN                         (uint16_t)(0x07E0)
#define COLOR_CYAN                          (uint16_t)(0x07FF)
#define COLOR_MAGENTA                       (uint16_t)(0xF81F)
#define COLOR_YELLOW                        (uint16_t)(0xFFE0)
#define COLOR_WHITE                         (uint16_t)(0xFFFF)

// Grayscale Values
#define COLOR_GRAY_15                       (uint16_t)(0x0861)    //  15  15  15
#define COLOR_GRAY_30                       (uint16_t)(0x18E3)    //  30  30  30
#define COLOR_GRAY_50                       (uint16_t)(0x3186)    //  50  50  50
#define COLOR_GRAY_80                       (uint16_t)(0x528A)    //  80  80  80
#define COLOR_GRAY_128                      (uint16_t)(0x8410)    // 128 128 128
#define COLOR_GRAY_200                      (uint16_t)(0xCE59)    // 200 200 200
#define COLOR_GRAY_225                      (uint16_t)(0xE71C)    // 225 225 225

// Color Palettes
#define COLOR_THEME_LIMEGREEN_BASE          (uint16_t)(0xD7F0)    // 211 255 130
#define COLOR_THEME_LIMEGREEN_DARKER        (uint16_t)(0x8DE8)    // 137 188  69
#define COLOR_THEME_LIMEGREEN_LIGHTER       (uint16_t)(0xEFF9)    // 238 255 207
#define COLOR_THEME_LIMEGREEN_SHADOW        (uint16_t)(0x73EC)    // 119 127 103
#define COLOR_THEME_LIMEGREEN_ACCENT        (uint16_t)(0xAE6D)    // 169 204 104

#define COLOR_THEME_VIOLET_BASE             (uint16_t)(0x8AEF)    // 143  94 124
#define COLOR_THEME_VIOLET_DARKER           (uint16_t)(0x4187)    //  66  49  59
#define COLOR_THEME_VIOLET_LIGHTER          (uint16_t)(0xC475)    // 194 142 174
#define COLOR_THEME_VIOLET_SHADOW           (uint16_t)(0x40E6)    //  66  29  52
#define COLOR_THEME_VIOLET_ACCENT           (uint16_t)(0xC992)    // 204  50 144

#define COLOR_THEME_EARTHY_BASE             (uint16_t)(0x6269)    //  97  79  73
#define COLOR_THEME_EARTHY_DARKER           (uint16_t)(0x3103)    //  48  35  31
#define COLOR_THEME_EARTHY_LIGHTER          (uint16_t)(0x8C30)    // 140 135 129
#define COLOR_THEME_EARTHY_SHADOW           (uint16_t)(0xAB29)    // 173 102  79
#define COLOR_THEME_EARTHY_ACCENT           (uint16_t)(0xFE77)    // 250 204 188

#define COLOR_THEME_SKYBLUE_BASE            (uint16_t)(0x95BF)    // 150 180 255
#define COLOR_THEME_SKYBLUE_DARKER          (uint16_t)(0x73B0)    // 113 118 131
#define COLOR_THEME_SKYBLUE_LIGHTER         (uint16_t)(0xE75F)    // 227 235 255
#define COLOR_THEME_SKYBLUE_SHADOW          (uint16_t)(0x4ACF)    //  75  90 127
#define COLOR_THEME_SKYBLUE_ACCENT          (uint16_t)(0xB5F9)    // 182 188 204

#define TOOLBAR_COLOR COLOR_GRAY_200


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
		_tft->fillRect(0, 115, 160, 13, TOOLBAR_COLOR);
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

void NWA_Display::updateHeading(float heading)
{
	
}

void NWA_Display::updateGPSSatellites(int count)
{
	_tft->fillCircle(18, 122, 4, BLACK);
	_tft->fillCircle(22, 119, 2, TOOLBAR_COLOR);
	_tft->drawCircle(22, 119, 2, BLACK);
	
	_tft->setCursor(26, 118);
	_tft->setTextSize(1);
	_tft->setTextColor(BLACK);
	_tft->print((String)count);

}

void NWA_Display::updateGPSQuality(int quality)
{
	_tft->drawRect(40, 117, 6, 9, BLACK);
	if(quality-1 > 4) { _tft->fillRect(40, 117, 6, 9, BLACK); }
	_tft->drawRect(47, 119, 6, 7, BLACK);
	if(quality-1 > 3) { _tft->fillRect(47, 119, 6, 7, BLACK); }
	_tft->drawRect(54, 121, 6, 5, BLACK);
	if(quality-1 > 2) { _tft->fillRect(54, 121, 6, 5, BLACK); }
	_tft->drawRect(61, 123, 6, 3, BLACK);
	if(quality-1 > 1) { _tft->fillRect(61, 123, 6, 3, BLACK); }
}

void NWA_Display::updateSDAvailability(bool available)
{
	_tft->drawLine(2, 119, 2, 126, BLACK);
	_tft->drawLine(3, 118, 3, 126, BLACK);
	_tft->fillRect(4, 117, 6, 10, BLACK);
	if(!available)
	{
		_tft->drawLine(2, 126, 10, 117, TOOLBAR_COLOR);
	}
}