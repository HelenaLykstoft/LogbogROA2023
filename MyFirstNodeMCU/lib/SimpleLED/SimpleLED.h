// If not defined, dvs. hvis der allerede er noget der hedder SIMPLELED_H så skal den køre ned til end if
#ifndef SIMPLELED_H
#define SIMPLELED_H


class SimpleLED{
    // Man skriver alle sine public ting først, fordi det er mere interessant for læseren hvad der er public
    public:
    // Constructor
        SimpleLED(int pin, bool ledON, long onTime, long offTime);
        void setup(long startTime);
        void update(long now);
    private:
    // Private variabler starter altid med _
        int _pin;
        // ledON = hvilken værdi den skal have for at den er tændt
        bool _ledON;
        long _onTime;
        long _offTime;
        long _nextChange;
        bool _state;
};

#endif