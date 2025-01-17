
#include <Arduino.h>
#include <pump.hh>

Pump::Pump(int relay_pin)
{   
    _relay_pin = relay_pin;
    _is_turned_on = false;
    
    pinMode(relay_pin, OUTPUT);

    // Start with the relay off
    digitalWrite(relay_pin, LOW);  

    Serial.println("Pump initialized!");
}

Pump::~Pump()
{
    // Destroy here if something comes up
    turn_off();
}

void Pump::turn_on()
{
    if (_is_turned_on) {
        Serial.println("Pump is already turned on!!!");
        return;
    }

    digitalWrite(_relay_pin, HIGH);  // Turn relay (and pump) on
    _is_turned_on = true;
    Serial.println("Pump is on!");
}

void Pump::turn_off()
{
    if (!_is_turned_on) {
        Serial.println("Pump is already turned off!!!");
        return;
    }
    digitalWrite(_relay_pin, LOW); // Turn relay (and pump) off
    _is_turned_on = false;
    Serial.println("Pump is off!");
}

void Pump::water_for(float seconds)
{
    int time = seconds * 1000;

    Serial.println("Pump will be on for  " + String(time) + " ms...");
    

    turn_on();
    delay(time);
    turn_off();

}
