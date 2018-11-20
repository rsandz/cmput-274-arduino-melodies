/** 
 * Description: 
 * This file will convert all of our key board inputs into musical notes as if a real piano were to be playing 
 */

#include <Arduino.h>
#include "config.h"
// #include <Keyboard.h>

/**
 * This function uses a switch statement to assign frequencies to the key values.Then it passes the key 
 * frequency value to the main() function which will decide what frequency or musical note to play for the corresponding keys 
 * pressed.
 * @key char stores the ascii value of the key pushed on the keyboard
 * @note float  holds the musical notes or frequencies associated with the corresponding keys 
 */
float keyboard_to_freq(char key)
{
//paino key board only recognizes the "d"to "k" for the white parts, "r" to "i" for the black parts. 
    float note;
    // 12 cases  11 for the piano and 1 for all other keys 
    switch(key)
    {
        //all the whites 
        case 'd': note = A; // frequency for A 

        case 'f': note = B; // frequency for B 

        case 'g': note = C; // frequency for C

        case 'h': note = D; // frequency for D 

        case 'j': note = E; // frequency for E
        
        case 'k': note = A; // frequency for F
        
        //now the black parts 
        case 'r': note =  A; // frequency for d

        case 't': note =  A; // Frequency for e

        case 'y': note =  A; // frequency for g

        case 'u': note =  A; // frequency for a

        case 'i': note =  A; // frequency for b
        
        // now the other case 
        default: note = 0;
    }

    return note;
}