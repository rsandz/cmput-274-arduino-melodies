/*
    Contains the songs for the buzzers
*/
#include "config.h"


#ifndef SONGS_H
#define SONGS_H

/*
================
|   Structs    |
================
*/

struct Track
{
    float freq[100];
    float beats[100];
};

struct Song 
{
    struct Track tracks[2];
};

/*
===============
|   Songs     |
===============
*/

struct Song twinkle_twinkle = 
{
    {
        // Track 0
        {
            // Freq
            {
                C4, C4, G4, G4, _A5, _A5, G4, G4, F4, F4, E4, E4, D4, D4, E4, C4, 
                G4, G4, F4, F4, E4, E4, D4, D4, 
                G4, G4, F4, F4, E4, E4, D4, D4,
                C4, C4, G4, G4, _A5, _A5, G4, G4, F4, F4, E4, E4, D4, D4, E4, C4,
                -1
            },

            // Beats
            {
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.75, 0.25, 2,
                1, 1, 1, 1, 1, 1, 1 ,1, 
                1, 1, 1, 1, 1, 1, 1, 1,
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.75, 0.25, 2,
            }
        },

        // Track 1
        {
            //Freq
            {
                C3, C4, E4, C4, F4, C4, E4, C4, D4, B4, C4, _A3, F3, G3, C3, 
                E4, G3, D4, G3, C4, G3, B3, G3, 
                E4, G3, D4, G3, C4, C4, D4, C4, B4,
                C3, C4, E4, C4, F4, C4, E4, C4, D4, B4, C4, _A3, F3, G3, C3,
                -1
            },

            // Beats
            {
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
                1, 1, 1, 1, 1, 1, 1, 1, 
                1, 1, 1, 1, 1, 0.75, 0.25, 1, 1,
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
            }
        }
    },
};

#endif
