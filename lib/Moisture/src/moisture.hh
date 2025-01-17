using namespace std;

class MoistureSensor {
    public:

        MoistureSensor(int sensor_pin);
        ~MoistureSensor();

        int get_moisture_percent();
        int get_moisture_raw();

        void set_dry_baseline(int value);
        void set_wet_baseline(int value);


    private:
        int _dry_baseline = 2600;
        int _wet_baseline = 1300;
        int _sensor_pin = 0;
};