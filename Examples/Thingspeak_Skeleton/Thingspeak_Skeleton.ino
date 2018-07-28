/*
  WriteMultipleVoltages
  
  Reads analog voltages from pins 0-7 and writes them to the 8 fields of a channel on ThingSpeak every 20 seconds.
  
  ThingSpeak ( https://www.thingspeak.com ) is an analytic IoT platform service that allows you to aggregate, visualize and 
  analyze live data streams in the cloud.
  
  Copyright 2017, The MathWorks, Inc.
  
  Documentation for the ThingSpeak Communication Library for Arduino is in the extras/documentation folder where the library was installed.
  See the accompaning licence file for licensing information.
*/

#include "ThingSpeak.h"

// ***********************************************************************************************************
// This example selects the correct library to use based on the board selected under the Tools menu in the IDE.
// Yun, Ethernet shield, WiFi101 shield, esp8266, and MXR1000 are all supported.
// With Yun, the default is that you're using the Ethernet connection.
// If you're using a wi-fi 101 or ethernet shield (http://www.arduino.cc/en/Main/ArduinoWiFiShield), uncomment the corresponding line below
// ***********************************************************************************************************

    #include <ESP8266WiFi.h>
char ssid[] = "IoT Geeks Guest";    //  your network SSID (name) 
char pass[] = "iotgeeks@2018";    // your network password
    int status = WL_IDLE_STATUS;
    WiFiClient  client;
  


/*
  *****************************************************************************************
  **** Visit https://www.thingspeak.com to sign up for a free account and create
  **** a channel.  The video tutorial http://community.thingspeak.com/tutorials/thingspeak-channels/ 
  **** has more information. You need to change this to your channel, and your write API key
  **** IF YOU SHARE YOUR CODE WITH OTHERS, MAKE SURE YOU REMOVE YOUR WRITE API KEY!!
  *****************************************************************************************/
unsigned long myChannelNumber = 549022;
const char * myWriteAPIKey = "OBM5Q0ITVDMU9IGH";

void setup() {

      WiFi.begin(ssid, pass);
      ThingSpeak.begin(client);
  
}

void loop() {

  float pinVoltage = 100;//GIve the sensorvalue here;
  ThingSpeak.setField(1,pinVoltage);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);  
  delay(20000);
}
