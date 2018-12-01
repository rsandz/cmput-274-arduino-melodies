/** Description: This file will create serveral arrays that hold the beats and the frquencies of certain songs to be played 
*by the buzzer. It will also have 2 structs that will hold these arrays
*/
#include <Arduino.h>

/**
 * This function uses math to convert the beats array into an period.Then it passes the key 
 * frequency value to the main() function which will decide what frequency or musical note to play for the corresponding keys 
 * pressed.
 */
void convert_to_period(float beats[], int bpm, int array_size)
{
    //get the number of elements in the beats array
    for( int i = 0; i < array_size; i++)
    {
        beats[i] = beats[i] / (float) bpm * 6.0e4;
        //the answer is in minutes so convert it to milliseconds with 6e4
    }
}