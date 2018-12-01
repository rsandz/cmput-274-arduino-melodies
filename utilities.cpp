/** Description: This file will create serveral arrays that hold the beats and the frquencies of certain songs to be played 
*by the buzzer. It will also have 2 structs that will hold these arrays
*/
#include <Arduino.h>

void setup()
{
    Serial.begin(9600);
    
}
/**This function uses math to calculate the beats per minute of the given frequencies.Then it passes the key 
*frequency value to the main() function which will decide what frequency or musical note to play for the corresponding keys 
*pressed.
*@key char stores the ascii value of the key pushed on the keyboard
*@note float  holds the musical notes or frequencies associated with the corresponding keys 
*/
float bpm(beat)
{
    //get number of elements in the freq array 
    n = sizeof(beat)/sizeof(beat[0]);
    // bpm is the same length as freq(the frquiencies array)
    float bpm[n];
    for (int i =0;i<n;i++)
    {
        //1bmp = (60/beat) minutes --> our freq array is in Hz so we are all good
        bpm[i] = 60/bpm[i];
    }
    return bpm;


}
/**This function uses math to convert the beats array into an period.Then it passes the key 
*frequency value to the main() function which will decide what frequency or musical note to play for the corresponding keys 
*pressed.
*@key char stores the ascii value of the key pushed on the keyboard
*@note float  holds the musical notes or frequencies associated with the corresponding keys 
*/
float beats_to_period(beat,bpm)
{
    
    //get the number of elements in the beats array
    b = sizeof(beat)/sizeof(beat[0]);
    float beat_period[b];
    for( int i = 0; i<b;i++)
    {
        beat_period[i] = beat[i]/ bpm[i];
        //the answer is in minutes so convert it to microseconds 
        beat_period[i] = beat_period[i]*6e7;
    }
    return beat_period;

}

int main()
{
    bpm = bpm(beat);
    beat_T = beats_to_period(beat);
}