/*
    Main Function
*/

// Includes //
#include "config.h"
#include "input.h"
#include "tone.h"
#include "test.h"
#include <Arduino.h>

/**
 * Setup for lowlevel arduino functionality
 */
void setup()
{
    init();
    Serial.begin(9600);

   // Setup buzzer pins
   pinMode(buzzer1_pin, OUTPUT); 
}

int main()
{
    char key;
    float freq;
    setup();
    scale_test();
    twinkle();
    while (true)
    {
        if(Serial.available()>0)
        {
            key = Serial.read();
            Serial.println(key); //just for testing take it out later!
            freq = keyboard_to_freq((char) key);
            Serial.print("Playing Freq: ");
            Serial.println(freq);
            play_tone(freq, 150);
        }
    }
    return 0;
}