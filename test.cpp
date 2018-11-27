/**
 * Tests 13 notes on the buzzer
 */
#include <Arduino.h>
#include "tone.h"
#include "config.h"

void scale_test()
{
    play_tone(C , 200);
    play_tone(d , 200);
    play_tone(D , 200);
    play_tone(e , 200);
    play_tone(E , 200);
    play_tone(F , 200);
    play_tone(g , 200);
    play_tone(G , 200);
    play_tone(a , 200);
    play_tone(A , 200);
    play_tone(b , 200);
    play_tone(B , 200);
}

void twinkle()
{
    delay(1000);
    play_tone(C, 500);
    play_tone(C, 500);
    play_tone(G, 500);
    play_tone(G, 500);
    play_tone(nA5, 500);
    play_tone(nA5, 500);
    play_tone(G, 1000);
    play_tone(F, 500);
    play_tone(F, 500);
    play_tone(E, 500);
    play_tone(E, 500);
    play_tone(D, 500);
    play_tone(D, 500);
    play_tone(C, 1000);
}