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


#define RELAY_PIN 5  // Control pin connected to the relay's IN pin
#define SENSOR_PIN 34 // Capacitive Soil Sensor


#include <Arduino.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <pump.hh>
#include <moisture.hh>
// Credentials are stored in config.hh
#include <config.hh>




Pump pump(RELAY_PIN);
MoistureSensor sensor(SENSOR_PIN);

// Control Pump
BLYNK_WRITE(V0)
{
    int button_state = param.asInt();
    
    if (button_state == 1)
    {
        //pump.turn_on();
        digitalWrite(RELAY_PIN, HIGH);
        delay(50);
    }
    else
    {
        //pump.turn_off();
        digitalWrite(RELAY_PIN, LOW);
        delay(50);
    }

}

// Refresh Moisture Value
BLYNK_WRITE(V1)
{
    int button_state = param.asInt();

    if (button_state == 1)
    {
        int moisture_percent = sensor.get_moisture_percent();
        Blynk.virtualWrite(V2, moisture_percent);
    }
    else
    {
        Blynk.virtualWrite(V1, 0);
    }
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