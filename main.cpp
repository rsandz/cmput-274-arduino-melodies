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
    setup();
    scale_test();
    Serial.print("Done Playing A");
    return 0;
}