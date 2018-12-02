/** 
 * Description: 
 * This file will convert all of our key board inputs into musical notes as if a real piano were to be playing 
 */

#include <Arduino.h>
#include "config.h"

/**
 * This function uses a switch statement to assign frequencies to the key values.Then it passes the key 
 * frequency value to the main() function which will decide what frequency or musical note to play for the corresponding keys 
 * pressed.
 * @key char stores the ascii value of the key pushed on the keyboard
 * @note float  holds the musical notes or frequencies associated with the corresponding keys 
 */
float keyboard_to_freq(char sound, char key)
{
//paino key board only recognizes the "d"to "k" for the white parts, "r" to "i" for the black parts. 
    float note;
    // 12 cases  11 for the piano and 1 for all other keys 
    switch(sound)
    {
        case 'z':
        {
            switch(key)
            {
                //all the whites
                case 'd': 
                    note = C3; 
                    break;

                case 'f': 
                    note = D3;
                    break;

                case 'g': 
                    note = E3; 
                    break;

                case 'h': 
                    note = F3; 
                    break;

                case 'j': 
                    note = G3; 
                    break;
                
                case 'k': 
                    note = _A3; 
                    break;

                case 'l': 
                    note = B3; 
                    break;
                case ';': 
                    note = C4; 
                    break;
                
                //now the black parts 
                case 'r': 
                    note =  d3; 
                    break;

                case 't': 
                    note =  e3; 
                    break;

                case 'u': 
                    note =  g3; 
                    break;

                case 'i':  
                    note =  a3; 
                    break;

                case 'o': 
                    note =  b3; 
                    break;
                
                // now the other case 
                default: note = 0;
            }  
            break;
        }

        //second case of frequiencies 
         case 'x':
        {
            switch((char) key)
            {
                //all the whites
                case 'd': 
                    note = C4; 
                    break;

                case 'f': 
                    note = D4;
                    break;

                case 'g': 
                    note = E4; 
                    break;

                case 'h': 
                    note = F4; 
                    break;

                case 'j': 
                    note = G4; 
                    break;
                
                case 'k': 
                    note = _A4; 
                    break;

                case 'l': 
                    note = B4; 
                    break;
                
                case ';': 
                    note = C5; 
                    break;
                
                //now the black parts 
                case 'r': 
                    note =  d4; 
                    break;

                case 't': 
                    note =  e4; 
                    break;

                case 'u': 
                    note =  g4; 
                    break;

                case 'i':  
                    note =  a4; 
                    break;

                case 'o': 
                    note =  b4; 
                    break;
                
                
                // now the other case 
                default: note = 0;
            }  
            break;
        }

        //third case of frequiencies 
         case 'c':
        {
            switch(key)
            {
                //all the whites
                case 'd': 
                    note = C5; 
                    break;

                case 'f': 
                    note = D5;
                    break;

                case 'g': 
                    note = E5; 
                    break;

                case 'h': 
                    note = F5; 
                    break;

                case 'j': 
                    note = G5; 
                    break;
                
                case 'k': 
                    note = _A5; 
                    break;

                case 'l': 
                    note = B5; 
                    break;
                
                case ';': 
                    note = C6; 
                    break;
                
                //now the black parts 
                case 'r': 
                    note =  d5; 
                    break;

                case 't': 
                    note =  e5; 
                    break;

                case 'u': 
                    note =  g5; 
                    break;

                case 'i':  
                    note =  a5; 
                    break;

                case 'o': 
                    note =  b5; 
                    break;
                
                // now the other case 
                default: note = 0;
            }  
            break;
        }
        // now the other case 
        default: note = 0;
    }

    return note;
}