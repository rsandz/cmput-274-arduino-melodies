/*
    Configuration File
*/

#ifndef CONFIG_H
#define CONFIG_H

// Change as needed
const int num_buzzers = 2;
const int buzzer_pins[] = {12, 11};
const int DEBUG = false; // Set to true to enable debug output
const int beats_per_min = 116; // Default 140
const int manual_note_length = 150; // Note length per press in manual mode

// How many us to wait till updating buzzers
// Higher numbers allow for more true sounds, at the cost of 
// error in frequencies.
const int cycle_length = 28; 

// Definitions for some Notes
// DO NOT CHANGE!
// Note: we put _ in front of 'A's to prevent name collision
// with arduino analog pin

// Naturals
const float C2 = 65.40639;
const float D2 = 73.41619;
const float E2 = 82.40689;
const float F2 = 87.30706;
const float G2 = 97.99886;
const float _A2 = 110.0000;
const float B2 = 123.4708;
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

// Flats

const float e1 = 38.89087;
const float a1 = 51.91309;
const float d2 = 69.29566;
const float e2 = 77.78175;
const float g2 = 92.49861;
const float a2 = 103.8262;
const float b2 = 116.5409;
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
