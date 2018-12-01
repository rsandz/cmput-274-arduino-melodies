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
   for (int i = 0; i < num_buzzers; i++)
   {
       pinMode(buzzer_pins[i], OUTPUT); 
   }
}

int main()
{
    Player player;
    setup();
    // scale_test();
    // twinkle();

    float freq[] = {C4, C4, G4, G4, _A5, _A5, G4, G4, -1};
    float freq2[] = {C3, C4, E4, C4, F4, C4, E4, C4, -1};
    int note_length[] = {500, 500, 500, 500, 500, 500, 500, 500};
    int note_length2[] = {500, 500, 500, 500, 500, 500, 500, 500};
    player.assign_voice(freq, note_length, buzzer_pins[0]);
    player.assign_voice(freq2, note_length2, buzzer_pins[1]);
    player.start();
    Serial.print("Done");
    Serial.flush();
    return 0;
}