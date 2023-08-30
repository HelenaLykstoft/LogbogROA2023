#ifndef BUTTONLIGHT_H
#define BUTTONLIGHT_H

class ButtonLight{
    public:
    // Constructor
        ButtonLight(int pin, bool ledON, long onTime, long offTime);
        void setup(long starttime);
        void update(long now);
    private:
    // Private variabler starter altid med _
        int _pin;
        bool _ledON;
        long _onTime;
        long _offTime;
        long _nextChange;
        bool _state;
};

#endif