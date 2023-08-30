#ifndef SIMPLETRAFFIC_H
#define SIMPLETRAFFIC_H

class SimpleTrafficLight{
    public:
    // Constructor
        SimpleTrafficLight(int pin, bool ledON, long onTime, long offTime);
        void setup(long starttime);
        void update(long now);
    private:
    // Private variabler starter altid med _
        enum currentState{
            S0,
            S1,
            S2,
            S3,
            S4,
            S5,
            S6,
            S7
        };
        int _pin;
        bool _ledON;
        long _onTime;
        long _offTime;
        long _nextChange;
        currentState _CurrentState;
        bool _state;
};

#endif