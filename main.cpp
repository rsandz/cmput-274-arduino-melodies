/*
    Main Function
*/

// Includes //
#include "input.h"
#include "tone.h"
#include "config.h"
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
    setup();
    play_tone(523.2511, 500);
    play_tone(523.2511, 500);
    play_tone(783.9909, 500);
    play_tone(783.9909, 500);
    play_tone(880.0000, 500);
    play_tone(880.0000, 500);
    play_tone(783.9909, 500);
    return 0;
}