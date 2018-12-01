/*
    Contains the songs for the buzzers
*/

#ifndef SONGS_H
#define SONGS_H

/*
================
|   Structs    |
================
*/

struct Track
{
    float freq[];
    float beats[];
};

struct Song 
{
    struct Track tracks[];
};

/*
===============
|   Songs     |
===============
*/

const struct Song twinkle_twinkle;


#endif
