/*
//	The NarwhAltimeter Library is used to support a helmet embedded visual skydiving altimeter.
//	Authored by: Braden Roseborough
//	License: CC BY-NC-ND 3.0 – http://creativecommons.org/licenses/by-nc-nd/3.0/
//	Copyright 2013
*/
#ifndef NWA_Message_h
#define NWA_Message_h

struct NWA_Message
{
  boolean sd;
  boolean gps_fix;
  int gps_fix_quality;
  int gps_satelites;
  int altitude;
};

#endif