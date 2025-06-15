/**
 * Documentation
 * 
 * Virtual Pins:
 *  
 *  V0: Control Pump
 *  V1: Refresh Moisture Percent
 *  V2: Write Moisture Percent
 * 
 * Some thing is wrong with the pump, it is not turning on
 */


#include <moisture.hh>
// Credentials are stored in config.hh
#include <config.hh>

#include <Arduino.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
//#include <pump.hh>

//Pump pump(RELAY_PIN);
MoistureSensor sensor(SENSOR_PIN);

BLYNK_READ(V2)
{
    // Read the moisture percentage and send it to the Blynk app
    int moisture_percent = sensor.get_moisture_percent();
    Blynk.virtualWrite(V2, moisture_percent);
}

void setup() 
{
    Serial.begin(9600);

    // Init Wifi And Blynk
    WiFi.begin(ssid, pass);
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
    
}

void loop() 
{   
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }    
    Blynk.run();
}