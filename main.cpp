/*
    Main Function
*/

// Includes //
#include "./config.h"
#include "./input.h"
#include "./tone.h"
#include  "./songs.h"
#include  "./utilities.h"
#include <Arduino.h>

/**
 * Setup for lowlevel arduino functionality
 * Also converts beats array into seconds.
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
            convert_to_period(songs[i].tracks[k].beats, beats_per_min,
                beat_arr_length);
        }
    }

}

/**
 * Runs the maual mode of the music player
 * User will be able to press keys in serial mon and 
 * play the buzzers like a piano!
 */
void manual_mode()
{
    char key, sound;
    float freq;

    // Instructions
    Serial.println("Manual Mode Selected");
    Serial.println("See Piano keys in the README.");
    Serial.println("Press `q` to quit.");
    Serial.println("Press 'z', 'x' or 'c' to switch pitch");
    sound = 'x';
    while (true)
    {
        key = get_key();

        // Check if quit or octave switch
        if (key == 'q') break;

        switch (key)
        {
            case 'z':
            {
                Serial.println("Switching to Low Pitch");
                sound = key;
                continue;
                break;
            }
            case 'x':
            {
                Serial.println("Switching to Mid Pitch");
                sound = key;
                continue;
                break;
            }
            case 'c':
            {
                Serial.println("Switching to High Pitch");
                sound = key;
                continue;
                break;
            }
        }

        // Play the Note
        freq = keyboard_to_freq((char) sound, (char) key);

        if (DEBUG)
        {
            Serial.print("Playing Freq: ");
            Serial.println(freq);
        }

        play_tone(freq, manual_note_length);
    }
}

/**
 * Runs the automatic mode of the arduino.
 * The user will be able to select a song and the buzzer will play it.
 * For songs, see song.h
 */
void automatic_mode()
{
    // This is the track player case
    // Ask them wha track do they want to play out of the three
    int song_num;
    float* note_lengths[num_buzzers];

    // Show Instructions
    Serial.print("Current Beats per minute is ");
    Serial.println(beats_per_min);
    Serial.println("Choose a track: ");
    for (int i = 0; i < num_songs; i++)
    {
        Serial.print(i + 1);
        Serial.print(": ");
        Serial.println(songs[i].title);
    }

    // Song selection
    // ============== 
    // Note that '1' == 49 and we want '1' to be equal to int 0
    song_num = (int) get_key() - 49;  
    Serial.print("Song #");
    Serial.print(song_num);
    Serial.println(" was selected");
    if (DEBUG) Serial.print("Assigning Voices...");

    // Create a player to play the song
    Player player;
    player.cycle_length = cycle_length;

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

    Serial.println("===============================");
    Serial.println("WELCOME TO ARDUINO MUSIC PLAYER");
    Serial.println("===============================");
    Serial.println("THE BRAND NEW PIANO AND TRACK PLAYER WITH ALL YOUR FAVOURITE SONGS!");

    // Initialize if the player wants to play the piano or listen to music
    // Loop forever
    char choice;
    char repeat = 'y';
    while ((repeat == 'y') || (repeat == 'Y'))
    {
            Serial.println("Press <p> if you want to play, Press <t> if you want to listen to a track");
            choice = get_key();

            switch( (char) choice)
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

                default:
                {
                    Serial.println("Please press a valid key.");
                    continue;
                }
            }
            Serial.println("Do you want to play again? (y/n)");
            repeat = get_key();
    }
    Serial.println("The Program has quit");
    Serial.flush();
    return 0;
}