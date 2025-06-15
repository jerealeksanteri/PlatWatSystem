
class MoistureSensor {
    public:

        MoistureSensor(int sensor_pin);
        ~MoistureSensor();

        int get_moisture_percent();
        int get_moisture_raw();

        void set_dry_baseline(int value);
        void set_wet_baseline(int value);

        void set_alert_moisture_percentage(int percentage);
        int get_alert_moisture_percentage();

        // Check if the soil is dry based on the alert moisture percentage
        bool is_dry();

    private:
        int _dry_baseline = 3000; // Air-dry soild raw value
        int _wet_baseline = 1300; // Fully. wet soil raw value
        int _alert_moisture_percentage; // Ideal moisture percentage (0-100)
        int _sensor_pin = 0;
};