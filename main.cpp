/*
    Main Function
*/

// Includes //
#include "config.h"
#include "input.h"
#include "tone.h"
#include "test.h"
#include <Arduino.h>
#include  "songs.h"

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

char check()
{ 
    char check;
    while (true)
    {
        if(Serial.available()>0)
        {
           check = Serial.read(); 
           break;
        }
    }
    return check;
}

void manual_loop()
{
    // keyboard piano player 
    char key;
    float freq;
    while (true)
    {
        key = check(); //Serial.read();
        Serial.println(key); //just for testing take it out later!
        freq = keyboard_to_freq((char) key);
        Serial.print("Playing Freq: ");
        Serial.println(freq);
        play_tone(freq, 150);
    }
}

void automatic_loop()
{
    //This is the track player case 
    // Ask them wha track do they want to play out of the three ---> nested Switch statements 
    int track;
    Serial.println("Choose a track: 1-twinkle twinkle, 2-hicory dickory dock, 3-ABC");
    track = check();
    switch( track)
    {
        //twinkle twinkle track 
        case 1:
        {

            break;
        }

        //Hicory Dickory Dock 
        case 2:
        {
            break;
        }

        //ABC
        case 3:
        {
            break;
        }
    }
}

int main()
{
    setup();

    // Initailize if the player wants to play the piano or listen to music 
    char choice;

    Serial.println("Press <p> if you want to play, Press <t> if you want to listen to a track");
    choice = check();

    switch((char) choice)
    {
        // Manual Mode
        case 'p':
        {
            manual_loop();
            break; 
        }

        // Automatic Mode
        case 't':
        {
            automatic_loop();
            break;
        }

        default: Serial.print("Error: Please start again");
    }

    return 0;
}