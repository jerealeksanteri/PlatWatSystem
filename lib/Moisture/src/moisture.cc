
#include <Arduino.h>
#include <moisture.hh>

MoistureSensor::MoistureSensor(int sensor_pin)
{   
    _sensor_pin = sensor_pin;
    Serial.println("Moisture Sensor initialized!");
}

MoistureSensor::~MoistureSensor()
{
    // Destroy here if something comes up
}


int MoistureSensor::get_moisture_percent()
{   
    // Use the public function to get raw data
    int moisture_raw = get_moisture_raw();

    // Convert with baselines to percent
    int moisture_percent = map(moisture_raw, _dry_baseline, _wet_baseline, 0, 100);
    
    // Constrain it 0-100
    moisture_percent = constrain(moisture_percent, 0, 100);
    
    Serial.println("Soil Moisture Percent:" + String(moisture_percent) + "%");

    return moisture_percent;
}

int MoistureSensor::get_moisture_raw()
{   
    // Get raw data from the analog pin
    int moisture_raw = analogRead(_sensor_pin);
    Serial.println("Raw Moisture Value Read: " + String(moisture_raw));
    return moisture_raw;
}

void MoistureSensor::set_dry_baseline(int value)
{
    _dry_baseline = value;
    Serial.println("Dry Baseline Value Set: " + String(value));
};

void MoistureSensor::set_wet_baseline(int value)
{
    _wet_baseline = value;
    Serial.println("Wet Baseline Value Set: " + String(value));
};

void MoistureSensor::set_alert_moisture_percentage(int percentage)
{
    _alert_moisture_percentage = percentage;
    Serial.println("Alert Moisture Percentage Set: " + String(percentage) + "%");
};

int MoistureSensor::get_alert_moisture_percentage()
{
    Serial.println("Alert Moisture Percentage: " + String(_alert_moisture_percentage) + "%");
    return _alert_moisture_percentage;
}

bool MoistureSensor::is_dry()
{
    int moisture_percent = get_moisture_percent();
    bool is_dry = moisture_percent < _alert_moisture_percentage;
    Serial.println("Is Dry: " + String(is_dry));
    return is_dry;
}
