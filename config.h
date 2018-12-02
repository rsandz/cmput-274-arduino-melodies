/*
    Configuration File
#define CONFIG_H 
*/

#ifndef CONFIG_H
# define CONFIG_H

const int num_buzzers = 2;
const int buzzer_pins[] = {12, 11};
const int DEBUG = true;
const int beats_per_min = 100;

// Definitions for some Notes
// Note: we put _ infrom of 'A's to prevent name collision
// with arduino analog pin

//Naturals
const float _A3 = 220.0000;
const float B3 = 246.9417;
const float C3 = 261.6256;
const float D3 = 293.6648;
const float E3 = 329.6276;
const float F3 = 349.2282;
const float G3 = 391.9954;
const float _A4 = 440.0000;
const float B4 = 493.8833;
const float C4 = 523.2511;
const float D4 = 587.3295;
const float E4 = 659.2551;
const float F4 = 698.4565;
const float G4 = 783.9909;
const float _A5 = 880.000;
const float B5 = 987.7666;
const float C5 = 1046.502;
const float D5 = 1174.659;
const float E5 = 1318.510;
const float F5 = 1396.913;
const float G5 = 1567.982;
const float _A6 = 1760.000;

//Flats
const float a4 = 415.3047;
const float b4 = 466.1638;
const float d4 = 554.3653;
const float e4 = 622.2540;
const float g4 = 739.9888;

#endif
