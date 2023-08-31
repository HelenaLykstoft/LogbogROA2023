#ifndef SIMPLETRAFFIC_H
#define SIMPLETRAFFIC_H

class SimpleTrafficLight{
    public:
    // Constructor
        SimpleTrafficLight(int ledRed, int ledYellow, int ledGreen, int ledRed2, int ledYellow2, int ledGreen2, bool ledON, long onTime, long offTime);
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
        int _ledRed;
        int _ledYellow;
        int _ledGreen;
        int _ledRed2;
        int _ledYellow2;
        int _ledGreen2;
        bool _ledON;
        long _onTime;
        long _offTime;
        long _nextChange;
        currentState _CurrentState;
        bool _state;
};

#endif