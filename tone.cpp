/*
    This file handles playing varous tones on 
    a buzzer. 
*/
#include "config.h"
#include <Arduino.h>

/**
 * Plays a tone on the buzzer
 * Algorithm based on arduino intro labs code.
 * @param freq Frequency in Hz
 * @param length In milliseconds
 */
void play_tone(float freq, float length)
{
    float period, half_period, elapsed_time;

    //Period in us
    period = (1 / freq) * 1000000;
    half_period = period / 2;
    elapsed_time = 0;
    
    while (elapsed_time < length * 1000)
    {
        digitalWrite(buzzer1_pin, HIGH);
        delayMicroseconds(half_period);
        digitalWrite(buzzer1_pin, LOW);
        delayMicroseconds(half_period);
        elapsed_time += period;
    }
}