using namespace std;

class Pump {
    public:

        Pump(int relay_pin);
        ~Pump();

        void turn_on();
        void turn_off();
        void water_for(float seconds);

    private:

        int _relay_pin = 0;
        bool _is_turned_on;

};