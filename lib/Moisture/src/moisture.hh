
class MoistureSensor {
    public:

        MoistureSensor(int sensor_pin);
        ~MoistureSensor();

        int get_moisture_percent();
        int get_moisture_raw();

        void set_dry_baseline(int value);
        void set_wet_baseline(int value);

        void set_ideal_moisture_percentage(int percentage);
        int get_ideal_moisture_percentage();

        bool is_dry();
        bool is_wet();

    private:
        int _dry_baseline = 2600; // Air-dry soild raw value
        int _wet_baseline = 1300; // Fully. wet soil raw value
        int _ideal_moisture_percentage; // Ideal moisture percentage (0-100)
        int _sensor_pin = 0;
};