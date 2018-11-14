/** Description: This file will convert all of our key board inputs into musical notes as if a real piano were to be playing 
* 
*/
#include <Arduino.h>
#include <Keyboard.h>

void setup()
{
    Keyboard.begin();
    char key;
}

/**This function just keeps on going until any key on our imaginary keyboard is pressed.Then it passes the key 
*ascii value to the keyboard() function which will decide what frequency or musical note to play for the corresponding keys 
*pressed.
*@key char stores the ascii value of the key pushed on the keyboard
*/
void press(key)
{
    while(True)
    {
        Keyboard.Press(key);
        Keyboard.releaseAll();
    }
}
/**This function uses a switch statement to assign frequencies to the key values.Then it passes the key 
*frequency value to the main() function which will decide what frequency or musical note to play for the corresponding keys 
*pressed.
*@key char stores the ascii value of the key pushed on the keyboard
*@note float  holds the musical notes or frequencies associated with the corresponding keys 
*/
void keyboard(key)
//paino key board only recognizes the "d"to "k" for the white parts, "r" to "i" for the black parts. 
{
    float note;
    // 12 cases  11 for the piano and 1 for all other keys 
    switch(note)
    {
        //all the whites 
        case 1:
        {
            if (key == "d")
            {
                note =  ;//frequency for A 
            }
        }

        case 2:
        {
            if (key == "f")
            {
                note =  ;//frequency for B 
            }
        }

        case 3:
        {
            if (key == "g")
            {
                note =   ;//frequency for C
            }
        }

        case 4:
        {
            if (key == "h")
            {
                note =  ;//frequency for D 
            }
        }

        case 5:
        {
            if (key == "j")
            {
                note =  ;//frequency for E
            }
        }

        case 6:
        {
            if (key == "k")
            {
                note =  ;//frequency for G 
            }
        }
        //now the black parts 
        case 7:
        {
            if (key == "r")
            {
                note =  ;//frequency for d
            }
        }

        case 8:
        {
            if (key == "t")
            {
                note =  ;//frequency for e 
            }
        }

        case 9:
        {
            if (key == "y")
            {
                note =  ;//frequency for g
            }
        }

        case 10:
        {
            if (key == "u")
            {
                note =  ;//frequency for a 
            }
        }

        case 11:
        {
            if (key == "i")
            {
                note =  ;//frequency for b
            }
        }
        // now the other case 
        default: note = 0;
    }
    return note;

}
/**This function calls all the other functions in order to get the frequencies for each key pressed on the piano player.
*/

int main()
{
    setup();
    press();
    keyboard();
}
