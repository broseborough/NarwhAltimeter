#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>

#include <EasyTransfer.h>
EasyTransfer ET; 

#include "NarwhAltimeter_Display.h"
NarwhAltimeter_Display *NWA_Display;

struct NWA_Message{
  boolean sd;
  boolean gps_fix;
  int gps_fix_quality;
  int gps_satelites;
  int altitude;
};

NWA_Message nwa_message;

void setup(){
  Serial.begin(9600);
  ET.begin(details(nwa_message), &Serial);
}

void loop(){
  if(ET.receiveData()){}
  
  //you should make this delay shorter then your transmit delay or else messages could be lost
  delay(100);
}
