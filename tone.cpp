/*
    This file handles playing varous tones on 
    a buzzer. 
*/
#include "tone.h"
#include "config.h"
#include <Arduino.h>

using namespace std;

/**
 * Plays a single tone on one buzzer
 * Algorithm based on arduino intro labs code.
 * @param freq Frequency in Hz
 * @param length In milliseconds
 */
void play_tone(float freq, float length)
{
    float period, half_period, elapsed_time;
    int buzzer1_pin = buzzer_pins[0];

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

/**
 * Constructor for Player
 */
Player::Player()
{
    total_voices = 0;
    cycle_length = 25;
}

/**
 * Assigns a voice to the player.
 * cycle() will then update the buzzers based on voice in order to make music.
 */

void Player::assign_voice(float* freq, float* note_lengths, int buzzer_pin)
{
    if (total_voices < num_buzzers)
    {
        // Total voices in this case has not been incremented.
        // it can be used to add the nex voice into the voices array
        voices[total_voices].freq_arr = freq;
        voices[total_voices].note_lengths = note_lengths; // In milliseconds
        voices[total_voices].buzzer_pin = buzzer_pin;
        voices[total_voices].song_index = 0;
        voices[total_voices].last_state = 0;
        voices[total_voices].voice_end = false;
        update_next_note(total_voices);
        
        total_voices++;

        if (DEBUG) Serial.println("New Voice Added");
    }
    else
    {
        if (DEBUG) Serial.println("Not enough buzzers. Voice not added");
    }
}

/**
 * Sets the voice to play the next note
 * @param int voice_index The voice index to change
 */
void Player::update_next_note(int voice_index)
{
    double period;
    Voice* voice = voices + voice_index;
    
    // Check if song is done
    if (voice->freq_arr[voice->song_index] == -1 || voice->voice_end == true)
    {
        voice->voice_end = true;
        return;
    }

    // Update the voice's properties as needed
    period = (1 / (voice->freq_arr[voice->song_index])) * 1000000L;
    voice->us_half_period = (long) period / 2L;
    voice->us_toggle = voice->us_half_period;
    voice->us_end = (voice->note_lengths[voice->song_index]) * 1000L;
    voice->song_index ++;

    if (DEBUG)
    {
        Serial.print("Playing ");
        Serial.print(voice->freq_arr[voice->song_index]);
        Serial.print("Hz at period ");
        Serial.print(period);
        Serial.print("us for ");
        Serial.print(voice->us_end);
        Serial.println(" us");
    }
}

/**
 * Causes the buzzer of a voice to toggle high or low.
 * @param Voice voice The voice to toggle
 */
void Player::toggle_voice_buzzer(int voice_index)
{
    Voice* voice = voices + voice_index;
    
    // Toggle
    digitalWrite(voice->buzzer_pin, !voice->last_state);
    voice->last_state = !voice->last_state;
    voice->us_toggle = voice->us_half_period;
}

/**
 * Decrements the us_half_period and us_end in voices
 * @param Voice voice
 */
void Player::decrement_times(int voice_index)
{
    Voice* voice = voices + voice_index;
    voice->us_end -= cycle_length;
    voice->us_toggle -= cycle_length;
}

/**
 * Cycles through each buzzer and updates their state, 
 * current note and time tracking.
 * Cycle must be ran in a loop as fast as possible
 */
void Player::cycle()
{
    // Check if time for a cycle
    if (micros() - last_cycle <= cycle_length)
    {
        return;
    }

    for (int i = 0; i < total_voices; i++)
    {
        // Check if time to update to next note
        if (voices[i].us_end <= 0)
        {
            update_next_note(i);
        }
        
        // Check if voice is done
        if (voices[i].voice_end)
        {
            continue;
        }
        
        // Check if time to toggle buzzer pin
        if (voices[i].us_toggle <= 0)
        {
            toggle_voice_buzzer(i);
        }

        decrement_times(i);
    }
    last_cycle = micros();
}

/**
 * Starts the player to play the song
 */
void Player::start()
{
    int done_voices = 0;
    while (true)
    {
        cycle();

        // Check if song is done
        done_voices = 0;
        for (int i = 0; i < total_voices; i++)
        {
            if (voices[i].voice_end)
            {
                done_voices++;
            }
        }

        if (done_voices == total_voices)
        {
            // Song is done
            return;
        }
    }
}

