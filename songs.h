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

/**
 * Holds the 'voice' for a song
 * Each voice has a frequency to play,
 * and it's corresponding length to play it at.
 * Eacb track occupies one buzzer. i.e. 1 track per buzzer
 */
struct Track {
    // Note, max length per track is 100 notes
    float freq[90];
    float beats[90];
};

/**
 * Holds several tracks (a.k.a. voices)
 * Can be loaded into a player in order to play a song.
 */
struct Song {
    char title[30];
    int num_voices;
    struct Track tracks[2];
};

/*
===============
|   Songs     |
===============
*/

/* Update this whenever you add a song!*/
const int num_songs = 4;
struct Song songs[] =
{
    {
        "Twinkle Twinkle Little Star", // Title
        2, // Number of voices
        {
            // Track 0
            {
                // Freq
                {
                    C4, C4, G4, G4, _A4, _A4, G4, G4, F4, F4, E4, E4, D4, D4, E4, C4, 
                    G4, G4, F4, F4, E4, E4, D4, D4, 
                    G4, G4, F4, F4, E4, E4, D4, D4,
                    C4, C4, G4, G4, _A4, _A4, G4, G4, F4, F4, E4, E4, D4, D4, E4, C4,
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
                    C4, C5, E5, C5, F5, C5, E5, C5, D5, B4, C5, _A4, F4, G4, C4, 
                    E5, G4, D5, G4, C5, G4, B3, G4, 
                    E5, G4, D5, G4, C5, C5, D5, C5, B4,
                    C4, C5, E5, C5, F5, C5, E5, C5, D5, B4, C5, _A4, F4, G4, C4,
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
    },

    // Next Song

    {
        "Jingle Bell Rock",
        2,
        {
            // Track 0
            {
                // Freq
                {
                    C5, C5, C5, B4, B4, B4, 
                    _A4, B4, _A4, E4, 
                    _A4, B4, _A4, E4, G4,
                    _A4, B4, _A4, F4, 
                    D4, E4, F4, G4, _A4, G4,
                    D4, E4, F4, G4,
                    0, _A4, a4, _A4, G4, _A4,
                    _A4, e4, e4,

                    C5, C5, C5, B4, B4, B4, 
                    _A4, B4, _A4, E4, 
                    _A4, B4, _A4, E4, G4,
                    _A4, B4, _A4, F4, 
                    D4, E4, F4, G4, _A4, G4,
                    D4, E4, F4, G4,
                    0, _A4, _A4, B4, G4, 
                    C5,
                    -1

                },

                // Beats
                {
                    0.5, 0.5, 1, 0.5, 0.5, 1,
                    0.5, 0.5, 0.5, 2.5,
                    0.5, 0.5, 1, 1, 1,
                    0.5, 0.5, 1, 2,
                    0.5, 1, 0.5, 0.5, 1, 0.5,
                    0.5, 0.5, 1, 2,
                    1, 0.5, 0.5, 0.5, 0.5, 1,
                    1, 0.5, 2.5,

                    0.5, 0.5, 1, 0.5, 0.5, 1,
                    0.5, 0.5, 0.5, 2.5,
                    0.5, 0.5, 1, 1, 1,
                    0.5, 0.5, 1, 2,
                    0.5, 1, 0.5, 0.5, 1, 0.5,
                    0.5, 0.5, 1, 2,
                    1, 0.5, 0.5, 1, 1,
                    4
                }
            },

            // Track 1
            {
                //Freq
                {
                    E4, E4, E4, E4, E4, E4, 
                    E4, E4, E4, E4,
                    C3, d3,
                    D3, G3, G3,
                    F3, E3, D3, G3,
                    F3, E3, D3, G3,
                    F3, B3,
                    G4,

                    E4, E4, E4, E4, E4, E4, 
                    E4, E4, E4, E4,
                    C3, d3,
                    D3, G3, G3,
                    F3, E3, D3, G3,
                    F3, E3, D3, G3,
                    F3, G3, F3,
                    G3, _A3, b3,
                    -1
                },

                // Beats
                {
                    0.5, 0.5, 1, 0.5, 0.5, 1,
                    0.5, 0.5, 0.5, 2.5,
                    2, 2,
                    2, 1, 1,
                    1, 1, 1, 1,
                    1, 1, 1, 1,
                    2, 2,
                    4,

                    0.5, 0.5, 1, 0.5, 0.5, 1,
                    0.5, 0.5, 0.5, 2.5,
                    2, 2,
                    2, 1, 1,
                    1, 1, 1, 1,
                    1, 1, 1, 1,
                    2, 1, 1,
                    1, 1, 2,
                }
            }
        },
    },

    // Next Song

    {
        "Metal Crusher - 2 Voice",
        2,
       {
           // Track 0
           {
               // Frequencies
               {
                   e4, e4, g3, g3, B3, B3, e2,
                   e1, e1, e1, e1, a1,
                   E5, e5, d5, e5, d5, B4, b4, a4, G4, a4, e4, E4,
                   e4, E4, e4, D4, e4, G4, B4, b4, 
                   a4, a4, b4, B4, b4, B4,
                   d5, B4, b4, G4, G4, b4, B4, B4, b4, a4, e4, E4,
                   e4, D4, e4, E4, e4, b3, B4, b4, 
                   a4, a4, G4, a4, a5,
                   -1
               },

               // Note lengths in beats
               {
                   0.75, 0.25, 0.5, 0.5, 0.75, 0.25, 1,
                   0.75, 0.25, 0.5, 0.5, 2,
                   0.5, 0.25, 0.25, 0.5, 0.25, 0.25, 0.5, 0.25, 0.25, 0.5, 0.25, 0.25,
                   0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 
                   0.5, 0.25, 0.25, 0.5, 0.25, 0.25, 
                   0.5, 0.25, 0.25, 0.5, 0.25, 0.25, 0.5, 0.25, 0.25, 0.5, 0.25, 0.25,
                   0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25,
                   0.5, 0.25, 0.25, 0.5, 0.5 
               }
           },

           // Track 2
           {
               // Freq
               {
                   0,
                   e3, e4, e3, e4, a3, a4, a3, a4, 
                   e3, e4, e3, e4, a3, a4, a3, a4, 
                   e3, e4, e3, e4, a3, a4, a3, a4, 
                   e3, e4, e3, e4, a3, a4, a3, a4, 
                   -1
               },

               // Note lengths

               {
                   8,
                   0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 
                   0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 
                   0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 
                   0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 
               }
           }
       } 
    },

    // Next track

    {
        "Metal Crusher - 1 Voice",
        1,
       {
           // Track 0
           {
               // Frequencies
               {
                   e4, e4, g3, g3, B3, B3, e2,
                   e1, e1, e1, e1, a1,
                   E5, e5, d5, e5, d5, B4, b4, a4, G4, a4, e4, E4,
                   e4, E4, e4, D4, e4, G4, B4, b4, 
                   a4, a4, b4, B4, b4, B4,
                   d5, B4, b4, G4, G4, b4, B4, B4, b4, a4, e4, E4,
                   e4, D4, e4, E4, e4, b3, B4, b4, 
                   a4, a4, G4, a4, a5,
                   -1
               },

               // Note lengths in beats
               {
                   0.75, 0.25, 0.5, 0.5, 0.75, 0.25, 1,
                   0.75, 0.25, 0.5, 0.5, 2,
                   0.5, 0.25, 0.25, 0.5, 0.25, 0.25, 0.5, 0.25, 0.25, 0.5, 0.25, 0.25,
                   0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 
                   0.5, 0.25, 0.25, 0.5, 0.25, 0.25, 
                   0.5, 0.25, 0.25, 0.5, 0.25, 0.25, 0.5, 0.25, 0.25, 0.5, 0.25, 0.25,
                   0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25,
                   0.5, 0.25, 0.25, 0.5, 0.5 
               }
           },
        },
    }
};

#endif
