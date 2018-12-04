/*
    Main Function
*/

// Includes //
#include "config.h"
#include "input.h"
#include "tone.h"
#include "test.h"
#include  "songs.h"
#include  "utilities.h"
#include <Arduino.h>

/**
 * Setup for lowlevel arduino functionality
 */
void setup()
{
    int beat_arr_length;
    init();
    Serial.begin(9600);

    // Setup buzzer pins
    for (int i = 0; i < num_buzzers; i++)
    {
        pinMode(buzzer_pins[i], OUTPUT); 
    }

    // Convert each beats array in songs into ms (period)
    // We do this in setup so it doesn't have to do it when the song is loaded
    for (int i = 0; i < num_songs; i++)
    {
        for (int k = 0; k < songs[i].num_voices; k++)
        {
            beat_arr_length = sizeof(songs[i].tracks[k].beats) / 
                sizeof(songs[i].tracks[k].beats[0]);
            convert_to_period(songs[i].tracks[k].beats, beats_per_min, beat_arr_length);
        }
    }

}

/**
 * Gets the last key that the user presses.
 * This function is Blocking
 */
char get_key()
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

/**
 * Runs the maual mode of the music player
 * User will be able to press keys in serial mon and 
 * play the buzzers like a piano!
 */
void manual_mode()
{
    // keyboard piano player 
    char key, sound;
    float freq;
    Serial.print("Pick a setting that you want to play: z - Low pitch, x - Mid Pitch, c - High Pitch");
    sound = get_key();
    while (true)
    {
        key = get_key(); //Serial.read();
        freq = keyboard_to_freq((char) sound, (char) key);
        
        if (DEBUG)
        {
            Serial.print("Playing Freq: ");
            Serial.println(freq);
        }
        play_tone(freq, 150);
    }
}

/**
 * Runs the automatic mode of the arduino.
 * The user will be able to select a song and the buzzer will play it.
 * For songs, see song.h
 */
void automatic_mode()
{
    //This is the track player case 
    // Ask them wha track do they want to play out of the three ---> nested Switch statements 
    int song_num;
    float* note_lengths[num_buzzers];

    Serial.println("Choose a track: ");
    for (int i = 0; i < num_songs; i++)
    {
        Serial.print(i + 1);
        Serial.print(": ");
        Serial.println(songs[i].title);
    }

    song_num = (int) get_key() - 49; // Note that '1' == 49 and we want '1' to be equal to int 0
    Serial.println(song_num);
    if (DEBUG) Serial.print("Assigning Voices...");

    // Create a player to play the song
    Player player;

    for (int i = 0; i < songs[song_num].num_voices; i++)
    {
        note_lengths[i] = songs[song_num].tracks[i].beats;
        player.assign_voice(songs[song_num].tracks[i].freq, note_lengths[i], buzzer_pins[i]);
    }

    // Play the song
    player.start();
}

int main()
{
    setup();
    Serial.print("WELCOME TO ARDUINO MUSIC PLAYER");
    Serial.print("THE BRAND NEW PIANO AND TRACK PLAYER WITH ALL YOUR FAVOURITE CHRISTMAS SONGS!")

    // Initailize if the player wants to play the piano or listen to music 
    char choice;
    char repeat = 'y';
    while ((repeat == 'y') || (repeat == 'Y'))
    {
            Serial.println("Press <p> if you want to play, Press <t> if you want to listen to a track");
            choice = get_key();

            switch((char) choice)
            {
                // Manual Mode
                case 'p':
                {
                    manual_mode();
                    break; 
                }

                // Automatic Mode
                case 't':
                {
                    automatic_mode();
                    break;
                }

                default: Serial.print("Error: Please start again");
            }
            Serial.print("Do you want to play again? (y/n)");
            repeat = get_key();
    }
    Serial.print("Done");
    Serial.flush();
    return 0;

}
