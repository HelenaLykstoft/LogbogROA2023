#ifndef BUTTON_H
#define BUTTON_H


class Button{
    public:
    // Constructor
        Button(int pin, bool buttonDown);
        bool getButtonState();
        void setup(long startTime);
        void update(long currentTime);
    private:
    // Private variabler starter altid med _
        enum ButtonState{
        BUTTON_OFF,
        BUTTON_PUSH,
        BUTTON_ON,
        BUTTON_RELEASE
        };
        const static long _noiseCancelTimer = 10;
        int _pin;
        bool _buttonDown;
        ButtonState _ButtonState;
        long _nextChangeTime;
};

#endif // BUTTON_H