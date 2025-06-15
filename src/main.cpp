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

// Blynk timer
BlynkTimer timer;

// Set the Idead Moisture Percentage
BLYNK_WRITE(V0) {
    int alert_moisture_percentage = param.asInt();
    sensor.set_alert_moisture_percentage(alert_moisture_percentage);
}

void send_values() {
    int moisture_percent = sensor.get_moisture_percent();
    bool is_dry = sensor.is_dry();

    Blynk.virtualWrite(V2, moisture_percent);
    Blynk.virtualWrite(V1, is_dry ? 1 : 0);
}

void setup() 
{
    Serial.begin(9600);
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

    timer.setInterval(10000L, send_values);
    
}

void loop() 
{   
    while (Blynk.connected() == false)
    {
        Serial.println("Connecting to Blynk...");
        Blynk.connect();
        delay(1000);
    }
    Blynk.run();
    timer.run();
}