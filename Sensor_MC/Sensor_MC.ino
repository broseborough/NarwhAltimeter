#include <SPI.h>
#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>
#include <SD.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>

#include <EasyTransfer.h>
EasyTransfer ET;

#include "NWA_Message.h"
#include "NarwhAltimeter_Sensors.h"
NarwhAltimeter_Sensors *NWA_Sensors; 

//give a name to the group of data
NWA_Message nwa_message;

void setup(){
  Serial.begin(9600);
  ET.begin(details(nwa_message), &Serial);
}

void loop(){
  ET.sendData();

  delay(500);
}
