/**
 * Tests 13 notes on the buzzer
 */
#include <Arduino.h>
#include "tone.h"
#include "config.h"

/**
 * Plays a chromatic scale
 */
void scale_test() {
    play_tone(a4 , 200);
    play_tone(_A4 , 200);
    play_tone(b4 , 200);
    play_tone(B4 , 200);
    play_tone(C4 , 200);
    play_tone(d4 , 200);
    play_tone(D4 , 200);
    play_tone(e4 , 200);
    play_tone(E4 , 200);
    play_tone(F4 , 200);
    play_tone(g4 , 200);
    play_tone(G4 , 200);
}

/**
 * Plays twinkle twinkle little star
 */
void twinkle() {
    delay(1000);
    play_tone(C4, 500);
    play_tone(C4, 500);
    play_tone(G4, 500);
    play_tone(G4, 500);
    play_tone(_A5, 500);
    play_tone(_A5, 500);
    play_tone(G4, 1000);
    play_tone(F4, 500);
    play_tone(F4, 500);
    play_tone(E4, 500);
    play_tone(E4, 500);
    play_tone(D4, 500);
    play_tone(D4, 500);
    play_tone(C4, 1000);
}
