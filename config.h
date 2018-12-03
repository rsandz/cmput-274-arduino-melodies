/*
    Configuration File
#define CONFIG_H 
*/

#ifndef CONFIG_H
# define CONFIG_H

const int num_buzzers = 2;
const int buzzer_pins[] = {12, 11};
const int DEBUG = true;
const int beats_per_min = 140;

// Definitions for some Notes
// Note: we put _ infrom of 'A's to prevent name collision
// with arduino analog pin

//Naturals
const float C3 = 130.8128;
const float D3 = 146.8324;
const float E3 = 164.8138;
const float F3 = 174.6141;
const float G3 = 195.9977;
const float _A3 = 220.0000;
const float B3 = 246.9417;
const float C4 = 261.6256;
const float D4 = 293.6648;
const float E4 = 329.6276;
const float F4 = 349.2282;
const float G4 = 391.9954;
const float _A4 = 440.0000;
const float B4 = 493.8833;
const float C5 = 523.2511;
const float D5 = 587.3295;
const float E5 = 659.2551;
const float F5 = 698.4565;
const float G5 = 783.9909;
const float _A5 = 880.000;
const float B5 = 987.7666;
const float C6 = 1046.502;
const float D6 = 1174.659;
const float E6 = 1318.510;
const float F6 = 1396.913;
const float G6 = 1567.982;
const float _A6 = 1760.000;

//Flats
const float d3 = 138.5913;
const float e3 = 155.5635;
const float g3 = 184.9972;
const float a3 = 207.6523;
const float b3 = 233.0819;
const float d4 = 277.1826;
const float e4 = 311.1270;
const float g4 = 369.9944;
const float a4 = 415.3047;
const float b4 = 466.1638;
const float d5 = 554.3653;
const float e5 = 622.2540;
const float g5 = 739.9888;
const float a5 = 830.6094;
const float b5 = 932.3275;
const float d6 = 1108.731;
const float e6 = 1244.508;
const float g6 = 1479.978;

#endif
