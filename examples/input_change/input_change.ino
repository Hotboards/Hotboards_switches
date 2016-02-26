/* input_change.ino
 * Author Diego Perez (http://hotboards.org)
 * read an input on pin 5, only when its value has been changed
 */

#include <Arduino.h>
#include <Hotboards_switches.h>

// create a single sw object, this interrupt will give us a LOW value when close
// because work with pull-ups.
Hotboards_switches sw( 5 );
// if your interrupt will gave you a HIGH value when close, then we need to create the sw
// object with an extra parameter: Hotboards_switches sw( 5, HIGH );
// in any case the functions will return a true value any time the sw is closed

void setup( void )
{
    // para este ejemplo usaremos el puerto serial, aqui lo inicializamos
    Serial.begin( 9600 );
}

void loop( void )
{
    // ask when the interrupt change its value
    if( sw.hasItChange( ) )
    {
        // when the interrupt is close (or ON) the fucntion will return a true value
        // it doesn't matter if our inut is configured with pull-ups(LOW) or pull-downs(HIGH)
        if( sw.read( ) )
        {
            Serial.print( "sw = close (on)\n\r" );
        }
        else
        {
            Serial.print( "sw = open (off)\n\r" );
        }
    }
}
