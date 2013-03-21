/*
//	NWA_BarometerHelpers.cpp
//	The NarwhAltimeter Library is used to support a helmet embedded visual skydiving altimeter.
//	Authored by: Braden Roseborough
//	License: CC BY-NC-ND 3.0 – http://creativecommons.org/licenses/by-nc-nd/3.0/
//	Copyright 2013
*/
#include "Arduino.h"
#include "NWA_BarometerHelpers.h"

NWA_Barometer::NWA_Barometer()
{
  	_barometer.begin();
  	_initialPressure = _barometer.readPressure();
}

float NWA_Barometer::altitude()
{
    int32_t AltitudeFeet = _barometer.readAltitude(_initialPressure) * 3.280839895;
    float ThousandsFeet = AltitudeFeet/1000;

    return ThousandsFeet;
}