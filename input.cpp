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
    Serial.print((char) key);
    switch((char) key)
    {
        //all the whites
        case 'd': 
            note = A; // frequency for A 
            break;

        case 'f': 
            note = B; // frequency for B 
            break;

        case 'g': 
            note = C; // frequency for C
            break;

        case 'h': 
            note = D; // frequency for D 
            break;

        case 'j': 
            note = E; // frequency for E
            break;
        
        case 'k': 
            note = F; // frequency for F
            break;
        
        //now the black parts 
        case 'r': 
            note =  d; // frequency for d
            break;

        case 't': 
            note =  e; // Frequency for e
            break;

        case 'y': 
            note =  g; // frequency for g
            break;

        case 'u':  
            note =  a; // frequency for a
            break;

        case 'i': 
            note =  b; // frequency for b
            break;
        
        // now the other case 
        default: note = 0;
    }

    return note;
}